#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    vector<bool> cntflag(n+2, true);
    int ans = 0;
    rep(i,q){
        int a;
        cin >> a;
        if(cntflag[a]){
            cntflag[a] = false;
            if(cntflag[a-1] && cntflag[a+1]){
                ans++;
                cout << ans << endl;
            }
            else if(!cntflag[a-1] && !cntflag[a+1]){
                ans--;
                cout << ans << endl;
            }
            else{
                cout << ans << endl;
            }
        }
        else{
            cntflag[a] = true;
            if(!cntflag[a-1] && !cntflag[a+1]){
                ans++;
                cout << ans << endl;
            }
            else if(!cntflag[a-1] || !cntflag[a+1]){
                cout << ans << endl;
            }
            else{
                ans--;
                cout << ans << endl;
            }
        }


    }


    
    return 0;
}