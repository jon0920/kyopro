#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    char s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    int x1 = s1 - 'A';
    int x2 = s2 - 'A';
    int y1 = t1 - 'A';
    int y2 = t2 - 'A';
    int diff1 = abs(x1 - x2 + 5) % 5;
    int diff2 = abs(y1 - y2 + 5) % 5;
    diff1 = min(diff1, 5 - diff1);
    diff2 = min(diff2, 5 - diff2);
    cout << (diff1 == diff2 ? "Yes" : "No") << endl;
    
    return 0;
}