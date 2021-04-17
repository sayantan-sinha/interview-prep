#include <bits/stdc++.h>

using namespace std;

vector<int> MEM = {0,1};

int fib(int n) {
//	cout << "n is " << n << " Mem size: " << MEM.size() << endl;
  if(n <= MEM.size()) {
    return MEM[n-1];
  } else {
	  MEM.push_back(fib(n-1) + fib(n-2));
	  if(MEM[n-2] > MEM[n-1]) {
	  	cout << "Overflow has occured" << endl;
	  	exit(1);
	  }
  	return MEM[n-1];
  }
  
}

int main() {
  int n, res;
  cout << "Enter a number: ";
  cin >> n;
  res = fib(n);
  cout << "Result is: " << res << endl;
  // Check the array
  /*
  vector<int>::iterator it = MEM.begin();
  cout << "MEM: ";
  do {
  	cout << *it << "	";
  	} while(++it!=MEM.end());
	*/
  return 0;
}

