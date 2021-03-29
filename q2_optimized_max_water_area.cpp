#include <bits/stdc++.h>

#define ARR {6,9,3,4,5,8}
#define SIZE 6

using namespace std;

int min(int a, int b) {
    return (a < b)? a: b;
}

int maxAreaTwoPointers(int* arr, int size) {
    int i=0, j=size-1, max_area = 0, area;
    while(i < j) {
        area = min(arr[i], arr[j]) * (j-i);
        if(area > max_area)
            max_area = area;
        if(arr[i] < arr[j]) {
            i++;
        } else {
            j--;
        }
    }
    return max_area;
}

int main() {
    int arr[] = ARR;
    int area = maxAreaTwoPointers(arr, SIZE);
    cout << area << endl;
    return 0;
}