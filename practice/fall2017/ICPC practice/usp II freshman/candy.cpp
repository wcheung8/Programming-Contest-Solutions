#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;

int main() {

  unsigned long long low = 0, high = 1e9;
  unsigned long long mid = 0;
  char x;
  while(low <= high) {
        mid = floor((high+low)/2);
        // printf("Q %i", mid);
        cout << "Q " << mid;
        cout.flush();
        cin >> x;
        if(x == '<') {
            high = mid - 1;
        } else if (x =='>') {
            low = mid + 1;
        } else {
            return 0;
        }

  }
  return -1;
}
