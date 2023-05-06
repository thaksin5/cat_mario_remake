#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "colliders.h"

using namespace game_framework;

void CGameStateRun::MapSetting(int map) {
	if (map == 1) {
		load_block_ground(12, groundX_up, groundY_up, groundX_down, groundY_down);
	}
	else if (map == 2) {

	}
	else if (map == 3) {

	}
	else if (map == 4) {

	}
}