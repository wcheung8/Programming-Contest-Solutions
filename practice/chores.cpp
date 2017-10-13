//http://codeforces.com/contest/873/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n,k,x;
int c[100];

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> x;
  for(int i = 0; i < n; i ++) {
        cin >> c[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i ++) {
        if(i >= n-k)
            sum+= min(x, c[i]);
        else
            sum += c[i];
  }
  cout << sum;


  return 0;
}
