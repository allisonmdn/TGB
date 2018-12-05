#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Account.h"
#include "StackAccounts.h"
#include "Texto.h"
#include "libUnicornio.h"

#pragma once
class User
{
public:
	User();
	~User();
	void Register();
	void Login();	
	
protected:
	std::string userName, passWord, userNameC, passWordC;	 	
	std::string uNameLog, passwLog;
	std::ofstream reg;
	std::ifstream regIn;
	Texto inputTEXT;
	StackAccounts StackUser;
	
	
};

