
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
	
	Account *account = new Account();

	while (!regIn.eof())
	{
		regIn.read(reinterpret_cast<char *>(account), sizeof(Account));
		userName = account->username;
		passWord = account->password;		//Stack vector.
		
	}
		
	//std::cout << "Enter your username and password.\n";
	//std::cout << "Username: ";
	
	//std::cin >> uNameLog;
	gTeclado.inputTexto.habilitar();
	inputTEXT.setFonte("fonte1");	
	inputTEXT.setString("Login:");
	inputTEXT.desenhar(400, 300); 	
	inputTEXT.setString("");
	if (gTeclado.soltou[TECLA_ENTER])
	{	
		uNameLog = gTeclado.inputTexto.getString();	 				
		gTeclado.inputTexto.desabilitar();
	}


	if (uNameLog == userName)
	{
		std::cout << "Password: ";
		std::cin >> passwLog;
		
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
	
	regIn.close();
	
}

void User::Organize()
{

	
	//		Apagar o texto com tecla voltar ou delete
	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		gTeclado.inputTexto.apagar();
	}
	if (gTeclado.pressionou[TECLA_DELETE])
	{
		if (gTeclado.inputTexto.getTamanhoSelecao() != 0)
			gTeclado.inputTexto.apagar();
		else if (gTeclado.inputTexto.getPosCursor() < gTeclado.inputTexto.getString().size())
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
			gTeclado.inputTexto.apagar();
		}
	}

	//		Mover a seleção do texto
	if (gTeclado.segurando[TECLA_SHIFT_ESQ])
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverSelecaoParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverSelecaoParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverSelecaoParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverSelecaoParaFim();
		}
	}
	//		Mover o cursor do texto
	else
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverPosCursorParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverPosCursorParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverPosCursorParaFim();
		}
	}

	//	3) Passar a string do input para o texto
	txt.setString(gTeclado.inputTexto.getString());
}

void User::Register()
{
	 	
	reg.open("Register.bin", std::ios::binary | std::ios::app);	  //Open

																  //Account *account = new Account();

	typedef std::unordered_map<std::string, std::string> type_map;
	typedef std::unordered_multimap<std::string, std::string> type_multimap;
	typedef std::pair<std::string, std::string> par;

	type_map users;
	par user;
	type_multimap::iterator it_multimap, it_multimap2;
	type_map::iterator it;

	user.first = "";
	user.second = "";

	if (!reg.is_open())
	{
		gDebug.erro("Arquivo de registro não está aberto");
	}
	else
	{
		Organize();
		
		gTeclado.inputTexto.habilitar();

		inputTEXT.setFonte("fonte1");
		inputTEXT.setString("");

		inputTEXT.desenhar(400, 300);


		if (gTeclado.pressionou[TECLA_ENTER])
		{

			if (user.first.empty())
			{
				user.first = gTeclado.inputTexto.getString();//Account

				gDebug.depurar("login: ", user.first);

				gTeclado.inputTexto.desabilitar();
			}
			else
			{

				do {


					if (!gTeclado.inputTexto.estaHabilitado())
					{
						gTeclado.inputTexto.habilitar();

						inputTEXT.setString(user.second);

						inputTEXT.desenhar(400, 400);

						if (user.second.empty())
						{
							user.second = gTeclado.inputTexto.getString();

							gDebug.depurar("password: ", user.first);

							gTeclado.inputTexto.desabilitar();
						}
						else
						{

							if (!gTeclado.inputTexto.estaHabilitado() && passwLog.empty())
							{
								gTeclado.inputTexto.habilitar();

								passwLog = gTeclado.inputTexto.getString();

								gDebug.depurar("re-type password", passwLog);

								if (passwLog == user.second)
								{
									user.second = passwLog;

									gDebug.depurar("password correct:", user.second);

									users.insert(user);

									reg << user.first << "\n" << user.second;

									gTeclado.inputTexto.desabilitar();
								}
								else
								{
									std::string teste3 = "PASSWORD INCORRECT";
									gGraficos.desenharTexto(teste3, 400, 300, 92, 51, 23, 255, 0, 0);
									gTeclado.inputTexto.desabilitar();
								}

							}

						}
					}
				} while (passwLog != user.second);
			}
			
			
		}
				
	}
	

	/*
	do {													  //Username
		std::cout << "Register your username: " << std::endl;
		std::cin >> userName;
		std::cout << "\n";				
				

		if (userName.length() >= 6 && userName.length() <= 12)
		{				
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
			
			account->password = passWord;

			StackUser.accountStack.push_back(*account);
			
			reg.write(reinterpret_cast<char *>(account), sizeof(Account));
		}
		else
		{				
			system("cls");					  
		}
	} while (passWordC != passWord || passWord.length() < 6 || passWord.length() > 12);		
	
	//us.close();   //Close
	//pass.close();
	*/
	reg.close();
}

