#ifndef _CLIST_H_
#define _CLIST_H_

class Node {
public:
	Node* next;
	int data;
	Node();
	Node(int value);
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
