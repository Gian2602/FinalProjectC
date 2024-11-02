//Rocchegiani Fabrizio

#include "LogManipulator.h"

LogManipulator::LogManipulator() {
    this->fileName = "TempLogFile_" + getCurrentDateString() + ".txt";
}

LogManipulator::LogManipulator(std::string fileName){
    this->fileName = fileName + ".txt";
}

std::string LogManipulator::getCurrentDateString() {
    //elementi necessari per poter estrarre e restituire la data nel formato e nel tipo desiderato:
    std::string date;
    char tempDate[DATE_DIM]{};
    //funzione che ci permette di ottenere la data attuale:
    time_t now = time(0);
    
    //conversione della data attuale in elementi all'interno del vettore di caratteri:
    ctime_s(tempDate, DATE_DIM, &now);
    date = date + tempDate;

    //ritorno la stringa nel formato che preferisco:
    return date.substr(4, 3) + "-" + date.substr(8, 2) + "-" + date.substr(20,4) + "_" + date.substr(11,2) + "-" + date.substr(14,2) + "-" + date.substr(17,2);
}

//metodo più lento, utilizzato nel caso in cui non voglio lasciare il file aperto per troppo tempo:
int LogManipulator::insertString(std::string str)
{
    std::ofstream fs;
    fs.open(fileName, std::ofstream::app);
    if (fs.fail())
        throw LogException("\nImpossibile aprire il file.");
    fs<<str<<"\n";
    fs.close();
    return 0;
}

//metodo più lento, utilizzato nel caso in cui non voglio lasciare il file aperto per troppo tempo:
std::string LogManipulator::getStringAt(int index) {
    std::ifstream fs;
    std::string str="";
    fs.open(fileName, std::ifstream::in);
    if (fs.fail())
        throw LogException("\nImpossibile aprire il file.");
    for (int i = index; i > 0; i--)
        std::getline(fs,str,'\n');
    fs.close();
    return str;
}

std::string LogManipulator::getFileName() const {
    return fileName;
}