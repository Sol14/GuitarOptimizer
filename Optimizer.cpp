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
	
	//Init matrices
	this->F = new float*[this->song.size()];
	this->E = new float*[this->song.size()];
	for(unsigned int i = 0; i <= this->song.size(); i++){
		F[i] = new float[3];
		E[i] = new float[3];
		for(int j = 0; j < 3; j++){
			F[i][j] = 0;
			E[i][j] = 0;
		}
	}
}

Optimizer::~Optimizer(){
	for(unsigned int i = 0; i <= this->song.size(); i++){
		//delete F[i];
		//delete E[i];
	}
}

float Optimizer::abs(float x){
	return x >= 0 ? x : x * -1;
}

float Optimizer::getExhaustive(){
	return recursiveOptime(0, 0, 0);
}

float Optimizer::getDynamic(){
	int n = song.size() - 1;
	for(int i = n - 1; i >= 0; i--){		//Movimiento de profundidad 
		for(int j = 2; j >= 0; j--){		//Movimiento lateral
			float emin = F[i+1][0] + abs(song[i].centroid(j) - song[i+1].centroid(0));//Minimo de la etapa
			E[i][j] = 1;
			for(int k = 1; k < 3; k++){		//Aqui se elige una de las 3 opciones
				float nemin = F[i+1][k] + abs(song[i].centroid(j) - song[i+1].centroid(k));
				if(nemin < emin){
					emin = nemin;
					E[i][j] = k+1;
				}
				F[i][j] = emin;
			}
		}
	}
	float min = F[0][0];
	for(int i = 1; i < 3; i++){
		min = F[0][i] < min ? F[0][i] : min;
	}
	return min;
}

std::vector<int> Optimizer::getDynamicPath(){
	std::vector<int>path;
	int p = 0;
	float min = F[0][0];
	for(int i = 1; i < 3; i++){
		if(F[0][i] < min){
		min = F[0][i];
		p = i;
		}
	}
	path.push_back(p + 1);
	for(unsigned int i = 0; i < this->song.size() - 2; i++){
		p = E[i][p] - 1;
		path.push_back(p + 1);
	}
	return path;
}

float Optimizer::recursiveOptime(unsigned int i, float last, float min){
	if(i == this->song.size()){ //Base
		if(min <= this->minimal){
			this->minimal = min;
		}
		return min;
	}
	float c0, c1, c2;
	c0 = c1 = c2 = std::numeric_limits<float>::max();
	float nlast = 0;								//Init case
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
	if(c0 < c1 && c0 < c2 && c0){
		if(c0 == minimal) solution[i] = 1;
		return c0;
	}
	if(c1 < c0 && c1 < c2 && c1){
		if(c1 == minimal) solution[i] = 2;
		return c1;
	}
	else{
		if(c2 == minimal) solution[i] = 3;
		return c2;
	}
}

void Optimizer::printSolution(){
	std::cout << "Pares ordenados por exhaustiva" << std::endl;
	for(unsigned int i = 0; i < this->song.size() - 1; i++){
		std::cout << "( " << this->song[i].getLabel() << ", " << this->solution[i] << " )" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Matriz Sigma" << std::endl;
	std::cout << std::endl;
	for(unsigned int i = 0; i < song.size(); i++){
		for(int j = 0; j < 3; j++){
			std::cout << this->E[i][j] << "    ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Oraculo" << std::endl;
	std::cout << std::endl;
	for(unsigned int i = 0; i < song.size(); i++){
		for(int j = 0; j < 3; j++){
			std::cout << this->F[i][j] << "    ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void Optimizer::printSong(){
	for(unsigned int i = 0; i < song.size() - 1; i++){
		std::cout << "( " << song[i].getLabel() << ", " << song[i].getP0() << ", " << song[i].getP1() << ", " << song[i].getP2() << " )" << std::endl;
	}
}