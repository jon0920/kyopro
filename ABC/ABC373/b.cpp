#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    int prevpos;
    int sum = 0;
    rep(i,26){
        rep(j,26){
            if(i == 0 && s[j] == 'A'){
                prevpos = j;
                break;
            }
            else{
                if(s[j] == 'A' + i){
                    sum += abs(prevpos - j);
                    prevpos = j;
                }
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}