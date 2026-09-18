#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> cnt(q + 2);
    cnt[0] = n;
    int sum = 0;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            int now = a[x];
            a[x]++;
            cnt[now + 1]++;
            if(cnt[sum + 1] == n){
                sum++;
            }
        } else {
            int y;
            cin >> y;
            if(sum + y > q) cout << 0 << endl;
            else cout << cnt[sum + y] << endl;
        }
    }

    
    return 0;
}