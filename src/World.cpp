#include "Entity.h"
#include "Player.h"
#include "World.h"

void World::add(Entity *newEntity) {
	/*int c = 0;
	bool added = false;
	while (!added and c < MAX) {
		if (!updateList[c]) {
			updateList[c] = newEntity;
			added = true; }
		c++; }*/
}
void World::update() {
	int c = 0;
	Entity *active;
	while (c < MAX) {
		active = updateList[c];
		if(active) {
			if (active->active) active->update(); }
		c++; }
}
World::World() {
}
World::~World() { }