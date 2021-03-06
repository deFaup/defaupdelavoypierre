#ifndef GLOBAL_MUTEX_H
#define GLOBAL_MUTEX_H

#include <mutex>
#include <condition_variable>

// pour l'export sous format json
#include <fstream>
#include <json/json.h>

//#include <random> //mt19937 //uniform_int_distribution
#include <cstdlib>	//srand
#include <ctime>	// time

namespace global
{
	extern std::mutex next_player;
	extern std::condition_variable next_player_cv;

	extern std::mutex get_engine;

	/* json */
	extern Json::Value json_commandes;

	//extern std::mt19937 rng;
	//extern std::uniform_int_distribution<std::mt19937::result_type> dist6;
	extern unsigned int server_seed;

	/* Network variables */
	extern std::string player_id;
	extern std::string player_name;
	extern int character_id;

}

#endif