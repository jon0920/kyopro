#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int a; int b; int id;
};

int main(){
    
    int n;
    cin >> n;
    vector<S> v(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        v[i] = {a, b, i};
    }
    sort(v.begin(), v.end(), [](const S &x, const S &y){
        if(x.b != y.b) return x.b > y.b;
        if(x.a != y.a) return x.a > y.a;
        return x.id < y.id;
    });

    for(auto [a, b, i] : v) cout << i + 1 << endl;
    
    return 0;
}