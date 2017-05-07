#include<iostream>

class lifeform {
protected:
	int hp = 100, shield_hp = 0;
public:
	int get_hp() { return hp; }
	int get_shield_hp() { return shield_hp; }
	void subtract_hp(int damage) { hp -= damage; };
	void subtract_shield_hp(int damage) { shield_hp -= damage; };
	void set_shield_hp(int h) { shield_hp = h; }
	void show_hp() {
		std::cout << " hero HP <" << hp << "/100>:";
		for (int i = 0; i<hp; i = i + 10) {
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	void show_shield_hp() {
		std::cout << "shell HP <" << shield_hp << "/100>:";
		for (int i = 0; i<shield_hp; i = i + 10) {
			std::cout << "|";
		}
		std::cout << std::endl;
	}
};

class swordsman : virtual public lifeform {
protected:
	int weapon;
public:
	void set_weapon(int w) { weapon = w; }
	int get_weapon() { return weapon; }
	int attack() {// return the damage
		int damage;
		switch (weapon) {
		case 0:
			damage = 10;
			break;
		case 1:
			damage = 20;
			break;
		case 2:
			damage = 100;
			break;
		}
		return damage;
	}
};

class wizard : virtual public lifeform {
protected:
	int wand, skill = -1;
public:
	void set_wand(int w) { wand = w; }
	int get_wand() { return wand; }
	void set_skill(int s) { skill = s; }
	int get_skill() { return skill; }
	void spell();
};

class magicka : public swordsman, public wizard {
protected:
	int profession;//sword or magic
public:
	void set_profession(int i) { profession = i; };
	int get_profession() { return profession; };
};

class boss {// damage 50
private:
	friend class swordsman;
	friend class wizard;
	int hp = 500;
public:
	int get_hp() { return hp; }
	void show_hp() {
		std::cout << " boss HP <" << hp << "/500>:";
		for (int i = 0; i<hp; i = i + 10) {
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	void subtract_hp(int damage) { hp -= damage; }
};

