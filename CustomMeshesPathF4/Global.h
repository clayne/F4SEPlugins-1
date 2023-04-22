#pragma once
#include <f4se/PluginAPI.h>
#include <f4se/GameReferences.h>
#include <f4se/GameData.h>
#include <f4se/GameRTTI.h>
#include <f4se/GameExtraData.h>
#include <f4se/NiExtraData.h>
#include <f4se/xbyak/xbyak.h>
#include <f4se/BSModelDB.h>

#include <f4se_common/f4se_version.h>
#include <f4se_common/Relocation.h>
#include <f4se_common/BranchTrampoline.h>
#include <f4se_common/SafeWrite.h>

#include <fstream>
#include <unordered_map>
#include <mutex>
#include <algorithm>
#include <thread>

#include "CaseInsensitiveMap.h"

#include "Hooks.h"
#include "CACS.h"
#include "Utils.h"

#define PLUGIN_NAME	"CustomMeshesPathF4"
#define PLUGIN_VERSION	MAKE_EXE_VERSION(0, 8, 1)

extern bool bDebug;