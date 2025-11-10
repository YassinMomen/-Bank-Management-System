#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
enum { Admin_Login, Customer_Login, Customer_Request };
enum { admin, employee, customer };
class Admin;
string Make_String(long long x);
void makeAccount(int type)
{
	ofstream New;
	if (type == admin)New.open("Admins.txt", ios::app);
	else New.open("Employees.txt", ios::app);
	string name, nationality; int id; double balance = -1;
	cin.ignore();
	cout << "Enter Your Name : \n";
	getline(cin, name);
	string pass;
	cout << "Enter Your id : \n"; cin >> id;
	cout << "Enter Your Nationality : \n"; cin >> nationality;
	cout << "Enter Your Password : \n";
	cin.ignore();

	getline(cin, pass);
	New << "Name: " << name << "|Nationality:  " << nationality << "|Id: " << id << "|Balance: " << balance << "| Password :" << pass << endl;
	return;

}
class Customer;
class Bank
{

	void Update()
	{
		ifstream upd("Customers.txt");
		ofstream tmp("Temp.txt");
		string line; int x;
		while (getline(upd, line))
		{
			cout << line << endl; string tp;
			cout << "You Want To Update This Customer \n1) Yes\n2)Delete Account\nAnother Number) NoChange\nYour Choice : ";
			cin >> x;
			if (x == 1)
			{
				cout << "You Want To Update \n1) Name\n2) ID \n3)Nationality \n4)Balance \n5)Password\nYour Choice : ";
				int choice; cin >> choice;
				while (choice < 1 || choice>5)
				{
					cout << "Enter Your Choice Beetwen 1 to 5\n";
					cin >> choice;
				}
				while (true)
				{
					if (choice == 1)
					{
						tp += "Name: ";
						string name;
						cout << " New Name : "; cin >> name;
						tp += name;
						int idx = line.find("|Nationality:  ");
						while (idx != line.size())tp.push_back(line[idx++]);

					}
					else if (choice == 2)
					{
						int id = 0;
						while (line.substr(id, 5) != "|Id: ")tp.push_back(line[id++]);
						tp += "|Id: ";
						string name;
						cout << " New id : "; cin >> name;
						tp += name;
						int idx = line.find("|Balance: ");
						while (idx != line.size())tp.push_back(line[idx++]);
					}
					else if (choice == 3)
					{
						int id = 0;
						while (line.substr(id, 15) != "|Nationality:  ")tp.push_back(line[id++]);
						tp += "|Nationality:  ";
						string name;
						cout << " New Nationlaity : "; cin >> name;
						tp += name;
						int idx = line.find("|Id: ");
						while (idx != line.size())tp.push_back(line[idx++]);
					}
					else if (choice == 4)
					{
						int id = 0;
						while (line.substr(id, 10) != "|Balance: ")tp.push_back(line[id++]);
						tp += "|Balance: ";
						string name;
						cout << " New Balance : "; cin >> name;
						tp += name;
						int idx = line.find("| Password :");
						while (idx != line.size())tp.push_back(line[idx++]);
					}
					else if (choice == 5)
					{
						int id = 0;
						while (line.substr(id, 12) != "| Password :")tp.push_back(line[id++]);
						tp += "| Password :";
						string name;
						cout << " New Password : "; cin >> name;
						tp += name;

					}


					cout << "Successfully Serve ! \n"; line = tp;
					cout << "You Want Any another Serve ? \n1) Yes\nAnother Number) No\n"; cin >> choice;
					if (choice == 1)
					{
						cout << "1)Check New Customer\n2)Current Bank Balance\n3)Update Customer Account\n4)Number Of Accounts\n5)See All Accounts\n6)Log_Out\nYour Choice Is: ";
						cin >> choice;
					}
					else break;
				}
			}
			else if (x == 2)continue;
			tmp << line << endl;
		}
		tmp.close(); upd.close();
		remove("Customers.txt");
		rename("Temp.txt", "Customers.txt");
	}
	void SeeingAccounts()
	{
		ifstream num("Customers.txt");
		string line;
		while (getline(num, line))cout << line << endl;
	}
	long long Accounts_Numbers()
	{
		long long n = 0;
		ifstream num("Customers.txt", ios::ate);
		string line;
		num.seekg(0, ios::beg);
		while (getline(num, line))n++;
		return n;
	}
	long long General_Balance()
	{
		long long n = 0;
		ifstream num("Customers.txt");
		string line;
		while (getline(num, line))
		{
			string transaction;
			int idx = line.find("|Balance: ") + 10;
			while (line.substr(idx, 12) != "| Password :")
			{
				transaction.push_back(line[idx++]);
			}
			long long  tra = 0;
			for (int i = 0; i < transaction.size(); i++)
			{
				tra *= 10;
				tra += transaction[i] - '0';
			}
			n += tra;
		}
		return n;
	}
	const int Bank_Id = 1;
	static long double Bank_Balance;
	friend class Admin;
	friend class Employee;
};
string GloLine; int Enter;
long double Bank::Bank_Balance = 0;
class User
{
protected:
	int Id = 0;
	string Name = "";
public:
	virtual void DisplayMenu() = 0;
	bool Check_login(int x)
	{
		string name, nation, id, pass, line;
		ifstream check;
		if (x == admin)check.open("Admins.txt");
		else if (x == employee)check.open("Employees.txt");
		else check.open("Customers.txt");
		cout << "Enter Your Name\nYour Name Is  : ";
		cin >> name;
		cout << "Enter Your Nationality\nYour Nationality Is: ";
		cin >> nation;
		cout << "Enter Your Id\nYour Id Is: ";
		cin >> id;
		cout << "Enter Your Password\nYour Password Is: ";
		cin >> pass;
		while (getline(check, line))
		{
			int ok = 0;
			int idx = line.find("Name: ") + 6;
			string test;
			while (line.substr(idx, 15) != "|Nationality:  ")
			{
				test.push_back(line[idx++]);
			}
			if (test == name)ok++;
			idx = line.find("|Nationality:  ") + 15;
			test.clear();
			while (line.substr(idx, 5) != "|Id: ")
			{
				test.push_back(line[idx++]);
			}
			if (test == nation)
			{
				ok++;
			}
			idx = line.find("|Id: ") + 5;
			test.clear();
			while (line.substr(idx, 10) != "|Balance: ")
			{
				test.push_back(line[idx++]);
			}
			if (test == id)ok++;
			test.clear();
			idx = line.find("| Password :") + 12;
			while (idx != line.size())
			{
				test.push_back(line[idx++]);
			}
			if (test == pass)ok++;
			if (ok == 4)
			{
				GloLine = line;
				return true;
			}
			//cout << line << endl;
		}

		return false;
	}
};
enum { Accepted = 1, Rejected };
enum class services { Check = 1, Bank_Balance, Update, NumberOfAccounts, SeeAccounts, Log_Out };
enum class CustomerServices { Withdrawal = 1, Deposite, Balance };
class Admin :public User, public Bank
{
	void check_customer()
	{
		ifstream check("CustomerApp.txt", ios::ate);

		ofstream cust("Customers.txt", ios::app);
		bool found = 0;
		string line;
		check.seekg(0, ios::beg);
		while (getline(check, line))
		{

			if (line.substr(0, 4) == "Name")
			{
				found = true;
				cout << line << endl;
				cout << "Are You Accept To Make This Account ? \n";
				cout << "1) Accept\n2)Reject\n";
				int ch;
				cin >> ch;
				if (ch == Accepted)
				{
					cust << line << endl;
				}
			}
		}
		check.close();
		if (found)
		{

			ofstream c("CustomerApp.txt", ios::trunc);
			c.close();
		}
		else cout << "Not Found Any New Account\n";
	}

public:

