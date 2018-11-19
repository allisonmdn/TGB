#include "stdafx.h"
#include "User.h"


User::User()
{
}


User::~User()
{
}

void User::Register()
{
	InOrOut.open("Register.bin", std::ios::out | std::ios::binary);	  //Open

	do {													  //Username
		std::cout << "Input your username: " << std::endl;
		std::cin >> Username;
		std::cout << "\n";
				
		if (Username.length() >= 6 && Username.length() <= 12)
		{
			InOrOut << Username;
		}
		else
		{
			system("cls");
		}
	} while (Username.length() < 6 || Username.length() > 12);
	do {													   //Password
		std::cout << "Input your password: " << std::endl;
		std::cin >> Password;
		std::cout << "\n";
		if (Password.length() >= 6 && Password.length() <= 12)
		{  			
			InOrOut << "\n" << Password << "\n";
		}
		else
		{
			system("cls");					  
		}
	} while (Password.length() < 6 || Password.length() > 12);
	
	InOrOut.close();   //Close
}
