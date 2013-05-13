#include <string> // strings!
#include <iostream> // cout, cin!
#include <fstream> //file streams, ifstream and ofstream
#include <map>
#include <ctype.h> //toupper, tolower
using namespace std;

void storeInp(string filename);
void addLineNumbersToFile(string inFile, string outFile);

// Part 2
void getStats(string inFile);

// Part 3
void wordStats(string inFile);

int main() {

	//storeInp("Part1.txt");
	//addLineNumbersToFile("derp.txt", "yoloswag.txt");
	//getStats("textdata.txt");
	wordStats("Part3.txt");
	cin.get();
}


//Part 1-a: Write a program that reads words from the user input
// and stores each word as a separate line in a text file.
void storeInp(string filename) {
	// step one: how do I grab that input?
	// cin doesn't read the input before the user presses the return key
	// so just loop cin >> someString and check for the exit-keyword, then.
	cout << "Hello and welcome to Part 1-a.\n";
	string s = ""; 
	ofstream outStream;
	outStream.open(filename);
	if (outStream.fail()) {
		cout << "alas, sweet prince, the file could not be opened.\n";
		return;
	}
	cout << "type \"quit\" followed by CARRIAGE RETURN to quit.\n";
	cin >> s; //if quit is the first thing the user types in then it should quit immediately.
	while (s.compare("quit") != 0) {
		//the assignment specified that each word was to be put on its own line...
		// fine, I'll replace spaces with newlines.
		for (unsigned int i = 0; i < s.length(); i++) {
			if (s.at(i) == ' ')
				s.replace(i, 1, "\n");
		}
		outStream << s << endl;
		cin >> s;
	}//string::compare returns 0 if the strings are equal, and some other value if something, something. I don't even know, it seems a lot more complicated than it has to be.

	cout << "Good day to you! Now gaze upon your work: you may find it in "
		 << filename << endl;
}

// Part 1-b
// write a program that reads from a text file and copies its content
// over to a new text file, adding line numbers.
void addLineNumbersToFile(string inFile, string outFile) {
	ofstream outStream(outFile);
	ifstream inStream(inFile);

	//display welcome message
	cout << "Hello and welcome to the wonderful world of Part 1-b\n";
	printf("Today, your input file is %s and your output file is %s\n",
		inFile.c_str(), outFile.c_str());
	if (inStream.fail()) { // check the input stream
		cout << "Oh dear, it seems that your input file is malfunctioning.\n";
		return;
	}
	if (outStream.fail()) { // check the output stream
		cout << "golly, your output file can't be opened!\n";
		return;
	}
	const int size = 1024;
	char s[size];
	// loop through the lines in the input file
	inStream.getline(s, size);
	for (int i = 1; ! inStream.eof(); i++) {
		outStream << i << " " << s << endl; 
		inStream.getline(s, size);
	}
}

// Part 2
void getStats(string inFile) {
	cout << "Welcome to part 2, the statistical adventure.\n";
	cout << "<excitement>, <applause>\n";
	char c;
	ifstream inStream(inFile);
	if (inStream.fail()) {
		cout << "Failed to open " << inFile << endl;
		return;
	}
	map<char, int> resultMap;
	//resultMap[key] <action>
	//for instance, resultMap[key]++;
	inStream.get(c); //get the first character.
	int count = 0; //number of characters counted.
	while (! inStream.eof()) {
		count++;
		resultMap[c]++;
		inStream.get(c);
	}
	//now to iterate over the map
	cout << "Character statistics:\nTotal number of characters: "<< count << endl;
	map<char, int>::const_iterator iter;
	int linebreak = 1;
	for (iter = resultMap.begin(); iter != resultMap.end(); iter++, linebreak++) {
		//iter->first == key
		//iter->second == value
		printf("%c: %i\t", iter->first, iter->second);
		if (linebreak % 5 == 0)
			cout << endl;
	}
}

// Part 3
void wordStats(string inFile) {
	//hmm, how to extract words.
	//let's say '.', '\n' and ' ' mark the end of words.
	// yes, we are now assuming that there is no word-division.
	// I'm not sure if the assignment wants us to count "word-divison"
	// as one or two words, however it does state that
	// "you should remove all non-normal letters and punctuation marks,
	//as well as convert the words to lowercase."
	// So I guess bitches be in for some trippin'
	char c;
	ifstream inStream(inFile);
	if (inStream.fail()) {
		cout << "oh no what is happen to "<< inFile << endl;
		return;
	}
	inStream.get(c); //get first char
	int wordCount = 0, lineCount = 0, currentWordLength = 0;
	map<string, int> resultMap; //word, count
	string s = "";
	string longestword;
	while (! inStream.eof()) {
		if (isalpha(c)) {
			tolower(c); //convert char to lower case
			s += c; //add to current word.
		} else {
			switch (c) {
				case '\n':
					lineCount++; //I assume a newline ends the current word.
				//case '.': //fall-through to next case
				case ' ': //the word has ended.
					if (s.length() > 0)
						resultMap[s]++;
					wordCount++;
					s = "";
				default:
					break;
			}
		}
		inStream.get(c); //get next char
	}
	printf("Number of words: %i\nNumber of lines: %i\n", wordCount, lineCount);
	map<string, int>::const_iterator it;
	for (it = resultMap.begin(); it != resultMap.end(); it++) {
		printf("%s: %i\n", it->first.c_str(), it->second);
		if (it->first.length() > longestword.length())
			longestword = it->first;
	}
	printf("\nLongest word: %s", longestword.c_str());
}