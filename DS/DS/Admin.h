#pragma once
#include "users.h"
#include<string>
using namespace std;
class Admin:public users
{
private:
	int employeeNumber;
	int passEmployee;
	int salary;
	string type; //for Employee type
	string designation; 
	int age;
	int ctc; // cost to company ( year)
	int experience;
public:
	Admin()
	{
		employeeNumber = 0;
		passEmployee = 0;
		salary = 0;
		age;
		ctc = 0;
		experience = 0;
		designation = "";
	}
	~Admin() {}
	void clrscr();
	void createEmployee(); 	//function for openning new Employee
	void search_Employee(int); //function to search details of perticular user
	void delete_Employee(int);	//function for deleting record_Employee
	void update_Employee(int);
	int get_last_index_Employee(); //Employee number automation 
	void number_system_put_Employee(int n1);
	void copy_content_Employee(string a, string b); //global declaration
	void temp_file_clear_Employee(); //for clearing temp file
	void ministatement_Employee(int); //function for ministatement
	void Admin_menu(int);
	void login_Admin(int, int);	//login_Admin function
	void login_Admin_menu(int);	//login_Admin_menu function
	void show_Employees(); //function for showing Employee details
};

