#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, pi> mi;

const int INF = 1e7;

vi a;
vvpi mods;
vi bad;
int n, m;
int thresh;

int main() {
    ios::sync_with_stdio(0);


    cin >> n >> m;
    a = vi(2e5 + 1);
    
    mods = vvpi(m, vpi());
    thresh = n/m;

    f(i, n) {
        cin >> a[i];
        int x = a[i] % m;
        mods[x].push_back(pi(i,x));
    }

    f(i, m) {
        if( mods[i].size() > thresh){
            bad.push_back(i);
        }
        
    }
    int counter = 0;

    while(bad.size() > 0){

        int x = bad.back();
        bad.pop_back();

        int c = mods[x].size() - thresh;
        f(i, c) {
            counter++;
            pi y = mods[x].back();
            mods[x].pop_back();
            mods[((x+1)%m)].push_back(y);
        }

        if (mods[(x+1)%m].size() > thresh)
            bad.push_back((x+1)%m);

    }


    f(i, m) {
        f(j, thresh) {
            pi x = mods[i][j];
            if(i >= x.second)
                a[x.first] += i - x.second;
            else 
                a[x.first] += (m - x.second) + i;
            
        }
    }

    cout << counter << endl;
    f(i, n) {

        cout << a[i] << " ";
    }




    return 0;
}