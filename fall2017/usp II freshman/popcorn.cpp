#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

unsigned long long n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    cout << (n-1)*(n)/2 + 1;

    return 0;
}
