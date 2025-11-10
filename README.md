Bank Management System in C++

This is a console-based Bank Management System implemented in C++. The system allows Admin, Employee, and Customer users to manage bank operations such as account creation, balance management, and transactions.

Features

                Admin

Login or create a new admin account.

Approve or reject new customer applications.

Update or delete existing customer accounts.

Check the general bank balance.

See number of accounts and details of all customers.

              Employee

Login or create a new employee account.

Perform withdrawals and deposits for customers.

Check number of bank accounts and bank balance.

              Customer

Login to an existing account or apply for a new account.

Perform withdrawals, deposits, and check current balance.

File Storage

The program uses text files to store user data:

File Name Purpose :

Admins.txt Stores admin accounts
Employees.txt Stores employee accounts
Customers.txt Stores approved customer accounts
CustomerApp.txt Stores pending customer applications
Temp.txt Temporary file for account updates
Program Flow

On startup, the user chooses their role: Admin, Employee, or Customer.

Depending on the role, users can login or create a new account.

Once logged in:

Admins can approve customers, update accounts, or check balances.

Employees can manage customer transactions.

Customers can deposit, withdraw, or check their balance.

All data is saved and updated in the text files.

Compilation and Execution

Compile the program using g++:

g++ -o bank_system main.cpp

Run the executable:

./bank_system

Dependencies

Standard C++ library (iostream, fstream, vector, algorithm, string)

No external libraries required.

Notes

The system uses text-based menus for interaction.

Customer accounts are first added as applications and need admin approval.

Bank balance and transactions are tracked in Customers.txt.

Example
Welcome To Our Bank Management System
Choice Your Enter

1. Admin
2. Employee
3. Customer
   Your Status Is : 1

Admin logs in → Approves customers, updates accounts.

Employee logs in → Deposits/Withdraws money for customers .

Customer logs in → Checks balance, deposits, withdraws, or applies for a new account.

Author

Developed by: developer\ Yassin Momen Ahmed

Project: Bank Management System in C++
