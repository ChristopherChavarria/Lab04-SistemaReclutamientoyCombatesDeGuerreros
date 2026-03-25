#ifndef SKILL_H
#define SKILL_H

#include <string>

namespace EIF201 {

    class Skill {
    private:
        std::string name;
        std::string damageType;  // "Physical", "Magical", "Healing"
        int power;               // 1-200
        int energyCost;          // 0-100

        int clampRange(int value, int min, int max); // Validad el rango de un valor
        bool isValidType(std::string type);

    public:
        Skill(std::string name, std::string damageType, int power, int energyCost);

        ~Skill();

        std::string getName() const;
        std::string getDamageType() const;
        int getPower() const;
        int getEnergyCost() const;

        // Physical: power * 1.0
        // Magical: power * 1.5
        // Healing: power * 0.8
        int calculateEffect() const;

        std::string toString() const;
    };

}

#endif

