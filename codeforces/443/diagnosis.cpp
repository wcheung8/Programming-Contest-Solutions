//http://codeforces.com/contest/879/problem/A
#include <bits/stdc++.h>
#define ull unsigned long long
#define fin for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vi a;
int n, x;
q qq;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    x = 0;
    fin {
        int a,b;
        cin >> a >> b;
        int d = a;
        while(d <= x) {
            d += b;
        }
        x = d;
    }

    cout << x;

    return 0;
}
