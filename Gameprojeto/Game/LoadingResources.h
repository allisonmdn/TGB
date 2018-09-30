#include <iostream>
#include <fstream>
#include <string>
#include <Global.h>

//Resources: <resource_type> <resource_name> <resource_local> [<n_animations> <n_max_frames>]


class LoadingResources
{
public:
	LoadingResources();
	~LoadingResources();
	bool Loader(std::fstream & fstr_resources_f);
private:
	int resources_n;

};

