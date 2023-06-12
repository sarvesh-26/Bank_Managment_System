//Akhil Dhawan
//Yashashvi Agnihotri

#include <iostream>
#include <fstream>
#include<cstdlib>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include<time.h>

using namespace std;
// for repeating the content again //

class tell_branch_details
{
public:
	// Wakna branch//
	void wakna_details()
	{
		cout << "\t\t\t********************************************************" << endl;

		cout << "\t\t\t\t\t\t!!!WELCOME TO THE WAKNAGHAT BRANCH!!!" << endl;

		cout << "\t\t\t********************************************************" << endl;

		ifstream innn;
		innn.open("branch_details_Wakna.txt");

		string s;
		while (innn.eof() == 0)
		{
			getline(innn, s);
			cout << s << endl;
		}
		innn.close();
	}
	// solan branch//
	void solan_details()
	{
		cout << "\t\t\t********************************************************" << endl;

		cout << "\t\t\t\t\t!!!WELCOME TO THE SOLAN BRANCH!!!" << endl;

		cout << "\t\t\t********************************************************" << endl;

		ifstream inn;
		inn.open("branch_details_solan.txt");

		string s;
		while (inn.eof() == 0)
		{
			getline(inn, s);
			cout << s << endl;
		}
		inn.close();
	}
};

class employee_Wakna
{
public:
	void name_btao()
	{
		string name[10] = {"Akhil", "Yashashvi   ", "Arpan ", "Avi    "};
		// cout<<"EMPLOYEE NAMES"<<endl;

		for (int i = 0; i < 4; i++)
			cout << name[i] << " | ";
		cout << endl;
	}
	void address_btao()
	{
		string address[10] = {"Noida  ", "Rajasthan", "Ghaziabad", "Chandigarh"};

		for (int i = 0; i < 4; i++)
		{
			cout << address[i] << " | ";
		}
		cout << endl;
	}
	void post_btao()
	{
		string post[10] = {"Manager", "Clerk    ", "Officer  ", "Cashier   "};

		for (int i = 0; i < 4; i++)
		{
			cout << post[i] << " | ";
		}
		cout << endl;
	}
	void mob_btao()
	{
		string mob_no[10] = {"1111   ", "2222     ", "7777     ", "4444      "};

		for (int i = 0; i < 4; i++)
		{
			cout << mob_no[i] << " | ";
		}
		cout << endl
			 << endl;
	}
};

class employee_solan
{
public:
	void name_btao()
	{
		string name[10] = {"Akhil", "Yashashvi   ", "Avi ", "Arpan    "};
		// cout<<"EMPLOYEE NAMES"<<endl;

		for (int i = 0; i < 4; i++)
			cout << name[i] << " | ";
		cout << endl;
	}

	void address_btao()
	{
		string address[10] = {"Noida  ", "Rajasthan", "Ghaziabad", "Chandigarh"};

		for (int i = 0; i < 4; i++)
		{
			cout << address[i] << " | ";
		}
		cout << endl;
	}

	void post_btao()
	{
		string post[10] = {"Manager", "Clerk    ", "Officer  ", "Cashier   "};

		for (int i = 0; i < 4; i++)
		{
			cout << post[i] << " | ";
		}
		cout << endl;
	}

	void mob_btao()
	{
		string mob_no[10] = {"1111   ", "2222     ", "7777     ", "4444      "};

		for (int i = 0; i < 4; i++)
		{

			cout << mob_no[i] << " | ";
		}
		cout << endl
			 << endl;
	}
};

class read_cust_details //for wakna people
{

public:
	void FUNC()
	{
		ifstream inn;
		inn.open("customer_info_wakna.txt");
		string s;
		// reading first name//
		while (inn.eof() == 0)
		{
			getline(inn, s);
			for (int i = 0; i < 10; i++)
			{
				if (s[i] == ' ')
					break;
				else
					cout << s[i];
			}
			cout << "\n";
		}
		//*******************
		inn.close();
	}
};

class read_cust_details_s //for solan people
{

public:
	void FUNC()
	{
		ifstream inn;
		inn.open("customer_info_solan.txt");
		string s;

		while (inn.eof() == 0)
		{
			getline(inn, s);

			for (int i = 0; i < 10; i++)
			{
				if (s[i] == ' ')
					break;
				else
					cout << s[i];
			}
			cout << "\n";
		}
		inn.close();
	}
};

struct bankStatement
{
	char name[30];
	char accNo[11];
	char accPassword[11];
	float currentBalance;
	float creditedAmount;
	float debitedAmount;
} statement;

class Bank
{
	char name[30];
	char accountNo[11];
	char password[11];
	float balance;

