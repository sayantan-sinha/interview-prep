#include <bits/stdc++.h>

using namespace std;

vector<int> howSum(int sum, vector<int> &arr) {
	vector<int> res, v = {-1};
	
	
	if(sum == 0) return vector<int>();
	
	if(sum < 0) return v;
	
	for(int num : arr) {
		res = howSum(sum-num, arr);
		if(res != v) {
			res.push_back(num);
			return res;
		}
	}
	
	return v;
}


int main() {
	int num, sum;
	vector <int> arr, res;
	string line;
	cout << "Enter array elements separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}
	
	cout << "Enter Target: ";
	cin >> sum;
	
	res = howSum(sum, arr);
	
	vector<int> v = {-1};
	
	if(res == v) {
		cout << "Not Possible" << endl;
	}	else {
		vector<int>::iterator it = res.begin();
		do {
			cout << *it << ",";
		} while(++it != res.end());
	}
	
	return 0;
	
}

	
