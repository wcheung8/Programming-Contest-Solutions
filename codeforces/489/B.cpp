#include <bits/stdc++.h>
#define ull  long long
#define f(i, n) for(ull (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<ull> vi;
typedef vector<vi> vvi;
typedef pair<ull, ull> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, pi> mi;

const ull INF = 1e7;

vi f;
ull a,b,x,y;

vector <ull> factors(ull x) {
    // We will store all factors in `result`
    vector <ull> result;
    ull i = a;
    // This will loop from 1 to ull(sqrt(x))
    while(i*i <= x && i <= b) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            result.push_back(i);
            // Handle the case explained in the 4th
            if(x/i != i && x/i <=b) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    return result;
}


int main() {
    ios::sync_with_stdio(0);
    cin >> a >> b >> x >> y;
    ull t = x * y;
    f = factors(t);


    ull counter = 0;
    for (ull i = 0; i < f.size(); i++ ){ 
        ull d = f[i];
        ull j = t / d;
        if(__gcd(d, j) == x) {
            counter+=1;
        }
    }
    cout << counter;

    return 0;
}