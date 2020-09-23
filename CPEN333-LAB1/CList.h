#ifndef _CLIST_H_
#define _CLIST_H_

class Node {
public:
	Node* next;
	int data;
	Node() : next(nullptr) {}
	Node(int value) : data(value), next(nullptr) {}
};

class CList {
private:
	Node* head;

public:
	CList();
	~CList();
	void InsertEnd(Node* newNode);
	void DeleteEnd();
	int GetElement(int n); //get the nth element from the list
};


#endif 
