#include "Chord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Optimizer.h"

using namespace std;


int main(int argc, char* argv[]){
	ifstream file("/home/solrak/Documents/GuitarOptimizer/Data/Posiciones de guitarra.csv"); //Por parametro a futuro
	ifstream song("/home/solrak/Documents/GuitarOptimizer/Data/Test.txt"); //Por parametro a futuro
	Optimizer Op = Optimizer(file, song);
	Op.printSong();
	
	
	cout << "Exhaustiva: " << Op.getExhaustive() << endl;
	cout << "Dinamica: " << Op.getDynamic() << endl;
	cout << endl;
	Op.printSolution();
	
	
	//Indicación del path Dinamico
	vector<int> path = Op.getDynamicPath();
	cout << "Vector solucion dinamico" << endl;
	cout << endl;
	for(unsigned int i = 0; i < path.size() - 1; i++){
		cout << path[i] << ", ";
	}
	cout << path[path.size() - 1] << endl;
}