#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int l; int r;
};

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    vector<S> pos(n + 1, {-1, -1});
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'L'){
            pos[i].r = i - 1;
            if(pos[i - 1].l == -1) pos[i - 1].l = i;
            else{
                int x = pos[i - 1].l;
                pos[x].r = i;
                pos[i].l = x;
                pos[i - 1].l = i;
            }
        } else {
            pos[i].l = i - 1;
            if(pos[i - 1].r == -1) pos[i - 1].r = i;
            else{
                int x = pos[i - 1].r;
                pos[x].l = i;
                pos[i].r = x;
                pos[i - 1].r = i;
            }
        }
    }

    int st;
    rep(i,n + 1){
        if(pos[i].l == -1){
            st = i;
            break;
        }
    }

    vector<int> res;
    while(st != -1){
        res.push_back(st);
        st = pos[st].r;
    }

    for(auto x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}