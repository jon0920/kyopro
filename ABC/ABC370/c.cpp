#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;
    vector<string> x;

    int n = s.size();
    int pos;
    while(s != t){
        rep(i,n){
            if(s[i] != t[i]){
                if(s[i] - '0' > t[i] - '0'){
                    s[i] = t[i];
                    x.push_back(s);
                    continue;
                }
            else pos = i;
            }
            if(i == n - 1){
                s[pos] = t[pos];
                x.push_back(s);
            }
        }
    }

    cout << x.size() << endl;
    for(string S : x){
        cout << S << endl;
    }
    
    return 0;
}