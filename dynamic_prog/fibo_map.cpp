#include <bits/stdc++.h>

using namespace std;

int fib(int n, unordered_map<int, int> &memo) {
	if(n==1 or n==2) return n-1;
	unordered_map<int, int>::iterator it;
	if(memo.count(n) == 0)
		memo[n] = fib(n-1, memo) + fib(n-2, memo);
	it = memo.find(n);
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
