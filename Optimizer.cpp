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
		solution.push_back(0);									//Solution init
	}
	this->minimal = std::numeric_limits<float>::max(); 	//Minimal init -1 //Infinite value
}

Optimizer::~Optimizer(){
}

float Optimizer::abs(float x){
	return x >= 0 ? x : x * -1;
}

void Optimizer::getOptime(){
		std::cout << "Minimal: " << recursiveOptime(0, 0, 0) << std::endl;
}

float Optimizer::recursiveOptime(unsigned int i, float last, float min){
	if(i == this->song.size()){ //Base
		if(min <= this->minimal){
			this->minimal = min;
		}
		return min;
	}
	else{//Candidate def
	float c0, c1, c2;
	c0 = c1 = c2 = std::numeric_limits<float>::max();
		float nlast = 0;
		if(song[i].getP0() != -1){
			if(i != 0) nlast = song[i].getP0();
			c0 = recursiveOptime(i + 1, song[i].getP0(), min + abs(last - nlast));
		}
		if(song[i].getP1() != -1){
			if(i != 0) nlast = song[i].getP1();
			c1 = recursiveOptime(i + 1, song[i].getP1(), min + abs(last - nlast));
		}
		if(song[i].getP2() != -1){
			if(i != 0) nlast = song[i].getP2();
			c2 = recursiveOptime(i + 1, song[i].getP2(), min + abs(last - nlast));
		}
		if(c0 < c1 && c0 < c2 && c0 == minimal){
			solution[i] = 1;
			return c0;
		}
		if(c1 < c0 && c1 < c2 && c1 == minimal){
			solution[i] = 2;
			return c1;
		}
		if(c2 < c0 && c2 < c1 && c2 == minimal){
			solution[i] = 3;
			return c2;
		}
		
	}
}

void Optimizer::printSolution(){
	for(unsigned int i = 0; i < this->song.size(); i++){
		std::cout << "( " << this->song[i].getLabel() << ", " << this->solution[i] << " )" << std::endl;
	}
	std::cout << this->minimal << std::endl; 
}

void Optimizer::printSong(){
	for(unsigned int i = 0; i < song.size(); i++){
		std::cout << "( " << song[i].getLabel() << ", " << song[i].getP0() << ", " << song[i].getP1() << ", " << song[i].getP2() << " )" << std::endl;
	}
}