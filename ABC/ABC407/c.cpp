#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    int sum = 0;
    int n = s.size();

    for(int i = 1; i <= n; i++){
        int si = s[n - i] - '0';
        int si1 = (i == 1 ? 0 : s[n - i + 1] - '0');
        int b = (10 + si - si1) % 10;
        sum += b;
    }

    int ans = sum + n;
    cout << ans << endl;

    return 0;
}