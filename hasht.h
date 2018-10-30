#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>
#include <iostream>

template <typename T>

class hasht{
public:
	hasht(int nEntradas){
		tabla.resize(nEntradas);
		numEntradas = nEntradas;
	};

			
	~hasht(){
		
	};
		
	T* search(const T& item){
		int pos = item % numEntradas;
		auto p = tabla[pos].begin();
		while(p !=  tabla[pos].end() && *p != item){
		++p;
		}
		T* q = *p == item ? &(*p) : NULL;
		return q;
	};
		
		
	void insert(const T& item){
		tabla[item % numEntradas].push_back(item); 
	};
			
private:
	int numEntradas;
		std::vector<std::list<T> > tabla;
	};
	
#endif
