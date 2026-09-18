#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int M = 200;
vector<bool> isp(M + 1, true);

void era(){
    isp[0] = false;
    isp[1] = false;
    for(int i = 2; pow(i, 2) <= M; i++){
        if(isp[i]) for(int j = 2; i * j <= M; j++) isp[i * j] = false;
    }
}

int main(){

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    era();
    set<int> prime;
    for(int i = 2; i <= 200; i++) if(isp[i]) prime.insert(i);

    bool takahashi = false;
    for(int i = a; i <= b; i++){
        bool aoki = false;
        for(int j = c; j <= d; j++){
            if(prime.count(i + j)) aoki = true;
        }
        if(!aoki) takahashi = true;
    }

    if(takahashi) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}