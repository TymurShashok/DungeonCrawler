#include "AnimeDungeonRebirthHeader.h"

enum DUNGEONS { FOREST = 1, CAVE = 2, AIRSHIP = 3, PIRATE_BOAT = 4, VOLCANO = 5, ROGUE_VILLAGE = 6 };

int dungeon_choice() {
	int number;
	std::cout << "Choose a dungeon: ";
	std::cin >> number;
	return number;
}

void forest_dungeon(PLAYER& player, MonsterStatsRange st) {
	const int forest_size = 3;
	for (int i = 0; i < forest_size; i++) {
		fight(player, random_forest_monster(random_value(1, 7), st));
		if (player.get_HP() < 0) {
			return;
		}
	}
}



void dungeons(PLAYER& player, MONSTERS monster) {
	int d_C = dungeon_choice();
	switch (d_C) {
	case FOREST: {

	}


	}
}
