#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> two_sum(int *arr, int sum, int size) {
    unordered_map<int, int> ntf;
    vector<int> pair = {-1, -1};
    int num_to_f;
    for(int i=0; i<size; i++) {
        cout << arr[i] << endl;
        num_to_f = sum - arr[i];
        if(ntf.count(arr[i])==0)
            ntf[num_to_f] = i;
        else {
            cout << "Match" << endl;
            pair[0] = ntf[arr[i]];
            pair[1] = i;
            break;
        }
    }

    /*
    unordered_map<int, int>::iterator it = ntf.begin();
    do {
        cout << "Key: " << it->first << "   Value: " << it->second << endl;
    } while(++it != ntf.end());
    */
   
    return pair;
}

int main() {
    int arr[] = {1,3,7,9,2};
    int sum = 11;
    int size = 5;
    vector<int> pair = two_sum(arr, sum, size);
    cout << pair[0] << "    " << pair[1] << endl;
    return 0;
}