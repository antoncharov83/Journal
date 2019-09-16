#pragma once
#include <string>
using namespace std;

class Predmet
{
private:
	int id;
	string name;
public:
	Predmet() {};
	Predmet(string name, int id) : name{ name }, id { id } {};
	Predmet(string name) : name{ name } {};
	Predmet(int id) : id{ id } {};
	~Predmet() {};
	friend std::ostream& operator<< (std::ostream &out, Predmet &predmet) { out << predmet.id << " " << predmet.name << '\n'; return out; }
	string getName() { return name; }
	int getId() { return id; }
	void setName(string name) { this->name = name; }
	bool operator==(const Predmet& other) const { return id == other.id; }
	bool operator==(const string other) const { return name == other; }
};
