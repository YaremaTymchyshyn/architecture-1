#include <iostream>
using namespace std;

int main()
{
	int y_1, y_2, y;
	int a, x;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter x: ";
	cin >> x;

	__asm
	{
		mov ecx, a
		mov ebx, x
		cmp ebx, 4
		jg great
		jle lesss
		great:
			mov y_1, -5
			jmp y2;
		lesss:
			sub ebx, ecx
			mov y_1, ebx
		y2:
			cmp ebx, ecx
			jg gretta
			jle lessa
		gretta:
			mov ebx, ecx
			mov y_2, ecx
			cmp ecx, 0
			jl isla
			jmp yf
		lessa:
			mov y_2, 9
			jmp yf
		isla:
			neg y_2
		yf:
			mov eax, 0
			mov ecx, y_1
			cmp y_1, 0
			jl y_1_islad
			jge fad
		y_1_islad:
			mov ebx, y_1
			neg ebx
			add eax, ebx
			add eax, y_2
			jmp result
		fad:
			add eax, ecx
			add eax, y_2
		result:
			mov y, eax
	}

	cout << "y1 = " << y_1 << endl;
	cout << "y2 = " << y_2 << endl;
	cout << "y = " << y << endl;

	system("pause");
	return 0;
}