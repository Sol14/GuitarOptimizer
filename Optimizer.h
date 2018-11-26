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
float ** F;
float ** E;
std::vector<Chord> song;
std::vector<int> solution;

float abs(float x); //Para no importar <CMath>
float recursiveOptime(unsigned int i, float last, float min);
public:
	Optimizer(std::ifstream& data, std::ifstream& song);
	~Optimizer();
	
	float getExhaustive();
	float getDynamic();
	std::vector<int> getDynamicPath();
	void printSolution();
	void printSong();
};

#endif // OPTIMIZER_H
