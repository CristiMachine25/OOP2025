#include <stdio.h>
#include <stdlib.h>

long double operator"" _Kelvin(long double Kelvin) {
	return Kelvin - 273.15;
}
long double operator"" _Fahrenheit(long double Fahrenheit) {
	return (Fahrenheit - 32) * 5 / 9 + 273.15;
}
int main() {    
    double a = 300.0_Kelvin;
    double b = 120.0_Fahrenheit;
	printf("300 Kelvin = %.2f Celsius\n", a);
	printf("120 Fahrenheit = %.2f Celsius\n", b);
    return 0;
}
