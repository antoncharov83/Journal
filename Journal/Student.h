#pragma once
#include "People.h"
#include "Predmet.h"
#include "LinkedList.h"
#include "Base.h"

struct Match {
	Predmet* predmet;
	short mark;
	bool operator==(Match other) { return predmet == other.predmet; }
};

class Student :
	virtual public People, virtual public Base
{
private:
	int count;
	LinkedList<Match*>* matches;
public:
	Student();
	Student(string name) : Base{ name }, People{ name } { count = 0; matches = new LinkedList<Match*>(); };
	int getCount();
	void setCount(int count);
	void addMatch(Predmet* predmet, short mark);
	void addMatch(Match * match);
	void changeMatch(Predmet* predmet, short mark);
	LinkedList<Match*>* getMatches() { return matches; }
	void delMatch(Predmet* predmet);
	void* getAsStudent() { return this; };
	float getAvg();
	string getName();
	friend std::ostream& operator<< (std::ostream &out, Student &student);
	//bool operator==(Student &other) { return name == other.name; }
	void print(std::ostream &out);
	~Student();
};

