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

bool inRange(double num, double min, double max) {
	return (min <= num && num <= max);
}

// brick collision
void CGameStateRun::Touching() {
	CMovingBitmap &PC = player.coll;

	for (auto &i : bricks_arr) {
		CMovingBitmap &BC = i.coll;

		if (player.jumpSpeed >= 10) {//predict penetrate
			if (PC.GetTop() + PC.GetHeight() <= BC.GetTop() && PC.GetTop() + PC.GetHeight() + player.jumpSpeed >= BC.GetTop() && PC.GetLeft() + 2 < BC.GetLeft() + BC.GetWidth() && PC.GetLeft() + PC.GetWidth() - 2 > BC.GetLeft()) {
				player.jumpSpeed = 0;
				player.jumpBonusFrame = 0;
				PC.SetTopLeft(PC.GetLeft(), BC.GetTop() - PC.GetHeight());
				double ground = BC.GetTop() - PC.GetHeight();
				player.ableToJump(ground); // can jump on block
			}
		}
		if (CMovingBitmap::IsOverlap(PC, BC)) {//check touch
			int obj_left = BC.GetLeft();
			int obj_right = BC.GetLeft() + BC.GetWidth();
			int obj_top = BC.GetTop();
			int obj_bottom = BC.GetTop() + BC.GetHeight();
			int obj_mid_x = BC.GetLeft() + (BC.GetWidth() / 2);
			int obj_mid_y = BC.GetTop() + (BC.GetHeight() / 2);
			//head touch
			if (inRange(PC.GetTop() - 1, obj_mid_y, obj_bottom) && PC.GetLeft() + 10 <= obj_right && PC.GetLeft() + PC.GetWidth() - 10 >= obj_left) {
				player.jumpSpeed = 0;
				PC.SetTopLeft(PC.GetLeft(), obj_bottom);
				player.jumpSpeed += 1;
			}
			//foot touch
			else if (inRange(PC.GetTop() + PC.GetHeight() + 1, obj_top, obj_mid_y) && PC.GetLeft() + 2 < obj_right && PC.GetLeft() + PC.GetWidth() - 2 > obj_left) {
				player.jumpSpeed = 0;
				player.jumpBonusFrame = 0;
				PC.SetTopLeft(PC.GetLeft(), obj_top - PC.GetHeight());
				double ground = obj_top - PC.GetHeight();
				player.ableToJump(ground); // can jump on block
			}
			//left touch
			else if (inRange(PC.GetLeft(), obj_mid_x, obj_right) && PC.GetTop() <= obj_bottom && PC.GetTop() + PC.GetHeight() - 5 >= obj_top) {
				player.moveSpeed = 0;
				PC.SetTopLeft(obj_right, PC.GetTop());
				player.frame += 2;
			}
			//right touch
			else if (inRange(PC.GetLeft() + PC.GetWidth() + 1, obj_left, obj_mid_x) && PC.GetTop() <= obj_bottom && PC.GetTop() + PC.GetHeight() - 5 >= obj_top) {
				player.moveSpeed = 0;
				PC.SetTopLeft(obj_left - PC.GetWidth(), PC.GetTop());
				player.frame += 2;
			}
		}
	}

}

