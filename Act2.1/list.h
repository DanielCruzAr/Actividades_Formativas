#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	
	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
class List{
	public:
		List();
		List(const List<T>&);
		~List();
		
		bool empty() const;
		void add_first(T);
		void add(T);
		T find(T);
		void update(T,T);
		T remove_first();
		T remove(T);
		
		string toString() const;
	private:
		Link<T> *head;
		int size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

//Create

template <class T>
void List<T>::add_first(T val) {
	Link<T> *newLink;
	
	newLink = new Link<T>(val);
	
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val){
	Link<T> *newLink, *p;
	
	newLink = new Link<T>(val);
	if(empty()){
		add_first(val);
		return;
	}
	
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	
	newLink->next = 0;
	p->next = newLink;
	size++;
}

//Read (find)

template <class T>
T List<T>::find(T val){
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
void List<T>::update(T pos,T val){
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
T List<T>::remove_first(){
	T val;
	Link<T> *p, *q;
	
	p = head;
	q = p;
	p = p->next;
	val = q->value;
	head = p;
	
	delete q;
	
	return val;
}

template <class T>
T List<T>::remove(T pos){
	int index;
	T val;
	Link<T> *p, *q;
	
	if (pos == 0){
		return remove_first();
	}
	
	q = 0;
	p = head;
	index = 0;
	while (index != pos){
		q = p;
		p = p->next;
		index++;
	}
	
	val = p->value;
	q->next = p->next;
	size--;
	
	delete p;
	
	return val;
}

//ToString

template <class T>
string List<T>::toString() const {
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

#endif /* LIST_H_ */ 