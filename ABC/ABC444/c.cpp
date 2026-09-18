#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    bool check1 = false, check2 = false;
    ll L1 = a[0] + a[n - 1];
    if(n % 2 == 0){
        check1 = true;
        rep(i,n/2){
            if(a[i] + a[n - i - 1] != L1) check1 = false;
        }
    }

    ll L2 = a[n - 1];
    while(a.back() == L2) a.pop_back();
    int m = a.size();
    if(m % 2 == 0){
        check2 = true;
        rep(i,m / 2){
            if(a[i] + a[m - i - 1] != L2) check2 = false;
        }
    }

    if(check2) cout << L2 << " ";
    if(check1) cout << L1;
    cout << endl;

    return 0;
}