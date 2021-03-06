#ifndef DList_H_
#define DList_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class DList;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	
	T	    value;
	Link<T> *next;
	Link<T> *previous;

	friend class DList<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
class DList{
	public:
		DList();
		DList(const DList<T>&);
		~DList();
		
		bool empty() const;
		void add_first(T);
		void add(T);
		T find(T);
		void update(T,T);
		T remove_first();
		T remove(T);
		
		string toStringForward() const;
		string toStringBackward() const;
	private:
		Link<T> *head;
		Link<T> *tail;
		int size;
};

template <class T>
DList<T>::DList() : head(0), size(0) {}

template <class T>
DList<T>::~DList() {
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0);
}

//Create

template <class T>
void DList<T>::add_first(T val) {
	Link<T> *newLink;
	
	newLink = new Link<T>(val);
	
	head = newLink;
	tail = newLink;
	size++;
}

template <class T>
void DList<T>::add(T val){
	Link<T> *newLink;
	
	newLink = new Link<T>(val);
	
	if(empty()){
		add_first(val);
		return;
	}
	
	tail->next = newLink;
	newLink->previous = tail;
	tail = newLink;
	size++;
}

//Read (find)

template <class T>
T DList<T>::find(T val){
	int pos = 0;
	Link<T> *p;
	
	p = head;
	while(p != 0){
		if (p->value == val){
			return pos;
		}
		p = p->next;
		pos++;
	}
	
	return -1;
}

//Update

template <class T>
void DList<T>::update(T pos,T val){
	int i = 0;
	Link<T> *p;
	
	p = head;
	while (p != 0){
		if (i == pos){
			p->value = val;
		}
		p = p->next;
		i++;
	}
}

//Delete 

template <class T>
T DList<T>::remove_first(){
	T val;
	Link<T> *p;
	
	p = head;
	val = p->value; 
	
	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;
	return val;
}

template <class T>
T DList<T>::remove(T pos){
	int index;
	T val;
	Link<T> *p;
	
	if (pos == 0){
		return remove_first();
	}
	
	p = head;
	index = 0;
	while (index != pos){
		p = p->next;
		index++;
	}
	
	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;

	return val;
}

//ToString

template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
string DList<T>::toStringBackward() const {
	stringstream aux;
	Link<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}


#endif /* DList_H_ */ 
