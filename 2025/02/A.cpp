/********************************************************************
 * Ejercicio: A. “Aaawww...” or “Aaayyy!!!”                         *
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
#define DBG(x) cout << x << endl;
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

typedef 	pair<int, string> T;
int32_t main() {
	#ifndef LOCAL
  fastIO;
  #endif
  gracias(A Carlos, Lucho y Maria);
#define int ll
	int n, m, r;
	cin>>n>>m>>r;
	vector<T> v;
	int pnd = 0;
	for(int i = 0; i < n; ++i){
		string s; cin>>s;
		for(auto &c : s)pnd += (c=='P');
		v.pb({i+1, s});
	}
	//DBG(pnd);
	
	auto next = [&]() -> int {
		for(int i = sz(v)-1; i >= 0; --i){
			if(v[i].S.find("P")!=string::npos)return i;
		}
		return -1;
	};
	
	auto prob = [&](string &s) -> int {
		for(int i = 0; i < sz(s); ++i){
			if(s[i] == 'P')return i;
		}
	};
 	
	for(int i = 0; i < pnd; ++i){
		int id = next();
		int prb = prob(v[id].S);
		string s; cin>>s>>s;
		if(s[3] == 'y'){
			v[id].S[prb] = 'A';
			int x = s.substr(6).size()-3;
			int it = id;
			//DBG("subir "<<x<<" equipo "<<it);
			//sDBG(v);
			while(x-- && it){
				swap(v[it-1], v[it]);
				it--;
			}
			//sDBG(v);
		}else{
			v[id].S[prb] = 'R';
		}
	}
	
	int i = 1;
	for(auto &p : v){
		if(p.F == r)cout<<i<<endl;
		i++;
	}
	
  return 0;
}
