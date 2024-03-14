#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	int** matrix = new int* [n];
	cout << "Enter elements of the A matrix:\n";
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "\nMatrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	int min_element = matrix[0][0], i_min = 0, j_min = 0;
	int max_element = matrix[0][0], i_max = 0, j_max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			__asm
			{
				xor eax, eax			// ������� eax
					
				mov eax, matrix			// �������� ������� � eax
				mov esi, i				// �������� i � ������ esi
				imul esi, 4				// ������� i * 4
				add eax, esi			// ������ eax i esi
				push[eax]				// ���������� � ����
				pop eax					// ���������� � �����
				mov esi, j				// �������� j � ������ esi
				imul esi, 4				// ������� j * 4
				add eax, esi			// ������ eax i esi
				push[eax]				// ���������� � ����
				pop eax					// ���������� � �����

					CheckIfMin:			// M����, ���� ����� � �������
				cmp eax, min_element	// ��������� eax � min_element
					jl ChangeMin		// ���� eax � ������ �� min_element, �� ���������� �� ���� ChangeMin
					jmp CheckIfMax		// ���� � eax �� � ������ �� min_element, �� �������� �� ���� CheckIfMax

					ChangeMin:			// M����, ���� ������� ������ �����
				mov min_element, eax	// �������� eax � min_element
					mov ebx, i			// �������� i � ebx
					mov i_min, ebx		// �������� ebx � i_min
					mov ebx, j			// �������� j � ebx
					mov j_min, ebx		// �������� ebx � j_min
					xor ebx, ebx		// ������� ebx

					CheckIfMax:			// M����, ���� ����� � ����������
				cmp eax, max_element	// ��������� eax � max_element
					jg ChangeMax		// ���� eax � ������ �� max_element, �� ���������� �� ���� ChangeMax
					jmp Exit			// ���� � eax �� � ������ �� max_element, �� �������� �� ���� Exit

					ChangeMax:			// M����, ���� ������� ������ ��������
				mov max_element, eax	// �������� eax � max_element
					mov ebx, i			// �������� i � ebx
					mov i_max, ebx		// �������� ebx � i_max
					mov ebx, j			// �������� j � ebx
					mov j_max, ebx		// �������� ebx � j_max
					xor ebx, ebx		// ������� ebx

					Exit:				// ̳���, ��� ������� ����� �����
				xor eax, eax			// ������� eax
				xor esi, esi			// ������� esi
			}
		}
	}

	// �������� �� �����
	cout << "Min element: " << min_element << " is on position [" 
		<< i_min << "][" << j_min << "]" << endl;
	cout << "Max element: " << max_element << " is on position [" 
		<< i_max << "][" << j_max << "]" << endl;
	cout << endl;

	int dot_product = 0;

	__asm
	{
		mov ecx, n						// ���������� ��������

		xor esi, esi					// ������� esi

		loopStart:						// ������� �����
			xor eax, eax				// ������� eax
			xor ebx, ebx				// ������� ebx

			mov eax, matrix				// �������� ������� � eax
			mov ebx, matrix				// �������� ������� � ebx

		// matrix[i_max][j]
			mov edx, i_max
			mov eax, [eax + 4 * edx]
			mov edx, esi
			mov eax, [eax + 4 * edx]

		// matrix[i][j_min]
			mov edx, esi
			mov ebx, [ebx + 4 * edx]
			mov edx, j_min
			mov ebx, [ebx + 4 * edx]

		// matrix[i_max][j] * matrix[i][j_min]
			mov edx, eax
			imul edx, ebx

		// Form dot product
			add edx, dot_product
			mov dot_product, edx
			loopEnd:
		xor edx, edx
			inc esi
			loop loopStart
	}

	cout << "Dot product: " << dot_product << endl;

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	system("pause");
	return 0;
}