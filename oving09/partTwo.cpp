#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;
// Part 2-c
void replace(vector<string> &v, string old, string replacement) {
	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if (*it == old) {
			it = v.erase(it);
			// erase returns an iterator pointing to the next element.
			it = v.insert(it, replacement);
			// wait, this returns an iterator pointing to the first
			// of the newly inserted elements
			// which means if old == replacement we'd get an infinite loop?
			// ha-ha no we don't because it is incremented by the for-loop before the next iteration.
		}
	}

}
// Part 2: ITERATORS!
int main() {
	// 2-a: create a vector for strings and put some strings in it

	vector<string> vec;
	vec.push_back("dicks");
	vec.push_back("are");
	vec.push_back("dickin'");
	vec.push_back("B-)");
	vec.push_back("apples");

	vector<string>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << " "; // it's a pointer yo we be dereffin'
	cout << endl << "now, let's do it in reverse (using a reverse iterator)." << endl;
	// Part 2-b: same thing, reverse iterator.

	vector<string>::reverse_iterator rit;
	for (rit = vec.rbegin(); rit != vec.rend(); rit++)
		cout << *rit << " ";

	cout << endl << endl;
	replace(vec, "dicks", "yoyo");
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << " "; // it's a pointer yo we be dereffin'

	cout << endl;
	cin.get();
}