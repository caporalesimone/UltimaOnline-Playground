//Copyright (c) 2012 RabaSoft ;-)
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
//and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
//OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
//OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#include "stdafx.h"
#include "RabaEUOdotNET.h"


///////// GLOBAL VARIABLES //////////////////////////////////////////////////////////

int majorVersion = 0;
int minorVersion = 5;

void* hnduoDll = NULL;
HINSTANCE hInstLibrary = NULL;

int executeError = 0;

char* charPtrResult = NULL;
char stringResult[4096] = "";
int integerResult = 0;
bool booleanResult = false;

VersionFunction uoDllVersion;

OpenFunction uoDllOpen;

SetTopFunction uoDllSetTop;
GetTopFunction uoDllGetTop;
GetTypeFunction uoDllGetType;

PushStrRefFunction uoDllPushStrRef;
PushStrValFunction uoDllPushStrVal;
PushIntegerFunction uoDllPushInteger;
PushBooleanFunction uoDllPushBoolean;

ExecuteFunction uoDllExecute;

GetIntegerFunction uoDllGetInteger;
GetStringFunction uoDllGetString;
GetBooleanFunction uoDllGetBoolean;
	
CloseFunction uoDllClose;


////////////////////////// INTERNAL FUNCTIONS ///////////////////////////////////////////////////

int getLPBufferLength(LPSTR pString)
{
	int i = 0;
	char* pTemp = pString;
	bool doLoop = true;

	while (doLoop)
	{
		
		if (*pTemp == NULL )
		{
			doLoop = false;
		}
		else
		{
		i = i++;
		pTemp = pString + i;
		}
	}

	return i + 1;
}

/////////////////////////////// RabaEUOdotNET FUNCTIONS //////////////////////////////////////////////

bool __stdcall REUONetInit()
{
	hInstLibrary = LoadLibrary("uo.dll");

	if (hInstLibrary) 
	{
		uoDllVersion = (VersionFunction)GetProcAddress(hInstLibrary, "Version");

		uoDllOpen = (OpenFunction)GetProcAddress(hInstLibrary, "Open");

		uoDllSetTop = (SetTopFunction)GetProcAddress(hInstLibrary, "SetTop");
		uoDllGetTop = (GetTopFunction)GetProcAddress(hInstLibrary, "GetTop");
		uoDllGetType = (GetTypeFunction)GetProcAddress(hInstLibrary, "GetType");

		uoDllPushStrVal = (PushStrValFunction )GetProcAddress(hInstLibrary, "PushStrVal");
		uoDllPushStrRef = (PushStrValFunction )GetProcAddress(hInstLibrary, "PushStrRef");
		uoDllPushInteger = (PushIntegerFunction)GetProcAddress(hInstLibrary, "PushInteger");
		uoDllPushBoolean = (PushBooleanFunction)GetProcAddress(hInstLibrary, "PushBoolean");

		uoDllExecute = (ExecuteFunction)GetProcAddress(hInstLibrary, "Execute");

		uoDllGetInteger = (GetIntegerFunction)GetProcAddress(hInstLibrary, "GetInteger");
		uoDllGetString = (GetStringFunction)GetProcAddress(hInstLibrary, "GetString");
		uoDllGetBoolean = (GetBooleanFunction)GetProcAddress(hInstLibrary, "GetBoolean");

		uoDllClose = (CloseFunction)GetProcAddress(hInstLibrary, "Close");

		std::cout << "uo.dll dynamic linking library loaded!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "ERROR! Unable to load uo.dll dynamic linking library!" << std::endl;
		return false;
	}
}

int __stdcall REUONetMajorVersion()
{
	return majorVersion;
}

int __stdcall REUONetMinorVersion()
{
	return minorVersion;
}


int __stdcall REUONetGetUoDllVersion()
{
	return uoDllVersion();
}

