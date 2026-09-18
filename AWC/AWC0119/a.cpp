#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<bool> used(101);
    int cnt = 0;
    int sum = 0;
    rep(i,n){
        int s;
        cin >> s;
        if(!used[s]){
            cnt++;
            sum += s;
            used[s] = true;
        }
    }
    cout << cnt << " " << sum << endl;
    
    return 0;
}