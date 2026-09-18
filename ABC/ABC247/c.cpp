#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int n;

void solve(int x, vector<int> vec){
    if(x == n){
        for(auto a : vec) cout << a << " ";
        cout << endl;
        return;
    }
    vector<int> nxt;
    for(auto v : vec) nxt.push_back(v);
    nxt.push_back(x + 1);
    for(auto v : vec) nxt.push_back(v);
    solve(x + 1, nxt);
};

int main(){
    
    cin >> n;

    solve(1, {1});

    return 0;
}