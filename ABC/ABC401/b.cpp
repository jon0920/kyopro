#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    bool authorized = false;
    int error = 0;
    rep(i,n){
        string s;
        cin >> s;
        if(s == "login") authorized = true;
        else if(s == "logout") authorized = false;
        else if(s == "private"){
            if(!authorized) error++;
        }
    }
    cout << error << endl;
    
    return 0;
}