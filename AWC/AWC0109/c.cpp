#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> c(m);
    rep(i,m) cin >> c[i];

    vector<priority_queue<int, vector<int>, greater<int>>> pq(m);
    
    while(q--){
        int p, d;
        cin >> p >> d;
        p--, d--;
        if(pq[d].size() < c[d]){
            pq[d].push(a[p]);
        } else if(pq[d].size() == c[d]){
            if(pq[d].top() < a[p]){
                pq[d].pop();
                pq[d].push(a[p]);
            }
        }
    }

    for(auto v : pq){
        cout << v.size() << " ";
    }
    cout << endl;
    
    return 0;
}