	public:
		void openAccount();

		void checkBalance();

		void depositMoney();
		void withdrawMoney();
		void transferMoney();

		void showStatement();
};

void Bank::openAccount()
{
	Bank *user = new Bank;
	cout << "\nPlease provide some information\n";

	cout << "Enter Your Name: ";
	cin.getline(user->name, 29);

	cin.sync();
	cout << "Account No. Generated for you : ";
	
	
														// using Random function for generating account no : //
	srand((unsigned) time(NULL));
	int random = rand();
	cout<<random<<endl;


	cout << "Create Password: ";

	cin.getline(user->password, 10);
	cout << "Deposit Account opening balance:";

	cin >> user->balance;
	ofstream writeRecord;
	writeRecord.open("bankRecord.txt", ios::app | ios::binary);

	if (!writeRecord)
	{
		cout << "\nFile is not found\n";
		return;
	}
	writeRecord.write((char *)user, sizeof(*user));

	writeRecord.close();
	cout << "\nYour Account is Opened successfully\n\n";
}

void Bank::checkBalance()
{
	char userAccNo[11], userPassword[11];

	cout << "Enter Your Account No: ";
	cin.getline(userAccNo, 10);
	cin.sync();

	cout << "Enter Your Password: ";
	cin.getline(userPassword, 10);

	ifstream readRecord;
	readRecord.open("bankRecord.txt", ios::in | ios::binary);

	while (!readRecord.eof())
	{
		readRecord.read((char *)this, sizeof(*this));
		if (!strcmp(accountNo, userAccNo) && !strcmp(password, userPassword))
		{
			cout << "\nYour Balance is " << balance << " Rupees\n\n";

			readRecord.close();
			return;
		}
	}
	cout << "\nBalance check Proccess is failed due to incorrect infomation Please try again\n\n";
	readRecord.close();
}

void Bank::depositMoney()
{
	struct bankStatement *record;

	record = &statement;
	char userAccNo[11], userPassword[11];

	float depositAmount;
	cout << "Enter Your Account No: ";
	cin.getline(userAccNo, 10);
	cin.sync();

	cout << "Enter Your Password: ";
	cin.getline(userPassword, 10);

	fstream updateRecord, tranStatement;
	updateRecord.open("bankRecord.txt", ios::in | ios::out | ios::binary);

	tranStatement.open("bankStatement.txt", ios::out | ios::app | ios::binary);
	while (!updateRecord.eof())
	{
		updateRecord.read((char *)this, sizeof(*this));

		if (!strcmp(accountNo, userAccNo) && !strcmp(password, userPassword))
		{
			cout << "Enter Deposit Amount: ";

			cin >> depositAmount;
			balance = balance + depositAmount;
			strcpy(record->name, name);
			strcpy(record->accNo, accountNo);
			strcpy(record->accPassword, password);

			record->currentBalance = balance;
			record->creditedAmount = depositAmount;

			record->debitedAmount = 0.00;
			int pos = updateRecord.tellg();
			updateRecord.seekg(pos - sizeof(*this));
			updateRecord.write((char *)this, sizeof(*this));
			tranStatement.write((char *)record, sizeof(*record));

			cout << "\n"
				 << depositAmount << " Rupees is deposited successfully\n\n";
			updateRecord.close();
			tranStatement.close();
			return;
		}
	}
	cout << "\nDeposit Proccess is failed due to incorrect infomation please try again\n\n";

	updateRecord.close();
	tranStatement.close();
}

void Bank::withdrawMoney()
{
	struct bankStatement *record;
	record = &statement;
	char userAccNo[11], userPassword[11];

	float withdrawAmount;
	cout << "Enter Your Account No: ";

	cin.getline(userAccNo, 10);
	cin.sync();

	cout << "Enter Your Password: ";
	cin.getline(userPassword, 10);
	fstream updateRecord, tranStatement;
	updateRecord.open("bankRecord.txt", ios::in | ios::out | ios::binary);

	tranStatement.open("bankStatement.txt", ios::out | ios::app | ios::binary);

	while (!updateRecord.eof())
	{
		updateRecord.read((char *)this, sizeof(*this));

		if (!strcmp(accountNo, userAccNo) && !strcmp(password, userPassword))
		{
			cout << "Enter Withdrawable Amount: ";
			cin >> withdrawAmount;
			if (balance < withdrawAmount)
			{
				cout << "\nSorry! You don't have enough Money to withdraw\n\n";
				return;
			}
			balance = balance - withdrawAmount;
			strcpy(record->name, name);
			strcpy(record->accNo, accountNo);

			strcpy(record->accPassword, password);
			record->currentBalance = balance;
			record->creditedAmount = 0.00;
			record->debitedAmount = withdrawAmount;

			int pos = updateRecord.tellg();

			updateRecord.seekg(pos - sizeof(*this));
			updateRecord.write((char *)this, sizeof(*this));
			tranStatement.write((char *)record, sizeof(*record));

			// might lead to error

			cout << "\n"
				 << withdrawAmount << " Rupees is withdrawl successfully\n\n";
			updateRecord.close();
			tranStatement.close();
			return;
		}
	}
	cout << "\nWithdraw Proccess is failed due to incorrect infomation please try again\n\n";

	tranStatement.close();
	updateRecord.close();
}

