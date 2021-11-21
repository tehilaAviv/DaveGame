#pragma once
#include <fstream>
#include <string>
#include <exception>
class MyExeption : public std::exception
{
public:

	MyExeption(std::string message) :exception(), m_message(message) {};
	~MyExeption() = default;
	void saveExeptionInFile();
	const std::string& getString() { return m_message; }
private:
	std::string m_message; // מכיל את הודעת החריגה
};
