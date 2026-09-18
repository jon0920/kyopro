#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    bool ans = false;
    do{
        bool ok = true;
        rep(i,n-1){
            int different = 0;
            rep(j,m){
                if(s[idx[i]][j] != s[idx[i + 1]][j]) different++;
            }
            if(different >= 2) ok = false;
        }
        if(ok) ans = true; 
    }while(next_permutation(idx.begin(), idx.end()));
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}