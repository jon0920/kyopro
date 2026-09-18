#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    double cost = 0;
    int lx = 0, ly = 0;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        cost += sqrt(pow((lx - x), 2) + pow((ly - y), 2));
        lx = x, ly = y;
    }
    cost += sqrt(pow((lx - 0), 2) + pow((ly - 0), 2));
    cout << fixed << setprecision(17) << cost << endl;
    
    return 0;
}