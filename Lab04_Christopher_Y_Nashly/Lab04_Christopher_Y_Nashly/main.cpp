#include <iostream>
#include "Squad.h"

using namespace EIF201;

int main()
{
    std::cout << "Iniciando el Escuadron" << std::endl;

	Squad* squad = new Squad("Alpha");
	squad->recruit("Thor", "Tank", 80, 70, 1200 , 5);
	squad->recruit("Loki", "Assassin", 90, 50, 635, 4);
	squad->recruit("Odin", "Mage", 85, 60, 700, 6);

	squad->showSquad();







	


	delete squad;
	return 0;









   
}

