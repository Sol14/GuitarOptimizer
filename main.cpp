#include "Chord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Optimizer.h"

using namespace std;


int main(int argc, char* argv[]){
	ifstream file("/home/solrak/Documents/GuitarOptimizer/Data/Posiciones de guitarra.csv");
	ifstream song("/home/solrak/Documents/GuitarOptimizer/Data/Test.txt");
	Optimizer Op = Optimizer(file, song);
	Op.getOptime();
	Op.printSolution();
	cout << "=================" << endl;
	Op.printSong();
}