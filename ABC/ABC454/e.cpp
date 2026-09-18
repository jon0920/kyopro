#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        a--, b--;

        if(n % 2 == 1 || (a + b) % 2 == 0){
            cout << "No" << endl;
            continue;
        }

        vector<string> s1, s2;

        for(int i = 0; i < n / 2 - 1; i++){
            string s = "";
            for(int j = 0; j < n - 1; j++) s += 'R';
            s += 'D';
            for(int j = 0; j < n - 1; j++) s += 'L';
            s += 'D';

            if(a >= 2){
                s1.push_back(s);
                a -= 2;
            } else {
                string rev_s = s;
                reverse(rev_s.begin(), rev_s.end());
                s2.push_back(rev_s);
            }
        }

        for(int i = 0; i < n / 2 - 1; i++){
            string s = "DRUR";
            if(b >= 2){
                s1.push_back(s);
                b -= 2;
            } else {
                string rev_s = s;
                reverse(rev_s.begin(), rev_s.end());
                s2.push_back(rev_s);
            }
        }

        if(a == 0 && b == 1) s1.push_back("DR");
        else s1.push_back("RD");

        cout << "Yes" << endl;
        for(const string &s : s1) cout << s;
        reverse(s2.begin(), s2.end());
        for(const string &s : s2) cout << s;
        cout << endl; 
    }

    return 0;
}