	void DisplayMenu()
	{
		cout << "1)Login \nAny number)New admin\nYour choice :  ";
		int ch; cin >> ch;
		if (ch == 1)
		{
			while (!Check_login(admin))
			{
				cout << "Invalid Login Please Check Your Data and Try Again ! \n";
			}
			cout << "---------------------------------------------------Hello Admin---------------------------------------------------\n";
			cout << "Choose one of Your Services\n";
			cout << "1)Check New Customer\n2)Current Bank Balance\n3)Update or Delete Customer Account\n4)Number Of Accounts\n5)See All Accounts\n6)Log_Out\nYour Choice Is: ";
			int choice; cin >> choice;
			while (choice < 1 || choice>6)
			{
				cout << "Enter Your Choice Beetwen 1 to 6\n";
				cin >> choice;
			}
			while (true)
			{

				if (choice == (int)services::Check)check_customer();
				else if (choice == (int)services::Bank_Balance)cout << "General Bank Balance Is : " << General_Balance() << '\n';
				else if (choice == (int)services::NumberOfAccounts)cout << "Number Of Accounts : " << Accounts_Numbers() << '\n';
				else if (choice == (int)services::SeeAccounts)SeeingAccounts();
				else if (choice == (int)services::Log_Out)return;
				else Update();
				cout << "Successfully Serve ! \n\nS";
				cout << "You Want Any another Serve ? \n1) Yes\nAnother Number) No\n"; cin >> choice;
				if (choice == 1)
				{
					cout << "1)Check New Customer\n2)Current Bank Balance\n3)Update Customer Account\n4)Number Of Accounts\n5)See All Accounts\n6)Log_Out\nYour Choice Is: ";
					cin >> choice;
				}
				else break;
			}
		}
		else
		{
			makeAccount(admin);
			return;
		}

	}


};
class Employee : public User
{
	void change_balance(long long change)
	{
		ifstream update("Customers.txt");
		ofstream temp("temp.txt");
		string line, up = GloLine, now;
		for (int i = 0; i < up.size(); i++)
		{
			if (up.substr(i, 10) != "|Balance: ")now.push_back(GloLine[i]);
			else
			{
				now += "|Balance: ";
				i = up.find("| Password ") - 1, now += Make_String(change);
			}
		}
		while (getline(update, line))
		{
			if (line != GloLine)temp << line << '\n';
			else temp << now << '\n';
		}
		update.close(); temp.close();
		remove("Customers.txt");
		rename("temp.txt", "Customers.txt");
	}
	void Services(int i)
	{
		ifstream cstm("Customers.txt");
		string line; bool found = 0;
		while (!found)
		{
			while (getline(cstm, line))
			{
				cout << "Is this account required?\n1)Yes\nAny Number else ) No\n Your Choice :  ";
				int ok; cin >> ok;
				if (ok == 1)
				{
					GloLine = line;
					found = 1;
					break;
				}
			}
			if (!found)cout << "Please Choice one Account \n";
		}
		long long  bal = 0, amount;
		int  x = GloLine.find("|Balance: ");
		x += 10;
		while (GloLine[x] != '|')bal = (bal * 10) + (GloLine[x++] - '0');
		while (i)
		{
			if (i == (int)CustomerServices::Withdrawal)
			{
				cout << "Enter The Amount To Be Withdrawn\nThe Amount Is : ";
				cin >> amount;
				if (bal >= amount)
				{
					bal -= amount;
				}
				else
				{
					cout << "-----------------------Failed Transaction\n";
					cout << "Your Wanted Amount is less than Your Balance \n";
				}
			}
			else if (i == (int)CustomerServices::Deposite)
			{
				cout << "Enter The Amount To Be Deposite\nThe Amount Is : ";
				cin >> amount;
				bal += amount;
				cout << "-------------------------Successful Transaction \n";
			}
			else if (i == (int)CustomerServices::Balance)
			{
				cout << "Your Current Balance is :  " << bal << endl;

				cout << "-------------------------Successful Process \n";
			}
			else cout << "Invalid Choice\n ";
			cout << "Choice Your Serve  \n";
			cout << "0)To Exit \n1)Withdrawal \n2)Deposite \n3)Checking Your Current Balance\nYour Choice is : ";
			cin >> i;
		}

		change_balance(bal);

	}
	long long Accounts_Numbers()
	{
		long long n = 0;
		ifstream num("Customers.txt", ios::ate);
		string line;
		num.seekg(0, ios::beg);
		while (getline(num, line))n++;
		return n;
	}
	long long General_Balance()
	{
		long long n = 0;
		ifstream num("Customers.txt");
		string line;
		while (getline(num, line))
		{
			string transaction;
			int idx = line.find("|Balance: ") + 10;
			while (line.substr(idx, 12) != "| Password :")
			{
				transaction.push_back(line[idx++]);
			}
			long long  tra = 0;
			for (int i = 0; i < transaction.size(); i++)
			{
				tra *= 10;
				tra += transaction[i] - '0';
			}
			n += tra;
		}
		return n;
	}
public:
	void DisplayMenu()
	{
		cout << "1)Login \nAny number)New Empolyee\nYour choice :  ";
		int ch; cin >> ch;
		if (ch == 1)
		{
			while (!Check_login(employee))
			{
				cout << "Invalid Login Please Check Your Data and Try Again ! \n";
			}
			cout << "--------------------------------------------------Welcome Employee--------------------------------------------\n";
			cout << "Choose one of Your Services\n";
			cout << "1)Withdrawn To Customer \n2)Deposite To Customer \n3)Number Of Bank Accounts \n4)Current_Bank_Balance \nAny Number Else )log_out  Your Choice Is: ";
			int choice; cin >> choice;

			if (choice == 1 || choice == 2)
			{
				long long amt;
				cout << "Enter The Amount Of Money :  ";
				cin >> amt; cout << endl;
				string tmp = GloLine;
				Services(choice);
				GloLine = tmp;

			}
			else if (choice == 3)
			{
				cout << " The Acounts Number Is : " << Accounts_Numbers() << endl;
			}
			else if (choice == 4)cout << "The Bank Balance Is : " << General_Balance() << endl;
			else return;
		}

		else
		{
			makeAccount(employee);
			return;
		}
	}

};
string Make_String(long long x)
{
	string convert;
	while (x)
	{
		convert.push_back((x % 10) + '0');
		x /= 10;
	}
	reverse(convert.begin(), convert.end());
	return convert;
}
enum class CustomerChoices { login = 1, application };
class Customer :public User
{