bool __stdcall REUONetOpen() 
{
	int version = uoDllVersion();

	std::stringstream errorStream;
	errorStream << "Initializing uo.dll... uo.dll current version is: " << version  << std::endl;
	std::cout << errorStream.str();


	if (version == 3) 
	{
		hnduoDll = uoDllOpen();

		std::stringstream errorStream;
		errorStream << "Opening uo.dll, handle value is " << hnduoDll << "..." << std::endl;
		std::cout << errorStream.str();

		if (hnduoDll) 
		{

			uoDllSetTop(hnduoDll, 0);
			uoDllPushStrRef(hnduoDll, "Set");
			uoDllPushStrRef(hnduoDll, "CliNr");
			uoDllPushInteger(hnduoDll, 1);
			int errSetCli = uoDllExecute(hnduoDll);

			uoDllSetTop(hnduoDll, 0);
			uoDllPushStrRef(hnduoDll, "Get");
			uoDllPushStrRef(hnduoDll, "CliNr");
			int errGetCli = uoDllExecute(hnduoDll);		
			int cliNr = uoDllGetInteger(hnduoDll, 1);

			std::stringstream errorStream;
			errorStream << "SetCli error code:" << errSetCli << ", GetCli error code: " << errGetCli << ", CliNr: " << cliNr  << std::endl;
			std::cout << errorStream.str();

			if (!errSetCli && !errGetCli && cliNr)
			{
				std::stringstream errorStream;
				errorStream << "uo.dll is now initialized."  << std::endl;
				std::cout << errorStream.str();
				return true;
			}
			else
			{
				std::stringstream errorStream;
				errorStream << "ERROR! Cannot initialize uo.dll!"  << std::endl;
				std::cout << errorStream.str();
				return true;
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		std::stringstream errorStream;
		errorStream << "ERROR! uo.dll version is: " << version << " (version 3 required)!" << std::endl;
		std::cout << errorStream.str();
		return false;
		
	}
}


bool __stdcall REUONetClose()
{
	if (hnduoDll) 
	{
		std::stringstream errorStream;
		errorStream << "uo.dll closed, handle " << hnduoDll << " released." << std::endl;
		std::cout << errorStream.str();
		uoDllClose(hnduoDll);
		return true;
	}
	else
	{
		std::stringstream errorStream;
		errorStream << "ERROR! Cannot release handle " << hnduoDll << std::endl;
		std::cout << errorStream.str();
		return false;
	}
}
		
bool __stdcall REUONetFree()
{
	if (hInstLibrary)
	{
		std::stringstream errorStream;
		errorStream << "Freeing uo.dll library... instance: " << hInstLibrary << std::endl;
		std::cout << errorStream.str();
		FreeLibrary(hInstLibrary);
		return true;
	}
	else
	{
		std::stringstream errorStream;
		errorStream << "ERROR! Cannot release uo.dll (instance: " << hInstLibrary  << " )" << std::endl;
		std::cout << errorStream.str();
		return false;
	}
}


///////////////////////////// RabaEUOdotNET GETTERS SETTERS /////////////////////////////////////////
			
int __stdcall REUONetSetStringVar(char* varName, char* value)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Set");
	uoDllPushStrRef(hnduoDll, varName);
	uoDllPushStrRef(hnduoDll, value);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetSetIntegerVar(char* varName, int value)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Set");
	uoDllPushStrRef(hnduoDll, varName);
	uoDllPushInteger(hnduoDll, value);
	int err = uoDllExecute(hnduoDll);	
	return err;
}

int __stdcall REUONetSetBooleanVar(char* varName, bool value)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Set");
	uoDllPushStrRef(hnduoDll, varName);
	uoDllPushBoolean(hnduoDll, value);
	int err = uoDllExecute(hnduoDll);
	return err;

}


int __stdcall REUONetGetStringVar(char* varName, char* value, int size)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Get");
	uoDllPushStrRef(hnduoDll, varName);
	executeError = uoDllExecute(hnduoDll);	
	charPtrResult = uoDllGetString(hnduoDll, 1);
	strcpy_s(value, size, charPtrResult);
	return executeError;
}

int __stdcall REUONetGetIntegerVar(char* varName, LPINT value)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Get");
	uoDllPushStrRef(hnduoDll, varName);
	executeError = uoDllExecute(hnduoDll);	
	integerResult = uoDllGetInteger(hnduoDll, 1);
	*value = integerResult;
	return executeError;
}


