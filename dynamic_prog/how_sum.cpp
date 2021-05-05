#include <bits/stdc++.h>
# define null vector<int>{-1}

using namespace std;

int main() {
	int target, num;
	string line;
	vector<int> arr;
	cout << "Enter target sum: ";
	cin >> target;
	//to clear buffer of the next line
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Enter array values separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}
	
	vector<vector<int>> sum_arr(target+1, null);
	sum_arr[0] = {};
	for(int i=0; i<=target; i++) {
		if(sum_arr[i]!=null)
			for(int num: arr) {
				if(i+num<=target) {
					sum_arr[i+num] = sum_arr[i];
					sum_arr[i+num].push_back(num);
				} 
			}
	}
	
	/*
	cout << "Sum arr " << endl;
	for(auto row: sum_arr) {
		for(auto elem: row)
			cout << elem << " ";
		cout << endl;
	}
	cout << "=====================" << endl;
	*/
	
	if(sum_arr[target] == null)	
		cout << "Not Possible" << endl;
	else {
		for(int elem: sum_arr[target])
			cout << elem << " ";
	}
	
	cout << endl;
	return 0;
}
