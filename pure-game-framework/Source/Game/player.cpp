#include "stdafx.h"
#include "colliders.h"
#include "mygame.h"

using namespace game_framework;
void Player::move() {
	// gravity and moving
	if (coll.GetTop() + jumpSpeed >= 1500) {// fall down (dead)
		coll.SetTopLeft(coll.GetLeft() + moveSpeed, 1500);
		jumpSpeed = 0; moveSpeed = 0;
		player_fall = true;
		player_on_air = false;
	}
	else if (moveSpeed != 0 || jumpSpeed != 0) {//move
		coll.SetTopLeft(coll.GetLeft() + moveSpeed, coll.GetTop() + jumpSpeed);
	}
	moveHor();
	moveVer();
	ani();
	voice();
}
void Player::moveHor() {
	frame += 1;
	if (keyRight == true) {
		if (moveSpeed == 0)
			moveSpeed += 1;
		if (frame % 5 == 0) {//every 10 frame
			moveSpeed += 1;
			if (moveSpeed < 0)
				moveSpeed += 3;
		}
		if (moveSpeed >= 10)//speed max = 6
			moveSpeed = 10;
	}
	if (keyLeft == true) {
		// move backward
		if (moveSpeed == 0)
			moveSpeed -= 1;
		if (frame % 5 == 0) {
			moveSpeed -= 1;
			if (moveSpeed > 0)
				moveSpeed -= 3;
		}
		if (moveSpeed <= -10)
			moveSpeed = -10;
	}
	if ((!keyRight && !keyLeft)) {// stop
		if (frame % 5 == 0) {
			if (moveSpeed >= 1)
				moveSpeed -= 1;
			else if (moveSpeed <= -1)
				moveSpeed += 1;
			else
				moveSpeed = 0;
		}
	}
	// player restriction
	if (coll.GetLeft() <= 0) {
		coll.SetTopLeft(0, coll.GetTop());
	}
	if (frame + 1 < 0) {//prevent int overflow
		frame = 0;
	}
}
void Player::moveVer() {
	double fall_gnd = 1500;
	Player::ableToJump(fall_gnd);
}
void Player::ableToJump(double &ground) {
	jumpBonusFrame++;

	if (coll.GetTop() < ground) {// player in the air
		jumpSpeed += 1; // v += a
		player_on_air = true;
	}

	else if (keyUp == true && coll.GetTop() == ground) {// jump while on the ground
		jumpBonusFrame = 0; // for big jump
		jumpSpeed = -19;// v0			
	}

	if (jumpBonusFrame == 5 && keyUp) {// jump hold duration (if hold long will higher)
		jumpSpeed -= 5; // v-=5(a)
	}
}
void Player::ani() {
	
}
void Player::voice() {

}
