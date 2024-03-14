#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const int n = 5; // розмір векторів
float d = 1, c = 0; // змінні для виразу з мого варіанту
float a[n]; // вектор вхідних даних
float res[n]; // вектор результатів
const float t = 10, f = 5, ty = 2, o = 1; // константи

void input() // функція для задання даних
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Input a[" << i << "] : ";
		cin >> a[i];
	}
	while (c < d)
	{
		cout << "Input c: ";
		cin >> c;
		cout << "Input d: ";
		cin >> d;
	}
}

void calculate() // функція для обчислення виразу
{
	_asm
	{
		lea esi, a // адреса початку вхідного вектора
		lea edi, res // адреса початку результуючого вектора
		mov ecx, n // розмір вектора
		finit // ініціалізація співпроцесу

		first:
		fld t // помістили в стек 10
			fld c // помістили с
			fmul //	10*с
			fld d // помістили d
			fdiv ty	// d/2
			fsub // 10*с - d/2
			fadd o // додали 1
			fld[esi] // помістили значення а в стек
			fmul[esi] // а*а

			fldln2
			fld d // помістили значення d в стек
			fsub f // d-5
			fyl2x // ln(d-5)
			fsub // a*a - ln(d-5)
			fdiv // (10*c - d/2 + 1) / (a*a - ln(d-5))
			fstp[edi] // запис виразу в масив

			add esi, 4 // переміститися на наступний елемент у вхідному векторі
			add edi, 4 // переміститися на наступний елемент у результуючому векторі
			loop first // перейти на початок циклу
	}
}

void calculateC() // функція для обчислення виразу в C++
{
	for (int i = 0; i < 5; i++)
	{
		res[i] = (10 * c - d / 2 + 1) / (a[i] * a[i] - log(d - 5));
	}
}

void print(string sum) // функція для виведення результуючого вектора
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Result for a[" << i << "] (" << a[i] << ") = " << res[i] << endl;
	}
}

int main()
{
	input();
	calculateC();
	cout << "Result for C++:" << endl;
	print("C++");
	calculate();
	cout << "Result for ASM:" << endl;
	print("ASM");
	system("pause");
	return 0;
}