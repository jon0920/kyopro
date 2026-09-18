#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    while(top <= bottom && left <= right){
        for(int c = left; c <= right; c++) a[top][c] = num++;
        top++;
        for(int r = top; r <= bottom; r++) a[r][right] = num++;
        right--;
        for(int c = right; c >= left; c--) a[bottom][c] = num++;
        bottom--;
        for(int r = bottom; r >= top; r--) a[r][left] = num++;
        left++; 
    }
    
    rep(i,n){
        rep(j,n){
            if(i != (n - 1) / 2 || j != (n - 1) / 2) cout << a[i][j] << " ";
            else cout << 'T' << " ";
        }
        cout << endl;
    }
    
    return 0;
}