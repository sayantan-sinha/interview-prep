#include <bits/stdc++.h>

using namespace std;

vector<int> howSumMemo(int sum, vector<int> &arr, unordered_map<int, vector<int>> &memo) {
	vector<int> res, v = {-1};
		
	if(memo.count(sum) != 0) return memo[sum];
	
	if(sum == 0) return vector<int>();
	
	if(sum < 0) return v;
	
	for(int num : arr) {
		res = howSumMemo(sum-num, arr, memo);
		if(res != v) {
			res.push_back(num);
			memo[sum] = res;
			return res;
		} else {
			memo[sum] = res;
		}
	}
	
	return v;
}

int main() {
	vector<int> arr, res;
	unordered_map<int, vector<int>> memo;
	int num, sum;
	string line;
	
	cout << "Enter array elements separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}
	
	cout << "Enter Target: ";
	cin >> sum;

	res = howSumMemo(sum, arr, memo);
	
	vector<int> v = {-1};
	
	if(res == v) {
		cout << "Not Possible" << endl;
	}	else {
		vector<int>::iterator it = res.begin();
		do {
			cout << *it << ",";
		} while(++it != res.end());
	}
	
	cout << endl;

	return 0;
}

