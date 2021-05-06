#include <bits/stdc++.h>

using namespace std;

int main() {
	string line, target;
	vector<string> arr;
	cout << "Enter target word: ";
	getline(cin, target);
	
	cout << "Enter words separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> line) {
		arr.push_back(line);
	}
	
	vector<bool> table(target.length()+1, false);
	table[0] = true;
	for(int i=0; i<=target.length(); i++) {
		if(table[i]==true) {
			for(auto word: arr) {
				if(target.substr(i, i + word.length()) == word)
					table[i + word.length()] = true;
			}
		}
	}
	
	cout << table[target.length()] << endl;
	return 0;
}
