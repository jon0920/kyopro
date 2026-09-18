#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, t;
    cin >> n >> t;
    vector<int> row(n, 0), col(n, 0);
    int diag1 = 0, diag2 = 0;

    rep(i,t){
        int a;
        cin >> a;
        a--;
        int x = a / n, y = a % n;

        row[x]++, col[y]++;
        if(row[x] == n || col[y] == n){
            cout << i + 1 << endl;
            return 0;
        }
        
        if(x == y){
            diag1++;
            if(diag1 == n){
                cout << i + 1 << endl;
                return 0;
            }
        }
        if(x + y == n - 1){
            diag2++;
            if(diag2 == n){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}