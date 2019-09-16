#include "pch.h"
#include "LinkedList.h"
#include "Prepod.h"
#include "Student.h"

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

	while (currentNode)
	{
		std::cout << *currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

template<class T>
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
		if (currentNode->data == data)
			return currentNode;
		currentNode = currentNode->next;
	}
	return nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getNodeById(int id)
{
	if(id > size) return nullptr;
	Node<T>* currentNode = head;

	while (id < size)
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
	}

	Node<T>* currentNode = head;

	while (currentNode->next) {
		if (currentNode->next == node) {
			currentNode->next = node->next;
			delete node;
		}
		currentNode = currentNode->next;
	}
}

template void LinkedList<People*>::display();
template void LinkedList<Student*>::display();
template void LinkedList<Predmet*>::display();
template void LinkedList<People*>::push(People*);
template void LinkedList<Predmet*>::push(Predmet*);
template int LinkedList<Match>::getSize();
template Node<Match>* LinkedList<Match>::getNodeById(int);
template Node<Match>* LinkedList<Match>::findNode(Match);
template void LinkedList<Match>::delNode(Node<Match>*);