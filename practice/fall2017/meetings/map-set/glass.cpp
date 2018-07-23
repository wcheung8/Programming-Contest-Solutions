//http://codeforces.com/contest/527/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(ull (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<ull> vi;
typedef vector<vi> vvi;
typedef pair<ull, ull> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, ull> mi;

const ull INF = 1e7;

ull n, xx, yy;
mi x;
mi y;
mi mx;
mi my;

int main() {

    ios::sync_with_stdio(0);
    cin >> xx >> yy >> n;

    x[xx] = xx;
    y[yy] = yy;
    x[0] = 0;
    y[0] = 0;

    mx[xx] = 1;
    my[yy] = 1;

    f(i, n) {
        char c;
        ull cc;

        cin >> c >> cc;

        if(c == 'H') {

            y[cc] = cc;
            mi::iterator b = y.find(cc);
            b--;
            ull lb = b->first;
            b++;
            b++;
            ull ub = b->first;

            ull l = ub-lb;

            my[l]--;


            if(my[l] == 0) {
                my.erase(my.find(l));
            }

            my[cc - lb]++;
            my[ub - cc]++;



            cout << my.rbegin()->first * mx.rbegin()->first << endl;



        } else {

            x[cc] = cc;
            mi::iterator b = x.find(cc);
            b--;
            ull lb = b->first;
            b++;
            b++;
            ull ub = b->first;

            ull l = ub-lb;

            mx[l]--;
            if(mx[l] == 0) {
                mx.erase(mx.find(l));
            }

            mx[cc - lb]++;
            mx[ub - cc]++;

            cout << my.rbegin()->first * mx.rbegin()->first << endl;


        }

    }


    return 0;
}
