#ifndef ENTITY_H
#define ENTITY_H

class Entity {
	public:
		bool collide;
		bool active;
		int x, y;
		unsigned int width, height;
		float red, green, blue;
		Entity();
		virtual ~Entity();
		virtual void update();
	private:
};

#endif
