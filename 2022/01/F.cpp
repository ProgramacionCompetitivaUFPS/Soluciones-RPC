/********************************************************************
 * Ejercicio: F                                                     *
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

const int inf = 1e9;
const int MX = 505;
vector<int> g[MX], inv[MX];
stack<int> st;
int low[MX], pre[MX], cnt;
int comp[MX], tam[MX];
bool villager[MX];
int vist[MX];
int SCC;
int n, k, act;

void tarjan(int u) {
    low[u] = pre[u] = cnt++;
    st.push(u);

    for (auto& v : g[u]) {
        if (pre[v] == -1)
            tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    if (low[u] == pre[u]) {
        while (true) {
            int v = st.top();
            st.pop();
            low[v] = inf;
            comp[v] = SCC;
            if (u == v)
                break;
        }
        SCC++;
    }
}

void init() {
    cnt = SCC = 0;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        pre[i] = -1;
    }
}

void dfs(int u) {
    villager[u] = true;
    for (int& v : g[u]) {
        if (!villager[v]) {
            dfs(v);
        }
    }
}

int f(int u) {
    vist[u] = act;
    int ans = 1;
    for (int& v : inv[u]) {
        if (vist[v] != act) {
            ans += f(v);
        }
    }
    return ans;
}

int main() {
    fastIO;
    cin >> n >> k;
    init();
    for (int u = 1; u <= n; u++) {
        int s, v;
        cin >> s;
        while (s--) {
            cin >> v;
            g[u].pb(v);
            inv[v].pb(u);
        }
    }
    for (int u = 1; u <= n; u++) {
        if (pre[u] == -1) {
            tarjan(u);
        }
    }
    for (int u = 1; u <= n; u++) {
        tam[comp[u]]++;
    }
    for (int u = 1; u <= n; u++) {
        act++;
        if (tam[comp[u]] > k || f(u) > k) {
            dfs(u);
        }
    }
    for (int u = 1; u <= n; u++) {
        cout << villager[u] << endl;
    }
    return 0;
}