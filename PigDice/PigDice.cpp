#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int roll_die() {
	//return rand() % 6 + 1;
	return rng() % 6 + 1;
}
int play() {
	int score = 0;
	int roll;
	while((roll = roll_die()) != 1) {
		score += roll;
	}
	return score;
}
int main() {
//	srand(time(NULL));
	int world_record = 660;
	int high_score = 0;
	unsigned long long games = 0;
	while(high_score <= world_record) {
		int score = play();
		games++;
		if(score > high_score) {
			high_score = score;
            std::cout.imbue(std::locale(""));
			std::cout << "WR is " << world_record 
				<< ", new HS is " << std::setw(3) << std::right << high_score
				<< " on game " << std::setw(16) << std::right << games << std::endl;
		}
	}
	std::cout << "New WR is " << high_score << std::endl;
}
