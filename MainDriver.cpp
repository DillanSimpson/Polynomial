#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
	Polynomial<int> p;
	Polynomial<int> r;
	Monomial<int> m(3, 4);
	Polynomial <int> q(3, 5);
	Polynomial<int> z1, z2;
	Polynomial<int> a;

	r = r + m;
	//Construct Polynomial from Monomial
	a = Polynomial<int>(m);

	//z1 += Polynomial<int>(2, 3) += Polynomial<int>(2, 1);
	//z2 += Polynomial<int>(2, 3) += Polynomial<int>(2, 1) += Polynomial<int>(1, 0);

	//Test if equal operator and += works
	//if (z1 == z2)
	//{
		cout << r.gethighestdegree() ;
	//}//


	return 0;
}