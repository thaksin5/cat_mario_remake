#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "colliders.h"
#include "ImageFactory.h"
using namespace game_framework;

// build brick
void CGameStateRun::build_brick(std::string brick_color, int brick_type, int amt, int x, int y) {
	Brick brick_obj_up;
	for (int i = 0; i < amt; i++) {
		brick_obj_up = ImageFactory::createBrick(brick_color, brick_type, x, y);
		bricks_arr.push_back(brick_obj_up);
		x += 60;
	}
}
// build ground
void CGameStateRun::build_ground(std::string brick_color, int amt, int x_Up, int y_Up, int x_Down, int y_Down) {
	build_brick(brick_color, 3, amt, x_Up, y_Up);
	build_brick(brick_color, 5, amt, x_Down, y_Down);
}

// build environment
void CGameStateRun::build_envionment(std::string name, int x, int y) {
	Environment env_obj;
	env_obj = ImageFactory::createEnvironment(name, x, y);
	environment_arr.push_back(env_obj);
}

// shift map image
void CGameStateRun::shiftMapImage() {
	if (player.coll.GetLeft() + player.coll.GetWidth() > 512) {
		int player_posX = 512 - player.coll.GetWidth();
		player.coll.SetTopLeft(player_posX, player.coll.GetTop());
		// shift image left
		for (auto &i : bricks_arr) {
			int obj_pos = i.coll.GetLeft() - player.moveSpeed;
			i.coll.SetTopLeft(obj_pos, i.coll.GetTop());
		}
		for (auto &i : environment_arr) {
			int obj_pos = i.coll.GetLeft() - player.moveSpeed;
			i.coll.SetTopLeft(obj_pos, i.coll.GetTop());
		}
	}
}

// high from ground
int CGameStateRun::high_from_ground(int blockCount) { return  groundY_up - (60 * blockCount); }

// far from start
int CGameStateRun::far_from_start(int blockCount) { return 60 * blockCount;}

int mountain_height = 132;
int grass_height = 50;
int pipeline_big_height = 240;
int pipeline_mid_height = 180;
int pipeline_short_height = 120;
int checkpoint_flag_height = 120;
int endpoint_building_height = 180;

