#include <bits/stdc++.h>

using namespace std;

bool canSum(int target, vector<int> &arr) {
	bool res;
		
	if(target==0)
		return true;
	
	for(int num : arr) {
		if(target-num >= 0) {
			res = canSum(target-num, arr);
			if(res) 
				return true;
		}
	}
	
	return false;
}

int main() {
	vector<int> arr;
	int target, num;
	bool res;
	
	//Taking array as input
	string line;
	cout << "Enter array elements separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}

	// Taking target as input
	cout << "Enter Target: ";
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
	res = canSum(target, arr);
	
	if(res)
		cout << "Possible" << endl;
	else 
		cout << "Not Possible" << endl;
		
	return 0;
}
