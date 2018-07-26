#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n, x, s;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> x;

    for(int i = 0; i < n; i++) {

        int t;
        cin >> t;
        s += t;

    }

    if(n-1 + s == x){
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
