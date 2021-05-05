#include <bits/stdc++.h>

using namespace std;

int main () {
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
	
	vector<bool>sum(target+1, false);
	sum[0] = true;
	for(int i=0; i<=target; i++) {
		if(sum[i] == true)
			for(int j: arr) {
				if(i+j <= target)
					sum[i+j] = true;
			}
	}
		
	cout << sum[target] << endl;
	return 0;
}
