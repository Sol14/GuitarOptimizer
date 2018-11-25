#include <vector>
#include <string>

#ifndef CHORD_H
#define CHORD_H
class Chord{
private:
	std::string label;
	float position[3];
	void average(std::vector<std::string> data);
	
public:
//Getters
	std::string getLabel();
	float getP0();
	float getP1();
	float getP2();
	float centroid(int i);

//Construction
	Chord();
	Chord(std::string line);
	Chord(std::string label, float p0, float p1, float p2);
	Chord(const Chord& original);
	
//Destruction
	~Chord();
};

#endif  // CHORD_H
