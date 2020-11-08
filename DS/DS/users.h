#pragma once
#include<iostream>
#include<string>
using namespace std;

class users
{
public:

	char fname[10], lname[10];
	string phone;
	string dob; //Data Of BrithDay
	bool close = 0; // Status account false

	users()
	{
		phone = '\0';
		dob = '\0';
	}
	/*~users()
	{}*/
};


