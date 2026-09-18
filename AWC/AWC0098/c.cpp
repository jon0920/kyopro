#include <bits/stdc++.h>
#include <atcoder/string>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string str = t + s;

    vector<int> z = z_algorithm(str);

    int ans = 0;
    for(int i = m; i < n + m; i++){
        ans++;
        if(z[i] >= m){
            i += m - 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}