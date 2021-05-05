#include <bits/stdc++.h>

using namespace std;

int main() {
	int x,y;
	cout << "Enter the dimensions of the grid: ";
	cin >> x >> y;
	vector<vector<int>> grid(y+1, vector<int>(x+1, 0));
	grid[1][1]=1;
	for(int i=0; i<=x; i++) {
		for(int j=0; j<=y; j++) {
			if(i+1<=x)
				grid[i+1][j] += grid[i][j];
			if(j+1<=y)
				grid[i][j+1] += grid[i][j];
		}
	}
	cout << grid[x][y] << endl;
	return 0;
}
