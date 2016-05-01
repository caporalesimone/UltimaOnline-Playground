#include "SSRabaWrapper.h"
#include <RabaEUOdotNET.h>

#define MAX_STRING_LENGTH 512

UOWrapper::UOWrapper()
{
	// Character Info
	CommandsList[CharInfo::CharPos_X] = "CharPosX";
	CommandsList[CharInfo::CharPos_Y] = "CharPosY";
	CommandsList[CharInfo::CharPos_Z] = "CharPosZ";
	CommandsList[CharInfo::Char_Dir] = "CharDir";
	CommandsList[CharInfo::Char_Status] = "CharStatus";
	CommandsList[CharInfo::Char_ID] = "CharID";
	CommandsList[CharInfo::Char_Type] = "CharType";
	CommandsList[CharInfo::Char_Ghost] = "CharGhost"; // ??????? Testare
	CommandsList[CharInfo::Char_BackPack_ID] = "BackpackID";

	//Character Status
	CommandsList[CharStatus::CharName] = "CharName";
	CommandsList[CharStatus::Sex] = "Sex";
	CommandsList[CharStatus::Str] = "Str";
	CommandsList[CharStatus::Dex] = "Dex";
	CommandsList[CharStatus::Int] = "Int";
	CommandsList[CharStatus::Hits] = "Hits";
	CommandsList[CharStatus::MaxHits] = "MaxHits";
	CommandsList[CharStatus::Stamina] = "Stamina";
	CommandsList[CharStatus::MaxStam] = "MaxStam";
	CommandsList[CharStatus::Mana] = "Mana";
	CommandsList[CharStatus::MaxMana] = "MaxMana";
	CommandsList[CharStatus::MaxStats] = "MaxStats";
	CommandsList[CharStatus::Luck] = "Luck";
	CommandsList[CharStatus::Weight] = "Weight";
	CommandsList[CharStatus::MaxWeight] = "MaxWeight";
	CommandsList[CharStatus::MinDmg] = "MinDmg";
	CommandsList[CharStatus::MaxDmg] = "MaxDmg";
	CommandsList[CharStatus::Gold] = "Gold";
	CommandsList[CharStatus::Followers] = "Followers";
	CommandsList[CharStatus::MaxFol] = "MaxFol";
	CommandsList[CharStatus::AR] = "AR";
	CommandsList[CharStatus::FR] = "FR";
	CommandsList[CharStatus::CR] = "CR";
	CommandsList[CharStatus::PR] = "PR";
	CommandsList[CharStatus::ER] = "ER";
	CommandsList[CharStatus::TP] = "TP";

	CommandsList[Extended_info::TargCurs] = "TargCurs";

	// Speech
	MacroList[Macro::Speech::Say] = std::make_pair(1, 0);
	MacroList[Macro::Speech::Emote] = std::make_pair(2, 0);
	MacroList[Macro::Speech::Whisper] = std::make_pair(3, 0);
	MacroList[Macro::Speech::Yell] = std::make_pair(4, 4);

	// Movements
	MacroList[Macro::Movements::Walk_North_West] = std::make_pair(5, 0);
	MacroList[Macro::Movements::Walk_North] = std::make_pair(5, 1);
	MacroList[Macro::Movements::Walk_North_East] = std::make_pair(5, 2);
	MacroList[Macro::Movements::Walk_East] = std::make_pair(5, 3);
	MacroList[Macro::Movements::Walk_South_East] = std::make_pair(5, 4);
	MacroList[Macro::Movements::Walk_South] = std::make_pair(5, 5);
	MacroList[Macro::Movements::Walk_South_West] = std::make_pair(5, 6);
	MacroList[Macro::Movements::Walk_West] = std::make_pair(5, 7);

	// Gump Control
	MacroList[Macro::GumpControl::Open::Configuration] = std::make_pair(8, 0);
	MacroList[Macro::GumpControl::Open::Paperdoll] = std::make_pair(8, 1);
	MacroList[Macro::GumpControl::Open::Status] = std::make_pair(8, 2);
	MacroList[Macro::GumpControl::Open::Journal] = std::make_pair(8, 3);
	MacroList[Macro::GumpControl::Open::Skills] = std::make_pair(8, 4);
	MacroList[Macro::GumpControl::Open::Spellbook] = std::make_pair(8, 5);
	MacroList[Macro::GumpControl::Open::Chat] = std::make_pair(8, 6);
	MacroList[Macro::GumpControl::Open::Backpack] = std::make_pair(8, 7);
	MacroList[Macro::GumpControl::Open::Overview] = std::make_pair(8, 8);
	MacroList[Macro::GumpControl::Open::Mail] = std::make_pair(8, 9);
	MacroList[Macro::GumpControl::Open::Party_Manifest] = std::make_pair(8, 10);
	MacroList[Macro::GumpControl::Open::Party_Chat] = std::make_pair(8, 11);
	MacroList[Macro::GumpControl::Open::Necro_Spellbook] = std::make_pair(8, 12);
	MacroList[Macro::GumpControl::Open::Paladin_Spellbook] = std::make_pair(8, 13);
	MacroList[Macro::GumpControl::Open::Combat_Book] = std::make_pair(8, 14);
	MacroList[Macro::GumpControl::Open::Bushido_Spellbook] = std::make_pair(8, 15);
	MacroList[Macro::GumpControl::Open::Ninjutsu_Spellbook] = std::make_pair(8, 16);
	MacroList[Macro::GumpControl::Open::Guild] = std::make_pair(8, 17);
	MacroList[Macro::GumpControl::Open::Spellweaving_SpellBook] = std::make_pair(8, 18);
	MacroList[Macro::GumpControl::Open::Questlog] = std::make_pair(8, 19);

	MacroList[Macro::GumpControl::Close::Configuration] = std::make_pair(9, 0);
	MacroList[Macro::GumpControl::Close::Paperdoll] = std::make_pair(9, 1);
	MacroList[Macro::GumpControl::Close::Status] = std::make_pair(9, 2);
	MacroList[Macro::GumpControl::Close::Journal] = std::make_pair(9, 3);
	MacroList[Macro::GumpControl::Close::Skills] = std::make_pair(9, 4);
	MacroList[Macro::GumpControl::Close::Spellbook] = std::make_pair(9, 5);
	MacroList[Macro::GumpControl::Close::Chat] = std::make_pair(9, 6);
	MacroList[Macro::GumpControl::Close::Backpack] = std::make_pair(9, 7);
	MacroList[Macro::GumpControl::Close::Overview] = std::make_pair(9, 9);
	MacroList[Macro::GumpControl::Close::Mail] = std::make_pair(9, 9);
	MacroList[Macro::GumpControl::Close::Party_Manifest] = std::make_pair(9, 10);
	MacroList[Macro::GumpControl::Close::Party_Chat] = std::make_pair(9, 11);
	MacroList[Macro::GumpControl::Close::Necro_Spellbook] = std::make_pair(9, 12);
	MacroList[Macro::GumpControl::Close::Paladin_Spellbook] = std::make_pair(9, 13);
	MacroList[Macro::GumpControl::Close::Combat_Book] = std::make_pair(9, 14);
	MacroList[Macro::GumpControl::Close::Bushido_Spellbook] = std::make_pair(9, 15);
	MacroList[Macro::GumpControl::Close::Ninjutsu_Spellbook] = std::make_pair(9, 16);
	MacroList[Macro::GumpControl::Close::Guild] = std::make_pair(9, 17);

	MacroList[Macro::GumpControl::Minimize::Paperdoll] = std::make_pair(10, 1);
	MacroList[Macro::GumpControl::Minimize::Status] = std::make_pair(10, 2);
	MacroList[Macro::GumpControl::Minimize::Journal] = std::make_pair(10, 3);
	MacroList[Macro::GumpControl::Minimize::Skills] = std::make_pair(10, 4);
	MacroList[Macro::GumpControl::Minimize::Spellbook] = std::make_pair(10, 5);
	MacroList[Macro::GumpControl::Minimize::Chat] = std::make_pair(10, 6);
	MacroList[Macro::GumpControl::Minimize::Backpack] = std::make_pair(10, 7);
	MacroList[Macro::GumpControl::Minimize::Overview] = std::make_pair(10, 8);
	MacroList[Macro::GumpControl::Minimize::Mail] = std::make_pair(10, 9);
	MacroList[Macro::GumpControl::Minimize::Party_Manifest] = std::make_pair(10, 10);
	MacroList[Macro::GumpControl::Minimize::Party_Chat] = std::make_pair(10, 11);
	MacroList[Macro::GumpControl::Minimize::Necro_Spellbook] = std::make_pair(10, 12);
	MacroList[Macro::GumpControl::Minimize::Paladin_Spellbook] = std::make_pair(10, 13);
	MacroList[Macro::GumpControl::Minimize::Combat_Book] = std::make_pair(10, 14);
	MacroList[Macro::GumpControl::Minimize::Bushido_Spellbook] = std::make_pair(10, 15);
	MacroList[Macro::GumpControl::Minimize::Ninjutsu_Spellbook] = std::make_pair(10, 16);
	MacroList[Macro::GumpControl::Minimize::Guild] = std::make_pair(10, 17);

	MacroList[Macro::GumpControl::Minimize::Paperdoll] = std::make_pair(11, 1);
	MacroList[Macro::GumpControl::Maximize::Status] = std::make_pair(11, 2);
	MacroList[Macro::GumpControl::Maximize::Journal] = std::make_pair(11, 3);
	MacroList[Macro::GumpControl::Maximize::Skills] = std::make_pair(11, 4);
	MacroList[Macro::GumpControl::Maximize::Spellbook] = std::make_pair(11, 5);
	MacroList[Macro::GumpControl::Maximize::Chat] = std::make_pair(11, 6);
	MacroList[Macro::GumpControl::Maximize::Backpack] = std::make_pair(11, 7);
	MacroList[Macro::GumpControl::Maximize::Overview] = std::make_pair(11, 8);
	MacroList[Macro::GumpControl::Maximize::Mail] = std::make_pair(11, 9);
	MacroList[Macro::GumpControl::Maximize::Party_Manifest] = std::make_pair(11, 10);
	MacroList[Macro::GumpControl::Maximize::Party_Chat] = std::make_pair(11, 11);
	MacroList[Macro::GumpControl::Maximize::Necro_Spellbook] = std::make_pair(11, 12);
	MacroList[Macro::GumpControl::Maximize::Paladin_Spellbook] = std::make_pair(11, 13);
	MacroList[Macro::GumpControl::Maximize::Combat_Book] = std::make_pair(11, 14);
	MacroList[Macro::GumpControl::Maximize::Bushido_Spellbook] = std::make_pair(11, 15);
	MacroList[Macro::GumpControl::Maximize::Ninjutsu_Spellbook] = std::make_pair(11, 16);
	MacroList[Macro::GumpControl::Maximize::Guild] = std::make_pair(11, 17);

	// Use Skill
	MacroList[Macro::UseSkill::Anatomy] = std::make_pair(13, 1);
	MacroList[Macro::UseSkill::Animal_Lore] = std::make_pair(13, 2);
	MacroList[Macro::UseSkill::Animal_Taming] = std::make_pair(13, 35);
	MacroList[Macro::UseSkill::Arms_Lore] = std::make_pair(13, 4);
	MacroList[Macro::UseSkill::Begging] = std::make_pair(13, 6);
	MacroList[Macro::UseSkill::Cartography] = std::make_pair(13, 12);
	MacroList[Macro::UseSkill::Detecting_Hidden] = std::make_pair(13, 14);
	MacroList[Macro::UseSkill::Discordance] = std::make_pair(13, 15);
	MacroList[Macro::UseSkill::Evaluating_Intelligence] = std::make_pair(13, 16);
	MacroList[Macro::UseSkill::Forensic_Evaluation] = std::make_pair(13, 19);
	MacroList[Macro::UseSkill::Hiding] = std::make_pair(13, 21);
	MacroList[Macro::UseSkill::Inscription] = std::make_pair(13, 23);
	MacroList[Macro::UseSkill::Item_Identification] = std::make_pair(13, 3);
	MacroList[Macro::UseSkill::Meditation] = std::make_pair(13, 46);
	MacroList[Macro::UseSkill::Peacemaking] = std::make_pair(13, 9);
	MacroList[Macro::UseSkill::Poisoning] = std::make_pair(13, 30);
	MacroList[Macro::UseSkill::Provocation] = std::make_pair(13, 22);
	MacroList[Macro::UseSkill::Remove_Trap] = std::make_pair(13, 48);
	MacroList[Macro::UseSkill::Spirit_Speak] = std::make_pair(13, 32);
	MacroList[Macro::UseSkill::Stealing] = std::make_pair(13, 33);
	MacroList[Macro::UseSkill::Stealth] = std::make_pair(13, 47);
	MacroList[Macro::UseSkill::Taste_Identification] = std::make_pair(13, 36);
	MacroList[Macro::UseSkill::Tracking] = std::make_pair(13, 38);
	MacroList[Macro::UseSkill::Imbuing] = std::make_pair(13, 56);
	MacroList[Macro::UseSkill::Use_Last_Skill] = std::make_pair(14, 0);

	// Magery

	MacroList[Macro::Magery::Circle_1::Cast_Spell_Clumsy] = std::make_pair(15, 0);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Create_Food] = std::make_pair(15, 1);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Feeblemind] = std::make_pair(15, 2);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Heal] = std::make_pair(15, 3);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Magic_Arrow] = std::make_pair(15, 4);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Night_Sight] = std::make_pair(15, 5);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Reactive_Armor] = std::make_pair(15, 6);
	MacroList[Macro::Magery::Circle_1::Cast_Spell_Weaken] = std::make_pair(15, 7);

	MacroList[Macro::Magery::Circle_2::Cast_Spell_Agility] = std::make_pair(15, 8);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Cunning] = std::make_pair(15, 9);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Cure] = std::make_pair(15, 10);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Harm] = std::make_pair(15, 11);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Magic_Trap] = std::make_pair(15, 12);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Magic_Untrap] = std::make_pair(15, 13);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Protection] = std::make_pair(15, 14);
	MacroList[Macro::Magery::Circle_2::Cast_Spell_Strength] = std::make_pair(15, 15);

	MacroList[Macro::Magery::Circle_3::Cast_Spell_Bless] = std::make_pair(15, 16);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Fireball] = std::make_pair(15, 17);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Magic_Lock] = std::make_pair(15, 18);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Poison] = std::make_pair(15, 19);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Telekinesis] = std::make_pair(15, 20);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Teleport] = std::make_pair(15, 21);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Unlock] = std::make_pair(15, 22);
	MacroList[Macro::Magery::Circle_3::Cast_Spell_Wall_Of_Stone] = std::make_pair(15, 23);

	MacroList[Macro::Magery::Circle_4::Cast_Spell_Arch_Cure] = std::make_pair(15, 24);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Arch_Protection] = std::make_pair(15, 25);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Curse] = std::make_pair(15, 26);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Fire_Field] = std::make_pair(15, 27);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Greater_Heal] = std::make_pair(15, 28);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Lightning] = std::make_pair(15, 29);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Mana_Drain] = std::make_pair(15, 30);
	MacroList[Macro::Magery::Circle_4::Cast_Spell_Recall] = std::make_pair(15, 31);

	MacroList[Macro::Magery::Circle_5::Cast_Spell_Blade_Spirits] = std::make_pair(15, 32);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Dispel_Field] = std::make_pair(15, 33);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Incognito] = std::make_pair(15, 34);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Magic_Reflection] = std::make_pair(15, 35);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Mind_Blast] = std::make_pair(15, 36);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Paralyze] = std::make_pair(15, 37);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Poison_Field] = std::make_pair(15, 38);
	MacroList[Macro::Magery::Circle_5::Cast_Spell_Summon_Creature] = std::make_pair(15, 39);

	MacroList[Macro::Magery::Circle_6::Cast_Spell_Dispel] = std::make_pair(15, 40);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Energy_Bolt] = std::make_pair(15, 41);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Explosion] = std::make_pair(15, 42);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Invisibility] = std::make_pair(15, 43);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Mark] = std::make_pair(15, 44);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Mass_Curse] = std::make_pair(15, 45);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Paralyze_Field] = std::make_pair(15, 46);
	MacroList[Macro::Magery::Circle_6::Cast_Spell_Reveal] = std::make_pair(15, 47);

	MacroList[Macro::Magery::Circle_7::Cast_Spell_Chain_Lightning] = std::make_pair(15, 48);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Energy_Field] = std::make_pair(15, 49);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Flame_Strike] = std::make_pair(15, 50);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Gate_Travel] = std::make_pair(15, 51);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Mana_Vampire] = std::make_pair(15, 52);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Mass_Dispel] = std::make_pair(15, 53);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Meteor_Swarm] = std::make_pair(15, 54);
	MacroList[Macro::Magery::Circle_7::Cast_Spell_Polymorph] = std::make_pair(15, 55);

	MacroList[Macro::Magery::Circle_8::Cast_Spell_Earthquake] = std::make_pair(15, 56);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Energy_Vortex] = std::make_pair(15, 57);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Resurrection] = std::make_pair(15, 58);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Air_Elemental] = std::make_pair(15, 59);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Summon_Daemon] = std::make_pair(15, 60);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Earth_Elemental] = std::make_pair(15, 61);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Fire_Elemental] = std::make_pair(15, 62);
	MacroList[Macro::Magery::Circle_8::Cast_Spell_Water_Elemental] = std::make_pair(15, 63);

	// Miscellaneous
	MacroList[Macro::Miscellaneous::Last_Spell] = std::make_pair(16, 0);
	MacroList[Macro::Miscellaneous::Last_Object] = std::make_pair(17, 0);
	MacroList[Macro::Miscellaneous::Bow] = std::make_pair(18, 0);
	MacroList[Macro::Miscellaneous::Salute] = std::make_pair(19, 0);
	MacroList[Macro::Miscellaneous::Quit_Game] = std::make_pair(20, 0);
	MacroList[Macro::Miscellaneous::All_Names] = std::make_pair(21, 0);
	MacroList[Macro::Miscellaneous::Last_Target] = std::make_pair(22, 0);
	MacroList[Macro::Miscellaneous::Target_Self] = std::make_pair(23, 0);
	MacroList[Macro::Miscellaneous::Arm_Disarm_Left] = std::make_pair(24, 1);
	MacroList[Macro::Miscellaneous::Arm_Disarm_Right] = std::make_pair(24, 2);
	MacroList[Macro::Miscellaneous::Wait_For_Target] = std::make_pair(25, 0);
	MacroList[Macro::Miscellaneous::Target_Next] = std::make_pair(26, 0);
	MacroList[Macro::Miscellaneous::Attack_Last] = std::make_pair(27, 0);
	MacroList[Macro::Miscellaneous::Delay] = std::make_pair(28, 0);
	MacroList[Macro::Miscellaneous::Circletrans] = std::make_pair(29, 0);
	MacroList[Macro::Miscellaneous::Close_Gumps] = std::make_pair(31, 0);
	MacroList[Macro::Miscellaneous::Always_Run] = std::make_pair(32, 0);
	MacroList[Macro::Miscellaneous::Save_Desktop] = std::make_pair(33, 0);
	MacroList[Macro::Miscellaneous::Kill_Gump_Open] = std::make_pair(34, 0);
	MacroList[Macro::Miscellaneous::Primary_Ability] = std::make_pair(35, 0);
	MacroList[Macro::Miscellaneous::Secondary_Ability] = std::make_pair(36, 0);
	MacroList[Macro::Miscellaneous::Equip_Last_Weapon] = std::make_pair(37, 0);

}

