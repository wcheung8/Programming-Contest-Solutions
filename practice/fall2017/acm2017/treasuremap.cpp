#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vector<pi> a[1001];
vector<pi> b(1001);
vvi dp(1001, vi(1001, -1));
int n, m;

int maximum(int v, int t) {

    if(t > 1000)
        return 0;

    if (dp[v][t] >= 0)
        return dp[v][t];

    int x = 0;
    for(int i = 0; i < a[v].size(); i++){
        pi p = a[v][i];
        pi pp = b[v];
        x = max(x, max(0, pp.first - t*pp.second) + maximum(p.first, t + p.second));
    }
    dp[v][t] = x;
    return x;

}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    f(i, n) {
        int g, d;
        cin >> g >> d;
        b[i+1] = pi(g, d);
    }

    f(i, m) {
        int x, y, d;
        cin >> x >> y >> d;
        a[x].push_back(pi(y,d));
        a[y].push_back(pi(x,d));
    }



    cout << maximum(1, 0);


    return 0;
}
