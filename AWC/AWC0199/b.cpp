#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    string s;
    cin >> n >> k >> s;
    s += "!";
    vector<pair<char,int>> rle;
    char last = s[0];
    int cnt = 0;
    for(char c : s){
        if(c == last){
            cnt++;
        } else {
            rle.push_back({last, cnt});
            last = c;
            cnt = 1;
        }
    }

    int ans = 0;
    for(auto [c, x] : rle){
        if(c == '.'){
            if(x < k){
                cout << -1 << endl;
                return 0;
            }
            ans += (x + k - 1) / k;
        }
    }

    cout << ans << endl;
    
    return 0;
}