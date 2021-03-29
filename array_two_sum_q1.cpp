#include<iostream>
using namespace std;

# define ARR {1,3,7,9,2}
# define SUM 11
# define SIZE 5

void target_sum(int *arr, int n, int target, int* pair) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[j]==(target - arr[i]))
            {
                pair[0] = i;
                pair[1] = j;
                return;
            }
        }
    }
}

int main() {
    int i;
    int pair[] = {-1, -1};
    int num[] = ARR;
    //int target = 11;
    target_sum(num, SIZE, SUM, pair);
    cout << "Hiiii " << endl;
    if (pair[0] == -1 && pair[1]==-1)
        cout << "No solution" << endl;
    else
        cout << pair[0] << " " << pair[1] << endl;
}