#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> res;
    rep(i,n){
        string s;
        cin >> s;
        int num = s[0] - 'a';
        if(num < 3) res.push_back(2);
        else if(num < 6) res.push_back(3);
        else if(num < 9) res.push_back(4);
        else if(num < 12) res.push_back(5);
        else if(num < 15) res.push_back(6);
        else if(num < 19) res.push_back(7);
        else if(num < 22) res.push_back(8);
        else res.push_back(9);
    }

    for(auto x : res) cout << x;
    cout << endl;
    
    return 0;
}