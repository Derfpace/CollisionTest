#ifndef WORLD_H
#define WORLD_H

class World {
	public:
		static const int MAX = 128;
		Entity *updateList[MAX];
		void add(Entity *newEntity);
		virtual void update();
		World();
		virtual ~World();
	protected:
	private:
};

#endif // WORLD_H
