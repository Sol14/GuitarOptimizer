#include "hasht.h"
#include <string>
#include "Chord.h"

#ifndef DATA_H
#define DATA_H

class Data{
private:
	std::vector<std::string> split(std::string strToSplit, char delimeter);
	Chord parse(const std::ifstream& line);
	std::vector<Chord> GData;
public:
	Data();
	~Data();
	Chord search(std::string key);
};

#endif // DATA_H
