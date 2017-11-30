#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

ull n,a = 0, s = 0;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    for(ull i = 0; i < n; i++) {
        ull t;
        cin >> t;
        a += s * t;
        s += t;
    }

    cout << a;
    return 0;
}
