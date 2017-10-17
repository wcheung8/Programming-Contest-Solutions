#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;
int values[80];

int main() {
  ios::sync_with_stdio(0);
  cin >> n;

  for(int _ = 0; _ < n; _++) {
    char c;
    cin >>c;
    string line;
    getline(cin, line);
    line = line.substr(1);
    replace(line.begin(),line.end(),' ', '`');


    int l = line.length();
    for(int i = 0; i < l; i ++) {
            values[i] = int(line[i]-96);
        }
    string out = "";
    out += line[0];
    if(c == 'e') {

        for(int i = 1; i < l; i++) {
            values[i] =(values[i] + values[i-1])%27;
            out += char(values[i] + 96);
        }

    }
    else {

        for(int i = 1; i < l; i++) {
            out += char((values[i]-values[i-1]+27)%27 + 96);
        }

    }

    replace(out.begin(),out.end(),'`', ' ');
    cout << out << endl;
  }

  return 0;
}

