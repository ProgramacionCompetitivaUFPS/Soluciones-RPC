/********************************************************************
 * Ejercicio: M                                                     *
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

const int MX = 1e9;

bool isNum(char ch) {
    return 47 < ch && ch < 58;
}

bool valid(string& s) {
    for (int i = 0; i < sz(s); i++) {
        if (!isNum(s[i]))
            return false;
    }
    if (s[0] == '0')
        return false;
    return true;
}

bool range(string& s) {
    if (sz(s) > 10)
        return false;
    if (sz(s) == 10 && s[0] != '1')
        return false;
    int num = atoi(s.data());
    return 3 < num && num <= MX;
}

bool isInt(string& s) {
    if (sz(s) > 10)
        return false;
    if (sz(s) == 10 && s[0] != '1')
        return false;
    int num = atoi(s.data());
    return num <= MX;
}

bool isPrime(int x) {
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    fastIO;
    vector<string> input;
    string s;
    while (cin >> s) {
        input.pb(s);
    }
    if (sz(input) == 3) {
        if (valid(input[0]) && valid(input[1]) && valid(input[2])) {
            if (range(input[0]) && isInt(input[1]) && isInt(input[2])) {
                int sum = atoi(input[0].data());
                int a = atoi(input[1].data()), b = atoi(input[2].data());
                if (sum % 2 == 0 && sum == a + b) {
                    if (isPrime(a) && isPrime(b)) {
                        cout << 1 << endl;
                    } else
                        cout << 0 << endl;
                } else
                    cout << 0 << endl;
            } else
                cout << 0 << endl;
        } else
            cout << 0 << endl;
    } else
        cout << 0 << endl;
    return 0;
}