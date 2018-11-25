#include <sstream>
#include "Chord.h"
#include <iostream>

Chord::Chord(){
	this->label = "";
	for(int i = 0; i < 3; i++){
		this->position[i] = 0;
	}
}

Chord::Chord(std::string label, float p0, float p1, float p2){
	this->label = label;
	this->position[0] = p0;
	this->position[1] = p1;
	this->position[2] = p2;
}

Chord::Chord(const Chord& original){
	this->label = original.label;
	for(int i = 0; i < 3; i++){
		this->position[i] = original.position[i];
	}
}

Chord::Chord(std::string line){
	for(int i = 0; i < 3; i++){
		this->position[i] = 0;
	}
	std::stringstream ss(line);
	std::string tline;
	std::vector<std::string> data;
	while(std::getline(ss, tline, ',')){
		data.push_back(tline);
	}
	this->label = data[0];
	this->average(data);
}

Chord::~Chord(){
	//Do not
}

std::string Chord::getLabel(){
	return this->label;
}

float Chord::getP0(){
	return this->position[0];
}

float Chord::getP1(){
	return this->position[1];
}

float Chord::getP2(){
	return this->position[2];
}

float Chord::centroid(int i){
	return this->position[i];
}


//Helper functions

void Chord::average(std::vector<std::string> data){
	int k = 2;
	int l = 1;
	for(int j = 0; j < 3; j++){
		int counter = 0;
		int extra = (data[l].empty()) ? 0 : stoi(data[l]);
		for(int i = k; i < k + 6; i++){
			if(!data[i].empty() && data[i] != *data.end()){
				this->position[j] += std::stoi(data[i]) + extra;
				counter++;
			}
		} 
		this->position[j] = counter == 0 ? -1 : this->position[j] / counter;
		k += 7;
		l += 7;
	}
}