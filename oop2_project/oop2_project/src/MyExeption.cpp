#include "..\include\MyExeption.h"

void MyExeption::saveExeptionInFile()
{
	std::ofstream fileToSave("exception.txt");
	if (fileToSave.is_open())
	{
		// file-����� ����� �� ���� �
		fileToSave << m_message << ::std::endl;
		fileToSave.close();
	}
}
