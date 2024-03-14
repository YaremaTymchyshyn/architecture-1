#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const int n = 5; // ����� �������
float d = 1, c = 0; // ���� ��� ������ � ���� �������
float a[n]; // ������ ������� �����
float res[n]; // ������ ����������
const float t = 10, f = 5, ty = 2, o = 1; // ���������

void input() // ������� ��� ������� �����
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

void calculate() // ������� ��� ���������� ������
{
	_asm
	{
		lea esi, a // ������ ������� �������� �������
		lea edi, res // ������ ������� ������������� �������
		mov ecx, n // ����� �������
		finit // ����������� ����������

		first:
		fld t // �������� � ���� 10
			fld c // �������� �
			fmul //	10*�
			fld d // �������� d
			fdiv ty	// d/2
			fsub // 10*� - d/2
			fadd o // ������ 1
			fld[esi] // �������� �������� � � ����
			fmul[esi] // �*�

			fldln2
			fld d // �������� �������� d � ����
			fsub f // d-5
			fyl2x // ln(d-5)
			fsub // a*a - ln(d-5)
			fdiv // (10*c - d/2 + 1) / (a*a - ln(d-5))
			fstp[edi] // ����� ������ � �����

			add esi, 4 // ������������ �� ��������� ������� � �������� ������
			add edi, 4 // ������������ �� ��������� ������� � ������������� ������
			loop first // ������� �� ������� �����
	}
}

void calculateC() // ������� ��� ���������� ������ � C++
{
	for (int i = 0; i < 5; i++)
	{
		res[i] = (10 * c - d / 2 + 1) / (a[i] * a[i] - log(d - 5));
	}
}

void print(string sum) // ������� ��� ��������� ������������� �������
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