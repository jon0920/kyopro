#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;

    vector<ll> vec;
    map<ll,int> mp;
    int cnt = 0;
    while(n--){
        string e;
        cin >> e;
        if(e == "PUT"){
            ll c;
            cin >> c;
            if(vec.empty()) vec.push_back(c);
            else vec.push_back(vec.back() ^ c);
        } else if(e == "REMOVE"){
            vec.pop_back();
        } else {
            cnt++;
            ll x = vec.back();
            if(mp.count(x)){
                cout << mp[x] << endl;
            } else {
                cout << -1 << endl;
            }
            mp[x] = cnt;
        }
    }

    return 0;
}