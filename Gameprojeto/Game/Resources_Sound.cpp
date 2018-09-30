#include "Resources_Sound.h"



Resources_Sound::Resources_Sound()
{
	
} 

Resources_Sound::~Resources_Sound()
{
}
void Resources_Sound::setThemeSong(std::string Theme_s)
{
		
	gRecursos.carregarMusica("Kings_Feast", "assets/sounds/Kings_Feast.ogg");
	gRecursos.carregarMusica("Desert_Theme", "assets/sounds/Desert_Theme.ogg");
	gMusica.tocar(Theme_s, true, 0, 0);
			
	if (!gRecursos.carregouMusica(Theme_s))
	{
		gDebug.erro("Error in loading theme");		
	} 	
}

void Resources_Sound::setEffectSong(std::string Effect_s)
{			
	gRecursos.carregarAudio("explosion", "assets/sounds/Explosion.wav");
	gRecursos.carregarAudio("hit", "assets/sounds/Hit.wav");
	gRecursos.carregarAudio("hurt", "assets/sounds/Hurt.wav");
	gRecursos.carregarAudio("laser_shoot","assets/sounds/Laser_Shoot.wav");
	gMusica.tocar(Effect_s, false);
	
	if (!gRecursos.carregouAudio(Effect_s))
	{
		gDebug.erro("Error in loading audio");
	}
}


