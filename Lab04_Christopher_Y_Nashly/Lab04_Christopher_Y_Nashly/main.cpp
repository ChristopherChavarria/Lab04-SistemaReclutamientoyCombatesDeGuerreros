#include <iostream>
#include "Squad.h"
#include "Warrior.h"
#include "Skill.h"

int main() {

    EIF201::Squad squad1("Heroes of Hyrule", 3);


    EIF201::Warrior* w1 = squad1.recruit("Rengar", "Assassin", 80, 60, 500, 5);
    EIF201::Warrior* w2 = squad1.recruit("Murker", "Tank", 70, 90, 800, 5);
    EIF201::Warrior* w3 = squad1.recruit("Luna", "Mage", 60, 50, 400, 5);
    EIF201::Warrior* w4 = squad1.recruit("Jinx", "Support", 50, 60, 450, 5);
    EIF201::Warrior* w5 = squad1.recruit("Morde", "Bruiser", 85, 55, 420, 5);


    w1->learnSkill("Sword Slash", "Physical", 100, 20);
    w1->learnSkill("Spin Attack", "Physical", 120, 30);

    w2->learnSkill("Shield Bash", "Physical", 90, 15);
    w2->learnSkill("Rock Smash", "Physical", 110, 25);

    w3->learnSkill("Fireball", "Magical", 130, 40);
    w3->learnSkill("Lightning", "Magical", 150, 50);



    std::cout << "\n-----------Squad Inicial-----------" << std::endl;
    squad1.showSquad();


    squad1.sortByPower();

    std::cout << "\n-----------Squad Ordenado por Poder-----------" << std::endl;
    squad1.showSquad();


    int resultCount = 0;
    EIF201::Warrior** assassins = squad1.getByClass("Assassin", resultCount);

    std::cout << "\n-----------Guerreros Assassin-----------" << std::endl;

    if (assassins != nullptr) {
        for (int i = 0; i < resultCount; i++) {
            std::cout << assassins[i]->getName() << std::endl;
        }
        delete[] assassins; 
    }


    std::cout << "\nEliminando a Morde..." << std::endl;
    squad1.dismiss("Morde");

    std::cout << "\n-----------Squad Actualizado-----------" << std::endl;
    squad1.showSquad();


    EIF201::Squad squad2("Ganondorf Army", 3);

    EIF201::Warrior* e1 = squad2.recruit("Moblin", "Tank", 75, 80, 700, 5);
    EIF201::Warrior* e2 = squad2.recruit("Lizalfos", "Assassin", 85, 50, 450, 5);
    EIF201::Warrior* e3 = squad2.recruit("Dark Mage", "Mage", 70, 40, 400, 5);

    e1->learnSkill("Heavy Smash", "Physical", 110, 25);
    e2->learnSkill("Poison Strike", "Physical", 120, 30);
    e3->learnSkill("Dark Fire", "Magical", 140, 45);


    std::cout << "\n-----------Simulacion de Batalla-----------" << std::endl;
    std::cout << squad1.simulateBattle(squad2) << std::endl;

    bool removed = squad1.dismiss("Ganon");

    if (!removed) {
        std::cout << "\nNo se encontro el guerrero Ganon." << std::endl;
    }

    return 0;
}