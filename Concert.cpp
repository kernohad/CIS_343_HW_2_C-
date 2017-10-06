/*********************************************************
*	A file that implements the Concert.h
*	
*	Created by: Dylan Kernohan on 10/2/2017
**********************************************************/

#include "Concert.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

/***************************
*	Default Constructor
***************************/
Concert::Concert(){
	concertName = "";
	friends.clear();
	desire = -1;
	date.tm_year = 2099;
	date.tm_mon = 1;
	date.tm_mday = 1;
}


/***************************
*	Constructor
***************************/
Concert::Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date ){
	this -> concertName = concertName;
	this -> friends = friends;
	this -> desire = desire;
	this -> date = date;

}


/***************************
*	Deconstructor
***************************/
Concert::~Concert(){



}



/***************************
*	< Operator Overload
*
*	Compare a concert by date first
*	then its desire
***************************/
bool Concert::operator<(const Concert& other) const{

	if (date.tm_year < other.date.tm_year){
		return true;
	}
	else if (date.tm_year == other.date.tm_year){
		if(date.tm_mon < other.date.tm_mon){
			return true;
		}
		else if(date.tm_mon == other.date.tm_mon){
			if(date.tm_mday < other.date.tm_mday)
				return true;
			else if(date.tm_mday == other.date.tm_mday){
				if(desire > other.desire){
					return true;
				}
			}
		}
	}


	return false;

}


/***************************
*	Getters
***************************/
std::string Concert::getConcertName(){
	return concertName;
}

std::vector<std::string> Concert::getFriends(){
	return friends;
}

int Concert::getDesire(){
	return desire;
}

std::tm Concert::getDate(){
	return date;
}


/***************************
*	Main
***************************/
int main(int argc, char* argv[]){
	std::tm tempdate;
	tempdate.tm_year = 1999;
	tempdate.tm_mon = 1;
	tempdate.tm_mday = 1;
	std::vector<std::string> sample {"dylan", "ryan", "keith"};
	auto concert_1 = new Concert("bobb", sample, 4, tempdate);

	
}
