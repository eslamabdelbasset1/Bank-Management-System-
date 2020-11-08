#include "Employee.h"
#include "users.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void Employee::clrscr()
{
	cout << string(100, '\n');
}
void Employee::createAccount()
{
	system("color 3");
	cout << "\n\tEnter your First name: ";
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

	char atype = '\0';
	cout << "\n\tSelect Accounts Type(Savings s / Creating c): ";
	cin >> atype;
	if (tolower(atype) == 's')
	{
		type = "Saved";
	}
	else if (tolower(atype) == 'c')
	{
		type = "Created";
	}
	else
	{
		type = "Other";
	}

	accountNumber = get_last_index();
	cout << "\n\t Your Accounts Number: " << accountNumber;

	cout << "\n\t Enter 4 digit account_pass: ";
	cin >> account_pass;

	cout << "\n\t Enter Primary Balance: ";
	cin >> balance;
	
	ofstream file("account_details.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << phone << " " << dob << " " << type << " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
	cout << endl;

	number_system_put(accountNumber);
	file.close();
}

	
void Employee::searchDetails(int user_no) //user_no for user session for only specified user can show
{
	int flag = 0;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	system("color 5");
	cout <<"\n\tEnter Accounts number: ";
	cin >> user_no;
	//cin.clear();

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
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == accountNumber)
		{
			cout << "\n\tAccounts Number is :" << accountNumber;
			cout << "\n\tName               :" << fname << " " << lname;
			cout << "\n\tPhone              :" << phone;
			cout << "\n\tDate of birth      :" << dob;
			cout << "\n\tAccounts Type      :" << type;
			cout << "\n\tBalance            :" << balance << " Egy.";
			cout << "\n\tAccount Status     :" << close;
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


void Employee::delete_details(int user_no)
{
	char buff;
	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 4");
	cout << "\n\tEnter Accounts number: ";
	cin >> user_no;
	//cin.clear();

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
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}
		if (user_no == accountNumber)
		{
			cout << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
			flag = 1;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
		}
	}
		if (flag != 1)
		{
			cout << "\n\tNo record found";

		}
	file_temp.close();
	file_read.close();
	copy_content(b,a);

	cout << "\n\tAccounts Is Removed!\n";
	temp_file_clear();
}


void Employee::close_details(int user_no)
{
	int ch;
	char buff;
	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 2");
	cout << "\n\tEnter Account number: ";
	cin >> user_no;
	//cin.clear();
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
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == accountNumber)
		{
			cout << "\n\tAccount Number is: " << accountNumber;
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New Status: ";
			cin >> close;
			cin.clear();


			cout << "\n\t Current Account Type:" << type;
			cout << "\n\t Change Type (Saving s /Other o) otherwiese press (N) :";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !account type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
			}
			else
			{
				type = "Other";
			}
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " "<< close << endl;
			flag = 1;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
		}

	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();

}

/* End View All Transection */
void Employee::update_details(int user_no)
{

	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 2");
	cout << "\n\tEnter Account number: ";
	cin >> user_no;
	//cin.clear();
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
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == accountNumber)
		{
			cout << "\n\tAccount Number is: " << accountNumber;
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New First name: ";

			cin >> fname;
			cin.clear();

			cout << "\n\t New Last name: ";
			cin >> lname;
			cin.clear();

			cout << "\n\t New  phone: ";
			cin >> phone;
			cin.clear();

			cout << "\n\t New Dob: ";
			cin >> dob;
			cin.clear();

			cout << "\n\t Current Account Type:" << type;
			cout << "\n\t Change Type (Saving S/Other O) otherwiese press (N) :";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !account type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
			}
			else
			{
				type = "Other";
			}
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
			flag = 1;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << dob << " " << type
				<< " " << accountNumber << " " << account_pass << " " << balance << " " << close << endl;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();
}

/*
copy content function for copy text to other file
*/
void Employee::copy_content(string a, string b)
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

int  Employee::get_last_index() {
	ifstream infile("number.txt");
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

void  Employee::number_system_put(int n1)
{
	n1 = n1 + 1;
	ofstream number_write("number.txt", ios::out);
	number_write << n1;
}


////functions for account number automation
/*
int number_system_get()
{
	int number;
	ifstream number_read("number.txt", ios::in);
	number_read >> number;
	return number;
}*/

void  Employee::temp_file_clear()
{
	char ch;
	int flag = 0;
	ofstream temp_write("temp.txt", ios::out);

	temp_write << " ";
	temp_write.close();
}

/*Start entmini statem function */
void Employee::ministatement(int user_no)
{
	int number, amount, flag = 0, pbalance = 0;
	string status;
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
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == accountNumber)
		{
			pbalance = balance;
		}
	}

	file_read.close();
	//transection part
	system("color B");
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\n\tAccounts Number : " << accountNumber << endl;
	cout << "\n\n";

	ifstream tr_file_read("transec.txt", ios::in);
	//cin.clear();
	cout << "\n\t" << "Date"
		<< " | " << "Amount" << " | " << "CR / DR " << endl;

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
			cout << "\t" << " | " << amount << " | " << status << " | " << endl;
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	cout << "\n\n";
	cout << "Total Primary Balance :" << pbalance << "/." << endl;
	tr_file_read.close();

}


/*End mini statement function */
void Employee::showDetails()
{
	int count = 1;
	//Employee e;
	//ifstream inFile;
	ifstream file_read("account_details.txt", ios::in);

	if (!file_read)

	{
		system("color C");
		cout << "File could not be open !! Press any Key...";

		return;

	}
	system("color C");
	cout << "\n\n\t\tACCOUNTS LIST\n\n";

	cout << "===============================================================================================\n";

	cout << "Name" << "		" << "Phone" << "		" << "Data Birthday" << "	" << "Type" << "	" << "Account No." << "  " << "Password" << "  " << "Balance"<< " " << "Status" << endl;

	cout << "===============================================================================================\n";
	string word;
	while (file_read >> word)
	{
		cout << word << "	";
		if (count>=9)
		{
			cout << endl;
			count = 0;
		}
		count++;
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;*/

		/*if (file_read.eof() != NULL)
		{
			cout << fname << " " << lname << "\t" << phone << "\t"
			<< dob << "\t" << type << "\t" << accountNumber << "\t" << account_pass << "\t" << balance << endl;

			system("pause");
		}*/
	}
	/*if (flag != 1)
	{
		cout << "\n\tNo record found";
	}*/
	file_read.close();
	cout << "\n\n\n";
}

//menu for register user
void Employee::employee_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Employee e;
	do {
		system("color 9");
		cout << "\n\t\t\t 1- Create An Account";
		cout << "\n\t\t\t 2- View Info Of Account";
		cout << "\n\t\t\t 3- Show All Accounts";
		cout << "\n\t\t\t 4- Delete Account";
		cout << "\n\t\t\t 5- Close Account";
		cout << "\n\t\t\t 6- Update Your Details";
		cout << "\n\t\t\t 7- MiniStatement";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-6): ";
		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Employees \n\n ";
				break;
			case 1:
				system("cls");
				e.createAccount();
				break;
			case 2:
				system("cls");
				e.searchDetails(user_sesstion);
				break;
			case 3:
				system("cls");
				e.showDetails();
				break;
			case 4:
				e.delete_details(user_sesstion);
				break;
			case 5:
				e.close_details(user_sesstion);
				break;
			case 6:
				system("cls");
				e.update_details(user_sesstion);
				break;

			case 7:
				e.ministatement(user_sesstion);
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
	}while (ch != 0);
}