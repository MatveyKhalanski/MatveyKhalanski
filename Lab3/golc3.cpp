#include <iostream>
#include "pair.h"
using namespace std;
int main()
{
    Pair p1, p2;
    int n;
    cin >> p1 >> p2;
    cout << p1<< endl<< p2;
    cin >> n;
    cout << p1.mul(n) << endl << p1 + p2 << endl;
    cout << "-------Money-------" << endl;
    Money m1, m2;
    cin >> m1 >> m2;
    cout << m1 << endl << m2 << endl;
    cout << "m1 + m2 " << m1 + m2 << endl;
    cout << "m1 - m2 " << m1.sub(m2) << endl;
    cout << "m1 / m2 " << m1.div(m2) << endl;

}
