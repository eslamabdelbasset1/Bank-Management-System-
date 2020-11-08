#include "Accounts.h"
#include "users.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;	

void Accounts::login_user(int user, int pass)
{
	int flag = 0;
	//getting data from file
	ifstream file_read("account_details.txt", ios::in);
	while (!file_read.eof())
	{
		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		if (file_read.eof())
		{
			break;
		}
		if (user == accountNumber && pass == account_pass)
		{
			cout << "\n Login sucessful..!" << endl;
			user_menu(user);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "\n User name & account_pass Not matched!" << endl;

	}
	file_read.close();
}

void Accounts::CurrentBalance(int user_no)
{
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	while (file_read)
	{

		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;

		if (file_read.eof())
		{
			break;
		}
		if (user_no == accountNumber)
		{
			system("color C");
			cout << "\n\tCurrent Balance: " << balance << " Egy.";
			cout << "\n\n\n";
		}
	}
	file_read.close();
}

/*start operator overloading (treanfering amount)*/
void Accounts::Deposit(int user_no, int amt)
{
	Employee e;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{

		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;

		if (file_read.eof())
		{
			break;
		}
		if (user_no == accountNumber)
		{
			balance = balance + amt;

			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << endl;

			tr_write << accountNumber << " " << " " << amt << " " << "CR" << endl;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << endl;
		}
	}

	file_temp.close();
	file_read.close();
	e.copy_content(b, a);
	cout << "\n\t Done ! Amount Added\n";
	e.temp_file_clear();
}
void Accounts::deduct_Money(int user_no, int amt)
{
	Employee e;
	string a = "account_details.txt";
	string b = "temp.txt";
	char tr_date[9];

	int flag = 0;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{
		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == accountNumber)
		{
			if (balance != 0 && balance > amt)
			{
				balance = balance - amt;

				file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
					<< " " << accountNumber << " " << account_pass << " " << balance << endl;

				tr_write << accountNumber << " " << amt << " " << "DR" << endl;

				flag = 1;
			}
			else
			{

				cout << "\nYour transection can not be completed balance is Zero or Less than withdrawal amount\n! ";
				file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
					<< " " << accountNumber << " " << account_pass << " " << balance << endl;
			}
		}

		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << endl;
		}

	}

	file_temp.close();
	file_read.close();
	e.copy_content(b, a);
	if (flag == 1)
	{
		cout << "\n\t Done ! Amount Deducted\n";

	}

	e.temp_file_clear();
}
/*end operator overload*/

/*Start Fund transfer function */
void Accounts::transfareTO(int user_no)
{
	Employee e;
	int user2_no, amt = 0, flag = 0;
	char ans;
	system("color 1");
	cout << "\nEnter Account Transfer Number: ";
	cin >> user2_no;

	cout << "\nEnter Amount : ";
	cin >> amt;

	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{

		file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;

		if (file_read.eof())
		{
			break;
		}

		if (user2_no == accountNumber)
		{
			cout << "\nAccount Holder's name: " << fname << " " << lname << endl;
			cout << "enter(y/n): ";
			cin >> ans;

			if (ans == 'n')
			{
				flag = 1;
				break;
			}

			balance = balance + amt;

			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << endl;

			tr_write << accountNumber <<"  " << amt << " " << "CR" << endl;

		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << endl;
		}

	}

	if (flag == 1)
	{
		cout << "\n NO Account Found";
	}
	file_temp.close();
	file_read.close();
	e.copy_content(b, a);
	cout << "\n\t Done ! Amount Added\n";
	e.temp_file_clear();

	//now time for deducting amount from main user
	deduct_Money(user_no, amt);
	cout << "\n Money Successfully Transferd !";
}

/* Start View All Transection */
void Accounts::viewTransfare(int user_no)
{

	int number, amount, flag = 0;
	string status;

	ifstream tr_file_read("transec.txt", ios::in);
	//cin.clear();
	system("color 2");
	cout << "\n\t" << "AccountNumber" << " | " << "Amount" << " | " << "CR / DR " << endl;

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
			cout << "\t" << number << "	      |  " << amount << "  | " << status << "  | " << endl;
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	tr_file_read.close();
}

//menu for register user
void Accounts::user_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Accounts a;
	do {
		system("color A");
		cout << "Welcome Sir your account number is:  " << user_sesstion << endl;
		cout << "\n\t\t\t 1- Check Balance";
		cout << "\n\t\t\t 2- Withdrawal";
		cout << "\n\t\t\t 3- Deposit";
		cout << "\n\t\t\t 4- Transfer Fund";
		cout << "\n\t\t\t 5- View Transection";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-5): ";

		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Account \n\n ";
				break;
			case 1:
				system("cls");
				a.CurrentBalance(user_sesstion);
				break;
			case 2:
				cout << "\n\tEnter Amount to withdraw: ";
				cin >> amount;
				a.deduct_Money(user_sesstion, amount);
				break;
			case 3:
				cout << "\n\tEnter Amount to Add: ";
				cin >> amount;
				a.Deposit(user_sesstion, amount);
				a.CurrentBalance(user_sesstion);
				break;
			case 4:
				system("cls");
				a.transfareTO(user_sesstion);
				break;
			case 5:
				a.viewTransfare(user_sesstion);
				break;
			default:
				cout << "\n\tWorng choise \n";
				break;
			}
		}
		else
		{
			cout << "\n\t Input only Digits please !";
			cin.clear();
			cin.ignore();
			ch = 10;
		}
	} while (ch != 0);

}