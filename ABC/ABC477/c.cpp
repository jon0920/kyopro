#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    string s, t;
    cin >> q >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> match(n);
    rep(i,n - m + 1){
        string sub = s.substr(i, m);
        if(sub == t) match[i] = 1;
    }

    vector<int> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + match[i];

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        if(r - l < m) cout << "No" << endl;
        else {
            r = r - m + 1;
            if(sum[r] - sum[l] > 0) cout << "Yes" << endl;
            else cout << "No" << endl; 
        }
    }
    
    return 0;
}