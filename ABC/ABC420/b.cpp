#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<int> nums(n);
    rep(i,m){
        int x = 0, y = 0;
        rep(j,n){
            if(s[j][i] == '0') x++;
            else y++;
        }
        if(x == 0 || y == 0){
            rep(j,n) nums[j]++;
        }
        else if(x < y){
            rep(j,n) if(s[j][i] == '0') nums[j]++; 
        }
        else{
            rep(j,n) if(s[j][i] == '1') nums[j]++;
        }
    }
    int mx = 0;
    for(int a : nums) mx = max(mx, a);
    rep(i,n) if(nums[i] == mx) cout << i + 1 << " ";
    cout << endl;
    
    return 0;
}