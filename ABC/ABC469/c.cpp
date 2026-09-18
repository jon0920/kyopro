#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;

    vector<int> sum(n + 1);
    rep(i,n){
        sum[i + 1] = sum[i] + (s[i] == 'x');
    }

    int cnt = 0;
    rep(i,n){
        if(s[i] == 'o') cnt++;
        int p = lower_bound(sum.begin(), sum.end(), sum[i + 1] + cnt) - sum.begin();
        p = min(n, p);
        cout << p << endl;
    }
    
    return 0;
}