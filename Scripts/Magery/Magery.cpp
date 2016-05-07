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
		bool target_self = true;
		printf("%d - Casting spell ", cnt++);
		int base, real, cap;
		UOWrapper::Skills::LockStatus status;
		uo.GetSkill(UOWrapper::Skills::Magery, base, real, cap, status);

		if (base < 400)
		{
			printf("You need at least 40.0 Magery\n");
			exit(EXIT_FAILURE);
		}
		else if (base >= 400 && base <= 550)
		{
			uo.UseMacro(UOWrapper::Macro::Magery::Circle_4::Cast_Spell_Mana_Drain);
			printf("Mana Drain\n");
		}
		else if (base > 550 && base <= 650)
		{
			uo.UseMacro(UOWrapper::Macro::Magery::Circle_5::Cast_Spell_Paralyze);
			printf("Paralize\n");
		}
		else if (base > 650 && base <= 750)
		{
			uo.UseMacro(UOWrapper::Macro::Magery::Circle_6::Cast_Spell_Reveal);
			printf("Reveal\n");
		}
		else if (base > 750 && base <= 919)
		{
			uo.UseMacro(UOWrapper::Macro::Magery::Circle_7::Cast_Spell_Mana_Vampire);
			printf("Mana Vampire\n");
		}
		else if (base > 919)
		{
			uo.UseMacro(UOWrapper::Macro::Magery::Circle_8::Cast_Spell_Earthquake);
			printf("Earthquake\n");
			//TODO: Non richiede il target mi pare quindi usare un bool per skippare la wait for target
			target_self = false;
		}

		::Sleep(150);

		if (target_self == true)
		{
			printf("Wait for target\n");
			uo.WaitForTarget();
			printf("Target Self\n");
			::Sleep(200);
			uo.UseMacro(UOWrapper::Macro::Miscellaneous::Target_Self);
			::Sleep(1000);
		}

		int mana, max_mana;
		bool retval;
		retval = uo.GetIntegerVar(UOWrapper::CharStatus::Mana, mana);
		retval = uo.GetIntegerVar(UOWrapper::CharStatus::MaxMana, max_mana);
		if (mana <= 60)
		{
			printf("No Mana\n");
			::Sleep(2000);
			while (mana < max_mana)
			{
				printf("Meditation\n");
				uo.UseMacro(UOWrapper::Macro::UseSkill::Meditation);
				::Sleep(10000);
				retval = uo.GetIntegerVar(UOWrapper::CharStatus::Mana, mana);
				printf("\t Mana: %d/%d\n", mana, max_mana);
				//::Sleep(1000);
			}
		}
		::Sleep(2500);
		printf("Cycle done\n\n");
	}



	return 0;
}

