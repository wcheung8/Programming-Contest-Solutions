#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vvi a(100, vi(100, 0));

int x, y;
int n = 0;

void explore(int i, int j, int m) {

    // can't traverse
    if(i < 0 || i >= x || j < 0 || j >= y || a[i][j] == 0)
        return;

    a[i][j] = 0;

    explore(i+1, j, m);
    explore(i-1, j, m);

    explore(i, j-1, m);
    explore(i, j+1, m);

    explore(i+1, j+1, m);
    explore(i-1, j+1, m);

    explore(i+1, j-1, m);
    explore(i-1, j-1, m);


}


int main() {
    ios::sync_with_stdio(0);
    cin >> y >> x;

    f(j, y) {
        string s;
        cin >> s;
        f(i, x) {
            if(s[i] == '#')
                a[i][j] = 1;
        }
    }
/*
    f(j, y) {
        f(i, x) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
*/
    f(j, y) {
        f(i, x) {
            if(a[i][j] == 1){
                    n++;
                explore(i , j, 0);
            }
        }
    }


    cout << n;



    return 0;
}



/*
12 12
.##########.
#..........#
#..#...##..#
#.##..#..#.#
#......#.#.#
#....#..#..#
#...#.#....#
#..#...#...#
.#..#.#....#
#....#.....#
#.........#.
.#########..

12 10
.#####....
#.....#...
#..#..#...
#.#.#.#...
#..#..#...
.#...#....
..###.....
......#...
.##..#.#..
#..#..#...
.##.......
..........

*/
