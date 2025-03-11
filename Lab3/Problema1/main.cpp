#include <stdlib.h>
#include "Math.h";
#include <iostream>
using namespace std;
int main() {
	int a = 4;
	int b = 5;
	double c = 3.2;
	double d = 4.0;
	Math math;
	cout << math.Add(a, b) << '\n';
	cout << math.Add(a, b, 6) << '\n';
	cout << math.Add(c, d) << '\n';
	cout << math.Add(c, d, 5.0) << '\n';
	cout << math.Mul(a, b) << '\n';
	cout << math.Mul(a, b, 6) << '\n';
	cout << math.Mul(c, d) << '\n';
	cout << math.Mul(c, d, 5.0) << '\n';
	cout << math.Add(7, 4, 5, 6, 3, 5, 6, 4) << '\n';
	printf("%s\n", math.Add(nullptr, "World"));
	return 0;
}