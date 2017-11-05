
#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef pair<int, si> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vi a;
int n, x;
map<int, set<int> > m;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    f(i, 10) {

        m.insert(pi(i, si()));

    }

    f(i, n) {


        f(j, 6) {
            int x;
            cin >> x;
            m[x].insert(i);
        }

    }
    int number = 123;
    string text = to_string(number);
    f(i, 1000) {
        string s = "a";
    }

    return 0;
}