	void change_balance(long long change)
	{
		ifstream update("Customers.txt");
		ofstream temp("temp.txt");
		string line, up = GloLine, now;
		for (int i = 0; i < up.size(); i++)
		{
			if (up.substr(i, 10) != "|Balance: ")now.push_back(GloLine[i]);
			else
			{
				now += "|Balance: ";
				i = up.find("| Password ") - 1, now += Make_String(change);
			}
		}
		while (getline(update, line))
		{
			if (line != GloLine)temp << line << '\n';
			else temp << now << '\n';
		}
		update.close(); temp.close();
		remove("Customers.txt");
		rename("temp.txt", "Customers.txt");
	}
	void Services(int i)
	{

		long long  bal = 0, amount;
		int x = GloLine.find("|Balance: ");
		x += 10;
		while (GloLine[x] != '|')bal = (bal * 10) + (GloLine[x++] - '0');
		while (i)
		{
			if (i == (int)CustomerServices::Withdrawal)
			{
				cout << "Enter The Amount To Be Withdrawn\nThe Amount Is : ";
				cin >> amount;
				if (bal >= amount)
				{
					bal -= amount;
				}
				else
				{
					cout << "-----------------------Failed Transaction--------------------------------\n";
					cout << "Your Wanted Amount is less than Your Balance \n";
				}
			}
			else if (i == (int)CustomerServices::Deposite)
			{
				cout << "Enter The Amount To Be Deposite\nThe Amount Is : ";
				cin >> amount;
				bal += amount;
				cout << "-------------------------Successful Transaction----------------------------------- \n";
			}
			else if (i == (int)CustomerServices::Balance)
			{
				cout << "Your Current Balance is :  " << bal << endl;

				cout << "-------------------------Successful Process--------------------------------------\n";
			}
			else cout << "Invalid Choice\n ";
			cout << "Choice Your Serve  \n";
			cout << "0)To Exit \n1)Withdrawal \n2)Deposite \n3)Checking Your Current Balance\nYour Choice is : ";
			cin >> i;
		}

		change_balance(bal);

	}

public:
	void DisplayMenu()
	{
		while (true)
		{
			cout << "===================================";
			cout << "Welcome Customer\n";
			cout << "Choice one of Your Servics\n";
			cout << "1) Log_in\n2)Apply To Make New Account\n ";
			cout << "Enter Your Choice Number : ";
			int x; cin >> x;
			cin.ignore();
			if (x == (int)CustomerChoices::login)
			{
				while (!Check_login(customer))
				{
					cout << "Invalid Login Please Check Your Data and Try Again ! \n";
				}

				cout << "---------------------Hello Customer----------------------\n";
				cout << "Choice Your Order\n";
				cout << "1)Withdrawal \n2)Deposite \n3)Checking Your Current Balance\nYour Choice is : ";
				int cho; cin >> cho;
				while (cho < 1 && cho>3)
				{
					cout << "Please Enter Valid Number From 1 To 3 Only\n";
					cout << "Choice Your Order\n";
					cout << "1)Withdrawal \n2)Deposite \n3)Checking Your Current Balance\nYour Choice is : ";
					cin >> cho;
				}

				Services(cho);
				break;
			}
			else if (x == (int)CustomerChoices::application)
			{
				fstream cust("CustomerApp.txt", ios::app | ios::out);
				string name, nationality; int id; double balance;
				cout << "Enter Your Name : \n";
				getline(cin, name);
				string pass;
				cout << "Enter Your id : \n"; cin >> id;
				cout << "Enter Your Nationality : \n"; cin >> nationality;
				cout << "Enter Your Current Balance : \n"; cin >> balance;
				cout << "Enter Your Password : \n";
				cin.ignore();

				getline(cin, pass);
				cust << "Name: " << name << "|Nationality:  " << nationality << "|Id: " << id << "|Balance: " << balance << "| Password :" << pass << endl;
				cout << "_____________________Thank You_______________________\n";
				break;
			}
			else
			{
				cout << "Invalid Choice \n";
				cout << "Valid choice is 1 or 2 only\n";
			}
		}
	}

};

