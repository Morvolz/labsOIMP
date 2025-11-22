#pragma once 

class Fraction {
    private: 
    int m_numerator, m_denominator;
    
    public: 
    int get_numerator() const;
    int get_denominator() const;
    void reduce();
    
    Fraction(int _numerator, int  _denominator);
    Fraction(const Fraction& frac);
    Fraction() = delete;

    Fraction add(const Fraction& frac) const;
    Fraction multiply(const Fraction& frac) const;
    Fraction divide(const Fraction& frac) const;

    void print() const;
};