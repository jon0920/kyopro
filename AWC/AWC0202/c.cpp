#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> pre(n), nxt(n);
    int cur = -1;
    rep(i,n){
        cin >> pre[i] >> nxt[i];
        pre[i]--, nxt[i]--;
        if(pre[i] == -1) cur = i;
    }

    vector<int> ans;
    while(cur != -1){
        ans.push_back(cur + 1);
        cur = nxt[cur];
    }

    for(int x : ans) cout << x << endl;
    
    return 0;
}