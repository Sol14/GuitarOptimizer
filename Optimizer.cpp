#include "Optimizer.h"
#include <limits>

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
	for(unsigned int i = 0; i < this->song.size(); i++){
		solution.push_back(0);
	}
	this->minimal = -1; 	//Minimal init -1 //Infinite value
}

Optimizer::~Optimizer(){
}

float Optimizer::abs(float x){
	return x >= 0 ? x : x * -1;
}

void Optimizer::getOptime(){
		recursiveOptime(0, 0, 0);
}

float Optimizer::recursiveOptime(unsigned int i, float last, float min){
	float c0, c1, c2;
	c0 = c1 = c2 = std::numeric_limits<float>::max();
	if(i == this->song.size()){ //Base
		if(min <= this->minimal || this->minimal == -1){
			this->minimal = min;
			return min;
		}
		return -1;
	}
	else{//Candidate def
		if(this->song[i].getP0() != -1){
			float tmp = min + abs(last - this->song[i].getP0());
			if (i == 0) tmp = min;
			c0 = recursiveOptime(i+1, this->song[i].getP0(), tmp);
		}
		
		if(this->song[i].getP1() != -1){
			float tmp = min + abs(last - this->song[i].getP1());
			if (i == 0) tmp = min;
			c1 = recursiveOptime(i+1, this->song[i].getP1(), tmp);
		}
		
		if(this->song[i].getP2() != -1){
			float tmp = min + abs(last - this->song[i].getP2());
			if (i == 0) tmp = min;
			c2 = recursiveOptime(i+1, this->song[i].getP2(), tmp);
		}
	}
	if(c0 < c1 && c0 < c2){
		if(c0 == this->minimal)this->solution[i] = 0;
		return c0;
	}
	else if(c1 < c0 && c0 < c2){
		if(c1 == this->minimal)this->solution[i] = 1;
		return c1;
	}
	else{
		if(c2 == this->minimal)this->solution[i] = 2;
		return c2;
	}
}

void Optimizer::printSolution(){
	for(unsigned int i = 0; i < this->song.size(); i++){
		std::cout << "(" << this->song[i].getLabel() << "," << this->solution[i] << ")" << std::endl;
	}
	std::cout << this->minimal << std::endl; 
}

void Optimizer::printSong(){
	for(unsigned int i = 0; i < song.size(); i++){
		std::cout << "(" << song[i].getLabel() << "," << song[i].getP0() << "," << song[i].getP1() << "," << song[i].getP2() << ")" << std::endl;
	}
}