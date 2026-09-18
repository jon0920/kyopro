#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> event;
    rep(i,n){
        int s, e;
        cin >> s >> e;
        event.push_back({s,1});
        event.push_back({e,-1});
    }
    sort(event.begin(), event.end());

    int cnt = 0;
    for(auto [t, i] : event){
        cnt += i;
        if(cnt >= k){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}