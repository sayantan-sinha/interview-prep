#include <bits/stdc++.h>

using namespace std;

int fib(int n, unordered_map<int, int> &memo) {
	cout << "n: " << n << endl;
	unordered_map<int, int>::iterator it;
	if(memo.count(n) == 0)
		memo[n] = fib(n-1, memo) + fib(n-2, memo);
	it = memo.find(n);
	cout << it->second << endl;
	return it->second;
}
	

int main() {
  int n, res;
  cout << "Enter a number: ";
  cin >> n;
  unordered_map<int, int> memo;
  res = fib(n, memo);
  cout << "Result is: " << res << endl;
}
