#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Account.h"  
#include "Texto.h"
#include "libUnicornio.h"
#include <unordered_map>
#include <map>
#include <algorithm>
#include "InputTexto.h"

#pragma once
class User
{
public:
	User();
	~User();
	void Register();
	void Login();	
	Texto getText();
	
protected:
	//std::string userName, passWord, userNameC, passWordC;	 	
	//std::string uNameLog, passwLog;
	//std::ofstream reg;
	//std::ifstream regIn;
	//Texto inputTEXT;
	//InputTexto inputMe;
	
	
};

