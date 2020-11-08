#pragma once
#include "users.h"
#include<iostream>
#include<string>
using namespace std;

class Accounts : public users
{
protected:
		int accountNumber;
		int account_pass;
		int balance;
		string type; //for account type
public:
		Accounts()
		{
			accountNumber = 0;
			balance = 0;
			account_pass = 0;
		}
		/*~Accounts() {}*/

		void CurrentBalance(int);	//balance chack
		void login_user(int, int);	//login function
		void Deposit(int, int);     //Deposit
		void deduct_Money(int, int); //Deduct Money
		void viewTransfare(int); //view all transections 
		void transfareTO(int); //For tranfering fund between tow users
		void user_menu(int);
};




