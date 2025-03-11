#include "Math.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list list;
	va_start(list, count);
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr || b == nullptr)
	{
		return nullptr;
	}
	char* result = new char[strlen(a) + strlen(b) + 1];
	strcpy_s(result, strlen(a) + 1, a);
	strcat_s(result, strlen(a) + strlen(b) + 1, b);
	return result;
}