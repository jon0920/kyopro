#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    string s;
    cin >> n >> q >> s;

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        swap(s[a], s[b]);
    }

    cout << s << endl;
    
    return 0;
}