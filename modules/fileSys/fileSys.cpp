#include "fileSys.hpp"
#include <nfd.h>
#include "nfd.hpp"
#include <filesystem>
#include<iostream>
#include<codecvt>
#include<locale>
fileSys::fileSys()
{
}

fileSys::~fileSys()
{
}

std::string fileSys::OpenFileDialog()
{
	NFD::Guard nfdGuard;
	NFD::UniquePath outPath;
	nfdfilteritem_t filterItem[1] = { {"🎵音乐文件🎵", "mp3,flac,ogg"} };
	nfdresult_t result = NFD::OpenDialog(outPath, filterItem, 1);
	if (result == NFD_OKAY)
	{
		return outPath.get();
	}
	else if (result == NFD_CANCEL)
	{
		return "用户取消";
	}
	else
	{
		return NFD::GetError();
	}
}

std::string fileSys::OpenFolderDialog()
{
	NFD::Guard nfdGuard;
	NFD::UniquePath outPath;
	nfdresult_t result = NFD::PickFolder(outPath);
	if (result == NFD_OKAY)
	{
		return outPath.get();
	}
	else if (result == NFD_CANCEL)
	{
		return "";
	}
	else
	{
		return NFD::GetError();
	}
}

std::vector<std::string> fileSys::GetFilePathFromFolderPath(std::string FolderPath)
{
	std::vector<std::string> result = {};
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(FolderPath))
	{
		if (!dir_entry.is_directory())
		{
			//printf("%s\t%s\n", dir_entry.path().extension().string().substr(1).c_str(), dir_entry.path().string().c_str());
			for (auto& i : MusicFileType)
			{
				if (dir_entry.path().extension().string().substr(1) == i)
				{
					std::wstring path_ansi = dir_entry.path().wstring();
					std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
					std::string utf8Str = converter.to_bytes(path_ansi);
					result.push_back(utf8Str);
					break;
				}
			}
		}
	}
	return result;
}

