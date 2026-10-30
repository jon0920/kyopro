#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int m;
    cin >> m;
    if(m <= 2) m += 12;

    int n = m / 3;
    if(n == 1) cout << "Spring" << endl;
    else if(n == 2) cout << "Summer" << endl;
    else if(n == 3) cout << "Autumn" << endl;
    else cout << "Winter" << endl;
    
    return 0;
}