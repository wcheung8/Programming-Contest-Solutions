//https://open.kattis.com/problems/cheatingbooleantree
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n,m,v;
vi g(10000);
vi c(10000);
vi swaps(10000, INF);

// returns the min number of gates to make true
int solve(int want, int v) {
    if(v >= (m+1)/2) {
        if(want != g[v])
            return INF;
        else
            return 0;
    }

    if(swaps[v] < INF)
        return swaps[v];

    int c1 = 2*v;
    int c2 = 2*v+1;
    int r = INF;
    int a,b;
    if(c[v] == 1) {

        if(want == 0) {
            a = min(solve(want, c1), solve(want, c2));
        } else {
            a = solve(want, c1) + solve(want, c2);
        }
        if(want == 0) {
            b = solve(want, c1) + solve(want, c2);
        } else {
            b = min(solve(want, c1), solve(want, c2));
        }

        if(g[v] == 1)
            r = min(a, b+1);
        else
            r = min(a+1, b);


    } else {
        if(g[v] == 1) {
            if(want == 0) {
                r = min(solve(want, c1), solve(want, c2));
            } else {
                r = solve(want, c1) + solve(want, c2);
            }
        } else {
            if(want == 0) {
                r = solve(want, c1) + solve(want, c2);
            } else {
                r = min(solve(want, c1), solve(want, c2));
            }
        }
    }

    swaps[v] = r;
    return r;

}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;

  for(int _ = 0; _ < n; _++) {
        g = vi(100000);
        c = vi(100000);
        swaps = vi(10000,INF);
        cin >> m >> v;

        for(int i = 0; i < (m-1)/2; i++) {
            cin >> g[i+1] >> c[i+1];
        }

        for(int i = (m-1)/2; i < m; i++) {
            cin >> g[i+1];
        }

        int asdf = solve(v,1);
        if (asdf < INF)
            cout << "Case #" << _+1 << ": " << asdf << endl;
        else
            cout  << "Case #" << _+1 << ": IMPOSSIBLE" <<endl;

  }

  return 0;
}

