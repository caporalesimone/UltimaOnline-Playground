// Magery.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <SSRabaWrapper.h>


int main()
{
	UOWrapper uo;
	if (uo.InitWrapper() == false) return 0;

	int cnt = 1;
	while (true)
	{
		printf("%d - Cast spell\n", cnt++);
		uo.UseMacro(UOWrapper::Macro::Magery::Circle_7::Cast_Spell_Mana_Vampire);
		::Sleep(150);
		printf("Wait for target\n");
		uo.WaitForTarget();
		printf("Target Self\n");
		::Sleep(200);
		uo.UseMacro(UOWrapper::Macro::Miscellaneous::Target_Self);
		::Sleep(1000);
		int mana, max_mana;
		bool retval;
		retval = uo.GetIntegerVar(UOWrapper::CharStatus::Mana, mana);
		retval = uo.GetIntegerVar(UOWrapper::CharStatus::MaxMana, max_mana);
		if (mana <= 35)
		{
			/*
			printf("No Mana\n");
			::Sleep(2000);
			printf("Meditation\n");
			uo.UseMacro(UOWrapper::Macro::UseSkill::Meditation);
			::Sleep(10000);
			printf("Hiding\n");
			uo.UseMacro(UOWrapper::Macro::UseSkill::Hiding);
			::Sleep(10000);
			*/
			printf("Wait for Mana\n");
			while (mana < max_mana)
			{
				retval = uo.GetIntegerVar(UOWrapper::CharStatus::Mana, mana);
				printf("\t Mana: %d/%d\n", mana, max_mana);
				::Sleep(1000);
			}
		}
		::Sleep(2500);
		printf("Cycle done\n\n");
	}



	return 0;
}

