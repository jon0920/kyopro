#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 200100;

int main(){

    int n;
    cin >> n;
    vector<int> imos(M);
    rep(i,n){
        int a;
        cin >> a;
        a--;
        imos[a]++;
    }

    reverse(imos.begin(),imos.end());
    rep(i,M - 1){
        imos[i + 1] += imos[i];
    }
    reverse(imos.begin(),imos.end());

    rep(i,M - 1){
        imos[i + 1] += (imos[i] / 10);
        imos[i] %= 10;
    }

    while(imos.back() == 0) imos.pop_back();

    reverse(imos.begin(), imos.end());
    for(auto x : imos) cout << x;
    cout << endl;

    return 0;
}