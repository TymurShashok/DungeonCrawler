#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 

#include "AnimeDungeonRebirthRandom.h"
#include "AnimeDungeonRebirthSKILLS.h"
#include "AnimeDungeonRebirthMODIFIERS.h"
#include "AnimeDungeonRebirthSWORDS.h"
#include "AnimeDungeonRebirthARMORS.h"
#include "AnimeDungeonRebirthMONSTERS.h"


const std::string Name = "\033[1m Anime Dungeon: Rebirth\033[0m";

class STATS {

	// HP_ AND mana_
private:
	int level_ = 1;
	double experience_ = 0;
	double max_experience_ = 80 * level_;
	int skill_points_ = level_ * 3;
	double HP_ = 100.0;
	double mana_ = 100.0;

	/// ABILITES

	int strength_ = 1;
	int intelegience_ = 1;
	int vitality_ = 1;
	int agility_ = 1;

public:
	STATS(): level_(1), experience_(0), max_experience_(80), skill_points_(0), HP_(20), mana_(100), strength_(0), intelegience_(0), vitality_(0), agility_(0) {}
	STATS(int Lvl,  double Health, double M, int STR, int INT, int VIT, int AGI) : level_(Lvl), HP_(Health), mana_(M), strength_(STR), intelegience_(INT), vitality_(VIT), agility_(AGI) {}

	// get

	int get_level() {
		return level_;
	}

	double get_experience() {
		return experience_;
	}

	double get_max_experience() {
		return max_experience_;
	}

	double get_HP() {
		return HP_;
	}

	double get_mana() {
		return mana_;
	}

	int getStrenght() {
		return strength_;
	}
	int getIntelegience() {
		return intelegience_;
	}
	int getVitality() {
		return vitality_;
	}
	int getAgility() {
		return agility_;
	}

	// 

	void lvl_up(int Lvl) {
		level_++;
	}
	void set_level(int Lvl) {
		this->level_ = Lvl;
	}

	 void set_HP(double HP_) {
		this->HP_ = HP_;
	}
	 void set_mana(double mana_) {
		this->mana_ = mana_;
	}

	 void get_experience(double exp) {
		 this->experience_ += exp;
	 }
	 void reset_experience() {
		 this->experience_ = 0;
	 }

	 double get_max_HP() {
		 return 100.0 + vitality_ * 3.0;
	 }
	 double get_max_mana() {
		 return 100.0 + intelegience_ * 5;
	 }
};


class PLAYER {
private:
	std::string name;
	STATS stats;
	WEAPON weapon;
	ARMOR armor;

	bool PlayerState = true; // true = alive | false = dead

public:
	PLAYER() :name("None"), stats(), weapon(Wood_Sword), armor(StartClothes) {}
	PLAYER(WEAPON weapon, ARMOR arm) :name("None"), stats(), weapon(weapon), armor(arm) {}
	PLAYER(std::string name , STATS stats, WEAPON weapon, ARMOR arm) :name(name), stats(stats), weapon(weapon), armor(arm) {}

	bool is_alive() {
		if (PlayerState = true) {
			return true;
		}
		else {
			return false;
		}
	}

	void Die() {
		if (stats.get_HP() <= 0) {
			PlayerState = false;
		}
	}

	void Revive() {
		stats.set_HP(stats.get_max_HP());
		stats.set_mana(stats.get_max_mana());
		PlayerState = true;
	}

	std::string get_name() {
		return name;
	}

	double get_damage() {
		return weapon.get_visual_damage();
	}

	double attack(int g) {
		return weapon.get_damage(g) + stats.getStrenght() * 0.2;
	}

	void take_damage(double damage) {
		double take_damage = damage - armor.getDefense();
		stats.set_HP(stats.get_HP() - take_damage);
	}


	double get_mana() {
		return stats.get_mana();
	}
	double get_HP() {
		return stats.get_HP();
	}

	int get_Level() {
		return stats.get_level();
	}

	double get_experience() {
		return stats.get_experience();
	}

	double get_Max_Experience() {
		return stats.get_max_experience();
	}

	void lvl_up(int Lvl) {
		stats.lvl_up(Lvl);
	}

	std::string get_skill_name(int i) {

		return weapon.get_skill_name(i);
	}

	void get_experience(double exp) {
		stats.get_experience(exp);
	}

	void reset_experience() {
		stats.reset_experience();
	}

};

//==============================
//DUNGEONS 
//==============================

int dungeon_choice();
void forest_dungeon(PLAYER& player, MonsterStatsRange st);
void Dungeons(PLAYER& player, MONSTERS monster);





//==============================


//==============================
//FIGHTING
//==============================
int skill_choice(char skill);
char fighting_choice();
void Play(PLAYER& player, MONSTERS Monster); // Function for Play game; Dungeon Choice, Fighting and more;
void fight(PLAYER& player, MONSTERS Monster); // Fight Mechanic






//-------------------------------


//===============================
// Player
//===============================
bool get_new_lvl(PLAYER& player); // Function for lvl_up Mechanic



//--------------------------------




//===============================
// Interface
//===============================
void fighting_tab();

template<typename T>
void hp_bar(T player_or_Monster) {
	int i = 0;
	for (i; i < player_or_Monster.get_HP(); i += 10) {

		if (i % 20 == 0) {
			std::cout << "#";
		}

		if (i == player_or_Monster.get_HP()) {
			return;
		}

	}

}

std::string stat_to_string(double value);
void box_top_and_bottom(int width);
void fighting_box_line(std::string playerstat, std::string monsterstat, int width);

void fighting_box(PLAYER player, MONSTERS monster);
void fighting_stats(PLAYER player, MONSTERS monster);

void action_tab_menu();
void action_tab_box(PLAYER player, MONSTERS monster, char action);
void action_tab(PLAYER player, MONSTERS monster, char action);
void default_box_line(std::string text, int width);

void level_up_tab_box(PLAYER& player, MONSTERS monster); // level up menu;


void main_menu(); // main_menu of program
void move_choice();



//-------------------------------

// tests
void test_experience(double experience_, double Expected_experience);


//RANDOM_VALUE


MONSTERSTATS generate_stats(MONSTERSTATS& stats, MonsterStatsRange st);
MONSTERS random_forest_monster(int random_value, MonsterStatsRange st);