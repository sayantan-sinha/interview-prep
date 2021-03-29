#include <bits/stdc++.h>
using namespace std;

int sub_max(vector<int> arr, int i, int j) {
    int max = *max_element(arr.begin() + i, arr.begin() + j);
    return max;
}

int total_water(vector<int> arr) {
    int water= 0;
    for(int i=0; i<arr.size(); i++) {
        int cH = arr[i];
        int maxL = sub_max(arr,0,i);
        int maxR = sub_max(arr, i, arr.size());
        int min_idx = min(maxL, maxR);
        cout << "At index " << i << " water level is " << max(min_idx - cH, 0) << endl;
        water += max(min_idx - cH, 0);
    }

    return water;
}

int main() {
    vector<int> arr = {0,1,0,2,1,0,3,1,0,1,2};
    int water = total_water(arr);
    cout << water << endl;
}