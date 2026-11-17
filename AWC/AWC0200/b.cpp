#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x = 0, y = 0, z = 0;
    for(int i = 1; i < n; i++){
        if(a[i - 1] < a[i]) x++;
        else if(a[i - 1] > a[i]) y++;
        else z++;
    }

    cout << x << " " << y << " " << z << endl;
    
    return 0;
}