void Bank::transferMoney()
{
	struct bankStatement *record;
	record = &statement;
	char userAccNo[11];
	char userPassword[11];

	char transferAccNo[11], accHolderName[30];

	float transferAmount;
	bool isFound = false;

	cout << "Enter Your Account No: ";
	cin.getline(userAccNo, 10);
	cin.sync();

	cout << "Enter Your Password: ";
	cin.getline(userPassword, 10);
	cin.sync();
	fstream updateRecord, tranStatement;

	updateRecord.open("bankRecord.txt", ios::in | ios::out | ios::binary);
	while (!updateRecord.eof())
	{
		updateRecord.read((char *)this, sizeof(*this));
		if (!strcmp(accountNo, userAccNo) && !strcmp(password, userPassword))
		{
			cout << "Enter Account Holder Name: ";

			cin.getline(accHolderName, 29);
			cin.sync();
			cout << "Enter Account No: ";
			cin.getline(transferAccNo, 10);

			cout << "Enter Transfer Amount: ";
			cin >> transferAmount;
			if (balance < transferAmount)
			{
				cout << "\nSorry! You don't have enough Money to Transfer\n\n";
				return;
			}
			balance = balance - transferAmount;
			int pos = updateRecord.tellg();
			updateRecord.seekg(pos - sizeof(*this));

			updateRecord.write((char *)this, sizeof(*this));
			updateRecord.close();
			isFound = true;
			break;
		}
	}
	if (isFound == false)
	{
		updateRecord.close();
		cout << "\nTransfer Proccess is failed due to incorrect infomation please try again\n\n";
		return;
	}
	updateRecord.open("bankRecord.txt", ios::in | ios::out | ios::binary);

	tranStatement.open("bankStatement.txt", ios::out | ios::app | ios::binary);

	while (!updateRecord.eof())
	{
		updateRecord.read((char *)this, sizeof(*this));
		if (!strcmp(accountNo, transferAccNo) && !strcmp(name, accHolderName))
		{
			balance = balance + transferAmount;
			strcpy(record->name, name);
			strcpy(record->accNo, accountNo);

			strcpy(record->accPassword, password);
			record->currentBalance = balance;

			record->creditedAmount = transferAmount;
			record->debitedAmount = 0.00;
			int pos = updateRecord.tellg();

			updateRecord.seekg(pos - sizeof(*this));

			updateRecord.write((char *)this, sizeof(*this));

			tranStatement.write((char *)record, sizeof(*record));
			cout << "\n"
				 << transferAmount << " Rupees is transfered successfully\n\n";
			updateRecord.close();
			tranStatement.close();
			return;
		}
	}
	updateRecord.close();

	tranStatement.close();

	updateRecord.open("bankRecord.txt", ios::in | ios::out | ios::binary);
	while (!updateRecord.eof())
	{
		updateRecord.read((char *)this, sizeof(*this));
		if (!strcmp(accountNo, userAccNo) && !strcmp(password, userPassword))

		{
			balance = balance + transferAmount;
			int pos = updateRecord.tellg();

			updateRecord.seekg(pos - sizeof(*this));
			updateRecord.write((char *)this, sizeof(*this));

			updateRecord.close();
			break;
		}
	}
	cout << "\nTransfer Proccess is failed due to incorrect infomation please try again\n\n";
}

void Bank::showStatement()
{
	struct bankStatement *record;
	record = &statement;

	char accountNo[11], Password[11];

	bool isFound = false;
	int check = 0;
	cout << "Enter Your Account No: ";
	cin.getline(accountNo, 10);

	cin.sync();
	cout << "Enter Your Password: ";

	cin.getline(Password, 10);
	ifstream readRecord;

	readRecord.open("bankStatement.txt", ios::in | ios::binary);

	cout << "\n Name \tAccount No \tBalance \tCredit \tDebited\n\n";

	readRecord.read((char *)record, sizeof(*record));
	while (!readRecord.eof())
	{
		if (!strcmp(accountNo, record->accNo) && !strcmp(Password, record->accPassword))
		{
			cout << " " << record->name << " \t" << record->accNo << " \t" << record->currentBalance << " \t";
			cout << record->creditedAmount << " \t" << record->debitedAmount << endl;

			isFound = true;
		}
		readRecord.read((char *)record, sizeof(*record));
	}
	cout << endl;
	readRecord.close();
	if (!isFound)
	{
		cout << "\nBalance check Proccess is failed due to incorrect infomation Please try again\n\n";
	}
}

