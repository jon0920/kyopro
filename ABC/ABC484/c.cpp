#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    deque<int> A, B;
    for(int x : a) A.push_back(x);
    for(int x : b) B.push_back(x);

    while(!A.empty() && !B.empty() && A.front() == B.front()){
        A.pop_front(); B.pop_front();
    }
    if(A.empty() && B.empty()){
        cout << "Yes" << endl;
        return 0;
    }
    while(!A.empty() && !B.empty() && A.back() == B.back()){
        A.pop_back(); B.pop_back();
    }


    deque<int> LA = A, RA = A;
    int x = LA.front();
    LA.pop_front(); LA.push_back(x);
    int y = RA.back();
    RA.pop_back(); RA.push_front(y);

    deque<int> BB = B;
    while(!LA.empty() && !B.empty() && LA.front() == B.front()){
        LA.pop_front(); B.pop_front();
    }
    if(LA.empty() && B.empty()){
        cout << "Yes" << endl;
        return 0;
    }

    while(!RA.empty() && !BB.empty() && RA.front() == BB.front()){
        RA.pop_front(); BB.pop_front();
    }
    if(RA.empty() && BB.empty()){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    
    return 0;
}