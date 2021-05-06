#include <bits/stdc++.h>
# define null vector<int>{-1}

using namespace std;

int main() {
	int num, target;
	string line;
	vector<int> arr;
	cout << "Enter target sum: ";
	cin >> target;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Enter array elements separated by space: ";
	getline(cin, line);
	istringstream stream(line);
	while(stream >> num) {
		arr.push_back(num);
	}
	
	vector<vector<int>> sum_arr(target+1, null);
	sum_arr[0] = {};
	for(int i=0; i<=target; i++) {
		if(sum_arr[i]!=null) {
			for(int elem: arr)
				if(i+elem <= target) {
					if(sum_arr[i+elem]==null) {
						sum_arr[i+elem] = sum_arr[i];
						sum_arr[i+elem].push_back(elem);
					} else {
						if(sum_arr[i+elem].size()>sum_arr[i].size()+1) {
							sum_arr[i+elem] = sum_arr[i];
							sum_arr[i+elem].push_back(elem);
						}
					}
				}
		}
	}
	
	if(sum_arr[target] == null)	
		cout << "Not Possible" << endl;
	else {
		for(int elem: sum_arr[target])
			cout << elem << " ";
	}
	
	cout << endl;
	
	return 0;
}
