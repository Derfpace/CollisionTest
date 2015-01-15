#include "Player.h"
#include "Input.h"

void Player::update() {
	if (Input::leftDown)	x -= 5;
	if (Input::rightDown)	x += 5;
	if (Input::downDown)	y -= 5;
	if (Input::upDown)		y += 5;
}
Player::Player(int posx = 0, int posy = 0, int poswidth = 0, int posheight = 0, float colorRed = 0.0, float colorGreen = 0.0, float colorBlue = 0.0) {
	x 		= posx;
	y 		= posy;
	width 	= poswidth;
	height 	= posheight;

	red 	= colorRed;
	green 	= colorGreen;
	blue	= colorBlue;
}
Player::~Player() {}
