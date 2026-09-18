#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    int logo_cnt = 0;
    pair<int,int> t = {m, 0};
    for(char c : s){
        if(c == '0') t = {m, logo_cnt};
        else if(c == '1'){
            if(t.first > 0) t.first--;
            else if(t.second > 0) t.second--;
            else logo_cnt++;
        }
        else{
            if(t.second > 0) t.second--;
            else logo_cnt++;
        }
    }
    cout << logo_cnt << endl;
    
    return 0;
}