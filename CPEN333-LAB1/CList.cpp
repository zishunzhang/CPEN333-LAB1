#include "CList.h"
#include <iostream>

CList::CList(): head(nullptr){}

CList::~CList() {
	if (!head) {
		return;
	}

	Node* curr = head;
	Node* next;

	while (curr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
}

void CList::DeleteEnd() {
	if (!head)
		return;

	Node* prev = nullptr;
	Node* curr = head;
	while (curr) {
		if (!curr->next) {
			if (!prev) {
				delete curr;
			}
			else {
				prev->next = nullptr;
				delete curr;
			}
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void CList::InsertEnd(Node* newNode) {
	if (!head) {
		head = newNode;
		return;
	}

	Node* curr = head;
	while (curr->next) {
		curr = curr->next;
	}
	curr->next = newNode;
}

int CList::GetElement(int n) {
	if (n < 0)
		return;
	Node* curr = head;
	while (curr) {
		if (n == 0) {
			return curr->data;
		}
		n--;
		curr = curr->next;
	}

	return 0;
}