int __stdcall REUONetGetBooleanVar(char* varName, LPBOOL value)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Get");
	uoDllPushStrRef(hnduoDll, varName);
	executeError = uoDllExecute(hnduoDll);	
	booleanResult = uoDllGetBoolean(hnduoDll, 1);
	*value = booleanResult;
	return executeError;
}


////////////// RabaEUOdotNET COMMANDS ///////////////////////////////////////////////////////

int __stdcall REUONetCommandCliDrag(int itemID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "CliDrag");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandClick(int x, int y, bool left, bool down, bool up, bool move)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Click");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushBoolean(hnduoDll, left);
	uoDllPushBoolean(hnduoDll, down);
	uoDllPushBoolean(hnduoDll, up);
	uoDllPushBoolean(hnduoDll, move);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandContTop(int index)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "ContTop");
	uoDllPushInteger(hnduoDll, index);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandDrag(int itemID, int stack)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Drag");
	uoDllPushInteger(hnduoDll, itemID);
	uoDllPushInteger(hnduoDll, stack);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandDropC(int contID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "DropC");
	uoDllPushInteger(hnduoDll, contID);
	int err = uoDllExecute(hnduoDll);
	return err;
}


int __stdcall REUONetCommandDropCXY(int contID, int x, int y)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "DropC");
	uoDllPushInteger(hnduoDll, contID);
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandDropG(int x, int y, int z)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "DropG");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushInteger(hnduoDll, z);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandDropPD()
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "DropPD");
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandEquip(int itemID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Equip");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandExMsg(int itemID, int font, int color, char* message)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "ExMsg");
	uoDllPushInteger(hnduoDll, itemID);
	uoDllPushInteger(hnduoDll, font);
	uoDllPushInteger(hnduoDll, color);
	uoDllPushStrRef(hnduoDll, message);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandGetCont(int index, char* contName, int size, LPINT x, LPINT y, LPINT width, LPINT height, LPINT contKind, LPINT contID, LPINT contType, LPINT HP)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetCont");
	uoDllPushInteger(hnduoDll, index);
	int err = uoDllExecute(hnduoDll);
	char* nameResult;
	nameResult = uoDllGetString(hnduoDll, 1);
	strcpy_s(contName, size, nameResult);
	int xResult = uoDllGetInteger(hnduoDll, 2);
	*x = xResult;
	int yResult = uoDllGetInteger(hnduoDll, 3);
	*y = yResult;
	int widthResult = uoDllGetInteger(hnduoDll, 4);
	*width = widthResult;
	int heightResult = uoDllGetInteger(hnduoDll, 5);
	*height = heightResult;
	int kindResult = uoDllGetInteger(hnduoDll, 6);
	*contKind = kindResult;
	int idResult = uoDllGetInteger(hnduoDll, 7);
	*contID = idResult;
	int typeResult = uoDllGetInteger(hnduoDll, 8);
	*contType = typeResult;
	int hpResult = uoDllGetInteger(hnduoDll, 9);
	*HP = hpResult;
	return err;
}


int __stdcall REUONetCommandGetItem(int index, LPINT itemID, LPINT itemType, LPINT itemKind, LPINT contID, LPINT x, LPINT y, LPINT z, LPINT stack, LPINT reputation, LPINT color)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetItem");
	uoDllPushInteger(hnduoDll, index);
	int err = uoDllExecute(hnduoDll);
	int itemIDResult = uoDllGetInteger(hnduoDll, 1);
	*itemID = itemIDResult;
	int typeResult = uoDllGetInteger(hnduoDll, 2);
	*itemType = typeResult;
	int kindResult = uoDllGetInteger(hnduoDll, 3);
	*itemKind = kindResult;
	int contIDResult = uoDllGetInteger(hnduoDll, 4);
	*contID = contIDResult;
	int xResult = uoDllGetInteger(hnduoDll, 5);
	*x = xResult;
	int yResult = uoDllGetInteger(hnduoDll, 6);
	*y = yResult;
	int zResult = uoDllGetInteger(hnduoDll, 7);
	*z = zResult;
	int stackResult = uoDllGetInteger(hnduoDll, 8);
	*stack = stackResult;
	int repResult = uoDllGetInteger(hnduoDll, 9);
	*reputation = repResult;
	int colResult = uoDllGetInteger(hnduoDll, 10);
	*color = colResult;
	return err;
}


