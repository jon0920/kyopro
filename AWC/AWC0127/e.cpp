#include <bits/stdc++.h>
#include <atcoder/string>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int L, M;
    cin >> L >> M;
    string s, t;
    cin >> s >> t;
    string l = t + s;
    string r = s + t;

    vector<int> zl = z_algorithm(l);
    vector<int> zr = z_algorithm(r);

    for(int i = L; i > 0; i--){
        if(zl[L + M - i] >= i || zr[L + M - i] >= i){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
    return 0;
}