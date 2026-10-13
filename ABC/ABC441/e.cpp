#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int op(int a, int b){ return a + b; }
int e(){ return 0; }

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    vector<int> sum(n + 1);
    rep(i,n){
        if(s[i] == 'A') sum[i + 1] = sum[i] + 1;
        else if(s[i] == 'B') sum[i + 1] = sum[i] - 1;
        else sum[i + 1] = sum[i];
    }
    
    vector<int> sort_sum = sum;
    sort(sort_sum.begin(), sort_sum.end());
    sort_sum.push_back(1e9);
    int cur = sort_sum[0];
    int num = 0;
    map<int,int> mp;
    for(int x : sort_sum){
        if(x != cur){
            mp[cur] = num;
            num++;
            cur = x;
        }
    }

    int sz = mp.size();
    vector<int> cnt(sz);
    for(int x : sum){
        cnt[mp[x]]++;
    }

    segtree<int,op,e> seg(cnt);

    ll ans = 0;
    rep(i,n){
        int x = mp[sum[i]];
        ans += seg.prod(x + 1, sz);
        int y = seg.get(x);
        seg.set(x, y - 1);
    }

    cout << ans << endl;

    return 0;
}