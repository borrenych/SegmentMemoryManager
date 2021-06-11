#pragma once

#include <iostream>
int H = 0;


int Mem[10000];

struct Segment
{
	int Start;
	int sz;
	int Busy;
	int Handle;
};

Segment MassSeg[50] = { NULL };

int AllocMemory(int sz)
{
	int i = 0;
	int SizeSeg = 0;
	for (i; i < 50; i++)
	{
		if (MassSeg[i].Handle != 0)
		{
			SizeSeg += MassSeg[i].sz;
			if (SizeSeg + sz > 10000)
			{

				return 0;
			}
		}
		else
		{
			MassSeg[i].Start = SizeSeg;
			MassSeg[i].sz = sz;
			MassSeg[i].Busy = 0;
			MassSeg[i].Handle = ++H;
			return MassSeg[i].Handle;

		}

	}



}
void FreeMemory(int Handle)
{
	int i = 0;



	for (i; i < 50; i++)
	{
		if (MassSeg[i].Handle == Handle)
		{
			if (MassSeg[i].Handle == H)
			{
				MassSeg[i].Start = 0;
				MassSeg[i].sz = 0;
				MassSeg[i].Busy = 0;
				MassSeg[i].Handle = 0;
			}
			else
			{

				MassSeg[i].Handle = 0;
				MassSeg[i].Busy = MassSeg[i + 1].Busy;


				while (MassSeg[i + 1].Handle != 0)
				{
					MassSeg[i].sz = MassSeg[i + 1].sz;
					MassSeg[i].Handle = MassSeg[i + 1].Handle;






					for (int g = 0; g <= MassSeg[i + 1].sz; g++)
					{
						Mem[MassSeg[i].Start + g] = Mem[MassSeg[i + 1].Start + g];
					}
					MassSeg[i + 1].Start = MassSeg[i].Start + MassSeg[i].sz;
					MassSeg[i].Busy = MassSeg[i + 1].Busy;
					i++;
				}
				MassSeg[i].Handle = 0;

				MassSeg[i].Busy = 0;
				//MassSeg[i].Start = MassSeg[i - 1].Start + MassSeg[i - 1].sz;

			}
		}
	}

}
int WriteMemory(int Handle, int Offset, int Size, int* Data)
{
	int i = 0;
	for (i; i < 50; i++)
	{
		if (MassSeg[i].Handle == Handle)
		{
			if (Offset + Size > MassSeg[i].sz)
				return 1;
			else
			{
				MassSeg[i].Busy = 1;
				int start = MassSeg[i].Start + Offset;
				for (int g = 0; g < Size; g++)
				{
					Mem[start + g] = Data[g];
				}

				return 0;
			}
		}
	}





}
int ReadMemory(int Handle, int Offset, int Size, int* Data)
{
	int i = 0;
	for (i; i < 50; i++)
	{
		if (MassSeg[i].Handle == Handle)
		{
			if (Offset + Size > MassSeg[i].sz)
				return 1;
			else
			{
				int start = MassSeg[i].Start + Offset;
				for (int g = 0; g < Size; g++)
				{
					std::cout << Mem[start + g];
				}
				return 0;
			}
		}
	}


}
void Dump(void)
{
	int p = 0;
	int SizeSeg = 0;
	for (int k = 0; k < 50; k++)
	{

		if (MassSeg[k].Handle != 0)
		{
			SizeSeg += MassSeg[k].sz;
			std::cout << "\nBlock";
			std::cout << "\nH: ";
			std::cout << MassSeg[k].Handle;
			std::cout << " Start: ";
			std::cout << MassSeg[k].Start;
			std::cout << " Size: ";
			std::cout << MassSeg[k].sz;
			std::cout << " Busy: ";
			if (MassSeg[k].Busy == 1)
				std::cout << "Yes";
			else
				std::cout << "No";
			std::cout << " Bytes: ";
			int start = MassSeg[k].Start;
			if (MassSeg[k].sz < 10)
				p = MassSeg[k].sz;
			else
				p = 10;
			for (int g = 0; g < p; g++)
			{
				std::cout << " ";
				std::cout << Mem[start + g];
			}

		}
	}
	std::cout << "\nFreeMem = ";
	std::cout << 10000 - SizeSeg;
}

