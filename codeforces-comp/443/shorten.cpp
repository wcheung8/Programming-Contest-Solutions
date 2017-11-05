//http://codeforces.com/contest/879/problem/C
#include <bits/stdc++.h>
#define ull unsigned long long
#define fin for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

int n;

int a = 1023;
int b = 0;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    fin {
        char c;
        int d;
        cin >> c >> d;

        if(c == '|') {
            a |= d;
            b |= d;
        } else if (c == '^') {
            a ^= d;
            b ^= d;
        } else {
            a &= d;
            b &= d;
        }
    }

    int x=0, y=0, z=1023;

    for(int i = 0; i < 10; i++) {
        int o = (b>>i)&1;
        int p = (a>>i)&1;
        //cout << o<< ' ' << p << endl;
        if(o == 1&& p ==1) {
            x |= 1<<i;
        } else if(o ==1 && p == 0) {
            y |= 1<<i;
        } else if(o == 0 && p== 0) {
            z &= ~(1<<i);
        }

    }
    cout << 3 << endl;
    cout << "| " << x << endl;
    cout << "^ " << y << endl;
    cout << "& " << z << endl;
    return 0;
}