class udpate
{
public:
	int ac_no;
	string passw;
	string name;
	string address;

	udpate()
	{

		cout << "You are now in Updation request.....please wait...." << endl;
		cout << "Enter your name : " << endl;
		cin >> name;
		cout << "Enter your account no : " << endl;
		cin >> ac_no;
		cout << "Enter your password : " << endl;
		cin >> passw;

		cout << "Enter your address : " << endl;
		cin >> address;

		ofstream ou;
		ou.open("updation.txt");
		// ou.open('updation.txt');
		ou << name << endl;
		ou << ac_no << endl;
		ou << address << endl;
		ou.close();
		string s;
		cout << "Now what you want to change name or the address : " << endl;
		cin >> s;

		if (s == "name")
		{
			cout << "Enter the new name : ";
			cin >> name;
			ou.open("updation.txt");
			ou << name << endl;
			ou << ac_no << endl;
			ou << address << endl;

			cout << "updation successful" << endl;
		}
	}
};

class helpdesk_clerk
{
public:
	void enter_choice()
	{
		int choose;
		Bank account;
		do
		{			cout << "********************************************************" << endl;
			cout << "0. to update information" << endl;
			cout << "1. to Open Account\n";
			cout << "2. to Check Balance\n";
			cout << "3. to Deposit Money\n";
			cout << "4. to Withdraw Money\n";
			cout << "5. to Transfer Money\n";
			cout << "6. to Show Statement\n";

			cout << "7. to Exit\n";
			cout << "********************************************************" << endl;

			cout << "Enter your choice: ";
			cin >> choose;
			cin.sync();

			if (choose == 0)
			{
				udpate uu;
			}

			switch (choose)
			{
			case 1:
				account.openAccount();

				break;
			case 2:
				account.checkBalance();
				break;
			case 3:
				account.depositMoney();

				break;
			case 4:
				account.withdrawMoney();
				break;

			case 5:
				account.transferMoney();
				break;
			case 6:
				account.showStatement();
				break;
			case 7:
				break;
			default:
				cout << "Invalid choice try again\n";
				break;
			}
		} while (choose != 7);
	}
};

