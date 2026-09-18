#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    int n = s.size();
    int cnt = 0;
    char judge = 'i';
    for(char c : s){
        if(c == judge){
            if(judge == 'i') judge = 'o';
            else judge = 'i';
        }
        else cnt++;
    }
    if(judge == 'o') cnt++;
    cout << cnt << endl;
    return 0;
}