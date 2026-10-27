#include <bits/stdc++.h>
#include <atcoder/string>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();

    string rev = s;
    reverse(rev.begin(), rev.end());
    string t = rev + s;
    
    vector<int> z = z_algorithm(t);

    for(int i = n; i < n * 2; i++){
        if(i + z[i] == n * 2){
            s.erase(i - n);
            s += rev;
            break;
        }
    }

    cout << s << endl;

    return 0;
}