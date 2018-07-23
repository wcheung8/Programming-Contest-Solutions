//http://codeforces.com/problemset/problem/165/B
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e9;

unsigned long long n, k;

unsigned long long eval(unsigned long long v) {

    unsigned long long n = k;
    unsigned long long a = v;
    while(floor(v / n) != 0) {

        a += floor(v / n);
        n *= k;

    }
    return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;

  unsigned long long low = 0, high = n*k;
  unsigned long long mid = 0;
  unsigned long long x = 0;
  unsigned long long last_valid = 0;
  while(low <= high) {
        mid = floor((high+low)/2);
        x = eval(mid);
        if(x > n) {
            high = mid - 1;
            last_valid = mid;
        } else if (x < n) {
            low = mid + 1;
        } else {
            cout << mid;
            return 0;
        }

  }

  cout << last_valid;
  return 0 ;
}