int __stdcall REUONetCommandGetJournal(int index, char* line, int size, LPINT color)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetJournal");
	uoDllPushInteger(hnduoDll, index);
	int err = uoDllExecute(hnduoDll);
	char* lineResult;
	lineResult = uoDllGetString(hnduoDll, 1);
	strcpy_s(line, size, lineResult);
	int colResult = uoDllGetInteger(hnduoDll, 2);
	*color = colResult;
	return err;
}

int __stdcall REUONetCommandGetPix(int x, int y, LPINT pixel)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetPix");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	int err = uoDllExecute(hnduoDll);
	int result = uoDllGetInteger(hnduoDll, 1);
	*pixel = result;
	return err;
}

int __stdcall REUONetCommandGetShop(LPBOOL res, LPINT pos, LPINT cnt, LPINT id, LPINT type, LPINT max, LPINT price, char* name, int size)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetShop");
	int err = uoDllExecute(hnduoDll);
	bool resResult = uoDllGetBoolean(hnduoDll, 1);
	*res = resResult;
	int posResult = uoDllGetInteger(hnduoDll, 2);
	*pos = posResult;
	int cntResult = uoDllGetInteger(hnduoDll, 3);
	*cnt = cntResult;
	int idResult = uoDllGetInteger(hnduoDll, 4);
	*id = idResult;
	int typeResult = uoDllGetInteger(hnduoDll, 5);
	*type = typeResult;
	int maxResult = uoDllGetInteger(hnduoDll, 6);
	*max = maxResult;
	int priceResult = uoDllGetInteger(hnduoDll, 7);
	*price = priceResult;
	char* nameResult;
	nameResult = uoDllGetString(hnduoDll, 8);
	strcpy_s(name, size, nameResult);
	return err;
}

int __stdcall REUONetCommandGetSkill(char* skill, LPINT norm, LPINT real, LPINT cap, LPINT lock)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "GetSkill");
	uoDllPushStrRef(hnduoDll, skill);
	int err = uoDllExecute(hnduoDll);
	int normResult = uoDllGetInteger(hnduoDll, 1);
	*norm = normResult;
	int realResult = uoDllGetInteger(hnduoDll, 2);
	*real = realResult;
	int capResult = uoDllGetInteger(hnduoDll, 3);
	*cap = capResult;
	int lockResult = uoDllGetInteger(hnduoDll, 4);
	*lock = lockResult;
	return err;
}

int __stdcall REUONetCommandHideItem(int itemID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "HideItem");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandKey(char* key, bool ctrl, bool alt, bool shift)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Key");
	uoDllPushStrRef(hnduoDll, key);
	uoDllPushBoolean(hnduoDll, ctrl);
	uoDllPushBoolean(hnduoDll, alt);
	uoDllPushBoolean(hnduoDll, shift);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandMacro(int param1, int param2, char* paramString)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Macro");
	uoDllPushInteger(hnduoDll, param1);
	uoDllPushInteger(hnduoDll, param2);
	uoDllPushStrRef(hnduoDll, paramString);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandMove(int x, int y, int tolerance, int timeout, LPBOOL success)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Move");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushInteger(hnduoDll, tolerance);
	uoDllPushInteger(hnduoDll, timeout);
	int err = uoDllExecute(hnduoDll);
	bool result = uoDllGetBoolean(hnduoDll, 1);
	*success = result;
	return err;
}

int __stdcall REUONetCommandMsg(char* message)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Msg");
	uoDllPushStrRef(hnduoDll, message);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandPathfind(int x, int y, int z)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Pathfind");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushInteger(hnduoDll, z);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandPopup(int itemID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Popup");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	return err;
}


int __stdcall REUONetCommandPopupXY(int itemID, int x, int y)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Popup");
	uoDllPushInteger(hnduoDll, itemID);
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	int err = uoDllExecute(hnduoDll);
	return err;
}


