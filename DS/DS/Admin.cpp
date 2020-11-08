#include "Admin.h"
#include "users.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void Admin::clrscr() // clear
{
	cout << string(100, '\n');
}
void Admin::createEmployee()
{
	system("color C");
	cout << "\n\tEnter first name: ";
	cin >> fname;
	cin.clear();

	cout << "\n\tEnter Last name: ";
	cin >> lname;
	cin.clear();

	string temp_phone;
	cout << "\n\tEnter phone number: ";
	cin >> temp_phone;
	cin.clear();
	if (temp_phone.length() == 11)
	{
		phone = temp_phone;
	}
	else
	{
		while (temp_phone.length() != 11)
		{
			cout << "phone number must be 11 digit\n";
			cout << "\n input chone number: ";
			cin >> temp_phone;
			phone = temp_phone;
		}
	}

	cout << "\n\tEnter Birthday(01/01/1900): ";
	cin >> dob;
	cin.ignore();

	cout << "\n\tEnter Designation: ";
	cin >> designation;
	cin.clear();

	cout << "\n\tEnter Employee Age: ";
	cin >> age;
	cin.clear();

	cout << "\n\tEnter Employee CTC: ";
	cin >> ctc;
	cin.clear();

	cout << "\n\tEnter Employee Experience: ";
	cin >> experience;
	cin.clear();

	char atype = '\0';
	cout << "\n\tSelect Accounts Type(Savings s / Creating c): ";
	cin >> atype;
	if (tolower(atype) == 's')
	{
		type = "Saved";
	}
	else
	{
		type = "Created";
	}

	employeeNumber = get_last_index_Employee();
	cout << "\n\tYour Accounts Number: " << employeeNumber;

	cout << "\n\tEnter passEmployee (min 4 digit): ";
	cin >> passEmployee;

	cout << "\n\t Enter Primary salary: ";
	cin >> salary;

	ofstream file("Employee_details.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << phone << " " << dob << " "<< designation <<" " 
		<< age <<" " << ctc <<" " << experience << " " << type << " " << employeeNumber << " " 
		<< passEmployee << " " << salary << endl;
	cout << endl;
	number_system_put_Employee(employeeNumber);
	file.close();
}

void Admin::search_Employee(int employee_no) //employee_no for user session for only specified user can show
{
	int flag = 0;
	Admin(); //constructor call to empty variables;
	ifstream file_read("Employee_details.txt", ios::in);
	cout <<"\n\tEnter Accounts number: ";
	cin >> employee_no;
	//cin.clear();

	while (file_read)
	{
		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;

		if (file_read.eof())
		{
			break;
		}

		if (employee_no == employeeNumber)
		{
			system("color 6");
			cout << "\n\tAccounts Number	: " << employeeNumber;
			cout << "\n\tName			:" << fname << " " << lname;
			cout << "\n\tPhone			:" << phone;
			cout << "\n\tDate of birth		:" << dob;
			cout << "\n\tDesignation		:" << designation;
			cout << "\n\tAge			:" << age;
			cout << "\n\tCost to company (CTC)	:" << ctc << " Egy";
			cout << "\n\tExperience		:" << experience;
			cout << "\n\tAccounts Type		:" << type;
			cout << "\n\tSalary			:" << salary << " Egy.";
			cout << "\n\n\n";
			flag = 1;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	file_read.close();
}

void Admin::delete_Employee(int employee_no)
{
	char buff;
	int flag = 0;
	string a = "Employee_details.txt";
	string b = "temp_Employee.txt";
	Admin();//constructor call to empty variables;

	ifstream file_read("Employee_details.txt", ios::in);
	ofstream file_temp("temp_Employee.txt", ios::out | ios::app);
	cout << "\n\tEnter Accounts number: ";
	cin >> employee_no;
	cin.clear();

	while (!file_read.eof())
	{
		file_read >> fname;	
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;

		if (file_read.eof())
		{
			break;
		}
		if (employee_no == employeeNumber)
		{
			cout << fname << " " << lname << "\t" << phone << "\t" << dob
				<< "\t" << designation << "\t" << age << "\t" << ctc << "\t" << experience
				<< "\t" << type << "\t" << employeeNumber << "\t" << passEmployee << "\t" << salary << endl;
			flag = 1;

		}
		else 
		{
			file_temp << fname << " " << lname << "\t" << phone << "\t" << dob
				<< "\t" << designation << "\t" << age << "\t" << ctc << "\t" << experience
				<< "\t" << type << "\t" << employeeNumber << "\t" << passEmployee << "\t" << salary << endl;
		}
		if (flag != 1)
		{
			cout << "\n\tNo record found";
		}
		file_temp.close();
		file_read.close();
		copy_content_Employee(b,a);
		
		cout << "\n\t Accounts Is Removed!\n";
	}
}

void Admin::update_Employee(int employee_no)
{
	int flag = 0;
	string a = "Employee_details.txt";
	string b = "tempEmployee.txt";

	Admin();//constructor call to empty variables;
	ifstream file_read("Employee_details.txt", ios::in);
	ofstream file_temp("tempEmployee.txt", ios::out | ios::app);
	cout << "\n\tEnter Enployee  number: ";
	cin >> employee_no;
	//cin.clear();
	while (!file_read.eof())
	{

		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;

		if (file_read.eof())
		{
			break;
		}

		if (employee_no == employeeNumber)
		{
			system("color 7");
			cout << "\n\Employee Number is: " << employeeNumber;
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New First name: ";

			cin >> fname;
			cin.clear();

			cout << "\n\t New Last name: ";
			cin >> lname;
			cin.clear();

			cout << "\n\t New phone: ";
			cin >> phone;
			cin.clear();

			cout << "\n\t New Birthday(01/01/1900): ";
			cin >> dob;
			cin.clear();

			cout << "\n New Designation: ";
			cin >> designation;
			cin.clear();

			cout << "\n New Employee Age: ";
			cin >> age;
			cin.clear();

			cout << "\n New Employee CTC: ";
			cin >> ctc;
			cin.clear();

			cout << "\n New Employee Experience: ";
			cin >> experience;
			cin.clear();

			cout << "\n\t Current Employee Type: " << type;
			cout << "\n\t Change Type (Saving s/Other o) otherwiese press (N): ";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !Employee type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
			}
			else
			{
				type = "Other";
			}
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << designation 
				<< " " << age << " " << ctc << " " << experience <<" " << type
				<< " " << employeeNumber << " " << passEmployee << " " << salary << endl;
			flag = 1;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << designation
				<< " " << age << " " << ctc << " " << experience << " " << type
				<< " " << employeeNumber << " " << passEmployee << " " << salary << endl;
		}

	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content_Employee(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear_Employee();
}

/*
copy content function for copy text to other file
*/
void  Admin::copy_content_Employee(string a, string b)
{
	char ch;
	int flag = 0;
	ifstream temp_read(a.c_str(), ios::in);
	ofstream file_write(b.c_str(), ios::out);
	while (!temp_read.eof())
	{
		temp_read.get(ch);
		file_write.put(ch);
		flag = 1;
	}
	if (flag != 1)
	{
		cout << "\n\tFile Error !";
	}
}

int Admin::get_last_index_Employee() {
	ifstream infile("numberEmployee.txt");
	string sLine;
	if (infile.good())
	{
		getline(infile, sLine);
		cout << sLine << endl;
	}
	infile.close();
	int last = std::stoi(sLine);
	return last++;
}

void  Admin::number_system_put_Employee(int n1)
{
	n1 = n1 + 1;
	ofstream number_write("numberEmployee.txt", ios::out);
	number_write << n1;
}

////functions for account number automation
//int number_system_get()
//{
//	int number;
//	ifstream number_read("number.txt", ios::in);
//	number_read >> number;
//	return number;
//}

void  Admin::temp_file_clear_Employee()
{
	char ch;
	int flag = 0;
	ofstream temp_write("tempEmployee.txt", ios::out);

	temp_write << " ";
	temp_write.close();
}

/*Start entmini statem function */
void Admin::ministatement_Employee(int user_no)
{
	int number, amount, flag = 0, psalary = 0;
	string status;
	Admin();//constructor call to empty variables;
	ifstream file_read("Employee_details.txt", ios::in);

	while (file_read)
	{

		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == employeeNumber)
		{
			psalary = salary;
		}
	}

	file_read.close();
	//transection part

	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\n\Employee Number: " << employeeNumber << endl;
	cout << "\n\n";

	ifstream tr_file_read("transecEmployee.txt", ios::in);
	//cin.clear();
	cout << "\n\t" << "Employee" << " | " << "CR / DR " << endl;

	while (tr_file_read)
	{
		tr_file_read >> number;
		tr_file_read >> amount;
		tr_file_read >> status;
		if (tr_file_read.eof())
		{
			break;
		}

		if (user_no == number)
		{
			cout << "\t" << amount << " | " << status << " | " << endl;
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	cout << "\n\n";
	cout << "Total Primary salary: " << psalary << "/." << endl;
	tr_file_read.close();
	 
}

/*End mini statement function */
void Admin::show_Employees()
{
	int count = 0;
	Admin e;

	ifstream file_read("Employee_details.txt", ios::in);
	if (!file_read)
	{
		system("color 4");
		cout << "File could not be open !! Press any Key...";
		return;
	}
	system("color 4");
	cout << "\n\n\t\tEMPLOYEES LIST\n\n";
	cout << "==================================================================================================================================================\n";

	cout << "Name" << "	    		   " << "Phone" << "	" << "Data Birthday" << "	" << "Designation" << " "<< "Age" << "	" << "CTC" <<" "<< "Experience" << "    " << "Type" << "  " << "ID" << "  " << "Password" << " " << "Salary" << endl;

	cout << "==================================================================================================================================================\n";
	string word;
	while (file_read >> word)
	{
		cout << word << "	";
		if (count >= 12)
		{
			cout << endl;
			count = 0;
		}
		count++;
	}
	file_read.close();
	cout <<"\n\n\n";
}

//menu for register Admin_menu
void Admin::Admin_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Admin ad;
	do {
		system("color E");
		cout << "\n\t\t\t 1- Create An Employee";
		cout << "\n\t\t\t 2- View Info Of Employee";
		cout << "\n\t\t\t 3- Show All Employee";
		cout << "\n\t\t\t 4- Delete Employee";
		cout << "\n\t\t\t 5- Update Your Details Of Employee";
		cout << "\n\t\t\t 6- MiniStatement Of Employee";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-6): ";

		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Admins \n\n ";
				Sleep(10);
				//return;
				break; 
			case 1:
				system("cls");
				ad.createEmployee();
				break;
			case 2:
				system("cls");
				ad.search_Employee(user_sesstion);
				break;

			case 3:
				system("cls");
				ad.show_Employees();
				break;

			case 4:
				ad.delete_Employee(user_sesstion);
				break;
			case 5:
				system("cls");
				ad.update_Employee(user_sesstion);
				break;

			case 6:
				ad.ministatement_Employee(user_sesstion);
				break;

			default:
				cout << "\n\tWorng choise \n";
				break;
			}
		}
		else
		{
			cout << "\n\t Input only Digits please!";
			cin.clear();
			cin.ignore();
			ch = 10;
		}

	}while (ch != 0);
}

void Admin::login_Admin(int user, int pass)
{
	Employee e;
	int flag = 0;

	//getting data from file
	ifstream file_read("Employee_details.txt", ios::in);
	while (!file_read.eof())
	{
		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;
		if (file_read.eof())
		{
			break;
		}
		
		if (user == employeeNumber && pass == passEmployee)
		{
			cout << "\n Login sucessful...!" << endl;
			e.employee_menu(user);
			flag = 1;
		}

	}
	if (flag == 0)
	{
		cout << "\n Username & password Employee Not matched !" << endl;

	}
	file_read.close();
}


void Admin::login_Admin_menu(int user_admin)
{
	Admin ad;
	int flag = 0;
	
	if (user_admin == 0000)
	{
		cout << "\n Login sucessful !" << endl;
		ad.Admin_menu(user_admin);
		flag = 1;
	}

	if (flag == 0)
	{
		cout << "\n password Admin Not matched !" << endl;

	}

}