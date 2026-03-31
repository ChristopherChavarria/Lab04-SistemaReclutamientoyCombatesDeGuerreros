#ifndef SQUAD_H
#define SQUAD_H

#include <string>
#include "Warrior.h"

namespace EIF201 {

	class Squad {
	private:
		std::string name;
		Warrior** warriors;
		int capacity;
		int count;

		void expand(); // Método privado para duplicar la capacidad

	public:
		// Constructor y destructor
		Squad(std::string name, int capacity = 3);
		~Squad();

		// Métodos básicos
		Warrior* recruit(std::string name, std::string cls,
			int atk, int def, int hp, int maxSkills);

		bool dismiss(std::string name);

		int totalPower() const;

		void showSquad() const;

		int getCount() const;
		std::string getName() const;

		// Métodos avanzados
		Warrior** getByClass(std::string cls, int& resultCount) const;

		void sortByPower();

		std::string simulateBattle(const Squad& enemy) const;

	};

}

#endif
