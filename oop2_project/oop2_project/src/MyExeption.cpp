#include "..\include\MyExeption.h"

void MyExeption::saveExeptionInFile()
{
	std::ofstream fileToSave("exception.txt");
	if (fileToSave.is_open())
	{
		// file-העתקת הגודל של הלוח ל
		fileToSave << m_message << ::std::endl;
		fileToSave.close();
	}
}
