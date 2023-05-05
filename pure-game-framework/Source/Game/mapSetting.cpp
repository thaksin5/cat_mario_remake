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

void CGameStateRun::MapSetting(int map){
	if (map == 1) {
		Brick a = Brick(0, 800, { "resources/image/object/block1/brown_brick.bmp" });
		bricks_arr.push_back(a);
	}
	else if(map == 2) {

	}
	else if (map == 3) {

	}
	else if (map == 4) {

	}
}