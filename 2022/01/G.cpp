/********************************************************************
 * Ejercicio: G                                                     *
 * Url: https://redprogramacioncompetitiva.com/contests/2022/01/    *
 * Lenguaje: c++                                                    *
 * Autor: Everything_Is_Binary_Search                               *
 * Fecha: 12-02-2026                                                *
 *******************************************************************/

#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a - c > 1 && b - d > 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}