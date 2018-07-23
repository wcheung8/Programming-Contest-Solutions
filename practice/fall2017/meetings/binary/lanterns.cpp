#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

//http://codeforces.com/problemset/problem/492/B
using namespace std;

const int MAX = 1000;

int main() {

    int n, l;
    scanf("%d %d", &n, &l);

    int arr[MAX];
    int dist[MAX+1];

    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 1; i < n; i++) {
        dist[i] = arr[i] - arr[i-1];
    }
    dist[0] = arr[0] * 2;
    dist[n] = (l - arr[n-1]) * 2;

    int m = arr[0];
    for(int i = 0; i < n+1; i++) {
        m = max(m,dist[i]);
    }
    printf("%.8f", (float)m/2);


}
