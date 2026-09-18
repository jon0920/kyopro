#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;

    int x = 0, y = 0;
    set<pair<int,int>> smoke;
    smoke.insert({x, y});
    string ans = "";
    for(auto d : s){
        if(d == 'N'){
            r++;
            x++;
        } else if(d == 'S'){
            r--;
            x--;
        } else if(d == 'W'){
            c++;
            y++;
        } else {
            c--;
            y--;
        }
        smoke.insert({x, y});
        if(smoke.count({r, c})) ans.push_back('1');
        else ans.push_back('0'); 
    }
    cout << ans << endl;

    return 0;
}