
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

vi l(100000,INF);
vvi qq(10000, vi(2));
int n, q, s;
vi b(100000, INF);

void init() {

    s = floor(sqrt(n));

    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            b[i] = min(b[i] , l[i*s + j]);
        }
    }

    for(int i = s * s; i < n; i++){
        b[s] = min(b[s], l[s*s + i]);
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> qq[i][0] >> qq[i][1];
  }

  init();


  for(int _ = 0; _ < q; _++) {
    int a = qq[_][0];
    int z = qq[_][1];
    int aa = floor(qq[_][0] / s);
    int bb = floor(qq[_][1] / s);

    int r = l[a];

    if(aa == bb) {
        for(int i = a; i <= z; i++){
            r = min(r, l[i]);
        }
    } else {
        for(int i = a; i < (aa+1)*s; i++) {
            r = min(r, l[i]);
        }

        for(int i = bb*s; i <= z; i++) {
            r = min(r, l[i]);
        }

        for(int i = aa+1; i < bb; i++) {
            r = min(r, b[i]);
        }
    }


    cout << r << endl;

  }

  return 0;
}
