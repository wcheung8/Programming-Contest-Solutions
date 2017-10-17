#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> p;
typedef vector<p> vp;
typedef vector<vp> vvp;
typedef priority_queue<p> q;
const int INF = 1e10;
const int mx = 1e5;

int n, m, x;
vi closest(mx, INF);
vvp el(mx);
q pq;

int main() {
  ios::sync_with_stdio(0);

  cin >> n >> m;
  for(int i = 0; i<n; i++) {
        cin >> x;
        if(x)
            pq.push(p(0,i));
  }


  for(int i = 0; i<m ; i++) {
    int a,b,w;
    cin >> a >> b >> w;
    el[a].push_back(p(b,w));
    el[b].push_back(p(a,w));
  }


  while(!pq.empty()) {
    x = pq.top().second;

    for(int i = 0; i<el[x].length(); i++) {



    }

    pq.pop();
  }


  return 0;
}
