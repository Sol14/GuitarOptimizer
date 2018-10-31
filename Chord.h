#include <string>
#include <vector>
#include <string>

#ifndef CHORD_H
#define CHORD_H
class Chord{
private:
	std::string label;
	float position[3];
	void setAve(std::vector<std::string> line);
	
public:
	Chord();
	
	Chord(std::string label, float p1, float p2, float p3);

	Chord(const Chord& original);
	
	Chord(std::vector<std::string> line);

	~Chord();

	std::string getLabel();
	float getP1();
	float getP2();
	float getP3();
	void setLabel(std::string label);
	void setP1(float p1);
	void setP2(float p2);
	void setP3(float p3);

};

#endif  // CHORD_H
