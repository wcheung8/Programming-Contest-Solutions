#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

ull n, m;

bool isPrime(ull number){
    if (number != 2){
        if (number < 2 || number % 2 == 0) {
            return false;
        }
        for(int i=3; (i*i)<=number; i+=2){
            if(number % i == 0 ){
                return false;
            }
        }
    }
    return true;
}

void print_edges(ull mx) {
    ull edges = n - 1;
    for(ull i = 2; i <= n; i++) {
        for(ull j = i+1; j <= n; j++) {
            if(edges < m) {
                cout << i << " " << j << " " << mx << endl;
                edges += 1;
            } else{
                return;
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;

    ull s = 2 * (n-1);
    ull c = 2;
    while(!isPrime(s)) {
        c += 1;
        s += 1;
    }

    cout << 2 << " " << s << endl;
    for(ull i = 3; i <= n; i++) {
        cout << "1 " << i << " 2" << endl;
    }
    cout << "1 2 " << c << endl;
    print_edges(c+1);

    return 0;
}
