/********************************************************************
 * Ejercicio: I                                                     *
 * Url: https://redprogramacioncompetitiva.com/contests/2022/01/    *
 * Lenguaje: c++                                                    *
 * Autor: Everything_Is_Binary_Search                               *
 * Fecha: 12-02-2026                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
// scanf("%d %d %d %d",&w,&b,&d,&s); %lld
// printf("%d\n" ,points);
// const double PI = acos(-1);

bool grid[24][60][60];

vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (getline(ss, sub, c)) v.pb(sub);
    return v;
}

vector<pii> format(string& s, bool h) {
    vector<pii> ans;
    vector<string> ranges = split(s, ',');
    for (int i = 0; i < sz(ranges); i++) {
        if (s == "*") {
            if (h)
                ans.pb({0, 23});
            else
                ans.pb({0, 59});
        } else {
            int ind = ranges[i].find("-"), x, y;
            if (ind != -1) {
                x = atoi((ranges[i].substr(0, ind)).data());
                y = atoi((ranges[i].substr(ind + 1)).data());
                ans.pb({x, y});
            } else {
                x = atoi(ranges[i].data());
                ans.pb({x, x});
            }
        }
    }
    return ans;
}

void mark(pii h, pii m, pii s) {
    for (int i = h.ft; i <= h.sd; i++) {
        for (int j = m.ft; j <= m.sd; j++) {
            for (int k = s.ft; k <= s.sd; k++) {
                grid[i][j][k] = true;
            }
        }
    }
}

int main() {
    fastIO;
    int n;
    ll sum = 0, ans = 0;
    cin >> n;
    string h, m, s;
    for (int i = 0; i < n; i++) {
        cin >> h >> m >> s;
        vector<pii> a = format(h, true);
        vector<pii> b = format(m, false);
        vector<pii> c = format(s, false);
        for (int x = 0; x < sz(a); x++) {
            for (int y = 0; y < sz(b); y++) {
                for (int z = 0; z < sz(c); z++) {
                    mark(a[x], b[y], c[z]);
                    ll aux = a[x].sd - a[x].ft + 1;
                    aux *= b[y].sd - b[y].ft + 1;
                    aux *= c[z].sd - c[z].ft + 1;
                    ans += aux;
                }
            }
        }
    }
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                sum += grid[i][j][k];
            }
        }
    }
    cout << sum << " " << ans << endl;
    return 0;
}