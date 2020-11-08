#include<iostream>
#include "Accounts.h"
#include "Employee.h"
#include "Admin.h"
#include<conio.h>
#include<iomanip>
#include<string>
#include <Windows.h>
using namespace std;
int user_admin; // login_Admin_menu (global Variable)
int main()
{
	int ch;
	int login_state = 0;
	int user;
	int pass;
	Accounts a;
	Employee e;
	Admin ad;
	//manual m;
	do {
 
		system("cls");
		system("Color B");
		/*cout << "\n";
		cout << "              .oPYo.              8      o     o                                                          o  .oPYo.                 o               " << endl;
		cout << "              8   `8              8      8b   d8                                                          8  8                      8                " << endl;
		cout << "              o8YooP' .oPYo. odYo. 8  .o  8`b d'8 .oPYo. odYo. .oPYo. .oPYo. .oPYo. ooYoYo. .oPYo. odYo.  o8P `Yooo. o    o .oPYo.  o8P .oPYo. ooYoYo." << endl;
		cout << "              8   `b .oooo8 8' `8 8oP'   8 `o' 8 .oooo8 8' `8 .oooo8 8    8 8oooo8 8' 8  8 8oooo8 8' `8   8      `8 8    8 Yb..     8  8oooo8 8' 8  8" << endl;
		cout << "              8    8 8    8 8   8 8 `b.  8     8 8    8 8   8 8    8 8    8 8.     8  8  8 8.     8   8   8       8 8    8   'Yb.   8  8.     8  8  8" << endl;
		cout << "              8oooP' `YooP8 8   8 8  `o. 8     8 `YooP8 8   8 `YooP8 `YooP8 `Yooo' 8  8  8 `Yooo' 8   8   8  `YooP' `YooP8 `YooP'   8  `Yooo' 8  8  8" << endl;
		cout << "              :......::.....:..::....::.....::::..:.....:..::..:.....::...8 :.....:..:..:..:.....:..::..::..::.....::....8 :.....:::..::.....:..:..:..." << endl;
		cout << "              ::::::::::::::Basics::::::::::::::::::::::::::::::::::::::ooP'.:::::::::::::::::::::::::::::::::::::::::::DS'.:::::::::::::::::::::::::::" << endl;
		cout << "              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::...::::::::::::::::::::::::::::::::::::::::::::...:::::::::::::::::::::::::::::" << endl<<endl;
		cout << "						WELCOME";
		for (int a = 1;a <= 8;a++) // Change 'a<?' to how many * you want
		{
			Sleep(400);
			cout << "...";
		}
	cout << "\n\n                                                            MADE BY:																	" << endl;
		cout << "                                                            I-    Eslam Abdelbasset                                                            " << endl;
		cout << "                                                            II-   Ahmed Kamal                                                           " << endl;
		cout << "                                                            III-  Aya Abdelhady                                                            " << endl;
		cout << "\n" << endl;
		cout << "                                                       ********************************" << endl;
		cout << "                                                       ************   LOL   **********" << endl;
		cout << "                                                       ********************************" << endl;
		*/
		cout<< "\n\t\t\t\t\t\t***************************************************"
			<< "\n\t\t\t\t\t\t*                                                 *"
			<< "\n\t\t\t\t\t\t*              1- Login To your Account.	  *"
			<< "\n\t\t\t\t\t\t*              2- Employee			  *"
			<< "\n\t\t\t\t\t\t*              3- Admin.                          *"
			<< "\n\t\t\t\t\t\t*              0- Exit.                           *"
			<< "\n\t\t\t\t\t\t*                                                 *"
			<< "\n\t\t\t\t\t\t***************************************************\n";
		cout<< "\n\n\t\t\t\t\t\tEnter your choice: ";
		if (cin >> ch)
		{
			switch (ch)
			{
			case 1:
				cout << "\n\t Enter Account Number:  ";
				cin >> user;
				cout << "\n\t Enter 4-digit passcode: ";
				cin >> pass;
				system("cls");
				a.login_user(user, pass);
				break;
			case 2:
				cout << "\n\t Enter Account Number: ";
				cin >> user;
				cout << "\n\t Enter 4-digit password: ";
				cin >> pass;
				system("cls");
				ad.login_Admin(user, pass);
				break;
			case 3:
				cout << "\n\t Enter 4-digit User Admin: ";
				cin >> user_admin;
				system("cls");
				ad.login_Admin_menu(user_admin);
				break;

			}
		}
		else
		{
			cout << "\n\t Input only Digits please ! Press Enter To continue";
			cin.clear();
			cin.ignore();
			ch = 10;
		}



	} while (ch != 0);
	system("pause");
	system("clear");
	return 0;
}
