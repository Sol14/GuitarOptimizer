#include "Optimizer.h"

Optimizer::Optimizer(std::ifstream& data, std::ifstream& song){
	Chord C;
	std::string line;
	while(std::getline(data, line)){
		C = Chord(line);
		this->GData[C.getLabel()] = C;
	}
	while(std::getline(song, line)){
		this->song.push_back(Chord(GData.find(line)->second));
	}
}

Optimizer::~Optimizer(){
}

