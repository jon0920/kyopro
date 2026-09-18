#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> st;
    int ans = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x; 
            cin >> x;
            x--;
            if(a[x] == 0) st.insert(x);
            ans ^= a[x] ^ (a[x] + 1);
            a[x]++;
        } else {
            set<int> tmp;
            for(int x : st){
                ans ^= a[x] ^ (a[x] - 1);
                a[x]--;
                if(a[x] != 0) tmp.insert(x);
            }
            st = move(tmp);
        }
        cout << ans << endl;
    }
    
    return 0;
}