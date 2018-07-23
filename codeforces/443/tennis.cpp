#include <bits/stdc++.h>
#define ull unsigned long long
#define fin for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;


vi a(1000);
ull n, x;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> x;
    fin {
        cin >> a[i];
    }

    ull c = 0;
    ull s = a[0];
    for(int i = 1; i < n; i++) {
        if (c >= x){
            cout << s;
            return 0;
        } else if(s >= a[i]){
            c++;
        } else {
            s = a[i];
            c = 1;
        }

    }

    cout << s;

    return 0;
}
