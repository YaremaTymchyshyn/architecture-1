#include <iostream>
using namespace std;

void main()
{
	int a;
	int b;
	int c;
	int isosceles;
	cin >> a >> b >>c;

	__asm
	{
		mov eax, a
		mov ebx, b
		cdq
		sub eax, ebx
		test eax, eax
		jz is_equal

		mov eax, a
		mov ecx, c
		sub eax, ecx
		test eax, eax
		jz is_equal

		mov ebx, b
		mov ecx, c
		sub ebx, ecx
		test ebx, ebx
		jz is_equal
		jmp result

		is_equal:
			mov ebx, 0
			jmp result

		result:
			mov isosceles, ebx
	}

	if (isosceles == 0)
		cout << "The triangle is isosceles" << endl;

	else
		cout << "The triangle is NOT isosceles" << endl;

	system("pause");
}