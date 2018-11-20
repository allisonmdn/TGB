#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


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
	std::vector <std::string> uStack, pStack, account;//Account[0] == uStack[0] and pStack[0]; 	
	std::string uNameLog, passwLog;
	std::fstream us; std::fstream pass;
	bool acessGranted;
	std::vector <std::string>::iterator itU, itP;
	
};

