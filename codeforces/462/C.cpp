#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;
typedef map<ull, ull> mi;

const int INF = 1e7;

int a[2000];
int n, k;

int lo = 0;
int hi = 0;

int GetCeilIndex(int arr[], vector<int> &T, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l)/2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LNIS(int arr[], int n){

    vector<int> tailIndices(n, 0);
    vector<int> prevIndices(n, -1);

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[tailIndices[0]])
        {
            tailIndices[0] = i;
        }
        else if (arr[i] <= arr[tailIndices[len-1]])
        {
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        }
        else
        {
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len-1, arr[i]);
            prevIndices[i] = tailIndices[pos-1];
            tailIndices[pos] = i;
        }
    }


    cout << "LIS of given input" << endl;
    for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i])
        cout << arr[i] << " ";
    cout << endl;

    return len;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    f(i, n){
        cin >> a[i];
        cout << i << " " << a[i] << endl;
    }

    LNIS(a, n);

    cout << lo << hi;



    return 0;
}
