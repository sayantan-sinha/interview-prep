#include <bits/stdc++.h>

using namespace std;

int gT(int m, int n, vector<vector<int>> &index) {
//	cout << m << ", " << n << endl;
	if(m==0 or n==0) return 0;
	if(m==1 and n==1) return 1;
	if(index[m][n]!=-1) return index[m][n];
	index[m][n] = gT(m-1,n,index) + gT(m,n-1,index);
	return index[m][n];
}

int main() {
	int n,m,res;
	cout << "Enter dimensions (m,n): ";
	cin >> m >> n;
	vector<vector<int>> index;
	index.resize(m+1, vector<int>(n+1, -1));
	res = gT(m,n,index);
	cout << "Result: " << res << endl;
	return 0;
}
