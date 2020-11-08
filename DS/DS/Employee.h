#pragma once
#include "Accounts.h"

class Employee:public Accounts
{
public:
	void clrscr();
	void createAccount(); 		//functionv for openning new account
	void searchDetails(int);	//function to search details of perticular user
	void delete_details(int);		//function for deleting record
	void update_details(int); 	//function for updating record
	void close_details(int);  //function for close record
	void showDetails(); //function for showing account details
	void temp_file_clear();//for clearing temp file
	void copy_content(string a, string b); //global declaration
	void number_system_put(int n1);
	int get_last_index();  //account number automation 
	void ministatement(int); //function for ministatement
	void employee_menu(int);
};