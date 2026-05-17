/********************************************************************
 * Ejercicio: E. Expected Error                                    *
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
	int n, k, p, conb, con, res, bac, bacb;
	cin >> n >> k >> p;
	conb = n - k + 1 + 3 + n + 1;
	conb *= p;
	con = n - k + 1;
	con *= 100 - p ;
	res = 3 + n + 1;
	bac = 1+ n - k + 1;
	bac *= p;
	bacb = 1 + n - k + 1 + 3 + n + 1;
	bacb *= 100 - p;
	con += conb;
	bac += bacb;
	map<int,string> m;
	m[bac] = "backspace";
	m[con] = "continue";
	m[res*100] = "restart";
	cout << m.begin()->sd << endl;
	return 0;
}
