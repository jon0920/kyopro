#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> pre(n + 1), suf(n + 1);
    while(q--){
        int c, p;
        cin >> c >> p;
        int next_top = pre[c];
        if(next_top != 0){
            suf[next_top] = 0;
        }

        pre[c] = p;
        suf[p] = c;
    }

    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
        if(pre[i] == 0){
            int cnt = 0;
            int cur = i;
            while(cur != 0){
                cnt++;
                cur = suf[cur];
            }
            ans[i] = cnt;
        } else ans[i] = 0;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}