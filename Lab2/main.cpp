#include <stdio.h>
#include <stdlib.h>
#include "NumberList.h";

int main() {
	NumberList list1;
	list1.Init();
	list1.Add(1);
	list1.Add(5);
	list1.Add(3);
	list1.Add(7);
	list1.Add(2);
	list1.Sort();
	list1.Print();
}	