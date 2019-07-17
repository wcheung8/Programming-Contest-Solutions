#include <bits/stdc++.h>

#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi>> q;
typedef map<ull, ull> mi;

const int INF = 1e7;

vi a = vi(1001);
vi b = vi(1001);

int n, m;

double r = 1e9, l = 0;

bool checkfuel(double fuel) {

    double weight;
    f(i, n) {
        weight = m + fuel;
        fuel -= weight / a[i];

        if (fuel < 0)
            return false;
        weight = m + fuel;
        fuel -= weight / b[i];

        if (fuel < 0)
            return false;
    }
    return true;
}

double binarySearch() {
    double best = -1;
    while (abs(l - r) > 1e-6) {
        double mid = (r + l) / 2;
        bool makeit = checkfuel(mid);

        if (makeit) {
            r = mid;
            best = r;
        } else
            l = mid;
    }

    // if we reach here, then element was
    // not present
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;

    f(i, n) {
        cin >> a[i];
        l += m / a[i];
    }

    f(i, n) {
        cin >> b[i];
        l += m / b[i];
    }

    cout << setprecision(12) << binarySearch();


    return 0;
}
