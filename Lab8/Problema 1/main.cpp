#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;

		if (p1.second > p2.second)
			return false;

		if (p1.first > p2.first)
			return true;

		return false;

	}
};

int main() {
	ifstream myFile("input.txt");
	if (!myFile) {
		cout << "Error opening file" << endl;
		return 0;
	}
	string myString;
	if (!getline(myFile, myString)) {
		printf("Error la citirea din fisier: input.txt\n");
		return 0;
	}
	myFile.close();

	cout << "Stringul citit este: " << myString << endl;

	for (int i = 0; i <= myString.size(); i++) {
		myString[i] = tolower(myString[i]);
	}
	
	vector<string> words;
	string currentWord = "";
	string separators = " ,.!?\n";

	for (int i = 0; i < myString.size(); i++) {
		if (separators.find(myString[i]) != string::npos) {
			if (currentWord != "") {
				words.push_back(currentWord);
				currentWord = "";
			}
		}
		else {
			currentWord += myString[i];
		}
	}
	if (currentWord != "") {
		words.push_back(currentWord);
	}
	
	map<string, int> wordMap;

	for (int i = 0; i < words.size(); i++) {
		if (wordMap.count(words[i]) == 0)
			wordMap[words[i]] = 1;
		else
			wordMap[words[i]]++;
	}
	priority_queue <pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
	for (auto it = wordMap.begin(); it != wordMap.end(); it++) {
		myQueue.push(pair<string, int>(it->first, it->second));
	}
	while (!myQueue.empty()) {
		cout << myQueue.top().first << " => " << myQueue.top().second << endl;
		myQueue.pop();
	}
}
