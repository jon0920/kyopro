#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n, -1);
    int cur;
    rep(i,n){
        cin >> a[i];
        if(a[i] == -1) cur = i;
        else b[a[i] - 1] = i;
    }

    while(cur != -1){
        cout << cur + 1 << " ";
        cur = b[cur];
    }

    cout << endl;
    
    return 0;
}