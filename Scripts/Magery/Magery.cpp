// Magery.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <SSRabaWrapper.h>

int main()
{
	UOWrapper uo;

	bool bret = uo.InitAll();

    return 0;
}

