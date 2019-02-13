#ifndef __POLYNOMIAL_CPP_
#define __POLYNOMIAL_CPP_
#include "Polynomial.h"

template<typename NumberType>
void Polynomial<NumberType>::insert_in_poly(Polynomial<NumberType> & p, const Monomial<NumberType> & m) {
	typename list<Monomial<NumberType>>::iterator itr = p.term_list.begin();
	int count = 0;
	//Iterates through list until monomial is the smallest in the list
	while (itr != p.term_list.end() && m.degree() < (*itr).degree()) {
		if (count == 0) {
			p.highest_degree = itr->degree();
		}
		count++;
		itr++;
	}
	
	//Checks if the current object is eqaul if so add's deletes if addition equates to 0
	if (itr != p.term_list.end() && m.degree() == (*itr).degree()) {
			if (((*itr).coefficient() + m.coefficient()) == 0) {
				itr = p.term_list.erase(itr);
				p.number_of_terms--;
			}
			else {
				itr->assign_coefficient(itr->coefficient() + m.coefficient());
			}
	}

	else if (itr != p.term_list.end()) {
		p.term_list.insert(itr, m);
		p.number_of_terms++;
	}

	else if (itr == p.term_list.end()) {
		p.term_list.push_back(m);
		p.number_of_terms++;
	}
	else if (itr == p.term_list.end()) {
		p.term_list.push_front(m);
		highest_degree = m.degree();
		p.number_of_terms++;
	}

}

template<typename NumberType>
NumberType Polynomial<NumberType>::power(NumberType x, int n) const
{
	NumberType product = 1;
	for (int i = 0; i < n; i++) {
		product *= x;
	}
	return product;
}

template<typename NumberType>
const Polynomial<NumberType>& Polynomial<NumberType>::operator=(const Polynomial<NumberType>& rhs)
{
	if (rhs != *this)
	{
		for (unsigned int i = 0; i < rhs.term_list.size(); i++)
		{
			term_list = rhs.term_list;
			highest_degree = rhs.highest_degree;
			number_of_terms = rhs.number_of_terms;
		}
	}
	return *this;
}

template<typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Monomial<NumberType>& m)
{
	insert_in_poly(*this, m);
	return *this;
}


template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Polynomial<NumberType> & rhs) {
	typename list<Monomial<NumberType>>::const_iterator itr = rhs.term_list.begin();
	while (itr != rhs.term_list.end()) {
		(*this) += *itr;
		itr++;
	}
	return *this;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator+ (const Monomial<NumberType> &m)const {
	return Polynomial(*this) += m;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator+ (const Polynomial<NumberType> & rhs) const {
	return Polynomial<NumberType>(*this) += rhs;
}

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Monomial<NumberType> &m) {
	Monomial<NumberType> mon;
	mon = m;

	mon.assign_coefficient(-m.coefficient());
	insert_in_poly(*this, mon);
	return *this;
}

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Polynomial<NumberType> & rhs) {
	typename list<Monomial<NumberType>>::const_iterator itr = rhs.term_list.begin();
	while (itr != rhs.term_list.end()) {
		(*this) -= *itr;
		itr++;
	}
	return *this;
}

template <typename NumberType>
const Polynomial<NumberType>  Polynomial<NumberType>::operator- (const Monomial<NumberType> &m)const {
	return Polynomial(*this) -= m;
}

template <typename NumberType>
const Polynomial<NumberType>  Polynomial<NumberType>::operator- (const Polynomial<NumberType> & rhs) const {
	return Polynomial(*this) -= rhs;
}

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Monomial<NumberType> &m) {
	typename list<Monomial<NumberType>>::iterator itr = term_list.begin();

	while (itr != term_list.end()) {
		itr->assign_coefficient(m.coefficient() * itr->coefficient());
		itr->assign_degree(m.degree() + itr->degree());
		itr++;
	}
	insert_in_poly(*this, m);
	return *this;
}

template <typename NumberType>
Polynomial<NumberType>  Polynomial<NumberType>::operator*=(const Polynomial<NumberType> & rhs) {
	typename list<Monomial<NumberType>>::const_iterator itr = rhs.term_list.begin();
	while (itr != rhs.term_list.end()) {
		(*this) *= *itr;
		itr++;
	}

	return *this;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Monomial<NumberType> &m) const {
	return Polynomial(*this) *= m;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Polynomial<NumberType> &rhs)const {
	return Polynomial(*this) *= rhs;
}

template <typename NumberType>
const Polynomial<NumberType>& Polynomial<NumberType>::operator=(const Polynomial<NumberType> && rhs) {
	Polynomial<NumberType> poly =rhs;
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < rhs.term_list.size(); i++)
		{
			term_list = rhs.term_list;
			highest_degree = rhs.highest_degree;
			number_of_terms = rhs.number_of_terms;
		}
		poly.term_list.clear();
		poly.highest_degree = 0;
		poly.number_of_terms = 0;	
	}
	//rhs = poly;
	return *this;
}

template <typename NumberType>
bool Polynomial<NumberType>::operator==(const Polynomial<NumberType> &p) const {
	typename list<Monomial<NumberType>>::const_iterator itr = this->term_list.begin();
	typename list<Monomial<NumberType>>::const_iterator itr2 = p.term_list.begin();
	
	while (itr != term_list.end() && itr2 != p.term_list.end()) {
		if (itr->coefficient() != itr2->coefficient() || itr->degree() != itr2->degree())
		{	
			return false;
		}
		itr++;
		itr2++;
	}
	
	return true;
}

template <typename NumberType>
bool Polynomial<NumberType>::operator!=(const Polynomial<NumberType> &p) const {
	typename list<Monomial<NumberType>>::const_iterator itr = this->term_list.begin();
	typename list<Monomial<NumberType>>::const_iterator itr2 = p.term_list.begin();

	while (itr != term_list.end() && itr2 != p.term_list.end()) {
		if (itr->coefficient() != itr2->coefficient() || itr->degree() != itr2->degree())
		{
			return true;
		}
		itr++;
	}

	return false;
}

template<typename NumberType>
void Polynomial<NumberType>::read(istream & in)
{
	NumberType coeff;
	int expo;
	*this = Polynomial<NumberType>::ZERO;

	cin >> coeff;
	while (coeff != 0)
	{
		cin >> expo;
		if (expo < 0)
		{
			cout << "Bad dgree";
			return;
		}

		Monomial<NumberType> m(coeff, expo);
		*this += Monomial<NumberType>(coeff, expo);
		in >> coeff;
	}
}

template<typename NumberType>
void Polynomial<NumberType>::print(ostream & out) const
{
	Polynomial<NumberType> poly = *this;
	typename list<Monomial<NumberType>>::iterator itr = poly.term_list.begin();
	while (itr != poly.term_list.end()) {
		out << itr->coefficient() << "x^" << itr->degree() << " ";
		itr++;
	}

}

template <typename NumberType>
const NumberType Polynomial<NumberType>::evaluate(NumberType x) const {
	NumberType eval = 0;
	NumberType prod;
	typename list<Monomial<NumberType>>::const_iterator itr = term_list.begin();
	while (itr != term_list.end()) {
		prod = power(x, itr->degree());
		prod *= itr->coefficient();
		eval += prod;
		itr++;
	}
	return eval;
}

template<typename NumberType>
istream& operator>>(istream & in, Polynomial<NumberType> & rhs) {
	rhs.read(in);
	return in;
}

template<typename NumberType>
ostream& operator<<(ostream & out, const Polynomial<NumberType> & rhs) {
	rhs.print(out);
	return out;
};
#endif