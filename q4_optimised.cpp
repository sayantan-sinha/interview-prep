#include <bits/stdc++.h>
using namespace std;

bool check(vector<char> s, vector<char> t) {
    int p1=s.size()-1, p2=t.size()-1, dec_p1=0, dec_p2=0;
    while(p1 >= 0 or p2 >= 0) {
        if(s[p1]==t[p2] and s[p1]!='#') {
            // cout << "First Block " << endl;
            p1--;
            p2--;
        } else if(s[p1] == '#' or t[p2] == '#') {
            dec_p1=dec_p2=0;
            // cout << "Second Block " << endl;
            if(s[p1] == '#') {
                do {
                    dec_p1+=1;
                    p1--;
                } while(s[p1] != '#' and p1 > 0);
                p1 = min(p1-dec_p1, -1);
                // cout << "P1: " << p1 << endl;
            }

            if(t[p2] == '#') {
                do {
                    dec_p2+=1;
                    p2--;
                } while(t[p2] != '#' and p2 > 0);
                p2 = min(p2-dec_p2, -1);
                // cout << "P2: " << p2 << endl;
            }
             
        } else {
            // cout << "3rd block " << endl;
            return false;
        } 
    }

    if(p1<0 and p2<0)
        return true;
    else
        return false;
}

int main() {
    string s,t;
    cin >> s >> t;
    vector<char> s_v(s.begin(), s.end());
    vector<char> t_v(t.begin(), t.end());
    bool res = check(s_v, t_v);
    if(res)
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;
    return 0;
}