int __stdcall REUONetCommandProperty(int itemID, char* name, int sizeName, char* info, int sizeInfo)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "Property");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	char* nameResult;
	nameResult = uoDllGetString(hnduoDll, 1);
	strcpy_s(name, sizeName, nameResult);
	char* infoResult;
	infoResult = uoDllGetString(hnduoDll, 2);
	strcpy_s(info, sizeInfo, infoResult);
	return err;
}


int __stdcall REUONetCommandRenamePet(int itemID, char* name)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "RenamePet");
	uoDllPushInteger(hnduoDll, itemID);
	uoDllPushStrRef(hnduoDll, name);
	int err = uoDllExecute(hnduoDll);
	return err;
}


int __stdcall REUONetCommandScanItems(bool visibleOnly, LPINT itemCnt)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "ScanItems");
	uoDllPushBoolean(hnduoDll, visibleOnly);
	int err = uoDllExecute(hnduoDll);
	int result = uoDllGetInteger(hnduoDll, 1);
	*itemCnt = result;
	return err;
}


int __stdcall REUONetCommandScanJournal(int oldRef, LPINT newRef, LPINT cnt)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "ScanJournal");
	uoDllPushInteger(hnduoDll, oldRef);
	int err = uoDllExecute(hnduoDll);
	int newRefResult = uoDllGetInteger(hnduoDll, 1);
	*newRef = newRefResult;
	int cntResult = uoDllGetInteger(hnduoDll, 2);
	*cnt = cntResult;
	return err;
}

int __stdcall REUONetCommandSetShop(int itemID, int num, LPBOOL res)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "SetShop");
	uoDllPushInteger(hnduoDll, itemID);
	uoDllPushInteger(hnduoDll, num);
	int err = uoDllExecute(hnduoDll);
	bool result = uoDllGetBoolean(hnduoDll, 1);
	*res = result;
	return err;
}

int __stdcall REUONetCommandSkillLock(char* skill, int lock)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "SkillLock");
	uoDllPushStrRef(hnduoDll, skill);
	uoDllPushInteger(hnduoDll, lock);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandStatBar(int itemID)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "StatBar");
	uoDllPushInteger(hnduoDll, itemID);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandStatLock(char* stat, int lock)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "StatLock");
	uoDllPushStrRef(hnduoDll, stat);
	uoDllPushInteger(hnduoDll, lock);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandSysMessage(char* message)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "SysMessage");
	uoDllPushStrRef(hnduoDll, message);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandSysMessageColor(char* message, int color)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "SysMessage");
	uoDllPushStrRef(hnduoDll, message);
	uoDllPushInteger(hnduoDll, color);
	int err = uoDllExecute(hnduoDll);
	return err;
}

int __stdcall REUONetCommandTileCnt(int x, int y, int facet, LPINT cnt)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "TileCnt");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushInteger(hnduoDll, facet);
	int err = uoDllExecute(hnduoDll);
	int result = uoDllGetInteger(hnduoDll, 1);
	*cnt = result;
	return err;
}

int __stdcall REUONetCommandTileGet(int x, int y, int index, int facet, LPINT type, LPINT z, char* name, int size, LPINT flags)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "TileGet");
	uoDllPushInteger(hnduoDll, x);
	uoDllPushInteger(hnduoDll, y);
	uoDllPushInteger(hnduoDll, index);
	uoDllPushInteger(hnduoDll, facet);
	int err = uoDllExecute(hnduoDll);
	int typeResult = uoDllGetInteger(hnduoDll, 1);
	*type = typeResult;
	int zResult = uoDllGetInteger(hnduoDll, 2);
	*z = zResult;
	char* nameResult;
	nameResult = uoDllGetString(hnduoDll, 3);
	strcpy_s(name, size, nameResult);
	int flagsResult = uoDllGetInteger(hnduoDll, 4);
	*flags = flagsResult;
	return err;
}

int __stdcall REUONetCommandTileInit(bool noOverrides, LPBOOL success)
{
	uoDllSetTop(hnduoDll, 0);
	uoDllPushStrRef(hnduoDll, "Call");
	uoDllPushStrRef(hnduoDll, "TileInit");
	uoDllPushBoolean(hnduoDll, noOverrides);
	int err = uoDllExecute(hnduoDll);
	bool result = uoDllGetBoolean(hnduoDll, 1);
	*success = result;
	return err;
}

