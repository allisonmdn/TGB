#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include <fstream>
#pragma once
class StackAccounts: virtual public Account
{
public:
	StackAccounts();
	~StackAccounts();
	std::vector<Account>accountStack;	
	int size = accountStack.size();	

protected:
	std::ifstream accIn;
	std::ofstream accOut;

};

