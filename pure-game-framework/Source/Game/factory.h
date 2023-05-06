#pragma once
#include "stdafx.h"
#include "colliders.h"
using namespace game_framework;

namespace game_framework {
	// Image factory
	class ImageFactory {
	public:
		static CMovingBitmap createBrick(int type, int x, int y) {
			CMovingBitmap new_brick;
			switch (type) {
			case 1: // brick1
				new_brick.LoadBitmapByString({ "resources/image/object/block1/brown_brick.bmp" }, RGB(163, 73, 164));
			case 2: // brick2
				new_brick.LoadBitmapByString({ "resources/image/object/block1/brown_brick2.bmp" }, RGB(163, 73, 164));
			case 3: // brick3
				new_brick.LoadBitmapByString({ "resources/image/object/block1/brown_brick3.bmp" }, RGB(163, 73, 164));
			case 4: //brick4
				new_brick.LoadBitmapByString({ "resources/image/object/block1/brown_brick4.bmp" }, RGB(163, 73, 164));
			case 5: // brick5
				new_brick.LoadBitmapByString({ "resources/image/object/block1/brown_brick5.bmp" }, RGB(163, 73, 164));
			default:
				break;
			}
			new_brick.SetFrameIndexOfBitmap(0);
			new_brick.SetTopLeft(x, y);
			return new_brick;
		}

		static CMovingBitmap createInteractBlock(std::string name, int x, int y) {
			CMovingBitmap new_obj;
			if (name == "pipeline_short") {
				new_obj.LoadBitmapByString({ "resources/image/object/block2/pipeline_short.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "pipeline_mid") {
				new_obj.LoadBitmapByString({ "resources/image/object/block2/pipeline_mid.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "pipeline_big") {
				new_obj.LoadBitmapByString({ "resources/image/object/block2/pipeline_big.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "item_block") {
				new_obj.LoadBitmapByString({ "resources/image/object/block1/item_brick.bmp", "resources/image/object/block1/brown_brick2.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "cloud_eye") {
				new_obj.LoadBitmapByString({ "resources/image/enemy/cloud_eye.bmp", "resources/image/enemy/cloud_devil.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "checkpoint_flag") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/checkpoint_reached.bmp" , "resources/image/object/environment/blank.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "endpoint_flag") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/end_point_flag.bmp" }, RGB(163, 73, 164));
			}
			new_obj.SetTopLeft(x, y);
			return new_obj;
		}

		static CMovingBitmap createEnemy(std::string name, int x, int y) {
			CMovingBitmap enemy;
			if (name == "normal") {
				enemy.LoadBitmapByString({ "resources/image/enemy/normal.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "star_smile") {
				enemy.LoadBitmapByString({ "resources/image/enemy/star_smile.bmp" }, RGB(163, 73, 164));
			}
			enemy.SetFrameIndexOfBitmap(0);
			enemy.SetTopLeft(x, y);
			return enemy;
		}

		static CMovingBitmap createEnvironment(std::string name, int x, int y) {
			CMovingBitmap new_obj;
			if (name == "mountain") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/mountain.bmp", }, RGB(163, 73, 164));
			}
			else if (name == "tree1") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/tree1.bmp", }, RGB(163, 73, 164));
			}
			else if (name == "tree2") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/tree2.bmp", }, RGB(163, 73, 164));
			}
			else if (name == "grass") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/grass.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "cloud") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/cloud.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "cloud_eye") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/cloud_eye.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "endpoint_building") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/end_point_building.bmp" }, RGB(163, 73, 164));
			}
			else if (name == "coin") {
				new_obj.LoadBitmapByString({ "resources/image/object/environment/coin.bmp" }, RGB(163, 73, 164));
			}

			new_obj.SetFrameIndexOfBitmap(0);
			new_obj.SetTopLeft(x, y);
			return new_obj;
		}
	};
}