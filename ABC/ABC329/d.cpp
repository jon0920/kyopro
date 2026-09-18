#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> canditate(n);
    pair<int,int> mx = {0, 0};
    rep(i,m){
        int a;
        cin >> a; a--;
        canditate[a]++;
        if(canditate[a] > mx.second){
            mx.first = a;
            mx.second = canditate[a];
        }
        else if(canditate[a] == mx.second){
            if(mx.first > a){
                mx.first = a;
                mx.second = canditate[a];
            }
        }
        cout << mx.first + 1 << endl;
    }
    
    return 0;
}