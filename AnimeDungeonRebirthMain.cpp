#include "AnimeDungeonRebirthHeader.h"

PLAYER player = {Virtus_Hammer, StartClothes}; // stats / weapon / armor

enum COMMANDS { PLAY = '1', INVENTORY = '2', SHOP = '3', SETTINGS = '4', };

int main() {

	srand(time(NULL));

	
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	/*player.getAll();*/

	//_getch();

	//test
	//player.get_experience(ORC.get_drop_experienece());
	//test_experience(player.get_experience(), 40);
	//get_new_lvl(player);
	//std::cout << player.get_Level();

	char cmd;

	do {
		player.Revive();
		std::cout << std::setfill('=') << std::setw(100) << " " << std::endl;
		std::cout << std::setfill(' ') << std::setw(65) << Name << std::endl;;
		std::cout << std::setfill('=') << std::setw(100) << " " << std::endl;
		main_menu();
		std::cout << std::setfill('=') << std::setw(100) << " " << std::endl;
		std::cout << std::setfill(' ');
		cmd = fighting_choice();
		system("cls");
		switch (cmd) {
		case PLAY: {

			forest_dungeon(player, forest_stats_range);

			break;
		}
		case INVENTORY: {

			break;
		}
		case SHOP: {

			break;
		}



		}

	} while (true);


}




//fight(player, ORC);