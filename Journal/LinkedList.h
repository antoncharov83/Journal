#pragma once
#include <iostream>
#include <fstream>
#include <string> 

template<typename T>
struct Node
{
	T data;
	Node* next;
	bool operator==(Node<T> other) { return data == other.data; }
};

template<typename T>
class LinkedList
{
private:

	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	LinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 }
	{
	}
	~LinkedList() {
		Node<T>* currentNode = head;

		while (currentNode)
		{
			Node<T>* nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
		delete currentNode;
	}
	Node<T>* createNode(T data);
	void display();
	void saveToFile(std::string filename);
	void push(T data);
	Node<T>* findNode(T data);
	Node<T>* getNodeById(int id);
	int getSize();
	void delNode(Node<T>* node);
	void delNode(T data);
};

template<typename T>
Node<T>* LinkedList<T>::createNode(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = nullptr;

	return newNode;
}

template<typename T>
void LinkedList<T>::display()
{
	Node<T>* currentNode = head;
	std::cout << "+++++Вывод списка++++++" << std::endl;
	while (currentNode)
	{
		std::cout << *currentNode->data;
		currentNode = currentNode->next;
	}
	std::cout << "+++++++++++++++++++++++" << std::endl;
	system("pause");
}

template<typename T>
inline void LinkedList<T>::saveToFile(std::string filename)
{
	Node<T>* currentNode = head;
	std::ofstream out(filename);
	if (out) {
		while (currentNode)
		{
			out << *currentNode->data;
			currentNode = currentNode->next;
		}
		out.close();
	}
}

template<typename T>
void LinkedList<T>::push(T data)
{
	Node<T>* newNode = createNode(data);

	if (size == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

	++size;
}

template<typename T>
Node<T>* LinkedList<T>::findNode(T data)
{
	Node<T>* currentNode = head;

	while (currentNode)
	{
		if (*(currentNode->data) == *data)
			return currentNode;
		currentNode = currentNode->next;
	}
	return nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getNodeById(int id)
{
	if (id > size) return nullptr;
	Node<T>* currentNode = head;

	while (id++ < size)
		currentNode = currentNode->next;
	return currentNode;
}

template<typename T>
int LinkedList<T>::getSize()
{
	return size;
}

template<typename T>
void LinkedList<T>::delNode(Node<T>* node)
{
	if (node == nullptr) return;

	if (node == head) {
		head = head->next;
		delete node;
		--size;
	}

	Node<T>* currentNode = head;

	while (currentNode->next) {
		if (currentNode->next == node) {
			currentNode->next = node->next;
			delete node;
			--size;
		}
		currentNode = currentNode->next;
	}
	
}

template<typename T>
inline void LinkedList<T>::delNode(T data)
{
	delNode(findNode(data));
}
