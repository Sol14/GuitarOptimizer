#include "Chord.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Optimizer.h"
#include <sys/time.h>
typedef unsigned long long timestamp_t;
using namespace std;

static timestamp_t get_timestamp (){
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int argc, char* argv[]){
	ifstream file("/home/solrak/Documents/GuitarOptimizer/Data/Posiciones de guitarra.csv"); //Por parametro a futuro
	ifstream song("/home/solrak/Documents/GuitarOptimizer/Data/Test.txt"); //Por parametro a futuro
	Optimizer Op = Optimizer(file, song);
	Op.printSong();
    timestamp_t t0 = get_timestamp();
   // cout << "Exhaustiva: " << Op.getExhaustive() << endl;
    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0) / 1000000.0L;
	cout << "Tiempo exhaustiva: " << secs << endl;
	
    t0 = get_timestamp();
    cout << "Dinamica: " << Op.getDynamic() << endl;
    t1 = get_timestamp();
    secs = (t1 - t0) / 1000000.0L;
	cout << "Tiempo Dinamica: " << secs << endl;
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
