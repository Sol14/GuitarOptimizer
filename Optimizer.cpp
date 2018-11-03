#include "Optimizer.h"

Optimizer::Optimizer(std::ifstream& data, std::ifstream& song){
	Chord C;
	std::string line;
	while(std::getline(data, line)){
		C = Chord(line);
	this->GData[C.getLabel()] = C;
	}
	
	std::string temp;
	int c = 1;
	while(std::getline(song, temp)){
		this->song.push_back(Chord(GData.find(temp)->second));
		c++;
	}
}

Optimizer::~Optimizer(){
}

