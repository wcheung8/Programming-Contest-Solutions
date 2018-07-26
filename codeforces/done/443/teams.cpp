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

vi strip(vi a, int* flag) {

        unsigned int f = 0;
        vi x;
        while(f < a.size())
        {
            int curr = a[f];
            int c = 1;
            f++;
            while(f < a.size() && a[f] == curr)
            {
                f++;
                c++;
            }

            if (c >= k)
                *flag = 1;

            c %= k;

            f(i, c)
            {
                x.push_back(curr);
            }
        }
        return x;

}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> m;

    f(i,n)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int flag = 1;
    while (flag)
    {
        flag = 0;
        a = strip(a, &flag);
    }

/*
6 2 5
1 3 2 2 3 5
*/

    if(m == 1)
    {
        cout << a.size();
        return 0;
    }

    int f = 0;
    int b = a.size()-1;
    while(true)
    {
        int c = 1;
        int curr = a[f];
        f++;
        while(f < b && a[f] == curr)
        {
            f++;
            c++;
        }

        while(b > f && a[b] == curr)
        {
            b--;
            c++;
        }

        c %= k;
        f -= c;
        if(c > 0)
        {
            int flag = 0;
            int curr = a[f];
            for(int i = f; i <= b; i++){
                if(curr != a[i])
                    flag = 1;
            }
            if (flag == 0) {
                int z = (c*m) % k;
                if(z == 0)
                {
                    cout << "0";
                    return 0;
                }
                else
                {
                    cout << (f + (a.size() - 1 - b)) + z;
                    return 0;
                }
            }
            else
            {
                cout <<  (f + (a.size() - 1 - b)) + (b - f + 1) * m;
                return 0;
            }

        }
        else
        {
            if(f > b)
            {
                cout << "0";
                return 0;
            }
            else
            {
                continue;
            }

        }


    }



    return 0;
}

