#include <stdlib.h>
#include "Canvas.h";

using namespace std;
int main() {
	Canvas c(100,100);
	c.DrawCircle(50, 50, 20, '*');
	c.DrawRect(10, 10, 30, 30, '#');
	c.FillRect(40, 40, 60, 60, '@');
	c.Print();
	c.Clear();
	return 0;
}
