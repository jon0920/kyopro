#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    string s;
    cin >> n >> s >> q;

    vector<pair<int, char>> status(n);
    rep(i,n) status[i] = {0, s[i]};

    int fill_time = -1;
    int fill_type = -1;
    rep(i,q){
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        if(t == 1) status[x] = {i, c};
        else{
            fill_time = i;
            fill_type = t;
        }
    }

    for(auto [time, c] : status){
        if(fill_time == -1 || time >= fill_time) cout << c;
        else if(fill_type == 2) cout << char(tolower(c));
        else cout << char(toupper(c));
    }
    cout << endl;
    
    return 0;
}