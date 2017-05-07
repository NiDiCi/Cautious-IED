#include<iostream>
#include"Lifeform.h"

int main() {
	magicka m;
	boss b;
	//choose weapon
	int i, a;
	std::cout << "please choose weapon for hero. [0]:sword, [1]:M60, [2]Excalibur >>" << std::endl;
	std::cin >> i;
	m.set_weapon(i);
	std::cout << "please choose wand for hero. [0]:wood wand, [1]:silver wand, [2]gold wand >>" << std::endl;
	std::cin >> i;
	m.set_wand(i);
	//fight
	int round = 1, b_damage = 0, m_damage = 0;
	int show_shield = 0;
	int shell_on = 0;

	for (;; round++) {//boss and hero are alive
					  //boss win
		if (m.get_hp() <= 0) {
			std::cout << "you lose.";
			return 0;
		}
		else if (b.get_hp() <= 0) {
			std::cout << "you win.";
			return 0;
		}

		std::cout << "Round " << round << std::endl;
		b.show_hp();
		m.show_hp();
		if (show_shield == 1) { m.show_shield_hp(); }
		//m.show_shield_hp();
		std::cout << "boss attack!!" << std::endl;
		std::cout << "select attack or magic for hero. [0]:attack, [1]:magic >>";
		std::cin >> i;
		m.set_profession(i);
		if (m.get_profession() == 0) {//sword
			b_damage = m.attack();
			b.subtract_hp(b_damage);

			if (shell_on == 1) {//shield
				m_damage = 40;
				m.subtract_shield_hp(m_damage);
				show_shield = 1;
				a = m.get_shield_hp();
				std::cout << a << std::endl;
				//!
				if (a <= 0) {
					std::cout << "shell break" << std::endl;
					shell_on = 0;
					show_shield = 0;
				}
			}
			else {
				m_damage = 50;
				m.subtract_hp(m_damage);
			}

		}
		else {//magic
			std::cout << "select skill for hero. >>";
			std::cin >> i;
			m.set_skill(i);

			//wand
			float bonus;
			if (m.get_wand() == 0)   bonus = 1;
			else if (m.get_wand() == 1)  bonus = 1.2;
			else if (m.get_wand() == 2)  bonus = 2;
			//skill of wizard
			if (m.get_skill() == 0) {
				m.set_shield_hp(100);
				shell_on = 1;
			}
			else if (m.get_skill() == 1)  b_damage = 50 * bonus;
			else if (m.get_skill() == 13112) b_damage = 100 * bonus;
			b.subtract_hp(b_damage);
			//attack of boss
			if (shell_on == 1) {//shield
				m_damage = 40;
				m.subtract_shield_hp(m_damage);
				show_shield = 1;

				if (m.get_shield_hp() <= 0) {
					shell_on = 0;
					show_shield = 0;
				}
			}
			else {
				m_damage = 50;
				m.subtract_hp(m_damage);
			}
		}
		std::cout << "hero got " << m_damage << " damage" << std::endl;
		//!
		if (m.get_shield_hp() <= 0) {
			std::cout << "shell break" << std::endl;
			shell_on = 0;
		}
		std::cout << "boss got " << b_damage << " damage" << std::endl << std::endl;
	}
}