#include "fileSys.hpp"
#include <nfd.h>
fileSys::fileSys()
{
	NFD_Init();
}

fileSys::~fileSys()
{
	NFD_Quit();
}

std::string fileSys::OpenFile()
{
	nfdchar_t* outPath;
	nfdfilteritem_t filterItem[1] = { {"音乐文件", "mp3,flac,ogg,m4a"} };
	nfdresult_t result = NFD_OpenDialog(&outPath, filterItem, 1, NULL);
	if (result == NFD_OKAY)
	{
		//选择成功
		result_path = std::string(outPath);
		NFD_FreePath(outPath);
	}
	else if (result == NFD_CANCEL)
	{
		//用户取消
		//无需释放outPath
		result_path = "";
	}
	else
	{
		//报错
		//无需释放outPath
		result_path = "";
		printf("Error: %s\n", NFD_GetError());
	}
	return result_path;
}
