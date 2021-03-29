#include <bits/stdc++.h>

#define ARR {7,1,2,3,9}
#define SIZE 5

using namespace std;

int min(int a, int b) {
    return (a < b)? a: b;
}

int maxArea(int* arr, int n) {
    int area, max_area = 0;
    for(int i=0; i<n ;i++) {
        for (int j=i+1; j<n; j++) {
            area = min(arr[i], arr[j]) * (j-i);
            if(area > max_area)
                max_area = area;
        }
    }
    return max_area;
}

int main() {
    int arr[] = ARR;
    int area = maxArea(arr, SIZE);
    cout << area << endl;
    return 0;
}