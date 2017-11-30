#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vvi a;
int x,y;

int main() {
    ios::sync_with_stdio(0);
    cin >> y >> x;
    a = vvi(x, vi(y));

    f(j, y){
        string l;
        cin >> l;
        f(i, x) {
            if (l[i] == 'C')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }




    return 0;
}


