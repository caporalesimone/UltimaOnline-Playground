#pragma once

#include <map>


class UOWrapper
{
public:
	struct CharInfo
	{
		enum
		{
			CharPos_X = 0,
			CharPos_Y = 1,
			CharPos_Z = 2,
			Char_Dir = 3,
			Char_Status = 4,
			Char_ID = 5,
			Char_Type = 6,
			Char_Ghost = 7,
			Char_BackPack_ID = 8,
		};
	};

	struct CharStatus
	{
		enum
		{
			CharName = 20,
			Sex = 21,
			Str = 22,
			Dex = 23,
			Int = 24,
			Hits = 25,
			MaxHits = 26,
			Stamina = 27,
			MaxStam = 28,
			Mana = 29,
			MaxMana = 30,
			MaxStats = 31,
			Luck = 32,
			Weight = 33,
			MaxWeight = 34,
			MinDmg = 35,
			MaxDmg = 36,
			Gold = 37,
			Followers = 38,
			MaxFol = 39,
			AR = 40,
			FR = 41,
			CR = 42,
			PR = 43,
			ER = 44,
			TP = 45,
		};
	};


	// http://wiki.easyuo.com/index.php/Event_Macro
	struct Macro
	{
		struct Speech
		{
			enum
			{
				Say = 50,
				Emote = 51,
				Whisper = 52,
				Yell = 53,
			};
		};

		struct Movements
		{
			enum
			{
				Walk_North_West = 60,
				Walk_North = 61,
				Walk_North_East = 62,
				Walk_East = 63,
				Walk_South_East = 64,
				Walk_South = 65,
				Walk_South_West = 66,
				Walk_West = 67,
			};
		};

		struct WarPeace_Paste
		{
			enum
			{
				E_TODO_1 = 70,
				E_TODO_2 = 79,
			};
		};

		struct GumpControl
		{
			struct Open
			{
				enum
				{
					Configuration = 80,
					Paperdoll = 81,
					Status = 82,
					Journal = 83,
					Skills = 84,
					Spellbook = 85,
					Chat = 86,
					Backpack = 87,
					Overview = 88,
					Mail = 89,
					Party_Manifest = 90,
					Party_Chat = 91,
					Necro_Spellbook = 92,
					Paladin_Spellbook = 93,
					Combat_Book = 94,
					Bushido_Spellbook = 95,
					Ninjutsu_Spellbook = 96,
					Guild = 97,
					Spellweaving_SpellBook = 98,
					Questlog = 99,
				};
			};

			struct Close
			{
				enum
				{
					Configuration = 110,
					Paperdoll = 111,
					Status = 112,
					Journal = 113,
					Skills = 114,
					Spellbook = 115,
					Chat = 116,
					Backpack = 117,
					Overview = 118,
					Mail = 119,
					Party_Manifest = 120,
					Party_Chat = 121,
					Necro_Spellbook = 122,
					Paladin_Spellbook = 123,
					Combat_Book = 124,
					Bushido_Spellbook = 125,
					Ninjutsu_Spellbook = 126,
					Guild = 127,
				};
			};

			struct Minimize
			{
				enum
				{
					Paperdoll = 130,
					Status = 131,
					Journal = 132,
					Skills = 133,
					Spellbook = 134,
					Chat = 135,
					Backpack = 136,
					Overview = 137,
					Mail = 138,
					Party_Manifest = 139,
					Party_Chat = 140,
					Necro_Spellbook = 141,
					Paladin_Spellbook = 142,
					Combat_Book = 143,
					Bushido_Spellbook = 144,
					Ninjutsu_Spellbook = 145,
					Guild = 146,
				};
			};

			struct Maximize
			{
				enum
				{
					Paperdoll = 150,
					Status = 151,
					Journal = 152,
					Skills = 153,
					Spellbook = 154,
					Chat = 155,
					Backpack = 156,
					Overview = 157,
					Mail = 158,
					Party_Manifest = 159,
					Party_Chat = 160,
					Necro_Spellbook = 161,
					Paladin_Spellbook = 162,
					Combat_Book = 163,
					Bushido_Spellbook = 164,
					Ninjutsu_Spellbook = 165,
					Guild = 166,
				};
			};
		};

