#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int MAXN = 222;

int n, V;
int v[MAXN], w[MAXN], c[MAXN];

vi get_basis(int x) {
    int a = 0;
    int b = 1;
    vi ans;
    while(2*b - 1 <=x) {
        ans.push_back(b);
        a+=b;
        b*=2;
    }
    if (x-a >0)
        ans.push_back(x-a);
    return ans;

}

long long solve_knapsack(const vector<pair<int, int> >& items, int capacity) {

    vector<long long> dp(capacity+1);
    f(i, items.size()) {
        int weight = items[i].first;
        int value = items[i]. second;

        for(int j = capacity; j >= 0; j--) {

            if (j >= weight) {
                dp[j] = max(dp[j], dp[j-weight] + value);
            }

        }

    }

    return dp[capacity];


}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> V;

    f(i, n) {
        cin >> v[i] >> w[i] >> c[i];
    }
    vector< pair<int, int> > items;
    f(i,n) {
        vi basis = get_basis(c[i]);
        f(j, basis.size()) {
            items.push_back(make_pair(basis[j] * v[i], basis[j] * w[i]));
        }
    }

    long long ans = solve_knapsack(items, V);

    cout << ans;
    return 0;
}
