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
	std::string OpenFileDialog();//ѡ���ļ��Ի���,�����ļ�ȫ·��
	std::string OpenFolderDialog();//ѡ���ļ��жԻ���,�����ļ���ȫ·��
	std::vector<std::string> GetFilePathFromFolderPath(std::string FolderPath);//��ȡ�ļ����������ļ�ȫ·��

};