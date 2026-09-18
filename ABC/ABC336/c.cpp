#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    n--;
    vector<int> ans;
    while(n){
        ans.push_back(n % 5);
        n /= 5;
    }
    if(ans.empty()) ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for(int a : ans) cout << a * 2;
    cout << endl;
    
    return 0;
}