#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

ull n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    ull a = 0;
    ull aa = 0;

    for(ull i = 0; i < n; i++) {
        cin >> aa;
        a += aa;
    }

    if(a % 5 == 0)
        cout << a/5;
    else
        cout << a/5 + 1;




    return 0;
}
