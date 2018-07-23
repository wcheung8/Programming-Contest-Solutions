#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;

  for(int i = 0; i < n; i ++) {
    int g,s,d;
    bool flag = true;
    cin >> g;
    cin >> s;
    for(int a = 1; a < g; a++) {

        cin >> d;
        if(s != d - 1 && flag) {
            cout << a+1 << endl;
            flag = false;
        }
        s = d;
    }

  }
  return 0;
}
