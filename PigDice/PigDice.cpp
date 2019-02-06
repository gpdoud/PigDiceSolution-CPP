#include "pch.h"
#include <iostream>
#include <cstdlib>

int roll_die() {
	return rand() % 6 + 1;
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
	int world_record = 606;
	int high_score = 0;
	int games = 0;
	while(high_score <= world_record) {
		int score = play();
		games++;
		if(score > high_score) {
			high_score = score;
			std::cout << "WR is " << world_record 
				<< ", new HS is " << high_score
				<< " on game " << games << std::endl;
		}
	}
	std::cout << "New WR is " << high_score << std::endl;
}
