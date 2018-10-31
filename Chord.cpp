#include "Chord.h"

Chord::Chord(){
	this->label = "";
	position[0] = 0;
	position[1] = 0;
	position[2] = 0;
}

Chord::Chord(std::string label, float p1, float p2, float p3){
	this->label = label;
	position[0] = p1;
	position[1]	= p2;
	position[2] = p3;
}

Chord::Chord(const Chord& original){
	this->label = original.label;
	this->position[0] = original.position[0];
	this->position[1] = original.position[1];
	this->position[2] = original.position[2];
}

Chord::Chord(std::vector<std::string> line){
	Chord();
	this->label = line[0];
	setAve(line);
}

std::string Chord::getLabel(){
	return this->label;
}

float Chord::getP1(){
	return position[0];
}

float Chord::getP2(){
	return position[1];
}

float Chord::getP3(){
	return position[2];
}

void Chord::setLabel(std::string label){
	this->label = label;
}

void Chord::setP1(float p1){
	position[0] = p1;
}

void Chord::setP2(float p2){
	position[1] = p2;
}

void Chord::setP3(float p3){
	position[2] = p3;
}


Chord::~Chord(){};

void Chord::setAve(std::vector<std::string> line){
	int quant = 0;
	int j = 2;
	int k = 8;
	int l = 1;
	for(int p = 0; p < 3; p++){
		for(int i = j; i < k; i++){
			if(!line[i].empty()){
				if(!line[l].empty()){
					line[i] += std::stof(line[l]);
				}
				quant ++;
				this->position[p] += std::stof(line[i]);
			}
		}
		this->position[p] = this->position[p] / quant;
		j += 7;
		k += 7;
		l += 7;
		quant = 0;
		}
	}
