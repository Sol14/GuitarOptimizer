#include "Chord.h"

Chord::Chord(std::string label, float p1, float p2, float p3){
	this->label = label;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Chord::Chord(const Chord& original){
	this->label = original.label;
	this->p1 = original.p1;
	this->p2 = original.p2;
	this->p3 = original.p3;
}

std::string Chord::getLabel(){
	return this->label;
}

float Chord::getP1(){
	return this->p1;
}

float Chord::getP2(){
	return this->p2;
}

float Chord::getP3(){
	return this->p3;
}


Chord::~Chord(){};