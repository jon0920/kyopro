#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i,n){
        int a;
        cin >> a;
        pq.push(a);
    }

    while(q--){
        int t;
        cin >> t;
        int ans = 0;
        while(!pq.empty() && pq.top() < t){
            ans++;
            pq.pop();
        }
        cout << ans << endl;
    }
    
    return 0;
}