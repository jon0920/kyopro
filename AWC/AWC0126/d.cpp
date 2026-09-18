#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s, t;
    cin >> n >> s >> t;

    auto to_binary = [&](string s){
        int res = 0;
        rep(i,s.size()){
            if(s[i] == 'B') res += 1 << i;
        }
        return res;
    };

    vector<int> div;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) div.push_back(i);
    }

    vector<int> dist(1 << n, -1);
    int init = to_binary(s);
    dist[init] = 0;
    queue<int> que;
    que.push(init);

    while(!que.empty()){
        int v = que.front(); que.pop();
        vector<int> cand;
        for(int d : div){
            
        }
    }
    
    return 0;
}