int main()
{
	cout << "\t\t\t********************************************************" << endl;

	cout << "\t\t\t\t\t\tWELCOME" << endl;

	cout << "\t\t\t********************************************************" << endl;

	cout << "\t\t\t\t BANK MANAGMENT CUM OPERATING SYSTEM PROJECT" << endl;

	cout << "\t\t\t********************************************************" << endl;

	cout << "\n";
	cout << "Welcome to Our Bank" << endl;
	cout << "Enter the branch in which you want to go" << endl;
	cout << "\t\t\t********************************************************" << endl;

	cout << "1. Waknaghat" << endl;
	cout << "2. Solan" << endl;

	string branch_place;

	cin >> branch_place;

	// wakna branch//

	if (branch_place == "Waknaghat")
	{
		// starting the menu driven program part 1 :
		int choice;
		while (choice != 6)
		{

			cout << endl
				 << "Enter the content number which is to performed" << endl;

			cout << "\t\t\t********************************************************" << endl;
			cout << "1. Branch details" << endl; // done
			cout << "2. Help desk" << endl;
			cout << "3. Our Employees details" << endl; // done
			cout << "4. Information about some of our customers" << endl;
			cout << "5. Delete a specific file" << endl;
			cout << "6. Exit" << endl;
			cin >> choice;

			if (choice == 1)
			{
				// class will be called //
				tell_branch_details tt;
				tt.wakna_details();

				cout << "__________________________________________________________________" << endl;
			}
			// choice 2 left//
			if (choice == 2)
			{
				cout << "\t\t\t********************************************************" << endl;

				cout << "\t\t\t\t\t\tWelcome to Helpdesk of our waknaghat branch " << endl;

				cout << "\t\t\t********************************************************" << endl;

				cout << "What can we do for you??? ";
				cout << "Amoung the following tasks choose an option to be performed" << endl
					 << endl;

				helpdesk_clerk hc1;
				hc1.enter_choice();
			}

			if (choice == 3)
			{
				cout << "\t\t\t********************************************************" << endl;

				cout << "\t\t\t\t\t!!!Here is our Employee Details!!!" << endl;
				cout << "\t\t\t********************************************************" << endl;

				employee_Wakna ew;
				ew.name_btao();
				ew.post_btao();

				ew.address_btao();

				ew.mob_btao();
				cout << "__________________________________________________________________" << endl;
			}

			if (choice == 4)
			{
				cout << "First We have to verify you before showing you all the secured details" << endl;
				sleep(1);
				cout << "OFFICER, Do you want to let him our personal information" << endl;
				cout << "say : : ";
				string officer_ans;
				cin >> officer_ans;

				if (officer_ans == "yes")
				{
					cout << "But , You are only allowed to see the names of all our bank account holders" << endl;

					read_cust_details rd;
					rd.FUNC();
				}
				else
				{
					cout << "Sorry , you have not been permitted" << endl;
				}
				cout << "__________________________________________________________________" << endl;
			}
			if (choice == 5)
			{
				cout << "Please wait, We are requesting for deletion operation" << endl;
				sleep(3);
				cout << "Request Granted" << endl;
				int status;
				char fileName[20];
				cout << "Enter the Name of File: ";
				cin >> fileName;
				status = remove(fileName);
				if (status == 0)
					cout << "\nFile Deleted Successfully!";
				else
					cout << "\nError Occurred!";
				cout << endl;
			}
		}

	} // wakna branch ends here//

	// branch is solan //

	if (branch_place == "Solan")
	{
		// starting the .....//

		int choice = 0;

		while (choice != 6)
		{

			cout << endl
				 << "Enter the content number which is to performed" << endl;

			cout << "********************************************************" << endl;
			cout << "1. Branch details" << endl; // done

			cout << "2. Help desk" << endl;

			cout << "3. Our Employees details" << endl; // done
			cout << "4. Information about our customers" << endl;
			cout << "5. Delete a specific file" << endl;
			cout << "6. Exit" << endl;
			cout << "********************************************************" << endl;
			cout << "Enter : ";
			cin >> choice;

			if (choice == 1)
			{
				// class will be called //
				tell_branch_details tt;
				tt.solan_details();
				cout << "__________________________________________________________________" << endl;
			}

			if (choice == 2)
			{
				cout << "\t\t\t********************************************************" << endl;

				cout << "\t\t\t\t\t\tWelcome to Helpdesk of our Solan branch " << endl;

				cout << "\t\t\t********************************************************" << endl;

				cout << "What can we do for you???";
				cout << "Choose thed following tasks which you needed to perform" << endl
					 << endl;

				helpdesk_clerk hc1;
				hc1.enter_choice();
			}

			if (choice == 3)
			{
				// class will again be called//
				cout << "\t\t\t********************************************************" << endl;

				cout << "\t\t\t\t\t!!!Here is our Employee Details!!!" << endl;

				cout << "\t\t\t********************************************************" << endl;
				employee_solan ew;
				ew.name_btao();

				ew.post_btao();
				ew.address_btao();
				ew.mob_btao();
				cout << "__________________________________________________________________" << endl;
			}
			if (choice == 4)
			{
				cout << "First We have to verify you before showing you all the secured details" << endl;
				cout << "OFFICER, Do you want to let him our personal information" << endl;
				cout << "say : : " << endl;
				string officer_ans;

				cin >> officer_ans;
				if (officer_ans == "yes")
				{
					cout << "But , You are only allowed to see the names of all our bank account holders" << endl;

					read_cust_details_s rd;
					rd.FUNC();
				}
				else
				{
					cout << "Sorry , you have not been permitted" << endl;
				}
			}
			if (choice == 5)
			{
				cout << "Please wait, We are requesting for deletion operation" << endl;
				sleep(3);
				cout << "Request Granted" << endl;
				int status;
				char fileName[20];
				cout << "Enter the Name of File: ";
				cin >> fileName;
				status = remove(fileName);
				if (status == 0)
					cout << "\nFile Deleted Successfully!";
				else
					cout << "\nError Occurred!";
				cout << endl;
			}
			cout << "__________________________________________________________________" << endl;
		}

	} // solan branch in main() ends
	// if branch entered is wrong//
	else
	{
		cout << "********************************************************" << endl;
		cout << "INVALID ENTRY" << endl;
	}

	cout << "*****************************************************************" << endl;

	cout << "!!!!  Thank you !!!!!!!" << endl;
	cout << "!!Please visit again !!" << endl;

	cout << "*****************************************************************" << endl;

	return 0;
}  