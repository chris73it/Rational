#include <iostream>
#include "Rational.h"

int main()
{
	Rational r1{ 131, 131 };
	std::cout << r1 << std::endl;

	Rational r2{ 131, 137 };
	std::cout << r2 << std::endl;

	Rational r5{ 5, 7 };
	std::cout << r5 << std::endl;
	Rational r6{ 2, 3 };
	std::cout << r6 << std::endl;
	
	Rational r7a = r5 + r6;
	std::cout << "[+] " << r7a << std::endl;

	r7a = r5 - r6;
	std::cout << "[-] " << r7a << std::endl;

	r7a = r5 * r6;
	std::cout << "[*] " << r7a << std::endl;

	Rational r7b = r7a = r5 / r6;
	std::cout << "[/ oper =] " << r7a << std::endl;
	std::cout << " copy ctor " << r7b << std::endl;

	return 0;
}
