#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a == 0) cnt0++;
        if(a == 1) cnt1++;
    }

    if(cnt0 || cnt1 >= 2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}