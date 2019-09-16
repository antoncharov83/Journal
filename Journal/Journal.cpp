// Journal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Prepod.h"
#include "Student.h"
#include <list>
#include <iterator>
#include <algorithm>

template<typename T>
T* findInList(const std::list<T*>& dataList, const T& data)
{
	auto p = find_if(dataList.begin(), dataList.end(), [&](const T * arg) {return *arg == data; });
	if (p != dataList.end()) return *p;
	return nullptr;
}

template<typename T>
T* findByName(const std::list<T*>& dataList, string name) {
	auto p = find_if(dataList.begin(), dataList.end(), [&](const T * arg) {return *arg == name; });
	if (p != dataList.end()) return *p;
	return nullptr;
}

void loadPredmet(string filename, list<Predmet*> *p) {//LinkedList<Predmet*> * p
	ifstream in(filename);
	if (in) {
		while (!in.eof()) {
			string name;
			int id;
			in >> id;
			in.get();
			if (getline(in, name))
				p->push_back(new Predmet(name, id));
				//p->push(new Predmet(name, id));
		}
	}
}

void loadStudent(string filename, list<People*> *p, list<Predmet*> *predmet) {//LinkedList<People*> * p, LinkedList<Predmet*> * predmet
	ifstream in(filename);
	if (in) {
		while (!in.eof()) {
			int who_is = 0;
			in >> who_is;
			in.get();
			string name;
			if (!getline(in, name)) return;
			if (who_is == -2) {
				Student* student = new Student(name);
				int size;
				in >> size;
				for (int i = 1; i <= size; ++i) {
					int id_pred;
					int mark;
					in >> id_pred;
					in >> mark;
					Match* match = new Match();
					//std::list<Predmet*>::iterator findIter = std::find(predmet.begin(), predmet.end(), new Predmet("", id_pred));
					
					//if(Node<Predmet*>* tmp = predmet->findNode(new Predmet("", id_pred)))
					if(Predmet* findIter = findInList(*predmet, Predmet(id_pred)))
						match->predmet = findIter;
					else {
						cout << "Предмет не найден!" << endl;
						continue;
					}
					match->mark = mark;
					student->addMatch(match);
					in.get();
				}
				p->push_back(student);
				//p->push(student);
			}
			else if (who_is == -1) {
				int age;
				in >> age;
				in.get();
				p->push_back(new Prepod(name, age));
				//p->push(new Prepod(name, age));
			}
			else return;
		}
	}
}

template<typename T>
void display(list<T> p) {
	for (T i : p)
	cout << *i;
}

template<typename T>
void saveToFile(string filename, list<T> p) {
	ofstream out(filename);
	if (out) {
		for (T i : p)
			out << *i;
	}
}



bool compareByName(People* first, People* second)
{
	return first->getName() < second->getName();
}


int main()
{
	system("chcp 1251");
	
	LinkedList<People*> peoples;
	LinkedList<Predmet*> predmets;
	
	list<People*> peoples_list;
	list<Predmet*> predmets_list;

	Student* st;
	Prepod* pr;
	
	int ans = 0;
	string name;
	
	while (true) {
		cout << "1 - загрузить список предметов из файла" << endl;
		cout << "2 - загрузить список студентов/преподавателей из файла" << endl;
		cout << "3 - добавить студента в список" << endl;
		cout << "4 - добавить преподавателя в список" << endl;
		cout << "5 - добавить предмет в список" << endl;
		cout << "6 - проставить оценки студенту" << endl;
		cout << "7 - сохранить список студентов/преподавателей" << endl;
		cout << "8 - сохранить список предметов" << endl;
		cout << "9 - вывод список людей" << endl;
		cout << "10 - вывод список предметов" << endl;
		cout << "11 - удалить из списка" << endl;
		cout << "12 - изменить возраст преподавателя" << endl;
		cout << "13 - сортировать людей" << endl;
		cout << "14 - выход" << endl;
		cin >> ans;
		cin.get();
		if (ans == 1) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			loadPredmet(name, &predmets_list);
		}
		else if (ans == 2) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			loadStudent(name, &peoples_list, &predmets_list);
		}
		else if (ans == 3) {
			cout << "Введите имя студента - ";
			getline(cin, name);
			cout << endl;
			st = new Student(name);
			peoples_list.push_back(st);
		}
		else if (ans == 4) {
			cout << "Введите имя преподавателя - ";
			getline(cin, name);
			cout << endl;
			pr = new Prepod(name);
			peoples_list.push_back(pr);
		}
		else if (ans == 5) {
			cout << "Введите название предмета - ";
			getline(cin, name);
			cout << endl;
			predmets_list.push_back(new Predmet(name, predmets_list.size()));
		}
		else if (ans == 6) {
			cout << "Введите имя студента - ";

			getline(cin, name);
			do {
				cout << endl << "Введите название предмета - ";
				string id_pred;
				getline(cin, id_pred);
				cout << endl;
				try {
					Predmet* pred;

					if (People *findIter = findInList(peoples_list, (People)Student(name))) {
						st = (Student*)findIter->getAsStudent();
					}
					else {
						cout << "Нет такого студента" << endl;
						break;
					}

					if(Predmet* findIter_p = findByName(predmets_list, id_pred)){
						pred = findIter_p;
					}
					else {
						cout << "Нет такого предмета" << endl;
						cout << "Нажмите Esc чтобы выйти";
						continue;
					}
					int mark;
					cout << "Введите оценку - ";
					cin >> mark;
					cout << endl;
					Match match;
					match.predmet = pred;
					if (st->getMatches()->findNode(&match))
						st->changeMatch(pred, mark);
					else
						st->addMatch(pred, mark);
				}
				catch (...) { cout << "Некорректные данные" << endl; }
				cout << "Нажмите Esc чтобы выйти";
			} while (_getch() != 27);
		}
		else if (ans == 7) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			saveToFile(name, peoples_list);
		}
		else if (ans == 8) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			saveToFile(name, predmets_list);
		}
		else if (ans == 9)
			display(peoples_list);
		else if (ans == 10)
			display(predmets_list);
		else if (ans == 11) {
			cout << "Введите имя человека - ";
			getline(cin, name);
			if (People * findIter = findInList(peoples_list, People(name)))
				peoples_list.remove(findIter);
		}
		else if (ans == 12) {
			cout << "Введите имя преподавателя - ";
			getline(cin, name);
			if(People* findIter_pr = findInList(peoples_list,(People)Prepod(name))) {
				Prepod* prepod = (Prepod*)findIter_pr->getAsStudent();
				cout << "Введите возраст - ";
				int age;
				cin >> age;
				cin.get();
				prepod->setAge(age);
			}
			else {
				cout << "Преподаватель не найден" << endl;
			}			
		}
		else 
			if (ans == 13) {
				peoples_list.sort(compareByName);
			}
			else
		if (ans == 14) return 0;
	}
	return 0;
}
