#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controller.h"
int main()
{
	//try {
		//define a Controller and call to run(), to run the game
		Controller c;
		c.runGame();
	/*}
	catch (const GeneralError & g)
	{
		std::cout << g.what() << std::endl;
	}*/
	return 0;
}
