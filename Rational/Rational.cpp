#include "Rational.h"

Rational::Rational(uint32_t _numerator, uint32_t _denominator) :
	m_numerator{_numerator}, m_denominator{_denominator},
	m_numeratorPrimeFactors{}, m_denominatorPrimeFactors{}
{
	for (uint8_t index = 0; index < N127; ++index) {
		if (_numerator % primes127[index] == 0) {
			m_numeratorPrimeFactors[index] += 1;
			_numerator /= primes127[index];
		}
	}

	for (uint8_t index = 0; index < N127; ++index) {
		if (_denominator % primes127[index] == 0) {
			if (m_numeratorPrimeFactors[index] > 0) {
				// Simplify common factors
				m_numeratorPrimeFactors[index] -= 1;
				m_numerator /= primes127[index];
				m_denominator /= primes127[index];
			}
			else {
				m_denominatorPrimeFactors[index] += 1;
			}
			_denominator /= primes127[index];
		}
	}
}

Rational::Rational(uint32_t _numerator)
	: Rational{_numerator, 1}
{
}

Rational::Rational()
	: Rational{0,1} // FIXME: should be 'zero over zero'
{
}

Rational::Rational(const Rational& other) :
	m_numerator{other.m_numerator}, m_denominator{other.m_denominator},
	m_numeratorPrimeFactors{other.m_numeratorPrimeFactors},
	m_denominatorPrimeFactors{other.m_denominatorPrimeFactors}
{
}

Rational Rational::operator = (const Rational& other)
{
	if (this != &other) {
		m_numerator = other.m_numerator;
		m_denominator = other.m_denominator;
		m_numeratorPrimeFactors = other.m_numeratorPrimeFactors;
		m_denominatorPrimeFactors = other.m_denominatorPrimeFactors;
	}
	return *this;
}

Rational Rational::operator + (const Rational& rhs)
{
	return Rational{
		m_numerator * rhs.m_denominator + m_denominator * rhs.m_numerator,
		m_denominator * rhs.m_denominator
	};
}

Rational Rational::operator - (const Rational& rhs)
{
	return Rational{
		m_numerator * rhs.m_denominator - m_denominator * rhs.m_numerator,
		m_denominator * rhs.m_denominator
	};
}

Rational Rational::operator * (const Rational& rhs)
{
	return Rational{
		m_numerator * rhs.m_numerator,
		m_denominator * rhs.m_denominator
	};
}

Rational Rational::operator / (const Rational& rhs)
{
	return Rational{
		m_numerator * rhs.m_denominator,
		m_denominator * rhs.m_numerator
	};
}

std::ostream& operator << (std::ostream& os, const Rational& rational)
{
	os << unsigned(rational.m_numerator) << " : " << unsigned(rational.m_denominator);
	return os;
}
