#include <bits/stdc++.h>

using namespace std;

bool isPrefix(string prefix, string target) {
	return prefix == target.substr(0, prefix.size());
}

string rmvString(string target, string prefix) {
	return target.substr(prefix.size());
}

int countConstruct(string target, vector<string> arr, unordered_map<string, int> &memo) {
	if(target=="") return 1;
	if(memo.count(target)!=0) return memo[target];
	int res=0;
	for(auto prefix:arr) {
		if(isPrefix(prefix, target)) {
			res += countConstruct(rmvString(target, prefix), arr, memo); 
		}
	}
	return res;
}

int main() {
	int count;
	string target, input;
	vector<string> arr;
	cout << "Enter the target: ";
	getline(cin, target);
	
	cout << "Enter strings for array separated by space: ";
	getline(cin, input);
	istringstream stream(input);
	while(stream >> input) {
		arr.push_back(input);
	}
	
	unordered_map<string, int> memo;
	count = countConstruct(target, arr, memo);
	cout << count << endl;
	return 0;
}
