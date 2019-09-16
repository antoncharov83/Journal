#pragma once
#include "People.h"
#include "Base.h"

class Prepod :
	virtual public People, virtual public Base
{
private:
	int age;
public:
	Prepod();
	Prepod(string name) : Base { name }, People{ name } {}
	Prepod(string name, int age) : Base { name }, People{ name }, age{ age } {}
	~Prepod();
	void* getAsStudent() { return this; };
	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	void print(std::ostream &out);
	friend std::ostream& operator<< (std::ostream &out, Prepod &prepod);
};

