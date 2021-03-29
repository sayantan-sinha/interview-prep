#include <bits/stdc++.h>
using namespace std;

int min(vector<int> arr, int p1, int p2) {
    if (arr[p1] < arr[p2])
        return 1;
    else
        return 2;
}

int calculate(vector<int> arr) {
    int p1=0, p2=arr.size()-1, maxL=arr[p1], maxR=arr[p2], water=0;
    while (p1 < p2) {
        if (min(arr, p1, p2) == 1) {
            if (maxL > arr[p1])
                water += (maxL - arr[p1]);
            else
                maxL = arr[p1];
            p1++;
        } else {
            if (maxR > arr[p2])
                water += (maxR - arr[p2]);
            else
                maxR = arr[p2];
            p2--;
        }
    }

    return water;
}

int main() {
    vector<int> arr = {0,1,0,2,1,0,3,1,0,1,2};
    int water = calculate(arr);
    cout << "Total Water: " << water << endl;
}