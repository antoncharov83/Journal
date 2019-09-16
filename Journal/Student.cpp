#include "pch.h"
#include "Student.h"


Student::Student()
{
	count = 0; matches = new LinkedList<Match*>();
}

int Student::getCount()
{
	return count;
}

void Student::setCount(int count)
{
	this->count = count;
}

void Student::addMatch(Predmet * predmet, short mark)
{
	Match* match = new Match();
	match->mark = mark;
	match->predmet = predmet;
	matches->push(match);
	count = matches->getSize();
}

void Student::addMatch(Match * match) {
	matches->push(match);
	count = matches->getSize();
}

void Student::changeMatch(Predmet * predmet, short mark)
{
	Match* tmp = new Match();
	tmp->predmet = predmet;
	Match* match = matches->findNode(tmp)->data;
	match->mark = mark;
}

void Student::delMatch(Predmet * predmet)
{
	Match* tmp = new Match();
	tmp->predmet = predmet;
	matches->delNode(matches->findNode(tmp));
	count = matches->getSize();
}

float Student::getAvg()
{
	if (matches->getSize() == 0) return 0;
	float avg = 0;
	for (int i = 1; i <= matches->getSize(); i++)
		avg += matches->getNodeById(i)->data->mark;
	return avg / matches->getSize();
}

string Student::getName()
{
	return Base::name;
}


void Student::print(std::ostream & out)
{
	if (out.rdbuf() == std::cout.rdbuf()) {
		out << "Студент " << Base::name << "  Средний балл - " << getAvg() << endl;
		Match* match;
		for (int i = 1; i <= count; ++i) {
			match = matches->getNodeById(i)->data;
			out << "       " << match->predmet->getName() << " " << match->mark << endl;
		}
	}
	else {
		out << "-2" << endl; // признак что записан студент
		out << Base::name << endl;
		out << count << endl;
		Match* match;
		for (int i = 1; i <= count; ++i) {
			match = matches->getNodeById(i)->data;
			out << match->predmet->getId() << " " << match->mark << endl;
		}
	}
}

Student::~Student()
{
	delete matches;
}

std::ostream & operator<<(std::ostream & out, Student & student)
{
	student.print(out);
	return out;
}
