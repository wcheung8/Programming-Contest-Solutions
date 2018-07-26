#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; i < (n); (i)++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

int n, k, m;
vi a;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> m;

    f(i,n) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int changed = 1;
    while(changed) {
        changed = 0;
        int curr = 0;
        int c = 1;
        for(int i = 1; i < a.size(); i++) {
            //cout << a[curr] << " " << a[i] << endl;
            if(a[curr] == a[i])
                c++;
            else {
                curr = i;
                c = 1;
            }
            if (c >= k) {
                changed = 1;
                a.erase(a.begin() + curr, a.begin() + i + 1);
                break;
            }

        }

    }
    int g = 0;
    while(true) {

        int curr = a[0];
        int c = 1;
        int f = 1, b = a.size();

        while(f < b && a[f+1] == curr) {
            c++;
            f++;
        }

        while(f < b && a[b-1] == curr) {
            c++;
            b--;
        }
        int z = c % k;

        if (c >= a.size()) {
            z = (c) % k;
            cout << (z * m)%k;
            return 0;
        } else {
            if (z != 0) {
                cout << g + (b - f + z) * m;
                return 0;
            } else {
                a.erase(a.end() - b + 2, a.end());
                a.erase(a.begin(), a.begin() + f);
                g += c;
            }
        }



    }

    return 0;
}


/*
6 2 5
1 2 3 3 2 5
*/

