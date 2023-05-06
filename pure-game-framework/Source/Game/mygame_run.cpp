#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "colliders.h"
#include "factory.h"
#include <typeinfo>
using namespace game_framework;

CMovingBitmap brick;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////
CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	player.move();
	Touching();
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	vector<string> player_image = { "resources/image/player/player_1.bmp" , "resources/image/player/player_2.bmp" ,"resources/image/player/player_1_flip.bmp" , "resources/image/player/player_2_flip.bmp", "resources/image/player/player_jump.bmp", "resources/image/player/player_jump_flip.bmp" };
	player = Player(0, 0, player_image);
	MapSetting(1);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar == VK_LEFT) {
		
		player.keyLeft = true;
		player.keyRight = false;
	}
	if (nChar == VK_RIGHT) {
		player.keyRight = true;
		player.keyLeft = false;
	}
	if (nChar == VK_UP) {
		player.keyUp = true;
	}
	if (nChar == VK_DOWN) {
		player.keyDown = true;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RIGHT) {
		player.keyRight = false;
	}
	if (nChar == VK_LEFT) {
		player.keyLeft = false;
	}
	if (nChar == VK_UP) {
		player.keyUp = false;
	}
	if (nChar == VK_DOWN) {
		player.keyDown = false;
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	player.coll.ShowBitmap();
	for (auto i : bricks_arr) {
		i.coll.ShowBitmap();
	}
}
