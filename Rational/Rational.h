#pragma once
#include <cstdint>
#include <iostream>
#include <array>
#include <map>

class Rational final
{
	friend std::ostream& operator << (std::ostream& os, const Rational& rational);
public:
	static const size_t N127 = 31;
	static inline const std::array<uint8_t,N127> primes127 = {
		 2,   3,   5,   7,  11,  13,  17,  19,  23,  29,
		31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
		73,  79,  83,  89,  97, 101, 103, 107, 109, 113, 127
	};
public:
	Rational(uint32_t _numerator, uint32_t _denominator);
	Rational(uint32_t _numerator);
	Rational();
	Rational(const Rational& other);
	Rational operator = (const Rational& other);
	~Rational() = default;
public:
	Rational operator + (const Rational& rhs);
	Rational operator - (const Rational& rhs);
	Rational operator * (const Rational& rhs);
	Rational operator / (const Rational& rhs);
private:
	uint32_t m_numerator;
	uint32_t m_denominator;
	std::array<uint8_t, N127> m_numeratorPrimeFactors;
	std::array<uint8_t, N127> m_denominatorPrimeFactors;
};

std::ostream& operator << (std::ostream& os, const Rational& rational);
