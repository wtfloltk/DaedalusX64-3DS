/*
Copyright (C) 2005 StrmnNrmn

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "stdafx.h"
//#include "ROM.h"

#include <stdio.h>

//#include "Cheats.h"
//#include "CPU.h"
//#include "PIF.h"		// CController
//#include "R4300.h"
//#include "ROMBuffer.h"
//#include "ROMImage.h"
//#include "RomSettings.h"

#include "Config/ConfigOptions.h"
#include "Debug/DBGConsole.h"
#include "Debug/DebugLog.h"
#include "Interface/RomDB.h"
#include "Math/MathUtil.h"
#include "OSHLE/patch.h"			// Patch_ApplyPatches
#include "OSHLE/ultra_os.h"		// System type
#include "OSHLE/ultra_R4300.h"
#include "Plugins/AudioPlugin.h"
#include "Plugins/GraphicsPlugin.h"
#include "Utility/CRC.h"
#include "Utility/FramerateLimiter.h"
#include "Utility/IO.h"
#include "Utility/Macros.h"
#include "Utility/Preferences.h"
#include "Utility/ROMFile.h"
#include "Utility/Stream.h"
#include "Utility/Synchroniser.h"

#include <3ds.h>

#define TICKS_PER_SEC 268123480.0

namespace NTiming {

bool GetPreciseFrequency( u64 * p_freq )
{
    *p_freq = SRomPreferences().Clock;
	return true;
}

bool GetPreciseTime( u64 * p_time )
{
	*p_time = svcGetSystemTick();
	return true;
}

u64 ToMilliseconds( u64 ticks )
{
	//?


    SRomPreferences romPreferences;
    CPreferences::Get()->GetRomPreferences(RomID() ,&romPreferences );
    return (ticks * 1000 * 1000) / romPreferences.Clock;
}

} // NTiming
