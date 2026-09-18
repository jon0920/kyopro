#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int k;
    string s, t;
    cin >> k >> s >> t;

    rep(i,2){
        while(!s.empty() && !t.empty() && s.back() == t.back()){
            s.pop_back();
            t.pop_back();
        }
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
    }
    
    if(s.size() <= 1 && t.size() <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}