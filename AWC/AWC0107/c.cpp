#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    map<int,vector<string>> mp;
    rep(i,n){
        string s;
        int v;
        cin >> s >> v;
        mp[v].push_back(s);
    }

    while(q--){
        int x;
        cin >> x;
        if(mp.count(x)){
            for(auto s : mp[x]){
                cout << s << " ";
            }
            cout << endl;
        }
        else{
            auto it = mp.lower_bound(x);
            int r = it->first;
            it--;
            int l = it->first;
        }
    }
    
    return 0;
}