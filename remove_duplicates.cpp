#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> removeDuplicates(int* a, int n) {
    vector<int> output;
    unordered_map<int, bool> index;
    int i;
    for(i=0; i<n; i++) {
        if(index.count(a[i]) == 0) {
            output.push_back(a[i]);
            index[a[i]] = true;
        }
    }
    return output;
}

int main() {
    int arr[] = {1,5,2,3,4,1,2,4,5,1,2,3};
    int i;
    vector<int> output = removeDuplicates(arr, 12);
    
    vector<int>::iterator it = output.begin();

    do {
        cout << *it << endl;
    }while(++it!=output.end());
    
    return 0;
}