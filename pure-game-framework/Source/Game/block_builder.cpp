#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "colliders.h"
#include "imageFactory.h"
using namespace game_framework;

/* build block */
void CGameStateRun::build_block_ground(std::string block_color, int block_type, int amt, int x, int y) {
	Brick brick_obj;
	std::vector<Brick> arr = {};
	for (int i = 0; i < amt; i++) {
		brick_obj = ImageFactory::createBrick(block_color, block_type, x, y);
		arr.push_back(brick_obj);
		x += 60;
	}
	if (block_type == 3) {
		for (auto &i : arr) { upper_ground_brick_arr.push_back(i); }
	}
	else if (block_type == 4) {
		for (auto &j : arr) { lower_ground_brick_arr.push_back(j); }
	}
}

/* load block */
void CGameStateRun::load_block_ground(int amount, int x_up, int y_up, int x_down, int y_down) {
	build_block_ground("brown", 3, amount, x_up, y_up); // ground brick up
	build_block_ground("brown", 4, amount, x_down, y_down); // ground brick down
}


/* display block */
void CGameStateRun::display_ground_brick() {
	for (auto &i : upper_ground_brick_arr) { i.coll.ShowBitmap();}
	for (auto &j : lower_ground_brick_arr) { j.coll .ShowBitmap(); }
}