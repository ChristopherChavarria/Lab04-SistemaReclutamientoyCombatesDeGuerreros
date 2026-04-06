#include "Squad.h"
#include <sstream>
#include <iostream>
using namespace EIF201;

Squad::Squad(std::string name, int capacity) : name(name.empty() ? "Unnamed Squad" : name), capacity(capacity > 0 ? capacity : 3), count(0) {
	warriors = new Warrior*[capacity];
	for (int i = 0; i < capacity; i++) {
		warriors[i] = nullptr;
	}
}

Squad::~Squad() {
	for (int i = 0; i < count; i++) {
		delete warriors[i];
	}
	delete[]warriors;
}

void Squad::expand() {

	int newCapacity = capacity * 2;

	Warrior** newArray = new Warrior * [newCapacity];

	for (int i = 0; i < count; i++) {
		newArray[i] = warriors[i];
	}

	for (int i = count; i < newCapacity; i++) {
		newArray[i] = nullptr;
	}

	delete[] warriors;
	warriors = newArray;
	capacity = newCapacity;
}

Warrior* Squad::recruit(std::string name, std::string cls, int atk, int def, int hp, int maxSkills) {
	if (count >= capacity) {
		expand();
	}
	Warrior* newWarrior = new Warrior(name, cls, atk, def, hp, maxSkills);
	warriors[count] = newWarrior;
	count++;
	return newWarrior;
}

bool Squad::dismiss(std::string name) {
	for (int i = 0; i < count; i++) {
		if (warriors[i]->getName() == name)
		{
			delete warriors[i];
			for (int j = i; j < count - 1; j++) {
				warriors[j] = warriors[j + 1];
			}
			warriors[count - 1] = nullptr;
			count--;
			return true;
		}

	}
	return false;
}

int Squad::totalPower() const {
	int total = 0;
	for (int i = 0; i < count; i++) {
		total += warriors[i]->calculatePower();
	}
	return total;
}

void Squad::showSquad() const {
	std::cout << "Escuadron: " << name << " (Total Power: " << totalPower() << ")\n";
	for (int i = 0; i < count; i++) {
		std::cout << " - " << warriors[i]->toString() << "\n";
	}
}

int Squad::getCount()const {
	return count;
}

std::string EIF201::Squad::getName() const
{
	return std::string();
}



Warrior** Squad::getByClass(std::string cls, int& resultCount) const {
	resultCount = 0;

	for (int i = 0; i < count; i++) {
		if (warriors[i]->getCombatClass() == cls) {
			resultCount++;
		}
	}

	if (resultCount == 0) {
		return nullptr;
	}

	Warrior** result = new Warrior * [resultCount];
	int index = 0;
	for (int i = 0; i < count; i++) {
		if (warriors[i]->getCombatClass() == cls) {
			result[index] = warriors[i];
			index++; }
	}
	return result;
}

void Squad::sortByPower() {

	for (int i = 0; i < count - 1; i++) {

		for (int j = 0; j < count - i - 1; j++) {

			if (warriors[j]->calculatePower() < warriors[j + 1]->calculatePower()) {

				Warrior* temp = warriors[j];
				warriors[j] = warriors[j + 1];
				warriors[j + 1] = temp;

			}
		}

	}

}

std::string Squad::simulateBattle(const Squad& enemy) const {

	int myPower = totalPower();
	int enemyPower = enemy.totalPower();

	std::stringstream result;

	result << "Battle Result:\n";
	result << name << " Power: " << myPower << "\n";
	result << enemy.getName() << " Power: " << enemyPower << "\n";

	if (myPower > enemyPower) {
		result << "Winner: " << name;
	}
	else if (enemyPower > myPower) {
		result << "Winner: " << enemy.getName();
	}
	else {
		result << "Result: Draw";
	}

	return result.str();
}





