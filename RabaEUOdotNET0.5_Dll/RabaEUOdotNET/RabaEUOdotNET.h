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

#pragma once

#include <iostream>
#include <sstream>
#include <windows.h>
#include <string.h>
 
extern "C"
{
 ///////////////////////////// RABA EUO.NET FUNCTIONS /////////////////////////////////////////
 __declspec(dllexport) bool __stdcall REUONetInit();
 __declspec(dllexport) int __stdcall REUONetMajorVersion();
 __declspec(dllexport) int __stdcall REUONetMinorVersion();
 __declspec(dllexport) int __stdcall REUONetGetUoDllVersion();
 __declspec(dllexport) bool __stdcall REUONetOpen();
 __declspec(dllexport) bool __stdcall REUONetClose();
 __declspec(dllexport) bool __stdcall REUONetFree();

 ///////////////////////////// RABA EUO.NET GETTERS SETTERS /////////////////////////////////////////
 __declspec(dllexport) int __stdcall REUONetSetStringVar(char* varName, char* value);
 __declspec(dllexport) int __stdcall REUONetSetIntegerVar(char* varName, int value);
 __declspec(dllexport) int __stdcall REUONetSetBooleanVar(char* varName, bool value);
 __declspec(dllexport) int __stdcall REUONetGetStringVar(char* varName, char* value, int size);
 __declspec(dllexport) int __stdcall REUONetGetIntegerVar(char* varName, LPINT value);
 __declspec(dllexport) int __stdcall REUONetGetBooleanVar(char* varName, LPBOOL value);

 //////////////////////////// RABA EUO.NET COMMANDS /////////////////////////////////////////////////
__declspec(dllexport) int __stdcall REUONetCommandCliDrag(int itemID);
__declspec(dllexport) int __stdcall REUONetCommandClick(int x, int y, bool left, bool down, bool up, bool move);
__declspec(dllexport) int __stdcall REUONetCommandContTop(int index);
__declspec(dllexport) int __stdcall REUONetCommandDrag(int itemID, int stack);
__declspec(dllexport) int __stdcall REUONetCommandDropC(int contID);
__declspec(dllexport) int __stdcall REUONetCommandDropCXY(int contID, int x, int y);
__declspec(dllexport) int __stdcall REUONetCommandDropG(int x, int y, int z);
__declspec(dllexport) int __stdcall REUONetCommandDropPD();
__declspec(dllexport) int __stdcall REUONetCommandEquip(int itemID);
__declspec(dllexport) int __stdcall REUONetCommandExMsg(int itemID, int font, int color, char* message);
__declspec(dllexport) int __stdcall REUONetCommandGetCont(int index, char* contName, int size, LPINT x, LPINT y, LPINT width, LPINT height, LPINT contKind, LPINT contID, LPINT contType, LPINT HP);
__declspec(dllexport) int __stdcall REUONetCommandGetItem(int index, LPINT itemID, LPINT itemType, LPINT itemKind, LPINT contID, LPINT x, LPINT y, LPINT z, LPINT stack, LPINT reputation, LPINT color);
__declspec(dllexport) int __stdcall REUONetCommandGetJournal(int index, char* line, int size, LPINT color);
__declspec(dllexport) int __stdcall REUONetCommandGetPix(int x, int y, LPINT pixel);
__declspec(dllexport) int __stdcall REUONetCommandGetShop(LPBOOL res, LPINT pos, LPINT cnt, LPINT id, LPINT type, LPINT max, LPINT price, char* name, int size);
__declspec(dllexport) int __stdcall REUONetCommandGetSkill(char* skill, LPINT norm, LPINT real, LPINT cap, LPINT lock);
__declspec(dllexport) int __stdcall REUONetCommandHideItem(int itemID);
__declspec(dllexport) int __stdcall REUONetCommandKey(char* key, bool ctrl, bool alt, bool shift);
__declspec(dllexport) int __stdcall REUONetCommandMacro(int param1, int param2, char* paramString);
__declspec(dllexport) int __stdcall REUONetCommandMove(int x, int y, int tolerance, int timeout, LPBOOL success);
__declspec(dllexport) int __stdcall REUONetCommandMsg(char* message);
__declspec(dllexport) int __stdcall REUONetCommandPathfind(int x, int y, int z);
__declspec(dllexport) int __stdcall REUONetCommandPopup(int itemID);
__declspec(dllexport) int __stdcall REUONetCommandPopupXY(int itemID, int x, int y);
__declspec(dllexport) int __stdcall REUONetCommandProperty(int itemID, char* name, int sizeName, char* info, int sizeInfo);
__declspec(dllexport) int __stdcall REUONetCommandRenamePet(int itemID, char* name);
__declspec(dllexport) int __stdcall REUONetCommandScanItems(bool visibleOnly, LPINT itemCnt);
__declspec(dllexport) int __stdcall REUONetCommandScanJournal(int oldRef, LPINT newRef, LPINT cnt);
__declspec(dllexport) int __stdcall REUONetCommandSetShop(int itemID, int num, LPBOOL res);
__declspec(dllexport) int __stdcall REUONetCommandSkillLock(char* skill, int lock);
__declspec(dllexport) int __stdcall REUONetCommandStatBar(int itemID);
__declspec(dllexport) int __stdcall REUONetCommandStatLock(char* stat, int lock);
__declspec(dllexport) int __stdcall REUONetCommandSysMessage(char* message);
__declspec(dllexport) int __stdcall REUONetCommandSysMessageColor(char* message, int color);
__declspec(dllexport) int __stdcall REUONetCommandTileCnt(int x, int y, int facet, LPINT cnt);
__declspec(dllexport) int __stdcall REUONetCommandTileGet(int x, int y, int index, int facet, LPINT type, LPINT z, char* name, int size, LPINT flags);
__declspec(dllexport) int __stdcall REUONetCommandTileInit(bool noOverrides, LPBOOL success);
}

/////////// IMPORTED FUNCTIONS PROTOTYPE //////////////////////////////////////////////////////

typedef int (__stdcall *VersionFunction)();

typedef void* (__stdcall *OpenFunction)();

typedef void (__stdcall *SetTopFunction)(void* handle, int index);
typedef int (__stdcall *GetTopFunction)(void* handle);
typedef int (__stdcall *GetTypeFunction)(void* handle);

typedef void (__stdcall *PushStrValFunction)(void* handle, char* value);
typedef void (__stdcall *PushStrRefFunction)(void* handle, char* value);
typedef void (__stdcall *PushIntegerFunction)(void* handle, int value);
typedef void (__stdcall *PushBooleanFunction)(void* handle, bool value);

typedef int (__stdcall *ExecuteFunction)(void* handle);

typedef int (__stdcall *GetIntegerFunction)(void* handle, int index);
typedef char* (__stdcall *GetStringFunction)(void* handle, int index);
typedef bool (__stdcall *GetBooleanFunction)(void* handle, int index);

typedef void (__stdcall *CloseFunction)(void* handle);
