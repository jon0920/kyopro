#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<char> mvs;
    for(char c : s){
        mvs.push_back(c);
        if(mvs.size() >= 2){
            int sz = mvs.size();
            if(mvs[sz - 1] == 'U' && (mvs[sz - 2] == 'R' || mvs[sz - 2] == 'L')){
                rep(_,2) mvs.pop_back();
            }
        }
    }

    for(char c : mvs){
        if(c == 'U') x /= 2;
        else if(c == 'L') x *= 2;
        else x = (x * 2) + 1;
    }

    cout << x << endl;
    
    return 0;
}