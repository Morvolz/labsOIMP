#include "Fraction.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

Fraction::Fraction(int _numerator, int  _denominator) {
    if (_denominator == 0) {
        throw invalid_argument("Denominator is cannot be 0!");
    }
    m_numerator = _numerator;
    m_denominator = _denominator;
    reduce();
}
Fraction::Fraction(const Fraction& frac) {
    m_numerator = frac.m_numerator;
    m_denominator = frac.m_denominator;
}

int Fraction::get_numerator() const {
    return m_numerator;
}

int Fraction::get_denominator() const {
    return m_denominator;
}

void Fraction::reduce()  {
    if (m_numerator == 0) return;
    int gc = __gcd(m_denominator, m_numerator);
    m_denominator /= gc;
    m_numerator /= gc;
    if (m_denominator < 0 && m_numerator >= 0) {
        m_denominator = -m_denominator;
        m_numerator = -m_numerator;
    }
}

Fraction Fraction::add(const Fraction& frac) const {
    if (frac.m_denominator == 0) {
        throw invalid_argument("Denominator is cannot be 0!");
    }
    int numerator = m_denominator * frac.m_numerator + m_numerator * frac.m_denominator;
    int denominator = m_denominator * frac.m_denominator;
    Fraction fr(numerator, denominator);
    fr.reduce();
    return fr;
}

Fraction Fraction::multiply(const Fraction& frac) const {
    if (frac.m_denominator == 0) {
        throw invalid_argument("Denominator is cannot be 0!");
    }
    int numerator = frac.m_numerator * m_numerator;
    int denominator = m_denominator * frac.m_denominator;
    Fraction fr(numerator, denominator);
    fr.reduce();
    return fr;
}

Fraction Fraction::divide(const Fraction& frac) const {
    Fraction fr(frac.m_denominator, frac.m_numerator);
    return multiply(fr);
}


void Fraction::print() const {
    cout << m_numerator << "/" << m_denominator << "\n";
}