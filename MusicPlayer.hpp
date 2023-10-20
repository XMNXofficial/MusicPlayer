#pragma once
#include <hello_imgui.h>
#include <core.hpp>
#include <fileSys.hpp>

class MusicPlayer {
private:
	ImFont* gFont = nullptr;
	static void ShowGUI();
	static void ShowMENU();
	static void ShowControl();//音乐控制面板
	HelloImGui::DockingParams CreateDockingParams();
public:
	MusicPlayer();
	~MusicPlayer();
	void RunGUI();
};

MusicPlayer MainAPP;
