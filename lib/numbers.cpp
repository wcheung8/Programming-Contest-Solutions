#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, ull> mi;

const int INF = 1e7;

int N, A, B;
int aa = -1, bb = -1;

// non-zero solutions to xa + yb = c
int solve_diaphantine(int a, int b, int c) {
    int x, y, sum, c0;
    c0 = c;
    y = 0;
    sum = a + b;
    while (c >= sum) {
        if (c % a == 0) {
          break;
        }
        c -= b;
    }
    if (c % a == 0) {
        y = (c0 - c) / b;
        x = c / a;
        aa = x;
        bb = y;
        return 1;
    } else {
        return 0;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin >> N >> A >> B;


    if (solve_diophantine(A, B, N)) {
        int index = 1;
        f(i, aa) {
            int start = index;
            f(i, A-1) {
                cout << ++index << " ";
            }
            cout << start << " ";
            index++;
        }

        f(i, bb) {
            int start = index;
            f(i, B-1) {
                cout << ++index  << " ";
            }
            cout << start << " ";
            index++;
        }



    } else {
        cout << -1;
    }



    return 0;
}
