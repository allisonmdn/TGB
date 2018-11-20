#include "stdafx.h"
#include "User.h"


User::User()
{
		
}


User::~User()
{
}
void User::Login()
{
	us.open("Username.bin", std::ios::in | std::ios::binary);  //Open.
	pass.open("Password.bin", std::ios::in | std::ios::binary);

	while (!us.eof() && !pass.eof())
	{
		if (us.is_open())
		{
			us >> userName;
			uStack.push_back(userName);
			uStack.size();
		}
		if (pass.is_open())
		{
			pass >> passWord;
			pStack.push_back(passWord);
			pStack.size();
		}
	}

	std::cout << "Enter your username and password.\n";
	std::cout << "Username: ";
	std::cin >> uNameLog;

	itU = std::find(uStack.begin(), uStack.end(), uNameLog);
	
	if (itU != uStack.end())
	{
		std::cout << "Password: ";
		std::cin >> passwLog;

		itP = std::find(pStack.begin(), pStack.end(), passwLog);
		
		if (itP != pStack.end())
		{	 			
			std::cout << "Password correct!\n";			
		}
		else
		{
			std::cout << "Password incorrect!\n";
		}
	}
	else
	{
		std::cout << "Username incorrect! \n";
	}
	us.close();	  //Close.
	pass.close();

}

void User::Register()
{
	us.open("Username.bin", std::ios::out | std::ios::binary);	  //Open
	pass.open("Password.bin", std::ios::out | std::ios::binary);
		

	do {													  //Username
		std::cout << "Register your username: " << std::endl;
		std::cin >> userName;
		std::cout << "\n";
		
				
		if (userName.length() >= 6 && userName.length() <= 12)
		{
			us << userName;
		}
		else
		{
			system("cls");
		}
	} while (userName.length() < 6 || userName.length() > 12);
	do {													   //Password
		std::cout << "Register your password: " << std::endl;
		std::cin >> passWord;
		std::cout << "\n";
		std::cout << "Retype your password: " << std::endl;
		std::cin >> passWordC;
		if (passWordC == passWord && passWord.length() >= 6 && passWord.length() <= 12)
		{  			
			pass << "\n" << passWord << "\n";
		}
		else
		{
			system("cls");					  
		}
	} while (passWordC != passWord || passWord.length() < 6 || passWord.length() > 12);
	
	us.close();   //Close
	pass.close();
}
