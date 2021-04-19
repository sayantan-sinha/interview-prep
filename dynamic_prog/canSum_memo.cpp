#include <bits/stdc++.h>

using namespace std;

bool canSumMemo(int target, vector<int> &arr, unordered_map<int, bool> &memo) {
	bool res;
	
	if(memo.count(target)!=0)
		return memo[target];
	
	if(target==0)
		return true;
	
	for(int num : arr) {
		if(target-num >= 0) {
			res = canSumMemo(target-num, arr, memo);
			memo[target] = res;
			if(res) 
				return true;
		}
	}
	
	return false;
}

int main() {
	vector<int> arr;
	int num, target;
	bool res;
	string line;
	
	// Taking array input
	cout << "Enter array nums: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}
	
	// Taking target output
	cout << "Enter target sum: ";
	cin >> target;
	
	// Verification
	/*
	vector<int>::iterator it = arr.begin();
	cout << "Array is: ";
	do {
		cout << *it << ",";
	} while(++it!=arr.end());
	cout << endl << "Target: " << target << endl;
	*/
	
	// Call function
	unordered_map<int, bool> memo;
	res = canSumMemo(target, arr, memo);
	
	if(res==true)
		cout << "Possible" << endl;
	else 
		cout << "Not Possible" << endl;
	
	return 0;
}
