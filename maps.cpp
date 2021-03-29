#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    //insert
    // Method 1
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    // Method 2
    ourmap["def"] = 2;

    // Access
    cout << ourmap["abc"] << endl;

    cout << ourmap.at("abc") << endl;

    // If key not present
    cout << "Checking if present" << endl;
    cout << ourmap.at("ghi") << endl;
    // cout << ourmap["ghi"] << endl; //--> inserts default value -> 0 and returns 0

    //Check if present
    //if (ourmap.count("ghi") > 0) {
    if (ourmap.at("ghi")) {
        cout << "ghi present" << endl;
    } else {
        cout << "ghi not present" << endl;
    }

    //erase
    ourmap.erase("ghi");
}