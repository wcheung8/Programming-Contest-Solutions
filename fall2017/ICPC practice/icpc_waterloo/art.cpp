#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int l[5];
int n = 0;
int main() {
  ios::sync_with_stdio(0);
  for(int i = 0; i < 5; i++) {
      int a;
    cin >> a;
    l[i] =a;
  }

  for(int a = 0; a < 5; a++) {
    for(int b = a+1; b < 5; b++) {
        for(int c = b+1; c < 5; c++) {

            if ( l[a] + l[b] > l[c] && l[a] + l[c] > l[b] && l[b] + l[c] > l[a])
                n++;

        }
    }
  }
  cout << n;
  return 0;
}