void CGameStateRun::MapSetting(int map) {
	if (map == 1) {
		int currentGroundBlock = 0; // track how many ground blocks were build

		Brick brick;
		Environment env;

		/* phase1 */
		build_ground("brown", 17, groundX_up, groundY_up, groundX_down, groundY_down); // ground
		
		env = Environment(far_from_start(7), high_from_ground(9), { "resources/image/object/environment/cloud_eye.bmp" }); environment_arr.push_back(env);
		env = Environment(far_from_start(1), groundY_up - 132, { "resources/image/object/environment/mountain.bmp" }); environment_arr.push_back(env);
		
		brick = Brick(far_from_start(9), high_from_ground(4), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);
		for (int i = 0; i < 5; i++) { 
			brick = Brick(far_from_start(9 + 3 + i), high_from_ground(4), { "resources/image/object/block1/brown_brick.bmp" }); 
			bricks_arr.push_back(brick);
		}
		brick = Brick(far_from_start(9+5), high_from_ground(4+3), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);
		
		/* phase2 */
		currentGroundBlock += 17;
		build_ground("brown", 15, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);

		brick = Brick(far_from_start(currentGroundBlock + 2), groundY_up - pipeline_mid_height, { "resources/image/object/block2/pipeline_mid.bmp" }); bricks_arr.push_back(brick);
		env = Environment(far_from_start(currentGroundBlock + 1), groundY_up - grass_height, { "resources/image/object/environment/grass.bmp" }); environment_arr.push_back(env);
		brick = Brick(far_from_start(currentGroundBlock + 10), groundY_up - pipeline_big_height, { "resources/image/object/block2/pipeline_big.bmp" }); bricks_arr.push_back(brick);

		/* phase3 */
		currentGroundBlock += 15;
		build_ground("brown", 9, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		env = Environment(far_from_start(currentGroundBlock + 2), groundY_up - mountain_height, { "resources/image/object/environment/mountain.bmp" }); environment_arr.push_back(env);

		/* phase4 */
		currentGroundBlock += 12;
		build_ground("brown", 11, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		
		env = Environment(far_from_start(currentGroundBlock + 3), groundY_up - grass_height, { "resources/image/object/environment/grass.bmp" }); environment_arr.push_back(env);

		for (int i = 0; i < 3; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 3+i), high_from_ground(4), {"resources/image/object/block1/brown_brick.bmp"});
			bricks_arr.push_back(brick);
		}

		for (int i = 0; i < 5; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 6 + i), high_from_ground(7), { "resources/image/object/block1/brown_brick.bmp" });
			bricks_arr.push_back(brick);
		}
		
		/* phase5 */
		currentGroundBlock += 14;

		build_ground("brown", 11, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		for (int i = 0; i < 3; i++) {
			brick = Brick(far_from_start(currentGroundBlock + i), high_from_ground(9), { "resources/image/object/block1/brown_brick.bmp" });
			bricks_arr.push_back(brick);
		}
		brick = Brick(far_from_start(currentGroundBlock + 2), high_from_ground(4), { "resources/image/object/block1/brown_brick.bmp" });
		env = Environment(far_from_start(currentGroundBlock + 7), high_from_ground(12), { "resources/image/object/environment/cloud_eye.bmp" });
		for (int i = 0; i < 2; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 9+i), high_from_ground(4), { "resources/image/object/block1/brown_brick.bmp" });
			bricks_arr.push_back(brick);
		}

		brick = Brick(far_from_start(currentGroundBlock + 9), high_from_ground(4) - checkpoint_flag_height, { "resources/image/object/environment/checkpoint_reached.bmp", "resources/image/object/environment/blank.bmp" }); bricks_arr.push_back(brick);
		
		/* phase6 */
		currentGroundBlock += 11;
		build_ground("brown", 17, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		
		brick = Brick(far_from_start(currentGroundBlock + 3), high_from_ground(4), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);
		brick = Brick(far_from_start(currentGroundBlock + 6), high_from_ground(4), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);
		brick = Brick(far_from_start(currentGroundBlock + 9), high_from_ground(4), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);
		brick = Brick(far_from_start(currentGroundBlock + 6), high_from_ground(8), { "resources/image/object/block1/item_brick.bmp" }); bricks_arr.push_back(brick);

		env = Environment(far_from_start(currentGroundBlock + 10), groundY_up - grass_height, { "resources/image/object/environment/grass.bmp" }); environment_arr.push_back(env);
		
		brick = Brick(far_from_start(currentGroundBlock + 14), high_from_ground(1), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		for (int i = 0; i < 2; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 15), high_from_ground(1+i), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 3; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 16), high_from_ground(1+i), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		}

		/* phase7 */
		currentGroundBlock += 20;

		build_ground("brown", 6, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		for (int i = 0; i < 3; i++) {
			brick = Brick(far_from_start(currentGroundBlock), high_from_ground(1 + i), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 2; i++) {
			brick = Brick(far_from_start(currentGroundBlock+1), high_from_ground(1 + i), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		}
		
		/* phase 8 */
		currentGroundBlock += 7;
		build_ground("brown", 13, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		for (int i = 0; i < 2; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 3+i), high_from_ground(4), { "resources/image/object/block1/brown_brick.bmp" }); 
			bricks_arr.push_back(brick);
		}
		brick = Brick(far_from_start(currentGroundBlock + 8), high_from_ground(4), { "resources/image/object/block1/brown_brick.bmp" }); bricks_arr.push_back(brick);

		env = Environment(far_from_start(currentGroundBlock + 7), high_from_ground(9), { "resources/image/object/environment/cloud_eye.bmp" }); environment_arr.push_back(env);
		brick = Brick(far_from_start(currentGroundBlock + 11), groundY_up - pipeline_short_height, { "resources/image/object/block2/pipeline_short.bmp" }); bricks_arr.push_back(brick);

		/* phase 9 */
		currentGroundBlock += 13;
		build_ground("brown", 9, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		
		for (int i = 0; i < 9; i++) { 
			brick = Brick(far_from_start(currentGroundBlock + i), high_from_ground(1), { "resources/image/object/block1/brown_brick4.bmp" });
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 8; i++) { 
			brick = Brick(far_from_start(currentGroundBlock + 1 + i), high_from_ground(2), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);

		}
		for (int i = 0; i < 7; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 2 + i), high_from_ground(3), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 6; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 3 + i), high_from_ground(4), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 5; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 4 + i), high_from_ground(5), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 4; i++) {
			brick = Brick(far_from_start(currentGroundBlock + 5 + i), high_from_ground(6), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 3; i++) { 
			brick = Brick(far_from_start(currentGroundBlock + 6 + i), high_from_ground(7), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		for (int i = 0; i < 2; i++) { 
			brick = Brick(far_from_start(currentGroundBlock + 7 + i), high_from_ground(8), { "resources/image/object/block1/brown_brick4.bmp" }); 
			bricks_arr.push_back(brick);
		}
		/* phase 10 */
		currentGroundBlock += 9;
		build_ground("brown", 7, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		brick = Brick(far_from_start(currentGroundBlock + 4), high_from_ground(1), { "resources/image/object/block1/brown_brick4.bmp" }); bricks_arr.push_back(brick);
		brick = Brick(far_from_start(currentGroundBlock + 4) + 20, high_from_ground(10) - 20, { "resources/image/object/environment/end_point_flag.bmp" }); bricks_arr.push_back(brick);

		/* phase 11 */
		currentGroundBlock += 7;
		build_ground("brown", 10, far_from_start(currentGroundBlock), groundY_up, far_from_start(currentGroundBlock), groundY_down);
		env = Environment(far_from_start(currentGroundBlock - 2), groundY_up - grass_height, { "resources/image/object/environment/grass.bmp" }); environment_arr.push_back(env);
		env = Environment(far_from_start(currentGroundBlock + 2), groundY_up - endpoint_building_height, { "resources/image/object/environment/end_point_building.bmp" }); environment_arr.push_back(env);

	}
	else if (map == 2) {

	}
	else if (map == 3) {

	}
	else if (map == 4) {

	}
}