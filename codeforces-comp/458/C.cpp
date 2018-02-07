#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1001;

int arr[INF][INF];
vi c(INF, 0);
int k;
ull sum = 0;

int num_bits(int i) {
    int c = 0;
    while(i > 0) {
        if((i&1) == 1){
            c++;
        }
        i = i >> 1;
    }
    return c;
}

void precompute() {

    f(i, INF) {
        if(i > 1) {
            int p = num_bits(i);
            if(p == 1)
                c[i] = 1;
            else
                c[i] = c[p] + 1;
        }

    }

}

void Pascal(int n){
  for (int line = 0; line < n; line++)
  {
    for (int i = 0; i <= line; i++)
    {
      if (line == i || i == 0)
           arr[line][i] = 1;
      else {
        arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
        arr[line][i] %= 1000000007;
      }

    }
  }
}

void compute_special(int p, int bits) {

    f(i, p+1) {
        //cout << p << " " << i << " "  << c[bits+i] << " "<< arr[p][i]<< endl;
        if(c[bits+i]+1 == k) {
            sum += arr[p][i];
            sum %= 1000000007;
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    string s;
    cin >> s >> k;
    precompute();
    Pascal(INF);
    c[0] = -999999;

    if(k == 0) {
        cout << 1;
        return 0;
    }
    
    if(s == "1") {
        cout << 0;
        return 0;
    }

    int bits = 0;
    f(i, s.size()) {
        if(s[i] == '1'){
            compute_special(s.size()-i-1, bits);
            bits++;
        }
    }

    if(c[bits]+1 == k) {
        sum += 1;
        sum %= 1000000007;
    }

    cout << sum;





    return 0;
}
