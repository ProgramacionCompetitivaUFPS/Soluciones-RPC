/********************************************************************
 * Ejercicio: H. Longest Common Substring                                                     *
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

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, x = 0, y = 0; i < n; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            x = i, y = i + z[i], z[i]++;
        }
    }
    return z;
}

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s = v[0];
    int lim = sz(v[0]), ans = 0;
    for (int i = 0; i < lim; i++) {
        v[0] = s.substr(i);
        int aux = sz(v[0]);
        for (int j = 1; j < n; j++) {
            string t = v[0] + "#" + v[j];
            vector<int> z = z_function(t);
            int mx = 0;
            for (int k = sz(v[0]) + 1; k < sz(z); k++) {
                mx = max(mx, z[k]);
            }
            aux = min(aux, mx);
        }
        ans = max(aux, ans);
    }
    cout << ans << endl;
    return 0;
}