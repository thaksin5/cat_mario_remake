#pragma once
#include "stdafx.h"
#include "colliders.h"

using namespace game_framework;

class ImageFactory {
public:
	static Brick createBrick(std::string brick_color, int brick_type, int x, int y) {
		Brick obj_brick;
		if (brick_color == "brown") {
			if (brick_type == 1) { obj_brick = Brick(x, y, { "resources/image/object/block1/brown_brick.bmp" });}
			else if(brick_type == 2){ obj_brick = Brick(x, y, { "resources/image/object/block1/brown_brick2.bmp" }); }
			else if (brick_type == 3) { obj_brick = Brick(x, y, { "resources/image/object/block1/brown_brick3.bmp" }); }
			else if (brick_type == 4) { obj_brick = Brick(x, y, { "resources/image/object/block1/brown_brick4.bmp" }); }
			else if (brick_type == 5) { obj_brick = Brick(x, y, { "resources/image/object/block1/brown_brick5.bmp" }); }
		}
		return obj_brick;
	}
	static Environment createEnvironment(std::string name, int x, int y) {
		Environment obj;
		if (name == "mountain") {
			obj = Environment(x, y, { "resources/image/object/environment/mountain.bmp" });
		}
		else if (name == "tree1") {
			obj = Environment(x, y, { "resources/image/object/environment/tree1.bmp" });
		}
		else if (name == "tree2") {
			obj = Environment(x, y, { "resources/image/object/environment/tree2.bmp" });
		}
		else if (name == "grass") {
			obj = Environment(x, y, { "resources/image/object/environment/grass.bmp" });
		}
		else if (name == "cloud") {
			obj = Environment(x, y, { "resources/image/object/environment/cloud.bmp" });
		}
		else if (name == "cloud_eye") {
			obj = Environment(x, y, { "resources/image/object/environment/cloud_eye.bmp" });
		}
		else if (name == "endpoint_building") {
			obj = Environment(x, y, { "resources/image/object/environment/end_point_building.bmp" });
		}
		else if (name == "coin") {
			obj = Environment(x, y, { "resources/image/object/environment/coin.bmp" });
		}
		return obj;
	}
};