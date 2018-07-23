#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;
//http://codeforces.com/contest/884/problem/A
int n,t;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> t;
    for(int i = 0; i< n; i++) {

        int x;
        cin >> x;
        t-=(86400-x);

        if(t <=0){
            cout << i+1;
            return 0;
        }
    }

    cout << n;
    return 0;
}
