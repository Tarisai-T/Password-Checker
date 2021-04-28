//CIS 3100 - Assignment 9

#include <iostream>
#include <string>
using namespace std;

//validatePassword takes a string variable as parameter and returns an integer
int validatePassword(string user_password)
{
	int i;
	int n = user_password.length();
	bool Upper = false; 
	bool Lower = false;
	bool Number = false;
	

	for (i = 0; i < n; i++)
	{
		if (isupper(user_password[i])) //Returns true if argument is uppercase letter
		{
			Upper = true;
		}
		if (islower(user_password[i])) //Returns true if argument is lowercase letter
		{
			Lower = true;
		}
		if (isdigit(user_password[i])) //Returns true if argument is digit from 0 through 9
		{
			Number = true;
		}			
	}
//Criteria
	if (Upper& Lower& Number)
	{
		cout << "Good Password!" << endl; 
		return 0;  //password meets all criteria
	}
	//Be at least eight characters long
	if (user_password.length() < 8)
	{
		cout << "Password must be at least 8 characters long. ";
		return 1; //does not meet criteria 1
	}
	//Contain at least one uppercase
	if (Upper != true)
	{
		cout << "Password must contain at least one uppercase letter. ";
		return 2; //does not meet criteria 2
	}
	//Contain at least one loweercase
	if (Lower != true)
	{
		cout << "Password must contain at least one lowercase letter. ";
		return 2; //does not meet criteria 2	
	}
	//Have at least one digit
	if (Number != true)
	{
		cout << "Password must contain at least one digit. ";
		return 3; //does not meet criteria 3
	}
}

int main()
{
	string user_password;

	cout << "Enter Password: " << endl;
	cin >> user_password; //user input
//keep asking for the password until it meets all criteria
	while (validatePassword(user_password) != 0)
	{
		cout << "Please Try Again.\n";
		cout << "Enter Password: " << endl;
		cin >> user_password;
	} 
	return 0;
}

/* Develop a program that validates a password (string) entered by a user. The password must meet the following criteria:

1. Be at least eight characters long.
2. Contain at least one uppercase and Contain at least one uppercase.
3. Have at least one digit.

Write a program that asks for a password and then verifies that it meets the stated criteria.
If it does not, the program should display a message telling the user why and then ask for another password.
The program should keep asking for the password until the password meets the criteria.

The validation should be done on a separate function called validatePassword, which takes a string
variable as parameter and returns an integer. It should return 0 if the password is valid and 1 if 
it does not match the first criteria, 2 if it does not match the second criteria and 3 if it does not match the third criteria */
