#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, pi> mi;

const int INF = 1e7;

vvi a;
vi sums;
map<int, pi> m;
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    a = vvi(n);
    sums = vi(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> k;
        a[i] = vi(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            sums[i] += a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++) {

            if(m.find(sums[i]-a[i][j]) == m.end()) {
                m[sums[i]-a[i][j]] = pi(i, j);
            } else {
                if(m[sums[i]-a[i][j]].first != i) {
                    cout << "YES" << endl;
                    cout <<  m[sums[i]-a[i][j]].first+1 << " " << m[sums[i]-a[i][j]].second+1 << endl;
                    cout <<  i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}