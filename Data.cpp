#include "Data.h"
#include <iostream>
#include <fstream>
#include <sstream>

Data::Data(){
	std::ifstream file("/home/solrak/Documents/CodeLite_Workspace/GuitarOptimizer/Data/PosicionesDeGuitarra.csv");
	std::string value;
	//Read line by line, separating values by ","
	
}

Data::~Data(){

}

Chord Data::search(std::string key){
	std::vector<Chord>::iterator p;
	p = this->GData.begin();
	while(p->getLabel() != key && p != GData.end()){
		p++;
	}
	return *p;
}

Chord Data::parse(const std::ifstream& file){
	std:vector<std::string> line;
	std::string temp;
	for (i = 0; i < 12; i++){
		std::getline(file, temp, ',');
		line.append(temp);
	}
}