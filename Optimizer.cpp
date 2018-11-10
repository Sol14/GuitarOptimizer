#include "Optimizer.h"

Optimizer::Optimizer(std::ifstream& data, std::ifstream& song){
	Chord C;
	std::string line;
	while(std::getline(data, line)){	//MapChord init
		C = Chord(line);				//Se puede separar a una clase diferente
		this->GData[C.getLabel()] = C;  //para ser mas generico
	}								    
	while(std::getline(song, line)){
		this->song.push_back(Chord(GData.find(line)->second));	//Song init
	}
	
	this->minimal = -1; 	//Minimal init -1 //Infinite value
}

Optimizer::~Optimizer(){
}

void Optimizer::abs(float x){
	x = x >= 0 ? x : x * -1;
}

float Optimizer::getOptime(int i, float min){
	if(i == song.size() - 1){ //Base
		if(min <= this->minimal){
			this->minimal = min;
			return min;
		}
		return -1;
	}
}
