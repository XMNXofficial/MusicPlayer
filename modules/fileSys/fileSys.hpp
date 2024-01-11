#pragma once
#include <string>
#include <vector>
class fileSys
{
private:
	std::string result_path = "";
	std::vector<std::string>MusicFileType = { "mp3","ogg","flac" };
public:
	fileSys();
	~fileSys();
	std::string OpenFileDialog();//选择文件对话框,返回文件全路径
	std::string OpenFolderDialog();//选择文件夹对话框,返回文件夹全路径
	std::vector<std::string> GetFilePathFromFolderPath(std::string FolderPath);//获取文件夹内所有文件全路径

};