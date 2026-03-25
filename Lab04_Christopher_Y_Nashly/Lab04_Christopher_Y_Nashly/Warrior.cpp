#include "Warrior.h"
#include <sstream>
#include <iostream>
using namespace EIF201;

int Warrior::clampRange(int value, int mn, int mx) {
	if (value < mn) return mn;
	if (value > mx) return mx;
	return value;
}

bool Warrior::isValidClass(std::string cls) {
	return cls == "Tank" || cls == "Assassin"
		|| cls == "Mage" || cls == "Support";
}

		

Warrior::Warrior(std::string name, std::string combatClass,	int attack, int defense, int health,
	int maxSkills): name(name.empty() ? "Unknown" : name),combatClass(isValidClass(combatClass)? combatClass : "Support"),
	attack(clampRange(attack, 1, 100)),
	defense(clampRange(defense, 1, 100)),
	health(clampRange(health, 1, 1000)),
	skillCount(0),
	maxSkills(maxSkills > 8 ? maxSkills : 3) {


	// TODO: crear el arreglo dinamico de punteros
	// a Skill con capacidad this->maxSkills.
	// Inicializar cada posicion a nullptr.
}

Warrior ::~Warrior() {

	// TODO: Liberar cada Skill individual (delete)
	// y luego el arreglo de punteros (delete[]).
	// Nulificar todo.
}

bool Warrior::learnSkill(std::string name, std::string type, int power, int cost) {

	    // TODO:
        // 1. Si ya conoce una habilidad con ese nombre,
		// 2. Si skillCount >= maxSkills, retornar false.
		// 3. Crear una nueva Skill en el heap con new.
		// 4. Almacenarla en skills[skillCount].
		// 5. Incrementar skillCount.
		// 6. Retornar true.



	return false;
}

bool Warrior::hasSkill(std::string name)const {
	for (int i = 0; i < skillCount; i++) {
		if (skills[i]->getName() == name) {
			return true;
		}
		return false;
	}

}

int Warrior::totalSkillEffect()const {
	int suma = 0;
	for (int i = 0; i < skillCount; i++) {
		suma += skills[i]->calculateEffect();
		return suma;
	}
	
}

int Warrior::calculatePower()const {

	// TODO: retornar la formula:
    // (attack * 2) + defense + (health / 10) 
	// +totalSkillEffect()



	return 0;//Placeholder
}

std::string Warrior::getName()const { return name; }
std::string Warrior::getCombatClass()const { return combatClass; }
int Warrior::getAttack()const { return attack; }
int Warrior::getDefense()const { return defense; }
int Warrior::getHealth()const { return health; }
int Warrior::getSkillCount()const { return skillCount; }

std::string Warrior::toString()const {
	std::ostringstream oss;
	oss << "[" << combatClass << "]" << name
	    << "|Attack   " << attack << " DEF" << defense 
	    << "|HP       " << health << "skills" << skills
	    << "/" << maxSkills << "/Power: " << calculatePower;
	return oss.str();
}

void Warrior::showSkills()const{
	std::cout << " Skill of " << name
		<< ":" << std::endl;
	for (int i = 0; i < skillCount; i++) {
		std::cout << "      - "
			<< skills[i]->toString()
			<< std::endl;
    }


}









