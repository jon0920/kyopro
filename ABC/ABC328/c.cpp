#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cnt(n,0);
    int c = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]) c++;
        cnt[i] = c;
    }
    
    while(q--){
        int l, r;
        cin >> l >> r; l--; r--;
        cout << cnt[r] - cnt[l] << endl;
    }
    
    return 0;
}