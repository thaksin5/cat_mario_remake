#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#ifndef COLLIDERS_H
#define COLLIDERS_H


namespace game_framework {
	class Collider {
	public:
		Collider() = default;
		Collider(int posx, int posy, std::vector<std::string> image);
		virtual ~Collider();
		virtual void move();
		virtual void event();
		CMovingBitmap coll;
		int speed_x = 0;
		int speed_y = 0;
	};

	class Player : public Collider {
	public:
		Player() = default;
		Player(int posx, int posy, std::vector<std::string> image) : Collider(posx, posy, image) {}
		~Player() = default;
		void move();
		void moveHor();
		void moveVer();
		void ableToJump(double &ground);
		void ani();
		void voice();

		int frame = 0;
		int animate_frame = 0;
		int jumpBonusFrame = 0;
		int jumpSpeed = 0;
		int moveSpeed = 0;
		int dead_audio_flag = 0;

		bool keyUp = false;
		bool keyDown = false;
		bool keyLeft = false;
		bool keyRight = false;
		bool player_fall = false;
		bool player_on_air = false;
		bool isMove = false;

		CAudio *player_jump_audio = CAudio::Instance();
		CAudio *player_dead_audio = CAudio::Instance();
	};

	class Brick : public Collider {
	public:
		Brick() {}
		Brick(int posx, int posy, std::vector<std::string> image) : Collider(posx, posy, image) {}
		~Brick() = default;
		bool _downBreak = false; //head touch -> break
		bool _upBreak = false;
		bool _invisible = false;
		bool _upFall = false;
		bool _haveItem = false;
		std::string _item;
	};
}

#endif