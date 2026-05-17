/********************************************************************
 * Ejercicio: D. Dialling Digits                                    *
 * Url: https://redprogramacioncompetitiva.com/contests/2025/02/    *
 * Lenguaje: c++                                                    *
 * Autor: Joa_mani_es_dp                                            *
 * Fecha: 08-03-2025                                                *
 *******************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forsn(i, s, n) for (int i = s; i < n; ++i)
#define forin(x)                                                               \
  for (auto &i : (x))                                                          \
    cin >> i;
#define dforn(i, n) for (int i = n - 1; i >= 0; --i)
#ifdef LOCAL
#define DBG(x) cout << #x << " = " << x << endl;
#else
#define DBG(x) "chamoy"
#endif
#define sDBG(x)                                                                \
  for (auto &el : x) {                                                         \
    cout << el << " ";                                                         \
  }                                                                            \
  cout << endl;
#define YESNO(b) cout << (b ? "YES" : "NO") << endl;
#define gracias(...) #__VA_ARGS__

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<long long, long long> pll;
typedef long double ld;

template <typename T, typename K>
std::ostream &operator<<(std::ostream &str, pair<T, K> const &p) {
  return str << "(" << p.F << "," << p.S << ")";
}

/**
//Collection cout
template <template <typename, typename, typename...> class collection,
          class key, class value, class... Args>
std::ostream &operator<<(std::ostream &str,
                         collection<key, value, Args...> const &coll) {
  str << "[";
  for (auto it = coll.begin(); it != coll.end(); ++it) {
    if (it != coll.begin()) {
      str << " ";
    }
    str << *it;
  }
  return str << "]";
}
//*/
int32_t main() {
	#ifndef LOCAL
  fastIO;
  #endif
  gracias(A Carlos, Lucho y Maria);
#define int ll
	int n, m;
	cin>>n>>m;
	map<string, vector<string>> mp;
	
	auto t = [&](string &s) -> string {
		string a = "";
		for(auto &c : s){
			if('a' <= c && c <= 'c')a += '2';
			if('d' <= c && c <= 'f')a += '3';
			if('g' <= c && c <= 'i')a += '4';
			if('j' <= c && c <= 'l')a += '5';
			if('m' <= c && c <= 'o')a += '6';
			if('p' <= c && c <= 's')a += '7';
			if('t' <= c && c <= 'v')a += '8';
			if('w' <= c && c <= 'z')a += '9';
		}
		return a;
	};
	
	while(n--){
		 string s; cin>>s;
		 mp[t(s)].pb(s);
	}
	while(m--){
		string s; cin>>s;
		cout<<sz(mp[s]);
		for(int i = 0; i < sz(mp[s]); ++i){
			cout<<" ";
			cout<<mp[s][i];
		}
		cout<<endl;
		
	}
	
  return 0;
}
