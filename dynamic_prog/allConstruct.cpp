#include <bits/stdc++.h>

using namespace std;

bool is_prefix(string prefix, string target) {
	return prefix == target.substr(0, prefix.size());
}

string get_suffix(string target, string prefix) {
	return target.substr(prefix.size());
}

vector<vector<string>> allConstruct(string target, vector<string> arr, unordered_map<string, vector<vector<string>>> &memo) {
	vector<vector<string>> temp, res={};
	if(target=="") return vector<vector<string>> {{}};
	if(memo.count(target) > 0) return memo[target];
	for(auto prefix: arr) {
		if(is_prefix(prefix, target)) {
			temp = allConstruct(get_suffix(target, prefix), arr, memo);
			if(!temp.empty()) {
				for(auto arr: temp) {
					arr.insert(arr.begin(), prefix);
					res.push_back(arr);
				}
			}
		}
	}
	memo[target] = res;
	return res;
}

int main() {
	string target, input;
	vector<string> arr;
	vector<vector<string>> res;
	
	cout << "Enter target string: ";
	getline(cin, target);
	
	cout << "Enter wordbank: ";
	getline(cin, input);
	istringstream stream(input);
	while(stream >> input) {
		arr.push_back(input);
	}
	
	unordered_map<string, vector<vector<string>>> memo;
	res = allConstruct(target, arr, memo);
	
	if(res.empty()) 
		cout << "Not Possible" << endl;
	else {
		for(auto arr: res) {
			cout << "[ ";
			for(auto str: arr) {
				cout << str << ", ";
			}
			cout << " ]" << endl;
		}
	}
	return 0;
}
