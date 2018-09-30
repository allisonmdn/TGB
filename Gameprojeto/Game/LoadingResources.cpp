#include "LoadingResources.h"

LoadingResources::LoadingResources()
{

}
LoadingResources::~LoadingResources()
{
}
bool LoadingResources::Loader(std::fstream & fstr_resource_f)
{
	bool b_loader_status = true;
	std::string def_resource_type;
	std::string def_resource_name;
	std::string def_resource_local;
	std::string def_n_animations;
	std::string def_n_max_frames;
	std::string vol;
	std::string::size_type size;

	if (fstr_resource_f)
	{
		char q_resources = fstr_resource_f.get();
		this->resources_n = q_resources - '0';
		gDebug.depurar("nResources", this->resources_n);

		while (!fstr_resource_f.eof())
		{				
			fstr_resource_f >> def_resource_type >> def_resource_name >> def_resource_local >> def_n_animations >> def_n_max_frames;
			

			if (!fstr_resource_f.fail())
			{
				gDebug.depurar("error", fstr_resource_f.fail());
				gDebug.depurar("resource_type", def_resource_type);
				gDebug.depurar("resource_name", def_resource_name);
				gDebug.depurar("resource_local", def_resource_local);
				gDebug.depurar("n_animations", def_n_animations);
				gDebug.depurar("n_max_frames", def_n_max_frames);

				if (def_resource_type == "sprite_sheet")
				{
					gRecursos.carregarSpriteSheet(def_resource_name, def_resource_local, std::stoi(def_n_animations, &size),
						std::stoi(def_n_max_frames, &size), QUALIDADE_ESCALA_BAIXA);
				}
				if (def_resource_type == "sounds")
				{
					gRecursos.carregarAudio(def_resource_name, def_resource_local);
				}
				if (def_resource_type == "music")
				{
					gRecursos.carregarMusica(def_resource_name, def_resource_local, std::stof(vol, &size));
				
				}

				if (!gRecursos.carregouSpriteSheet(def_resource_name) || !gRecursos.carregouAudio(def_resource_type) || !gRecursos.carregouMusica(def_resource_type))
				{
					if (!gRecursos.carregouSpriteSheet(def_resource_name))
					{
						gDebug.erro("Error in loading resources (Sprite Sheets)");
					}
					if (!gRecursos.carregouAudio(def_resource_type))
					{
						gDebug.erro("Error in loading resources (Sounds)");
					}
					if (!gRecursos.carregouMusica(def_resource_type))
					{
						gDebug.erro("Error in loading resources (Music Background)");
						
					}

					return false;
				}
				
				

		    }			 

		}


		return true;



	}



}
