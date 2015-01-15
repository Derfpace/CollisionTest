#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
	public:
		Player(int posx, int posy, int poswidth, int posheight, float colorRed, float colorGreen, float colorBlue);
		virtual ~Player();
		void update();
	protected:
	private:
};

#endif
