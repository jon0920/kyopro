#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s, t;
    cin >> n >> s >> t;
    s += "..";
    t += "..";
    map<string, int> dp;
    dp[s] = 0;
    queue<string> que;
    que.push(s);
    while(!que.empty()){
        auto str = que.front(); que.pop();

        int emp = 0;
        rep(i,(int)str.size()){
            if(str[i] == '.'){
                emp = i;
                break;
            }
        }

        rep(i,(int)str.size() - 1){
            if(str[i] == '.' || str[i + 1] == '.') continue;
            string str2 = str;
            swap(str2[i], str2[emp]);
            swap(str2[i + 1], str2[emp + 1]);
            if(!dp.count(str2)){
                dp[str2] = dp[str] + 1;
                que.push(str2);
            }
        }
    }
    if(dp.count(t)) cout << dp[t] << endl;
    else cout << -1 << endl;
    
    return 0;
}