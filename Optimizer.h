#include <iostream>
#include <fstream>
#include <string>
#include "Chord.h"
#include <map>

#ifndef OPTIMIZER_H
#define OPTIMIZER_H


class Optimizer{
private:
std::map<std::string, Chord> GData;
float minimal;
std::vector<Chord> song;
std::vector<int> solution;

void abs(float x); //Para no importar <CMath>
float getOptime(int i, float min);

public:
	Optimizer(std::ifstream& data, std::ifstream& song);
	~Optimizer();
};

#endif // OPTIMIZER_H
