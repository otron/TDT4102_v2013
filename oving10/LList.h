#ifndef _LLIST_H
#define _LLIST_H

#include <iostream>
#include <string>
using namespace std;

class ListNode{
private:
	std::string value;
	ListNode *next;
public:
	ListNode(const std::string &);
	std::string getValue() const;
	ListNode *getNext() const;

	friend class LinkedList;
};

class LinkedList{
private:
	ListNode *head;
	ListNode *last;
public:
	LinkedList();
	~LinkedList();
	bool isEmpty() const;
	void insertAtFront(const std::string &);
	void insertAtBack(const std::string &);
	bool removeFromFront(std::string &);
	bool removeFromBack(std::string &);

	friend std::ostream &operator <<(std::ostream &, const LinkedList &);

	// Part 2: Searching the linked list
	ListNode *search(const string &value); //this could be const, but it isn't.

	// Part 3: search and destroy
	void remove(const string &value);
};

#endif