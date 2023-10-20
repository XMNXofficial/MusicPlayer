#pragma once
#include <string>
class fileSys
{
private:
	std::string result_path = "";
public:
	fileSys();
	~fileSys();
	std::string OpenFile();
};