class Checking
{
public:
	Checking()
	{
		cout << "                                  Welcome To Our Bank Mangement System \n";
		while (true)
		{
			cout << "Choice Your Enter  \n 1) Admin\n 2) Employee\n 3) Customer\n";
			cout << "Your Status Is : ";
			int choice; cin >> choice;
			try
			{
				if (choice >= 4 || choice <= 0)throw"Please Enter Your Status between 1 to 3 Only\n";
				else
				{
					Enter = choice;
					break;
				}
			}
			catch (const char* x)
			{
				cout << x << endl;
			}
		}
	}
	~Checking()
	{
		cout << "-------------------------------------------Thank You-------------------------------------------\n";
	}
};

int main()
{
	bool ok = true;
	while (ok)
	{
		User* us[3]; Admin adm; Employee emp; Customer cus;
		us[0] = &adm;
		us[1] = &emp;
		us[2] = &cus; Checking obj;
		if (Enter - 1 == admin)us[admin]->DisplayMenu();
		else if (Enter - 1 == customer)us[customer]->DisplayMenu();
		else us[employee]->DisplayMenu();
		cout << "1 - Exit \n2 - New Operation ";
		int choice;

		cin >> choice;
		ok = (choice == 1) ? 0 : 1;

	}
	return 0;
}
