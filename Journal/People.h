#pragma once
#include <string>
using namespace std;

class People
{
protected:
	string name;
public:
	People();
	People(string name) : name{ name } {}
	string getName();
	void setName(string name);
	virtual ~People();
	virtual void print(std::ostream&) {};
	//virtual bool operator==(People &other) { return name == other.name; };
	bool operator==(const People& other) const { return name == other.name; }
	virtual void* getAsStudent() { return this; };
	friend std::ostream& operator<< (std::ostream &out, People &people) { people.print(out); return out; };
};

