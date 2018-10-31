#include "Data.h"
#include <iostream>
#include <fstream>

Data::Data(){
	std::ifstream file("/home/solrak/Documents/CodeLite_Workspace/GuitarOptimizer/Data/PosicionesDeGuitarra.csv");
	std::string tmp;
	while(!file.eof()){
		std::vector<std::string> line;
		for (int i = 0; i < 21; i++){
			std::getline(file, tmp, ',');
			line.push_back(tmp);
		}
		std::getline(file, tmp, '\n');
		line.push_back(tmp);
		Chord C(line);
		std::cout << C.getLabel() << std::endl;
		std::cout << C.getP1() << std::endl;
		std::cout << C.getP2() << std::endl;
		std::cout << C.getP3() << std::endl;
	}
}
	

Data::~Data(){

}

Chord Data::search(std::string key){
	//return GData.search(key);
}