// Author: Parker Padgett
// Assignment: Project 7 - Object Oriented Programming
// Description: Use object oriented programming and get data about the user, and calculate overtime (if user has it),
//				tax rate based on deductions user claimed, gross, and net pay, and output to the screen. 
// Date: 3/19/2022


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class employee
{
public:
	// Functions
	// Set functions
	void setFirstName(string text)
	{
		fName = text;
	}
	void setLastName(string text)
	{
		lName = text;
	}
	void setTitle(string text)
	{
		title = text;
	}
	void setEmployeeNumber(int number)
	{
		num = number;
	}
	void setHoursWorked(double number)
	{
		hours = number;
	}
	void setHourlyWage(double number)
	{
		wage = number;
	}
	void setDeductions(int number)
	{
		deductions = number;
	}
	void setPay()
	{
		if (hours > 40) 
		{
			oTimeWage = 1.5 * wage;
			oTimeHours = hours - 40;
			oTimePay = oTimeWage * oTimeHours;

			grossPay = oTimePay + (40 * wage);
		}
		else
		{
			grossPay = wage * hours;
		}

		if (deductions <= 0)
			tax = .30;
		else if (deductions <= 1)
			tax = .25;
		else if (deductions <= 2)
			tax = .20;
		else if (deductions <= 3)
			tax = .15;
		else
			tax = .10;

		tax = tax * grossPay;

		netPay = grossPay - tax;
	}


	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}
	string getTitle()
	{
		return title;
	}
	int getEmployeeNumber()
	{
		return num;
	}
	double getHoursWorked()
	{
		return hours;
	}
	double getHourlyWage()
	{
		return wage;
	}
	int getDeductions()
	{
		return deductions;
	}
	double getoTimeWage()
	{
		return oTimeWage;
	}
	double getoTimeHours()
	{
		return oTimeHours;
	}
	double getoTimePay()
	{
		return oTimePay;
	}
	double getGrossPay()
	{
		return grossPay;
	}
	double getTaxesWithheld()
	{
		return tax;
	}
	double getNetPay()
	{
		return netPay;
	}


private:
	// Variables
	string fName, lName, title;
	int num, deductions;
	double hours, wage, oTimeHours, oTimeWage, oTimePay, grossPay, taxesWitheld, netPay, tax;
};


// Function Declaration
void output(ifstream& inFile, employee info[10]);

// Function Declaration

int main()
{
	// Open input file
	ifstream inFile;
	inFile.open("input.txt");

	employee info[10];

	output(inFile, info);

	inFile.close();
	return 0;
}

void output(ifstream& inFile, employee info[10])
{
	string temp;
	int number;
	double dub;

	// input
	for (int a = 0; a <= 2; a++)
	{
		inFile >> temp;
		info[a].setFirstName(temp);

		inFile >> temp;
		info[a].setLastName(temp);

		inFile >> temp;
		info[a].setTitle(temp);

		inFile >> number;
		info[a].setEmployeeNumber(number);

		inFile >> dub;
		info[a].setHoursWorked(dub);

		inFile >> dub;
		info[a].setHourlyWage(dub);

		inFile >> number;
		info[a].setDeductions(number);

		info[a].setPay();
	}


	// output
	for (int a = 0; a <= 2; a++)
	{
		cout << "Name: " << info[a].getFirstName() << " " << info[a].getLastName() << endl;
		cout << "Tile: " << info[a].getTitle() << endl;
		cout << "Employee Number: " << info[a].getEmployeeNumber() << endl;
		cout << "Hours Worked: " << info[a].getHoursWorked() << endl;
		cout << "Hourly Wage: $" << info[a].getHourlyWage() << endl;
		cout << "Number of Deductions: " << info[a].getDeductions() << endl;

		if (info[a].getHoursWorked() > 40)
		{
			cout << "Overtime Wage: " << info[a].getoTimeWage() << endl;
			cout << "Overtime Hours: " << info[a].getoTimeHours() << endl;
			cout << "Overtime Pay: $" << info[a].getoTimePay() << endl;
		}

		cout << "Gross Pay: $" << info[a].getGrossPay() << endl;
		cout << "Taxes Withheld: $" << info[a].getTaxesWithheld() << endl;
		cout << "Net Pay: $" << info[a].getNetPay() << endl << endl;
	}
}