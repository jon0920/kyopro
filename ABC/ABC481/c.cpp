#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    int cur = 1;
    map<string,int> mp;
    while(q--){
        string s;
        cin >> s;
        if(mp.count(s)){
            cout << mp[s] << endl;
        } else {
            mp[s] = cur;
            cout << cur << endl;
            cur++;
        }
    }
    
    return 0;
}