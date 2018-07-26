#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vi a;
int n, x;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int count = 0;
    n++;
    int c;

    for(int a = 1; a < n; a++) {
        for(int b = a; b < n; b++) {
            c = b ^ a;
            if ((c < n) && (c != 0) && (a + b > c) && (a + c > b) && b + c > a) {
                count += 1;
            }
        }
    }

    count /= 3;



    cout << count;





    return 0;
}

