#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    double x, y;
    cin >> x >> y;
    double cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            if(i+j >= x){
                cnt1++;
                continue;
            }
            if(abs(i-j) >= y) cnt2++;
        }
    }

    double e1 = (cnt1 + cnt2) / 36;

    cout << fixed << setprecision(17) << e1 << endl;

    return 0;
}