		struct OpenDoor
		{
			enum
			{
				E_TODO_1 = 190,
			};
		};

		struct UseSkill
		{
			enum
			{
				Anatomy = 200,
				Animal_Lore = 201,
				Animal_Taming = 202,
				Arms_Lore = 203,
				Begging = 204,
				Cartography = 205,
				Detecting_Hidden = 206,
				Discordance = 207,
				Evaluating_Intelligence = 208,
				Forensic_Evaluation = 209,
				Hiding = 210,
				Inscription = 211,
				Item_Identification = 212,
				Meditation = 213,
				Peacemaking = 214,
				Poisoning = 215,
				Provocation = 216,
				Remove_Trap = 217,
				Spirit_Speak = 218,
				Stealing = 219,
				Stealth = 220,
				Taste_Identification = 221,
				Tracking = 222,
				Imbuing = 223,
				Use_Last_Skill = 224,
			};
		};

		struct Magery
		{
			struct Circle_1
			{
				enum
				{
					Cast_Spell_Clumsy = 300,
					Cast_Spell_Create_Food = 301,
					Cast_Spell_Feeblemind = 302,
					Cast_Spell_Heal = 303,
					Cast_Spell_Magic_Arrow = 304,
					Cast_Spell_Night_Sight = 305,
					Cast_Spell_Reactive_Armor = 306,
					Cast_Spell_Weaken = 307,
				};
			};

			struct Circle_2
			{
				enum
				{
					Cast_Spell_Agility = 308,
					Cast_Spell_Cunning = 309,
					Cast_Spell_Cure = 310,
					Cast_Spell_Harm = 311,
					Cast_Spell_Magic_Trap = 312,
					Cast_Spell_Magic_Untrap = 313,
					Cast_Spell_Protection = 314,
					Cast_Spell_Strength = 315,
				};
			};

			struct Circle_3
			{
				enum
				{
					Cast_Spell_Bless = 316,
					Cast_Spell_Fireball = 317,
					Cast_Spell_Magic_Lock = 318,
					Cast_Spell_Poison = 319,
					Cast_Spell_Telekinesis = 320,
					Cast_Spell_Teleport = 321,
					Cast_Spell_Unlock = 322,
					Cast_Spell_Wall_Of_Stone = 323,
				};
			};

			struct Circle_4
			{
				enum
				{
					Cast_Spell_Arch_Cure = 324,
					Cast_Spell_Arch_Protection = 325,
					Cast_Spell_Curse = 326,
					Cast_Spell_Fire_Field = 327,
					Cast_Spell_Greater_Heal = 328,
					Cast_Spell_Lightning = 329,
					Cast_Spell_Mana_Drain = 330,
					Cast_Spell_Recall = 331,
				};
			};

			struct Circle_5
			{
				enum
				{
					Cast_Spell_Blade_Spirits = 332,
					Cast_Spell_Dispel_Field = 333,
					Cast_Spell_Incognito = 334,
					Cast_Spell_Magic_Reflection = 335,
					Cast_Spell_Mind_Blast = 336,
					Cast_Spell_Paralyze = 337,
					Cast_Spell_Poison_Field = 338,
					Cast_Spell_Summon_Creature = 339,
				};
			};

			struct Circle_6
			{
				enum
				{
					Cast_Spell_Dispel = 340,
					Cast_Spell_Energy_Bolt = 341,
					Cast_Spell_Explosion = 342,
					Cast_Spell_Invisibility = 343,
					Cast_Spell_Mark = 344,
					Cast_Spell_Mass_Curse = 345,
					Cast_Spell_Paralyze_Field = 346,
					Cast_Spell_Reveal = 347,
				};
			};

