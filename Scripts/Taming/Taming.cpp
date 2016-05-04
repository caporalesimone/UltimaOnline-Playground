// Taming.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <SSRabaWrapper.h>

int main()
{
	UOWrapper uo;
	uo.InitWrapper();
	int tameable_list[] =
	{
		//0x7t,		// Hellcat (Large)
		//0x62,		// Hellhound
		//0x7a,		// Unicorn
		//0x84,		// Ki-Rin
		//0xbc,		// Savage Ridgeback
		//0xbb,		// Ridgeback
		//0x17,		// Dire Wolf
		//0xce,		// Lava Lizard
		//0x14,		// Frost spider
		//0xc9,		// Hellcat (Small)
		//0xda,		// Frenzied Ostard
		//0x50,		// Giant Toad
		0xe8,		// Bull
		0xe9,		// Bull2
					//0x22,		// White Wolf
					//0x25,		// White Wolf2
					//0x1c,		// Giant Spider
					//0xd4,		// Grizzly Bear
					//0xea,		// Great Hart
					//0x41,		// Snow leopard
					//0x40,		// Snow leopard
					//0x19,		// Gray wolf
					//0x1b,		// Gray wolf2
					//0x30,		// Scorpion
					//0xca,		// Alligator
					//0x3f,		// Cougar
					//0xa7,		// Brown Bear
					//0xdd,		// Walrus
					//0xd5,		// Polar Bear
					//0xd3,		// Black Bear
					//0xdc,		// Llama
					//0x124,	// Pack Llama
					//0x123,	// Pack Horse
					//0xc8,		// Horse
					//0xe2,		// Horse2
					//0xcc,		// Horse3
					//0xed,		// Giant Rat
					//0xdb,		// Forest Ostard
					//0xd2,		// Desert Ostard
					//0x122,	// Boar
					//0xe1,		// Timber Wolf
					//0xed,		// Hind
					//0x51,		// Bullfrog
	};



	UOWrapper uo;
	uo.InitWrapper();

	uo.UseMacro(UOWrapper::Macro::GumpControl::Open::Status);
	::Sleep(1000);



	int tameable_list_size = sizeof(tameable_list) / sizeof(tameable_list[0]);

	while (true)
	{
		int itemcount;
		REUONetCommandScanItems(true, &itemcount);

		struct Item
		{
			int ID;
			int Type;
			int Kind;
			int PosX;
			int PosY;
			int PosZ;
			int ContID;
			int Stack;
			int Reputation;
			int Color;
		};

		int index = 0xe8;
		int x, y, z, id, type, kind, contId, stack, rep, col;
		for (int index = 0; index < itemcount; index++)
		{
			REUONetCommandGetItem(index, &id, &type, &kind, &contId, &x, &y, &z, &stack, &rep, &col);
			Item iTemp;
			iTemp.ID = id;
			iTemp.Type = type;
			iTemp.Kind = kind;
			iTemp.PosX = x;
			iTemp.PosY = y;
			iTemp.PosZ = z;
			iTemp.ContID = contId;
			iTemp.Stack = stack;
			iTemp.Reputation = rep;
			iTemp.Color = col;

			if (type == 233) {
				char Name[100];
				char Info[1000];
				REUONetCommandProperty(id, Name, 100, Info, 1000);
				printf("%s\tx=%d - y=%d - z=%d\n", Name,x,y,z);
				//printf("%s\n--------------\n", Info);
				id = id;
			}
		}

		char line[100];
		int color;
		int ref; int count;
		REUONetCommandScanJournal(0, &ref, &count);
		REUONetCommandGetJournal(0, line, 100, &color);

	}

    return 0;
}

