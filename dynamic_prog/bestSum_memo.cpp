#include <bits/stdc++.h>

using namespace std;

vector<int> bestSumMemo(int target, vector<int> arr, unordered_map<int, vector<int>> &memo) {

	if(memo.count(target)!=0) return memo[target];
	
	vector<int> temp, res = {-1}, v = {-1};
	int min = numeric_limits<int>::max();

	if(target == 0) return vector<int> ();
	
	if(target < 0) return v;
	
	for(auto num: arr) {
		temp = bestSumMemo(target-num, arr, memo);
		if(temp != v) {
			temp.push_back(num);
			if(min > temp.size()) {
				min = temp.size();
				res = temp;
			}
		}
	}

	if(res == v) return v;

	memo[target] = res;
	return res;
}

// m = target sum
// n = length of array

// time: O(n^m * m) 
// space: O(m * m)-> m stack frames each frame storing one copy of res which can be of m length at max

int main() {
	vector<int> arr, res;
	int num, sum;
	string line;
	
	unordered_map<int, vector<int>> memo;
	
	cout << "Enter array elements separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}

	cout << "Enter Target: ";
	cin >> sum;

	res = bestSumMemo(sum, arr, memo);

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

