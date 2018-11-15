#include "define.hpp"
#include "RandomAI.h"
#include <stdlib.h>
#include <time.h>

using namespace ai;
using namespace render;

/*RandomAI::RandomAI(){
}*/

RandomAI::RandomAI(engine::GameEngine& moteur) : moteur(moteur){}

void RandomAI::play(){
	if(moteur.etat.current_player->name == "IA"){
		srand(time(NULL));
		unsigned int nb_aleatoire = rand()%2;	
		if(nb_aleatoire == 0 || nb_aleatoire == 1){
			unsigned int nb_aleatoire2 = rand()%2;
			if(nb_aleatoire == 0){
				for(unsigned int k =0; k < (rand()%100); k++){
					sfEvents events(arrow_left);
					moteur.add_command(events);
				}
			}
			else{
				for(unsigned int k =0; k < (rand()%100); k++){
					sfEvents events(arrow_right);
					moteur.add_command(events);
				}
			}
		}		
		sfEvents events(enter);
		moteur.add_command(events);
	}
	return;
}