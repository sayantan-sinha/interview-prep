#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,num;
	cout << "Enter the fib number: ";
	cin >> n;
	vector<int> fib(n+1, 0);
	if(n<1) {
		cout << fib[0] << endl;
	} else {
		fib[1]=1;
		for(int i=1; i<=n-1; i++) {
			fib[i+1] += fib[i];
			if(i<n-1) 
				fib[i+2] += fib[i];
		}
	}
	cout << fib[n] << endl;
	return 0;
}
