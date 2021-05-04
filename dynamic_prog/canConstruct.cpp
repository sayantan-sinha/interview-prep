#include <bits/stdc++.h>

using namespace std;

bool isPrefix(string prefix, string target) {
	return prefix == target.substr(0, prefix.size());
}

string rmvString(string target, string prefix) {
	return target.substr(prefix.size());
}

bool canConstruct(string target, vector<string> arr, unordered_map<string, bool> &memo) {
	
	if(memo.count(target) != 0) return true;
	if(target == "") return true;
	for(auto prefix: arr) {
//		cout << "Prefix: " << prefix << ", Target: " << target << endl;
		if(isPrefix(prefix, target)) {
			if(canConstruct(rmvString(target, prefix), arr, memo)) {
				memo[target] = true;
				return true;
			}
		}
	}
	
//	cout <<  "Target: " << target << " Not Possible" << endl;
	return false;
}

int main() {
	string target,input;
	bool result;
	vector<string> arr;
	cout << "Enter the target string: ";
	getline(cin, target);
	
	cout << "Enter strings for array separated by space: ";
	getline(cin, input);
	istringstream stream(input);
	while(stream >> input) {
		arr.push_back(input);
	}
	
	/*
	for(auto s: arr) {
		cout << s << endl;
	}
	*/
	
	unordered_map<string, bool> memo;
	
	result = canConstruct(target, arr, memo);
	if(result)
		cout << "Possible" << endl;
	else
		cout << "Not Possible" << endl;
		
	return 0;
}
