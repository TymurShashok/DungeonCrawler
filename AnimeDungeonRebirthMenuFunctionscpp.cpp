#include "AnimeDungeonRebirthHeader.h"

void main_menu() {
	
	std::ifstream infile("Interface/MainMenu.txt");
	std::string buf;
	if (!infile) {
		std::cout << "Don`t Open!";
		return;
	}
	while (infile.eof() == 0) {

		std::getline(infile, buf);
		std::cout << buf << std::endl;

	}

}



void fighting_tab() {

	std::ifstream infile("Interface/Fighting.txt");
	std::string buf;
	if (!infile) {
		std::cout << "Don`t Open!";
		return;
	}
	while (infile.eof() == 0) {

		std::getline(infile, buf);
		std::cout << buf << std::endl;

	}

}

void box_top_and_bottom(int width) {
	std::cout << '+' << std::setfill('-') << std::setw((width*2) + 4) << '-' << std::setfill(' ') << '+' << std::endl;
}
void fighting_box_line(std::string playerstat, std::string monsterstat, int width)
{
	std::cout << std::left << "| " << std::setw(width) << playerstat;
	std::cout << std::left << "| " << std::setw(width) << monsterstat << " |\n";
}

std::string stat_to_string(double value) {
	return std::to_string(static_cast<int>(value));
}

void fighting_box(PLAYER player, MONSTERS monster)
{
	const int width = 17;
		fighting_box_line(player.get_name(), monster.get_name(), width);

		fighting_box_line("LEVEL: " + stat_to_string(player.get_Level()), "LEVEL: " + std::to_string(monster.get_Level()), width);;
		fighting_box_line("HP: " + stat_to_string(player.get_HP()), "HP: " + stat_to_string(monster.get_HP()), width);
		fighting_box_line("MANA: " + stat_to_string(player.get_mana()), "MANA: " + stat_to_string(monster.get_mana()), width);
		fighting_box_line("ATTACK: " + stat_to_string(player.get_damage()), "ATTACK: " + stat_to_string(monster.get_damage()), width);
		box_top_and_bottom(width);
}


void fighting_stats(PLAYER player, MONSTERS monster) {

	fighting_box(player, monster);
}

void default_box_line(std::string text, int width)
{
	std::cout << std::left << "| " << std::setw(width*2 + 2) << text << " |\n";
}

void action_tab_box(PLAYER player, MONSTERS monster, char action) {
	const int width = 17;
	action = static_cast<int>(action) - '0';
	action_tab_menu();
	switch (action) {
	case 1: {
		for (int i = 1; i <= 4; i++) {
			default_box_line(player.get_skill_name(i), width);
		}
		break;
	}
	default: {
		default_box_line("[1] = ATTACK", width);
		default_box_line("[2] = BAG", width);
		default_box_line("[3] = RUN", width);
		break;
	}
	}
	box_top_and_bottom(width);
}

void action_tab(PLAYER player, MONSTERS monster, char action) {

	action_tab_box(player, monster,  action);
}


// Interface for level up!
void level_up_tab_box(PLAYER& player, MONSTERS monster) {
	const int width = 17;
	
	std::cout << "\033[90mYou earned a " << static_cast<int>(monster.get_drop_experienece()) << " experience" << std::endl;
	
	if (get_new_lvl(player) == true) {
		std::cout << "Congratulations you got level up! \033[33m" << player.get_Level() << "\033[0m" << std::endl;
	}
	else {
		std::cout << "You need " << static_cast<int>(player.get_Max_Experience() - player.get_experience()) << " experience for level up!\033[0m" << std::endl;
	}
	_getch();
	system("cls");
}





void move_choice() {

	std::ifstream infile("Interface/moveChoice.txt");
	std::string buf;
	if (!infile) {
		std::cout << "Don`t Open!";
		return;
	}
	while (infile.eof() == 0) {

		std::getline(infile, buf);
		std::cout << buf << std::endl;

	}

}

void action_tab_menu() {

	std::ifstream infile("Interface/Action_Tab.txt");
	std::string buf;
	if (!infile) {
		std::cout << "Don`t Open!";
		return;
	}
	while (infile.eof() == 0) {

		std::getline(infile, buf);
		std::cout << buf << std::endl;

	}

}

