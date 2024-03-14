#include <iostream>
using namespace std;

char FORMAT[] = "%s %s %s\n";
char DESIGN[] = "designed by";
char AUTHOR[] = "Yarema Tymchyshyn";
char DATE[] = "19.04.2022";

void main()
{
	__asm 
	{
		// початок асемблерного коду
		mov eax, offset DATE
		push eax
		mov eax, offset AUTHOR
		push eax
		mov eax, offset DESIGN
		push eax
		mov eax, offset FORMAT
		push eax

		// виклик функції виведення
		call printf

		// очищення стеку для коректного завершення процедури main
		pop ebx
		pop ebx
		pop ebx
		pop ebx

		// кінець асемблерного коду
	}
	system("pause");
}