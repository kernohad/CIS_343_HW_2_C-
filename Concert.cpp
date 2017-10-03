/*********************************************************
*	A file that implements the Concert.h
*	
*	Created by: Dylan Kernohan on 10/2/2017
**********************************************************/

#include <Concert.h>
#include <string>
#include <vector>

/***************************
*	Default Constructor
***************************/
Concert::Concert(){


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