#include "..\include\Collision.h"
#include <iostream>
#include "Dave.h"
#include "Monster.h"
#include "Fire.h"
#include "Diamond.h"
#include "Wall.h"
#include "Gifts.h"
#include "Key.h"
#include <utility> 
#include  <string>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Door.h"
#include "Level.h"
#include "StandingState.h"
#include "Const.h"
#include <SFML/Audio.hpp>
#include "Grafix.h"
namespace
{

	void DaveDiamond(Object& dave, Object& diamond, Level& l) //פונקציה הבודקת התנגשות בין שחקן ליהלום
	{
		Dave& d = dynamic_cast<Dave&>(dave);
		Diamond& diamond1 = dynamic_cast<Diamond&>(diamond);
		d.setNumScores(30);//בעת התנגשות של שחקן עם יהלום נוסיף 15 נקודות  
		Grafix::getInstance().m_eatSound.stop();
		Grafix::getInstance().m_eatSound.play();


	}

	void DaveFire(Object& dave, Object& fire, Level& l)
	{
		
		Dave& d = dynamic_cast<Dave&>(dave);
		Fire& f = dynamic_cast<Fire&>(fire);
		d.decreasLives();
		d.setNeedToSetBoard(true);//מתחיל את השלב מחדש
		Grafix::getInstance().m_colliedSound.stop();
		Grafix::getInstance().m_colliedSound.play();
	}


	void DaveKey(Object& dave, Object& key, Level& l)
	{
		Dave& d = dynamic_cast<Dave&>(dave);
		Key& key1 = dynamic_cast<Key&>(key);
		d.setIsKey(true);
		Grafix::getInstance().m_eatSound.stop();
		Grafix::getInstance().m_eatSound.play();
	}

	void DaveWall(Object& dave, Object& wall, Level& l)
	{
	   Dave& d = dynamic_cast<Dave&>(dave);
		Wall& wall1 = dynamic_cast<Wall&>(wall);
		//טיפול בהתנגשות של שחקן עם אבן 
		if ((dave.getLocation().y + dave.getFloatRect().height - wall.getLocation().y) < 5 && (dave.getLocation().x < wall.getLocation().x + wall.getFloatRect().width))
		{
			
			d.handleInput((sf::Keyboard::Key) Space);
		}

		else
		{
		
			d.setLastPosition();//החזרת השחקן למיקום הקודם
		}
	}
	void MonsterDave(Object& monster, Object& dave, Level& l)//טיפול בהתנגשות בין מפלצת לשחקן
	{

		Dave& d = dynamic_cast<Dave&>(dave);
		Monster& monster1 = dynamic_cast<Monster&>(monster);
		d.decreasLives();//הורדת חיים לשחקן
		d.setNeedToSetBoard(true);//מתחיל את השלב מחדש

	}
	void DaveMonster(Object& dave, Object& monster, Level& l)
	{
		MonsterDave(monster, dave, l);

	}

	void DaveDoor(Object& dave, Object& door, Level& l)//טיפול בהתנגשות בין דלת לשחקן
	{
		Dave& d = dynamic_cast<Dave&>(dave);
		Door& door1 = dynamic_cast<Door&>(door);
		if (d.isKey())
			d.setIsDoor(true);
		Grafix::getInstance().m_winLevelSound.stop();
		Grafix::getInstance().m_winLevelSound.play();
	
			
			

	}


	void monsterWall(Object& monster, Object& wall, Level& l)//טיפול בהתנגשות בין קיר למפלצת
	{
		Wall& wall1 = dynamic_cast<Wall&>(wall);
		Monster& monster1 = dynamic_cast<Monster&>(monster);
		monster1.setcanMove();//עצירת תזוזת המפלצת המיוחדת בגלל התנגשות בקיר
		monster1.setDirection();//שינוי התזוזה לכיוון הנגדי
	}

	void DaveGifts(Object& dave, Object& gifts, Level& l)//טיפול בהתנגשות בין מתנה לשחקן
	{
		Dave& d = dynamic_cast<Dave&>(dave);
		Gifts& g = dynamic_cast<Gifts&>(gifts);
		int SpecialKey = g.getSpecialKey();//קריאה לפונקציה שמזהה איזה מתנה נבחרה
		switch (SpecialKey)
		{
		case 0: d.setNumScores(30);//מתנה המעלה ניקוד ב30

			break;
		case 1:d.increasLives();// מתנה המעלה חיים

			break;
		default:
			break;
		}
		Grafix::getInstance().m_eatSound.stop();
		Grafix::getInstance().m_eatSound.play();

	}


	using HitFunctionPtr = void (*)(Object&, Object&, Level & l);// 
	using Kay = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Kay, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Kay(typeid(Dave), typeid(Diamond))] = &DaveDiamond;
		phm[Kay(typeid(Dave), typeid(Door))] = &DaveDoor;
		phm[Kay(typeid(Dave), typeid(Fire))] = &DaveFire;
		phm[Kay(typeid(Monster), typeid(Dave))] = &MonsterDave;
		phm[Kay(typeid(Dave), typeid(Key))] = &DaveKey;
		phm[Kay(typeid(Dave), typeid(Monster))] = &DaveMonster;
		phm[Kay(typeid(Dave), typeid(Gifts))] = &DaveGifts;
		phm[Kay(typeid(Dave), typeid(Wall))] = &DaveWall;
		phm[Kay(typeid(Monster), typeid(Wall))] = &monsterWall;
		return phm;
	}


	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}
}

void processCollision(Object& object1, Object& object2, Level& l)//
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
	    throw UnknownCollision(object1, object2);
	}
	phf(object1, object2, l);
}


