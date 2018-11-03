#include "Chord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Optimizer.h"

using namespace std;


int main(int argc, char* argv[]){
	ifstream file("/home/solrak/Documents/CodeLite_Workspace/GuitarOptimizer/Data/Posiciones de guitarra.csv");
	ifstream song("/home/solrak/Documents/CodeLite_Workspace/GuitarOptimizer/Data/One.txt");
	Optimizer Op = Optimizer(file, song);
}