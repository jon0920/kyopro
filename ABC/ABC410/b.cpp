#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    rep(i, n) mp[i] = 0;  // ← ここを追加

    rep(i,q){
        int x;
        cin >> x;
        if(x == 0){
            int best_key = -1, best_val = INT_MAX;
            for(auto [key, val] : mp){
                if(val < best_val){
                    best_val = val;
                    best_key = key;
                }
            }
            mp[best_key]++;
            cout << best_key + 1 << " ";
        }
        else{
            mp[x-1]++;
            cout << x << " ";
        }
    }
    cout << endl;
    
    return 0;
}