			struct Circle_7
			{
				enum
				{
					Cast_Spell_Chain_Lightning = 348,
					Cast_Spell_Energy_Field = 349,
					Cast_Spell_Flame_Strike = 350,
					Cast_Spell_Gate_Travel = 351,
					Cast_Spell_Mana_Vampire = 352,
					Cast_Spell_Mass_Dispel = 353,
					Cast_Spell_Meteor_Swarm = 354,
					Cast_Spell_Polymorph = 355,
				};
			};

			struct Circle_8
			{
				enum
				{
					Cast_Spell_Earthquake = 356,
					Cast_Spell_Energy_Vortex = 357,
					Cast_Spell_Resurrection = 358,
					Cast_Spell_Air_Elemental = 359,
					Cast_Spell_Summon_Daemon = 360,
					Cast_Spell_Earth_Elemental = 361,
					Cast_Spell_Fire_Elemental = 362,
					Cast_Spell_Water_Elemental = 363,
				};
			};
		};

		struct Necromancy
		{
			enum
			{
				E_TODO_1 = 400,
				E_TODO_2 = 449,
			};
		};

		struct Bushido
		{
			enum
			{
				E_TODO_1 = 450,
				E_TODO_2 = 499,
			};
		};

		struct Chivalry
		{
			enum
			{
				E_TODO_1 = 500,
				E_TODO_2 = 549,
			};
		};

		struct Ninja_Moves
		{
			enum
			{
				E_TODO_1 = 550,
				E_TODO_2 = 599,
			};
		};

		struct Spellweaving
		{
			enum
			{
				E_TODO_1 = 600,
				E_TODO_2 = 649,
			};
		};

		struct Mysticism
		{
			enum
			{
				E_TODO_1 = 650,
				E_TODO_2 = 699,
			};
		};

		struct Miscellaneous
		{
			enum
			{
				Last_Spell = 700,
				Last_Object = 701,
				Bow = 702,
				Salute = 703,
				Quit_Game = 704,
				All_Names = 705,
				Last_Target = 706,
				Target_Self = 707,
				Arm_Disarm_Left = 708,
				Arm_Disarm_Right = 709,
				Wait_For_Target = 710,
				Target_Next = 711,
				Attack_Last = 712,
				Delay = 713,
				Circletrans = 714,
				Close_Gumps = 715,
				Always_Run = 716,
				Save_Desktop = 717,
				Kill_Gump_Open = 718,
				Primary_Ability = 719,
				Secondary_Ability = 720,
				Equip_Last_Weapon = 721,
			};
		};

		struct Client_Range_Control
		{
			enum
			{
				E_TODO_1 = 800,
				E_TODO_2 = 849,
			};
		};

		struct Invoke_Virtues
		{
			enum
			{
				E_TODO_1 = 850,
				E_TODO_2 = 899,
			};
		};

		struct Targeting_System
		{
			enum
			{
				E_TODO_1 = 700,
				E_TODO_2 = 749,
			};
		};

		struct Gargoyle
		{
			enum
			{
				E_TODO_1 = 750,
				E_TODO_2 = 799,
			};
		};
	};

	struct Extended_info
	{
		enum
		{
			E_TODO_1 = 1000,
			TargCurs, // Boolean, cursor is a target?
			E_TODO_2 = 1099,
		};
	};



public:
	UOWrapper();
	virtual ~UOWrapper();

public:
	bool InitWrapper(void);

	bool SetStringVar(const int& VarName, const std::string& value);
	bool SetIntegerVar(const int& varName, const int& value);
	bool SetBooleanVar(const int& varName, const bool& value);
	bool GetStringVar(const int& varName, std::string& value);
	bool GetIntegerVar(const int& varName, int& value);
	bool GetBooleanVar(const int& varName, bool& value);

	bool UseMacro(const int& Macro);
	bool UseMacro(const int& Macro, const std::string& Text);

	bool WaitForTarget(const int& Timeout = 2000);


private:
	std::map<int, std::string> CommandsList;		// Command Enum, String Value
	std::map<int, std::pair<int, int>> MacroList;	// Macro Enum, Param1, Param2

	void CloseWrapper(void);

};
