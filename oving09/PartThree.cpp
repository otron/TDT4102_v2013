#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;
class Person {
private:
	string fname, lname;
public:
	Person() : fname("null"), lname("null") { }
	Person(string firstname, string lastname) : fname(firstname), lname(lastname) { }
	string getFirstName() const {return this->fname;}
	string getLastName() const {return this->lname;}

	friend ostream &operator <<(ostream &outs, const Person &rhs) {
		outs << rhs.getLastName() << ", " << rhs.getFirstName();
		return outs;
	}

	bool operator <(Person &p) const {
		string sThis = this->lname + this->fname;
		string sP = p.getLastName() + p.getFirstName();
		return (sThis < sP ? true : false);
	}
};

void insert(list<Person> &peeps, Person p) {
	// should insert elements in sorted order.
	// so we can just iterate through peeps until we find an appropriate place
	list<Person>::iterator it;
	for (it = peeps.begin(); it != peeps.end(); it++) {
		if (p < *it) {
			peeps.insert(it, p);
			return;
		}
	}
	peeps.push_back(p);
	return;
}


int main () {
	//I stole this from the answer key.
	list<Person> ppls;
	insert(ppls, Person("Trond", "Aalberg"));
	insert(ppls, Person("Arne", "Aalberg"));
	insert(ppls, Person("Trine", "Bakke"));
	insert(ppls, Person("Ola", "Norman"));
	insert(ppls, Person("Kari", "Norman"));

	list<Person>::iterator it;
	for (it = ppls.begin(); it != ppls.end(); it++) {
		cout << *it << endl;
	}

	cin.get();
}