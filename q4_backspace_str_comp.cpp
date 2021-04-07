#include <bits/stdc++.h>
using namespace std;

vector<char> check_str(vector<char> str) {
    vector<char> f_str;
    for(int i=0; i < str.size(); i++) {
        if(str[i]=='#') {
            if(!f_str.empty())
                f_str.pop_back();
        } else {
            f_str.push_back(str[i]);
        }
    }
    return f_str;
}

int main() {

    string str_s, str_t;
    cin >> str_s >> str_t;
    vector<char> s(str_s.begin(), str_s.end());
    vector<char> t(str_t.begin(), str_t.end());
    s = check_str(s);
    t = check_str(t);
    if(s == t) {
        cout << "Same" << endl;
    } else {
        cout << "Different" << endl;
    }
    
    vector<char>::iterator it = s.begin();
    do {
        cout << *it << " ";
    } while(++it!=s.end());

    return 0;
}