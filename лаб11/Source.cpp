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
				xor eax, eax			// Очищуємо eax
					
				mov eax, matrix			// Записуємо матрицю в eax
				mov esi, i				// Записуємо i в регістр esi
				imul esi, 4				// Множимо i * 4
				add eax, esi			// Додаємо eax i esi
				push[eax]				// Заштовхуємо в стек
				pop eax					// Виштовхуємо зі стека
				mov esi, j				// Записуємо j в регістр esi
				imul esi, 4				// Множимо j * 4
				add eax, esi			// Додаємо eax i esi
				push[eax]				// Заштовхуємо в стек
				pop eax					// Виштовхуємо зі стека

					CheckIfMin:			// Mітка, якщо число є мінімумом
				cmp eax, min_element	// Порівнюємо eax з min_element
					jl ChangeMin		// Якщо eax є меншим за min_element, то переходимо до мітки ChangeMin
					jmp CheckIfMax		// Якщо ж eax не є меншим за min_element, то стрибаємо до мітки CheckIfMax

					ChangeMin:			// Mітка, якщо потрібно змінити мінімум
				mov min_element, eax	// Записуємо eax в min_element
					mov ebx, i			// Записуємо i в ebx
					mov i_min, ebx		// Записуємо ebx в i_min
					mov ebx, j			// Записуємо j в ebx
					mov j_min, ebx		// Записуємо ebx в j_min
					xor ebx, ebx		// Очищуємо ebx

					CheckIfMax:			// Mітка, якщо число є максимумом
				cmp eax, max_element	// Порівнюємо eax з max_element
					jg ChangeMax		// Якщо eax є більшим за max_element, то переходимо до мітки ChangeMax
					jmp Exit			// Якщо ж eax не є більшим за max_element, то стрибаємо до мітки Exit

					ChangeMax:			// Mітка, якщо потрібно змінити максимум
				mov max_element, eax	// Записуємо eax в max_element
					mov ebx, i			// Записуємо i в ebx
					mov i_max, ebx		// Записуємо ebx в i_max
					mov ebx, j			// Записуємо j в ebx
					mov j_max, ebx		// Записуємо ebx в j_max
					xor ebx, ebx		// Очищуємо ebx

					Exit:				// Мітка, яка позначає кінець циклу
				xor eax, eax			// Очищуємо eax
				xor esi, esi			// Очищуємо esi
			}
		}
	}

	// Виводимо на екран
	cout << "Min element: " << min_element << " is on position [" 
		<< i_min << "][" << j_min << "]" << endl;
	cout << "Max element: " << max_element << " is on position [" 
		<< i_max << "][" << j_max << "]" << endl;
	cout << endl;

	int dot_product = 0;

	__asm
	{
		mov ecx, n						// Ініціалізуємо лічильник

		xor esi, esi					// Очищуємо esi

		loopStart:						// Початок циклу
			xor eax, eax				// Очищуємо eax
			xor ebx, ebx				// Очищуємо ebx

			mov eax, matrix				// Записуємо матрицю в eax
			mov ebx, matrix				// Записуємо матрицю в ebx

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