UOWrapper::~UOWrapper()
{
	CloseWrapper();
}

bool UOWrapper::InitWrapper(void)
{
	bool pass = REUONetInit();
	if (pass == false) return false;
	::Sleep(500);
	pass = REUONetOpen();
	if (pass == false) return false;
	::Sleep(500);
	REUONetCommandSysMessage("SimonSoft (c)2016 - Script Started");
	::Sleep(500);
	return pass;
}

void UOWrapper::CloseWrapper(void)
{
	REUONetClose();
	REUONetFree();
}

bool UOWrapper::GetStringVar(const int& varName, std::string& value)
{
	char out_val[MAX_STRING_LENGTH] = { 0 };
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetGetStringVar((char*)command.c_str(), (char*)&out_val, MAX_STRING_LENGTH);
	if (retVal == -1) return false;
	value = std::string(out_val);
	return true;
}

bool UOWrapper::GetIntegerVar(const int& varName, int& value)
{
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetGetIntegerVar((char*)command.c_str(), &value);
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::GetBooleanVar(const int& varName, bool& value)
{
	BOOL boolval;
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetGetBooleanVar((char*)command.c_str(), &boolval);
	value = (boolval != 0) ? true : false; // 255 = true, 0 = false;
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::SetStringVar(const int& varName, const std::string& value)
{
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetSetStringVar((char*)command.c_str(), (char*)value.c_str());
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::SetIntegerVar(const int& varName, const int& value)
{
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetSetIntegerVar((char*)command.c_str(), value);
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::SetBooleanVar(const int& varName, const bool& value)
{
	std::string command = CommandsList[varName].c_str();
	int retVal = REUONetSetBooleanVar((char*)command.c_str(), value);
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::UseMacro(const int& Macro)
{
	return UseMacro(Macro, "");
}

bool UOWrapper::UseMacro(const int& Macro, const std::string& Text)
{
	std::pair<int, int> params = MacroList[Macro];
	int retVal = REUONetCommandMacro(params.first, params.second, (char*)Text.c_str());
	if (retVal == -1) return false;
	return true;
}

bool UOWrapper::WaitForTarget(const int& Timeout)
{
	const int sleeptime = 50; // Sleep 50ms
	BOOL target = false;
	std::string command = CommandsList[Extended_info::TargCurs].c_str();
	int count = Timeout / sleeptime;
	while ((target == false) && (count-- > 0))
	{
		int retVal = REUONetGetBooleanVar((char*)command.c_str(), &target);
		if (retVal == -1) return false;
		::Sleep(sleeptime);
	}

	bool retval = (target != 0) ? true : false; // 255 = true, 0 = false;
	return (bool)target;
}
