#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "colliders.h"
using namespace game_framework;

Collider::Collider(int posx,int posy, std::vector<std::string> image) {
	coll.LoadBitmapByString(image, RGB(163, 73, 164));
	coll.SetTopLeft(posx, posy);
};
Collider::~Collider() {};
void Collider::move(){
}
void Collider::event(){

}
