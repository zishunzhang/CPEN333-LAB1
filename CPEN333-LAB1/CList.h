#ifndef _CLIST_H_
#define _CLIST_H_

template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node() : next(nullptr) {}
	Node(T value) : data(value), next(nullptr) {}
};


template <typename T>
class CList {
private:
	Node<T>* ptr;

public:

};


#endif 
