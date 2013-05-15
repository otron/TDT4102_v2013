#pragma once

#include <string>
#include <map>
#include <set>
#include <ostream>

class PhonebookEntry{
private:
	std::string name;
	std::map<std::string, std::string> numbers;
public:
	PhonebookEntry(){};
	PhonebookEntry(std::string name) : name(name){}
	std::string getName() const {return name;}
	void setName(const std::string &name){this->name = name;}
	void add(const std::string &label, const std::string &number){numbers[label] = number;}
	
	void add(const PhonebookEntry &copyFrom);
	friend bool operator <(const PhonebookEntry &lhs, const PhonebookEntry &rhs);
	friend std::ostream &operator <<(std::ostream &str, const PhonebookEntry &entry);
	
	//Part 5
	bool find(const std::string &label, PhonebookEntry &ret) const;
};

class Phonebook{
private:
	std::set<PhonebookEntry> entries;
public:
	void add(PhonebookEntry &addMe);
	friend std::ostream &operator <<(std::ostream &str, const Phonebook &book);
	
	//Part 5
	bool find(std::string name, std::string label, Phonebook &ret) const;
};
