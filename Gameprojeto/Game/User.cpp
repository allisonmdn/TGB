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
	regIn.open("Register.bin", std::ios::binary);  //Open.
	//pass.open("Password.bin", std::ios::in | std::ios::binary);
	

	Account *account = new Account();

	while (/*!us.eof() && !pass.eof()*/ !regIn.eof())
	{
		regIn.read(reinterpret_cast<char *>(account), sizeof(Account));
		userName = account->username;
		passWord = account->password;		
	}
	
	std::cout << "Enter your username and password.\n";
	std::cout << "Username: ";
	std::cin >> uNameLog;

	//itU = std::find(uStack.begin(), uStack.end(), uNameLog);
	
	//itU != uStack.end()

	if (uNameLog == userName)
	{
		std::cout << "Password: ";
		std::cin >> passwLog;

		//itP = std::find(pStack.begin(), pStack.end(), passwLog);
		//itP != pStack.end()
		if (passwLog == passWord)
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
	//us.close()  //Close.
	//pass.close();
	regIn.close();
	
}

void User::Register()
{
	reg.open("Register.bin", std::ios::binary);	  //Open
	//pass.open("Password.bin", std::ios::out | std::ios::binary);
	
	Account *account = new Account();

	do {													  //Username
		std::cout << "Register your username: " << std::endl;
		std::cin >> userName;
		std::cout << "\n";				
				
		if (userName.length() >= 6 && userName.length() <= 12)
		{
			//us << userName; 
			account->username = userName;
			break;
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
			//pass << "\n" << passWord << "\n";
					

			account->password = passWord;
			
			reg.write(reinterpret_cast<char *>(account), sizeof(Account));
		}
		else
		{
			system("cls");					  
		}
	} while (passWordC != passWord || passWord.length() < 6 || passWord.length() > 12);		
	
	//us.close();   //Close
	//pass.close();
	reg.close();
}

