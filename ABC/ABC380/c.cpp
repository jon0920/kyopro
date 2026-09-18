#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string tmp = s + '9';
    vector<pair<int,int>> p;
    int ns = tmp[0] - '0';
    int cnt = 0;
    rep(i,tmp.size()){
        if(tmp[i] - '0' == ns) cnt++;
        else{
            p.push_back({ns, cnt});
            cnt = 1;
            ns = tmp[i] - '0';
        }
    }

    int x = 0, y = 0;
    for(auto [a, b] : p){
        if(a == 1) x++;
        else y++;
        if(x == k){
            p.insert(p.begin() + (x + y - 2), {a, b});
            p.erase(p.begin() + x + y);
            break;
        }
    }

    for(auto [a, b] : p){
        for(int i = 0; i < b; i++){
            cout << a;
        }
    }

    cout << endl;
    
    return 0;
}