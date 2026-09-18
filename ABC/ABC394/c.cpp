#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    int n = s.size(), cur = 0;
    while(cur < n - 1){
        if(s[cur] == 'W' && s[cur + 1] == 'A'){
            s[cur] = 'A';
            s[cur + 1] = 'C';
            if(cur != 0) cur--;
        }
        else cur++;
    }

    cout << s << endl;
    
    return 0;
}