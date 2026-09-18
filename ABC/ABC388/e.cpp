#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> s, l;
    rep(i,n){
        int a;
        cin >> a;
        if(i < n / 2) s.push_back(a);
        else l.push_back(a);
    }

    int u = s.size(), v = l.size();
    int i = 0, j = 0;
    int ans = 0;
    while(i < u && j < v){
        if(s[i] * 2 <= l[j]){
            ans++;
            i++, j++;
        } else {
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}