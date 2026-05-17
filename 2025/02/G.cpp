/********************************************************************
 * Ejercicio: G. Grocery Greed                                   	*
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

vector<string> split(const string &s, char c) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    // vwhile (ss >> sub) v.pb(sub);
    while (getline(ss, sub, c)) v.pb(sub);
    return v;
}

int32_t main() {
	#ifndef LOCAL
  fastIO;
  #endif
  gracias(A Carlos, Lucho y Maria);
#define int ll
	int n; cin>>n;
	vector<int> q(10);
	vector<string> vv(n);
	vector<int> v;
	forin(vv);
	for(auto &s : vv){
		auto k = split(s,'.');
		int x = stoi(k[0])*100+stoi(k[1]);
		v.pb(x);
	}
	//sDBG(v);
	for(auto &x : v)q[x%10]++;
	//sDBG(q);
	
	int ahorro = q[1]+q[2]*2+q[6]+q[7]*2;
	int mn;
	
	
	int &c8 = q[8];
	int &c4 = q[4];
	int &c9 = q[9];
	int &c3 = q[3];

	vector<piii> ini = {
		{1, {3,4}},
		{2, {3,9}},
		{3, {4,8}},
		{4, {8,9}}
	};
	vector<int> ori = q;
	auto apply = [&](pii &p) -> int {
		int mn = min(q[p.F], q[p.S]);
		q[p.F] -= mn;
		q[p.S] -= mn;
		return mn;
	};
	
	auto geta = [&](vector<piii> &x) -> int {
		int s = 0;
		for(auto &pa : x){
			s += apply(pa.S)*2;
		}
		pii lst = {3,8};
		s += apply(lst);
		
		//3 se agrupan de a 2
		//4 se agrupan de a 3
		//8 se agrupan de a 2
		//9 se agrupan de a 3
		
		s += q[3]/2;
		s += q[4]/3*2;
		s += q[8]/2;
		s += q[9]/3*2;
		
		
		return s;
	};
	int aho = 0;
	vector<int> fin = q;
	do{
		//sDBG(ini);
		int res = geta(ini);
		if(res > aho){
			aho = res;
			fin = q;
		}		
		q = ori;
	}while(next_permutation(all(ini)));
	
	//DBG(aho);
	
	int sss = 0;
	for(auto &x : v)sss+=x;
	double res = sss-ahorro-aho;
	
	cout<<fixed<<setprecision(2)<<res/100.0<<endl;
	
	
  return 0;
}
