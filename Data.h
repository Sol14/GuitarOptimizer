#include "hasht.h"
#include <string>
#include "Chord.h"

#ifndef DATA_H
#define DATA_H

class Data{
private:
	float* average(std::vector<std::string>);
	hasht<Chord> GData = hasht<Chord>(7); //Cambiar apropiadamente
public:
	Data();
	~Data();
	Chord search(std::string key);
};

#endif // DATA_H
