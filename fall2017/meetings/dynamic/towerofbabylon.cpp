#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


typedef struct b {
    int x,y,z;
} block;

typedef vector<block> vb;
const int INF = 1e7;
int n;
vb blocks;
vvi dp;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  while(n != 0) {

    blocks = vb();

    int m = -1;

    for(int i = 0; i < n; i++) {
        int x,y,z1;
        cin >> x>> y>> z;
        block b = {x,y,z};
        blocks.push_back(b);

        m = max(x,y);
        m = max(m,z);
    }




  }
  return 0;
}
