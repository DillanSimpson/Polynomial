#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
	int x = 2;
	unsigned failedTests = 0;

	Polynomial<int> p;
	Polynomial<int> r;
	Polynomial <int> q(3, 4);
	Polynomial<int> q2(1, 4);
	Monomial<int> m(2, 5);
	Polynomial<int> a, b;
	Polynomial<int> c(2, 3), d(4,6), e(3,3), f(-2,3);
	Polynomial<int> z1, z2;

	z1 += Polynomial<int>(2, 3) += Polynomial<int>(2, 1);
	z2 += Polynomial<int>(2, 3) += Polynomial<int>(2, 1) += Polynomial<int>(1, 0);

	a = Polynomial<int>(m);
	cout << "*** Equality Tests ***" << endl << endl;
	//Equality operators test
	if (z1 == z2) {
		cout << "Problem with equal to or addition operators" << endl;
	}
	else
		cout << "No issues with equal or addition operator" << endl;

	if (q != q2) {
		cout << "Not equal to operator works" << endl;
	}
	else 
		cout << "Not equal to operator not working" << endl ;


	//Assignmet operator check
	cout << "\n*** Assignment Operator Tests ***" << endl << endl;

	r = Polynomial<int>(2, 3);
	q += Polynomial<int>(4, 5) += Polynomial<int>(6, 7);
	Polynomial<int> w = q;

	cout << w << endl;
	cout << q << endl;

	if (r == Polynomial<int>(2, 3) && q == w) {
		cout << "Assignment operator works " << endl;
	}
	else
		cout << "Assignment operator not working " << endl;

	cout << "\n*** Equality Tests ***" << endl << endl;
	//Constructor Tests
	if (p == Polynomial<int>(1, 0)) {
		cout << "defualt zero arg constructor works" << endl;
	}
	else
		cout << "defualt zero arg constructor failed" << endl;
	if (q == Polynomial<int>(3, 4)) {
		cout << "defualt arg constructor works" << endl;
	}
	else
		cout << "defualt arg constructor failed" << endl;

	//cin and cout test
	cout << "\n*** cin && cout Tests ***" << endl << endl;
	cout << "Enter the polynomial (1 2 3 4 2 7 0)" << endl;
	cin >> a;
	cout << "Poly entered: " << a << endl;

	cout << "\nEnter polynomial (5 2 4 3 3 3 1 5 0)" << endl;
	cin >> b;
	cout << "Polynomial entered: " << b << endl;

	if (a == (Polynomial<int>(1, 2) += Polynomial<int>(3, 4) += Polynomial<int>(2, 7)))
	{
		cout << "cin works" << endl;
	}
	else
		cout << "cin is broke " << endl;

	if (b == (Polynomial<int>(1, 5) += Polynomial<int>(7, 3) += Polynomial<int>(5, 2)))
	{
		cout << "+= works " << endl;
	}
	else
		cout << "+=  doesnt work " << endl;

	//Testing all arithmetic operators
	cout << "\n*** Arithmetic Tests ***" << endl << endl;

	c += d += e += f;
	cout << c << endl;

	if (c == (Polynomial<int>(4, 6) += Polynomial<int>(3, 3))) {
		cout << "+= operator works" << endl;
	}
	else
		cout << "+= operator not working" << endl;

	Polynomial<double> d1(2, 3);
	Polynomial<double> d2(4, 3);

	cout << d1 << " - " << d2 << " = ";
	d1 -= d2;
	cout << d1 << endl;

	if (d1 == Polynomial<double>(-2, 3)) {
		cout << "-= operator works" << endl;
	}
	else
		cout << "-= operator does not work" << endl;

	Polynomial<int>m1(1, 2);
	Polynomial<int>m4(3, 2);
	Polynomial<int>m5(4, 2);
	Monomial<int> m2(2, 3);
	Polynomial<int>m3;

	m1 += m2;
	if (m1 == (Polynomial<int>(2, 3) += Polynomial<int>(1, 2))) {
		cout << "Polynomail + Monomial operator works" << endl;
	}
	else
		cout << "Polynomail + Monomial operator failed" << endl;
	m3 = m1 + m2;

	if (m1 == (Polynomial<int>(2, 3) += Polynomial<int>(1, 2))) {
		cout << "Polynomail + Monomial operator works" << endl;
	}
	else
		cout << "Polynomail + Monomial operator failed" << endl;

	m3 = m5 - m4;

	if (m3 == Polynomial<int>(1,2)) {
		cout << "Polynomail + Monomial operator works" << endl;
	}
	else
		cout << "Polynomail - Monomial operator failed" << endl;


	Polynomial<int> a1(1, 3);
	Polynomial<int> a2(2, 4);
	Polynomial<int> a3;

	a3 = a1 * a2;

	if (a3 == Polynomial<int>(2, 7)) {
		cout << "Polynomail * Monomial operator works" << endl;
	}
	else
		cout << "Polynomail * Monomial operator failed" << endl;
	
	a1 *= a3;


	if (a1 == ( Polynomial<int>(4,14) += Polynomial<int>(4,11) += Polynomial<int>(2, 4))) {
		cout << "Polynomail *= Monomial operator works" << endl;
	}
	else
		cout << "Polynomail *= Monomial operator failed" << endl;

	cout << "\n*** Evaluate Tests ***" << endl << endl;
	Polynomial<int> s1(2, 3);
	
	if (s1.evaluate(2) == 16)
	{
		cout << "Evalutate passed" << endl;
	}
	else
		cout << "Evaluate failed" << endl;

	cout << "\n*** Side effect Tests ***" << endl << endl;
	if (a == (Polynomial<int>(1, 2) += Polynomial<int>(3, 4) += Polynomial<int>(2, 7))) {
		cout << "No side effect " << endl;
	}
	else
		cout << "Bad side effect" << endl;
	return 0;
}