#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e5+1;

int a[INF+2];
long long n, x;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    f(i, n) {
        cin >> x;
        a[x]++;
    }

    f(i,INF) {
        if((a[i]&1) == 1) {
            cout << "Conan";
            return 0;
        }
    }

    cout << "Agasa";
    return 0;
}
