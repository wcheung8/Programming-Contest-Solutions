//http://codeforces.com/contest/4/problem/C

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
string in;
map<string, int> m;
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    f(i,n){
        cin >> in;
        if(m[in] == 0) {
            cout << "OK" << endl;

        } else {
            cout << in << m[in] << endl;
        }
        m[in]++;
    }
    return 0;
}
