


#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	__int8 arr[7] = { 142, 4, 71, 11, 5, 255, 75 };

	int previous;
	int current;
	int count = 0;

	__asm
	{
		xor eax, eax			// очищуЇмо eax

		//заповнюЇмо eax
		mov al, arr[0]			// записуЇмо в al значенн€ нульового елемента
		shl eax, 8				// поб≥тово зсуваЇмо eax на 8 б≥т≥в
		mov al, arr[1]			// записуЇмо в al значенн€ першого елемента
		shl eax, 8				// поб≥тово зсуваЇмо eax на 8 б≥т≥в
		mov al, arr[2]			// записуЇмо в al значенн€ другого елемента
		shl eax, 8				// поб≥тово зсуваЇмо eax на 8 б≥т≥в
		mov al, arr[3]			// записуЇмо в al значенн€ третього елемента

		xor ebx, ebx			// очищуЇмо ebx

		//заповнюЇмо ebx
		mov bl, arr[4]			// записуЇмо в al значенн€ четвертого елемента
		shl ebx, 8				// поб≥тово зсуваЇмо eax на 8 б≥т≥в
		mov bl, arr[5]			// записуЇмо в al значенн€ п'€того елемента
		shl ebx, 8				// поб≥тово зсуваЇмо eax на 8 б≥т≥в
		mov bl, arr[6]			// записуЇмо в al значенн€ шостого елемента

		mov ecx, 32				// ≥н≥ц≥ал≥зац≥€ л≥чильника дл€ ecx

		forEAX:
	loopBeginEAX:
		shl eax, 1				// поб≥тово зсуваЇмо eax на 1 б≥т
		jc isOneEAX				// м≥тка, €кщо б≥т в eax одиниц€
		isNullEAX:				// м≥тка, €кщо б≥т нуль
	mov current, 0				// записуЇмо в поточний б≥т нуль
		cmp previous, 1			// пор≥внюЇмо попередн≥й б≥т з одиницею
		je previousIsOneEAX		// €кщо попередн≥й б≥т в eax дор≥внюЇ одиниц≥
		previousIsNullEAX:		// €кщо попередн≥й б≥т в eax дор≥внюЇ нулю
	jmp loopEndEAX				// стрибаЇмо в к≥нець циклу дл€ eax
		previousIsOneEAX:		// м≥тка, €кщо попередн≥й б≥т одиниц€
	inc count					// зб≥льшуЇмо л≥чильник на одиницю
		jmp loopEndEAX			// стрибаЇмо в к≥нець циклу дл€ eax
		isOneEAX:				// м≥тка, €кщо б≥т одиниц€
	mov current, 1				// записуЇмо в поточний б≥т одиницю
		loopEndEAX:				// к≥нець циклу
		mov edx, current		// записуЇмо поточний б≥т в edx
		mov previous, edx		// записуЇмо edx в попередн≥й б≥т
		loop loopBeginEAX		// вертаЇмось на початок циклу eax
			
		mov ecx, 24				// ≥н≥ц≥ал≥зуЇмо л≥чильник дл€ ebx

		shl ebx, 8				// поб≥тово зсуваЇмо ebx на 8 б≥т≥в

		forEBX:
	loopBeginEBX:
		shl ebx, 1				// поб≥тово зсуваЇмо ebx на 1 б≥т
		jc isOneEBX				// м≥тка, €кщо б≥т в ebx одиниц€
		isNullEBX:				// м≥тка, €кщо б≥т в ebx нуль
	mov current, 0				// записуЇмо в поточний б≥т нуль
		cmp previous, 1			// пор≥внюЇмо попередн≥й б≥т з одиницею
		je previousIsOneEBX		// €кщо попередн≥й б≥т в ebx дор≥внюЇ одиниц≥
		previousIsNullEBX:		// €кщо попередн≥й б≥т в ebx дор≥внюЇ нулю
	jmp loopEndEBX				// стрибаЇмо в к≥нець циклу дл€ ebx
		previousIsOneEBX:		// €кщо попередн≥й б≥т в ebx дор≥внюЇ одиниц≥
	inc count                   // зб≥льшуЇмо л≥чильник на одиницю
		jmp loopEndEBX			// стрибаЇмо на м≥тку isOneEBX
		isOneEBX:
	mov current, 1              // записуЇмо в поточний б≥т одиницю
		loopEndEBX:				// к≥нець циклу ebx
		mov edx, current        // записуЇмо поточний б≥т в edx
		mov previous, edx       // записуЇмо edx в попередн≥й б≥т
		loop loopBeginEBX		// вертаЇмось на початок циклу ebx

		// останн≥й б≥т = 0
		prelastElement:
	cmp previous, 1             // пор≥внюЇмо попередн≥й б≥т з одиницею
		jne prelastIsNull		// €кщо не нуль
		inc count               // зб≥льшуЇмо л≥чильник на одиницю
		prelastIsNull:

		//очищуЇмо рег≥стри
		xor eax, eax
		xor ebx, ebx
		xor edx, edx
	}

	for (int i = 0; i < 7; i++)
	{
		cout << bitset<8>(arr[i]) << ' ';
	}

	cout << endl;
	cout << "Number of zeros after 1: " << count << endl;

	system("pause");
}