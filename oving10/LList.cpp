#include "LList.h"

// inits the node
ListNode::ListNode(const string &value)
	: value(value) { }

// returns the value stored in the node
string ListNode::getValue() const {
	return this->value;
}

// return a pointer to the next node
ListNode *ListNode::getNext() const {
	return this->next;
}

// creates a new list with head and last pointing to NULL
LinkedList::LinkedList()
	: head(0) 
	, last(0) { }
	

// destructor which delets all elements from the list
LinkedList::~LinkedList() {
	ListNode *curr = this->head, *next = this->head;
	// hmm, Class* a, b; == Class *a; Class b;
	// and that's why everyone should put the * at the beginning of the variable name
	// not immediately following the class/type.
	while (next != 0) {
		next = next->getNext();
		delete curr;
		curr = next;
	}
	// I'll assume that if head == 0 then the list is empty
	this->head = 0; //y'know, just in case.
	this->last = 0;
}

// returns true if the list is empty
bool LinkedList::isEmpty() const {
	if (this->head == 0)
		return true;
	return false;
}

// inserts an item at the beginning of the list
void LinkedList::insertAtFront(const string &value) {
	ListNode *item = new ListNode(value); //apparently this is the correct syntax
	// not ListNode *item = &ListNode(value);
	if (this->isEmpty()) {
		this->last = item;
	}
	item->next = this->head;
	this->head = item;
	// ooh things tagged with friend in a class have access to the
	// class' private members right?
	// yup!
}

// inserts an item at the back of the list.
void LinkedList::insertAtBack(const string &value) {
	if (this->isEmpty()) {
		this->insertAtFront(value);
		// I already wrote the code for handling this case
		return;
	}
	// value becomes the new last, previous last has to point to this.
	ListNode *item = new ListNode(value);
	this->last->next = item;
	this->last = item;
	this->last->next = 0; //without this line the code crashes 
}

// removes an item from the front of the list.
// the value of the removed element should be stored in the string ref. arg.
bool LinkedList::removeFromFront(string &value) {
	if (this->isEmpty()) // do nothing.
		return false;

	ListNode *temp = this->head; //temporarily store the head
	this->head = temp->getNext(); //set head to the old head's next (2nd element in list)
	value = temp->getValue();
	delete temp;
	return true;
}

// removes an item from the back of the list
// wait, shit, we need to traverse the list to find the second-to-last element
// for this don't we? Yeah, we do. Otherwise we won't know what the new last
// element should be.
bool LinkedList::removeFromBack(string &value) {
	if (this->isEmpty())
		return false;

	ListNode *next = this->head, *prev = 0;
	while(next->getNext() != 0) { //when next == 0 we've found the last element 
		prev = next;
		next = next->getNext();
	}
	// at this point, next will be the last item and
	// prev should be the second-to-last item

	// oh shit, next is null her!
	value = last->getValue(); //get the return value.
	this->last = prev;
	if (this->last == 0) 
		this->head = 0;
	else
		this->last->next = 0;
	delete next;
	return true; //success!
}

// prints the list in a readable format

ostream &operator <<(ostream &outs, const LinkedList &li) {
	ListNode *item = li.head; //li is a reference here
	if (item == 0) {
		outs << "List is empty.\n";
		return outs; // we could just let it fall through past the while-loop
		// but eh.
	}
	while (item != 0) {
		outs << item->getValue() << endl;
		item = item->getNext();
	}
	return outs;
}

// should return a pointer to the first node containing a matching value
// and NULL if no such node is found
ListNode *LinkedList::search(const string &value) {
	ListNode *item = this->head;
	while (item != 0) {
		if (item->getValue() == value)
			return item;
		item = item->getNext();
	}
	// we didn't find anything :(
	return NULL;
}

// deletes all elements matching the given string
void LinkedList::remove(const string &value) {
	ListNode *item = this->head, *prev = this->head;
	while (item != 0) {
		if (item->getValue() == value) { //match!
			prev->next = item->getNext(); //item is no longer a part of the list
			delete item; //item is deleted
			item = prev->getNext();
			// prev should remain unchanged at this juncture.
			continue;
		} // using continue here is the same as putting the
		  // next two lines in an else-statement.
		prev = item;
		item = item->getNext();
	}
}

int main() {
		bool run = true;
	LinkedList *myList = new LinkedList();
	while(run){
		string value = "";
		int c;
		cout << "1: Insert at front\n2: Insert at back\n3: Remove from front\n4: Remove from back\n5: Search\n6: Remove\n7: Quit\nYour choise: ";
		cin >> c;
		switch(c){
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				myList->insertAtFront(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				myList->insertAtBack(value);
				break;
			case 3:
				myList->removeFromFront(value);
				cout << "Removed: " << value << endl;
				break;
			case 4:
				myList->removeFromBack(value);
				cout << "Removed: " << value << endl;;
				break;
			case 5:
				cout << "Enter value to find: ";
				cin >> value;
				if(myList->search(value) != NULL)
					cout << "Found it!\n";
				else
					cout << "No match...\n";
				break;
			case 6:
				cout << "Enter value to remove: ";
				cin >> value;
				myList->remove(value);
				break;
			case 7:
				run = false;
				break;
				
		}
		cout << *myList << endl << endl;;
	}
	delete myList;
	cin.get();
}