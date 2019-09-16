#include "pch.h"
#include "Prepod.h"
#include <iostream>

Prepod::Prepod()
{
}


Prepod::~Prepod()
{
}

string Prepod::getName()
{
	return Base::name;
}

void Prepod::setName(string name)
{
	Base::name = name;
	People::name = name;
}

int Prepod::getAge()
{
	return age;
}

void Prepod::setAge(int age)
{
	this->age = age;
}

void Prepod::print(std::ostream & out)
{
	if (out.rdbuf() == std::cout.rdbuf())
		out << "������������� " << Base::name << " ������� " << age << std::endl;
	else
		out << "-1" << std::endl << Base::name << std::endl << age << std::endl;// -1 - ������� ��� ������� ������
}

std::ostream & operator<<(std::ostream & out, Prepod & prepod)
{
	prepod.print(out);
	return out;
}
