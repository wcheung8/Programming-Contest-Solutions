//http://codeforces.com/contest/873/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n,d;
vvi p(400000, vi(2, -10));
char s[200000];

void check(int i, int v) {
    if(p[i][0] == -10)
        p[i][0] = v;

    if(p[i][1] < v)
        p[i][1] = v;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> s;
  d = 200000;
  check(d,-1);

  for(int i = 0; i < n; i++) {
        d += s[i] == '0' ? -1 : 1;
        check(d,i);
  }

  int m = 0;
  for(int i = 0; i < 400000; i++) {
        m = max(m, p[i][1] - p[i][0]);
  }
  cout << m;



  return 0;
}
