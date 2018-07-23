#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;
vector<string> words;
vvi adj;
vi dist[2];

void bfs(int node) {
  dist[node] = vi(n, INF);
  dist[node][node] = 0;
  queue<int> q;
  q.push(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (dist[node][v] == INF) {
        dist[node][v] = dist[node][u] + 1;
        q.push(v);
      }
    }
  }
}

int hamming(string s, string t) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) ans++;
  }
  return ans;
}

string get_link(string s, string t) {
  vi indices;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) indices.push_back(i);
  }
  string s1 = s;
  s1[indices[0]] = t[indices[0]];
  string s2 = s;
  s2[indices[1]] = t[indices[1]];
  return min(s1, s2);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    words.push_back(s);
  }
  adj = vvi(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (hamming(words[i], words[j]) == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  bfs(0);
  bfs(1);

  int ans = dist[0][1];
  string s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (hamming(words[i], words[j]) == 2) {
        string link = get_link(words[i], words[j]);
        int tmp_ans = dist[0][i] + 2 + dist[1][j];
        if (tmp_ans < ans) {
          ans = tmp_ans;
          s = link;
        } else if (ans == tmp_ans) {
          if (s == "" || link < s) s = link;
        }
      }
    }
  }

  if (ans == INF) {
    cout << 0 << "\n" << -1 << "\n";
  }
  else if (ans == dist[0][1]) {
    cout << 0 << "\n" << ans << "\n";
  }
  else if (ans < dist[0][1]) {
    cout << s << "\n" << ans << "\n";
  }
  return 0;
}
