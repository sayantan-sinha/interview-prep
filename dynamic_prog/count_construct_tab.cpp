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
	
	vector<int> table(target.length()+1, 0);
	table[0]=1;
	for(int i=0; i<=target.length(); i++) {
		if(table[i]!=0) {
			for(auto word: arr) {
				if(target.substr(i, i+word.length()) == word)
					table[i+word.length()] += table[i];
			}
		}
	}
	
	cout << table[target.length()] << endl;
	return 0;
}
