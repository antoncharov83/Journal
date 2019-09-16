#pragma once
#include <string>
using namespace std;

class Base
{
protected:
	string name;
public:
	Base();
	Base(string name) : name{ name } {};
	~Base();
	string getName();
};

