// Manager.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Prot.h"

#include <iostream>

//char Mem[10000];



int main()
{

	int AllocMemory(int sz);
	void FreeMemory(int Handle);
	int WriteMemory(int Handle, int Offset, int Size, int* Data);
	int ReadMemory(int Handle, int Offset, int Size, int* Data);
	void Dump(void);
	int trap1 = AllocMemory(100);
	int trap2 = AllocMemory(500);
	int trap3 = AllocMemory(1000);
	int trap4 = AllocMemory(1000);
	int trap5 = AllocMemory(1000);
	int trap6 = AllocMemory(1000);
	int c[3] = { 1,2,2 };
	int a[4] = { 9,1,1,2 };
	int f[5] = { 5,2,2,1,2 };
	WriteMemory(trap1, 0, 4, a);

	WriteMemory(trap2, 0, 5, f);
	WriteMemory(trap3, 0, 4, a);
	WriteMemory(trap4, 2, 3, c);
	WriteMemory(trap5, 2, 4, a);
	WriteMemory(trap6, 2, 4, f);
	Dump();

	FreeMemory(trap1);
	FreeMemory(trap5);

	Dump();

	ReadMemory(15, 0, 5, f);





}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова откры