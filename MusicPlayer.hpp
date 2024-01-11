#pragma once
#include <core.hpp>
#include <fileSys.hpp>
#include <hello_imgui.h>

class MusicPlayer
{
private:
	enum
	{
		Table_MusicLists_ID_ID,//ID,可以替换为收藏按钮之类的
		Table_MusicLists_ID_SongTitle,//歌名
		Table_MusicLists_ID_Singer,//歌手
		Table_MusicLists_ID_Album//专辑
	}Table_MusicLists_ID;
	ImFont* gFont = nullptr;
	static void ShowGUI();
	static void ShowMENU();
	static void ShowControl();//音乐控制面板
	static void ShowDevelop();
	static void ShowMusicLists();//音乐列表
	HelloImGui::DockingParams CreateDockingParams();
public:
	MusicPlayer();
	~MusicPlayer();
	void RunGUI();
};

MusicPlayer MainAPP;
