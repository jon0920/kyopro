#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    int dot_count = 0;
    int l = 0, ans = 0;
    for(int r = 0; r < n; r++){
        if(s[r] == '.') dot_count++;

        while(dot_count > k && l < n){
            if(s[l] == '.') dot_count--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;

    return 0;
}