#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "Helper.h"
#include "Soldier.h"

using namespace std;

int main(){
	srand(time(NULL));
	Knight kArmy = Knight();
	Samurai sArmy = Samurai();
	float v1 = 0, v2 = 0;
	int kHealth = 0, sHealth = 0, kSize = 0, sSize = 0, kDeath = 0, sDeath = 0;
	string cont, winner; 

	cout << "~~~~~Samurai vs Knights~~~~~" << endl << endl;

	while (true){
		// Acquire army sizes; 
		kSize = getInt("Please enter the number of Knights in this battle: ");
		sSize = getInt("Please enter the number of Samurai in this battle: ");

		// While neither army is completely dead, continue 1 on 1 battles
		while (kSize > 0 && sSize > 0){
			// Upon death of a soldier, reset health
			kHealth = kArmy.getHealth();
			sHealth = sArmy.getHealth();


			// Battle begins and continues while neither soldier is dead
			while (sHealth > 0 && kHealth > 0){
				// Determine who gets to attack
				v1 = rand() % kArmy.getAttack();
				v2 = rand() % sArmy.getAttack();

				// Deal damage to appropriate soldier
				if (v1 > v2){
					sHealth -= kArmy.getDamage();
				}
				else if (v2 > v1){
					kHealth -= sArmy.getDamage();
				}
				else{
					continue;
				}
			}

			// Depending on who died, decrease size of army and increase death count
			if (kHealth <= 0){
				kSize -= 1;
				kDeath += 1;
			}
			else{
				sSize -= 1;
				sDeath += 1;
			}
		}

		// Post battle report
		cout << "The winner was the " << (sSize == 0 ? "Knights" : "Samurai") << endl;
		cout << "There were " << kDeath << " knights killed\n";
		cout << "There were " << sDeath << " samurai killed\n";

		// Reset values
		kDeath = 0;
		sDeath = 0;

		// Check if user wants another battle
		cout << "Would you like to do another battle? (<N> to say no)";
		cin >> cont;
		if ( cont == "N" || cont == "n" ) break;
		else continue;
	}

	return 0;
}