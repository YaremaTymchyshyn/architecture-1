


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
		xor eax, eax			// ������� eax

		//���������� eax
		mov al, arr[0]			// �������� � al �������� ��������� ��������
		shl eax, 8				// ������� ������� eax �� 8 ���
		mov al, arr[1]			// �������� � al �������� ������� ��������
		shl eax, 8				// ������� ������� eax �� 8 ���
		mov al, arr[2]			// �������� � al �������� ������� ��������
		shl eax, 8				// ������� ������� eax �� 8 ���
		mov al, arr[3]			// �������� � al �������� �������� ��������

		xor ebx, ebx			// ������� ebx

		//���������� ebx
		mov bl, arr[4]			// �������� � al �������� ���������� ��������
		shl ebx, 8				// ������� ������� eax �� 8 ���
		mov bl, arr[5]			// �������� � al �������� �'����� ��������
		shl ebx, 8				// ������� ������� eax �� 8 ���
		mov bl, arr[6]			// �������� � al �������� ������� ��������

		mov ecx, 32				// ����������� ��������� ��� ecx

		forEAX:
	loopBeginEAX:
		shl eax, 1				// ������� ������� eax �� 1 ��
		jc isOneEAX				// ����, ���� �� � eax �������
		isNullEAX:				// ����, ���� �� ����
	mov current, 0				// �������� � �������� �� ����
		cmp previous, 1			// ��������� ��������� �� � ��������
		je previousIsOneEAX		// ���� ��������� �� � eax ������� �������
		previousIsNullEAX:		// ���� ��������� �� � eax ������� ����
	jmp loopEndEAX				// �������� � ����� ����� ��� eax
		previousIsOneEAX:		// ����, ���� ��������� �� �������
	inc count					// �������� �������� �� �������
		jmp loopEndEAX			// �������� � ����� ����� ��� eax
		isOneEAX:				// ����, ���� �� �������
	mov current, 1				// �������� � �������� �� �������
		loopEndEAX:				// ����� �����
		mov edx, current		// �������� �������� �� � edx
		mov previous, edx		// �������� edx � ��������� ��
		loop loopBeginEAX		// ��������� �� ������� ����� eax
			
		mov ecx, 24				// ���������� �������� ��� ebx

		shl ebx, 8				// ������� ������� ebx �� 8 ���

		forEBX:
	loopBeginEBX:
		shl ebx, 1				// ������� ������� ebx �� 1 ��
		jc isOneEBX				// ����, ���� �� � ebx �������
		isNullEBX:				// ����, ���� �� � ebx ����
	mov current, 0				// �������� � �������� �� ����
		cmp previous, 1			// ��������� ��������� �� � ��������
		je previousIsOneEBX		// ���� ��������� �� � ebx ������� �������
		previousIsNullEBX:		// ���� ��������� �� � ebx ������� ����
	jmp loopEndEBX				// �������� � ����� ����� ��� ebx
		previousIsOneEBX:		// ���� ��������� �� � ebx ������� �������
	inc count                   // �������� �������� �� �������
		jmp loopEndEBX			// �������� �� ���� isOneEBX
		isOneEBX:
	mov current, 1              // �������� � �������� �� �������
		loopEndEBX:				// ����� ����� ebx
		mov edx, current        // �������� �������� �� � edx
		mov previous, edx       // �������� edx � ��������� ��
		loop loopBeginEBX		// ��������� �� ������� ����� ebx

		// ������� �� = 0
		prelastElement:
	cmp previous, 1             // ��������� ��������� �� � ��������
		jne prelastIsNull		// ���� �� ����
		inc count               // �������� �������� �� �������
		prelastIsNull:

		//������� �������
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