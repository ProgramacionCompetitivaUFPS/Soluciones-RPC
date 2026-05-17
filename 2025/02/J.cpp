/********************************************************************
 * Ejercicio: J. Jumbled Scoreboards                                *
 * Url: https://redprogramacioncompetitiva.com/contests/2025/02/    *
 * Lenguaje: c++                                                    *
 * Autor: Joa_mani_es_dp                                            *
 * Fecha: 08-03-2025                                                *
 *******************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define laepica ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define sz(x) int((x).size())
#define DBG(x) cout << #x  << " = " << x << endl
#define print(v) for(auto &x : v) { cout << x << " "; } cout << endl
#define forin(v) for(auto &i : v) cin >> i
#define YESNO(x) cout << (x ? "yes" : "no") << endl
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ft first
#define sd second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pcs(x) cout << fixed << setprecision(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<typename T, typename K>
std::ostream &operator<<(std::ostream &str, pair<T,K> const &p) {
  return str << "(" << p.ft << "," << p.sd << ")";
}

int main(){
	laepica;
	int n, a,b;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i < n; i++){
        cin >> a >> b;
        v[i] = {a,b};
	}
	bool ok = 1;
	for(int i = 1; i < n && ok; i++){
        if(v[i-1].ft > v[i].ft || v[i-1].sd > v[i].sd) ok = 0;
        if(v[i-1].ft < v[i].ft && v[i-1].ft == v[i].ft) ok = 0;
        if(v[i-1].ft == v[i].ft && v[i-1].ft < v[i].ft) ok = 0;
	}
	YESNO(ok);
	return 0;
}
