#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> top3;
    rep(i,n){
        int a;
        cin >> a;
        top3.push_back(a);
        if(i >= 2){
            sort(top3.rbegin(), top3.rend());
            if(i >= 3) top3.pop_back();
            cout << top3.back() << endl;
        }
    }
    
    return 0;
}