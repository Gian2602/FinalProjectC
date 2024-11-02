//Rocchegiani Fabrizio

#ifndef LogManipulator_h
#define LogManipulator_h

#include <iostream>
#include <fstream>
#include <string>

class LogManipulator
{
	private:
		std::string fileName;
		const static int DATE_DIM = 26;
		std::string getCurrentDateString();
	public:
		//costruttori:
		LogManipulator();
		LogManipulator(std::string fileName);
		
		int insertString(std::string str);
		//funzioni per inserire dati in altri formati, non necessario nella versione corrente.
		std::string getStringAt(int index);
		//funzioni per prelevare dati in altri formati, non necessario nella versione corrente.

		//funzioni getters del log manipulator:
		std::string getFileName() const;
};

//eccezione personalizzata della classe LogManipulator:
class LogException : std::exception{
	private:
		const char* msg;
	public:
		LogException(const char* msg) : msg(msg) {}
		const char* what() const { return msg; }
};

#endif