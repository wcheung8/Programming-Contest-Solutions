#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<ull> vi;
typedef vector<vi> vvi;
typedef pair<ull, ull> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const ull INF = 1e7;

vi c(31, -1);
ull n, L;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> L;

    f(i, n) {
        cin >> c[i];
    }

    f(i, 31) {
        f(j, 31) {
            if(j < i) {
                ull x =  pow(2, i-j) * c[j];
                c[i] = min(c[i], x);
            } else if (j > i) {
                c[i] = min(c[i], c[j]);
            }
        }
    }
//    f(i, n) {
//        cout << c[i] << endl;
 //   }




    ull min_total = -1;
    ull start = L & ((1 << 31) -1);
    ull e = min((ull)1<<31, start << 1);
    cout << start << " " << e << endl;
    for(ull i = start; i <= e; i++){
        ull total = 0;
        f(j, 31) {
            if(i & (1 << j)) {
                total += c[j];
            }
        }
        min_total = min(min_total, total);
    }

    min_total += (L >> 30) * c[30];

    cout << min_total;


    return 0;
}
