#include <iostream>
#include <fstream>
#include <string>
#pragma once
class User
{
public:
	User();
	~User();
	void Register();
	
protected:
	std::string Username, Password;		
	std::fstream InOrOut;
	
};

