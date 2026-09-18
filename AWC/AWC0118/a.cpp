#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    rep(i,n){
        rep(j,m) cin >> s[i][j];
    }

    rep(j,m){
        set<int> st;
        rep(i,n){
            if(s[i][j] != -1) st.insert(s[i][j]);
        }
        if(st.size() >= 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}