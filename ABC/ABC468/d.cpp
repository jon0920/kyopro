#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;
    for(int i = 1; i < n - 1; i++){
        int left = i - 1, right = i + 1;
        int cnt = 0;
        while(left >= 0 && right < n){
            if(s[left] != s[right]) cnt++;
            if(cnt >= 2) break;
            ans++;
            left--; right++;
        }
    } 

    for(int i = 1; i < n - 2; i++){
        int left = i - 1, right = i + 2;
        int cnt = 0;
        if(s[i] != s[i + 1]) cnt++;
        while(left >= 0 && right < n){
            if(s[left] != s[right]) cnt++;
            if(cnt >= 2) break;
            ans++;
            left--; right++;
        }
    }

    cout << ans + n * 2 - 1 << endl;
    
    return 0;
}