#pragma once
#include "stdafx.h"
#include "colliders.h"
#include <string>
using namespace game_framework;

class ImageFactory {
public:
	static Brick createBrick(std::string brick_color, int brick_type, int x, int y) {
		Brick brick_obj;
		if (brick_color == "brown") {
			switch (brick_type)
			{
			case 1:
				brick_obj = Brick(x, y, { "resources/image/object/block1/brown_brick.bmp" });
			case 2:
				brick_obj = Brick(x, y, { "resources/image/object/block1/brown_brick2.bmp" });
			case 3: // upper ground brick
				brick_obj = Brick(x, y, { "resources/image/object/block1/brown_brick3.bmp" });
			case 4: // lower ground brick
				brick_obj = Brick(x, y, { "resources/image/object/block1/brown_brick5.bmp" });
			default:
				break;
			}
		}
		
		brick_obj.coll.SetTopLeft(x, y);
		brick_obj.coll.SetFrameIndexOfBitmap(0);
		return brick_obj;
	}
};