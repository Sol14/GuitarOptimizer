#include <sstream>
#include "Chord.h"

Chord::Chord(){
	this->label = "";
	for(int i = 0; i < 3; i++){
		this->position[i] = 0;
	}
}

Chord::Chord(std::string label, float p1, float p2, float p3){
	this->label = label;
	this->position[0] = p1;
	this->position[1] = p2;
	this->position[2] = p3;
}

Chord::Chord(const Chord& original){
	this->label = original.label;
	for(int i = 0; i < 3; i++){
		this->position[i] = original.position[i];
	}
}

Chord::Chord(std::string line){
	std::sstream ss(line);
	std::vector<std::string> data;
	while(std::getline())
}

Chord::~Chord(){
	//Do not
}

std::string Chord::getLabel(){
	return this->label;
}

float Chord::getP1(){
	return this->position[0];
}

float Chord::getP2(){
	return this->position[1];
}

float Chord::getP3(){
	return this->position[2];
}
