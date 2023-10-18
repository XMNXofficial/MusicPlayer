#include "MusicPlayer.hpp"
#include <hello_imgui.h>
#include <core.hpp>
#include <imgui_internal.h>
int main()
{
	MainAPP.RunGUI();
	return 0;
}


void MusicPlayer::ShowGUI()
{
	static std::string text_welcome = "欢迎使用XMNX的专属音乐播放器!";
	ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize(text_welcome.c_str()).x) / 2);
	ImGui::Text("%s", text_welcome.c_str());
}

void MusicPlayer::ShowMENU()
{
	if (ImGui::BeginMenu("文件"))
	{
		if (ImGui::MenuItem("从文件导入"))
		{

		}
		if (ImGui::MenuItem("从文件夹导入"))
		{

		}
		if (ImGui::MenuItem("退出"))
		{

		}
		ImGui::EndMenu();
	}

	ImGui::SameLine();
	ImGui::Text("尹俊镔666");
}

void MusicPlayer::ShowControl()
{
	//音乐状态显示
	{
		static const ImVec2 size_image = { 80,80 };
		HelloImGui::ImageButtonFromAsset(R"(yl-image.jpg)", size_image);
		ImGui::SameLine();
		ImGui::Text("やわらかな光");
	}


	//三个按钮
	{
		static const  ImVec2 size_button = { 180,80 };
		static const float spacing_button = 5.0f;
		static const float startX_button = 0.0f;
		ImGui::SetCursorPosX((ImGui::GetWindowSize().x - size_button.x * 3 - spacing_button * 3) / 2);
		ImGui::SetCursorPosY((ImGui::GetWindowSize().y - size_button.y) / 2);
		if (ImGui::Button("上一首", size_button))
		{

		}
		ImGui::SameLine(startX_button, spacing_button);
		if (ImGui::Button("继续/暂停", size_button))
		{

		}
		ImGui::SameLine(startX_button, spacing_button);
		if (ImGui::Button("下一首", size_button))
		{

		}

	}

}

HelloImGui::DockingParams MusicPlayer::CreateDockingParams()
{
	HelloImGui::DockingParams DP;//docking总参数
	std::vector<HelloImGui::DockingSplit> DS;//容器空间分配,空间分配百分比受分配顺序影响
	std::vector<HelloImGui::DockableWindow> DW;//存储窗口信息,可以指定窗口放在哪个docking空间.
	//分配容器空间
	{
		//创建容器空间
		HelloImGui::DockingSplit DS_control;
		DS_control.initialDock = "MainDockSpace";//基于主窗口进行分配
		DS_control.newDock = "control_dock";//容器名
		DS_control.direction = ImGuiDir_Down;
		DS_control.ratio = 0.10f;
		DS_control.nodeFlags = ImGuiDockNodeFlags_NoTabBar;
		DS.push_back(DS_control);
	}

	//在容器空间内创建窗口
	{
		//在指定dock空间内创建指定窗口
		HelloImGui::DockableWindow DW_control;
		DW_control.label = "control_window";//设置窗口标题
		DW_control.dockSpaceName = "control_dock";//容器名
		DW_control.GuiFunction = [] {ShowControl(); };//界面渲染
		DW.push_back(DW_control);
	}

	DP.dockingSplits = DS;
	DP.dockableWindows = DW;
	return DP;
}

MusicPlayer::MusicPlayer()
{
}

MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::RunGUI()
{
	HelloImGui::RunnerParams p;
	//窗口容器大小
	p.appWindowParams.windowGeometry.size = { 1400, 1200 };
	p.appWindowParams.windowGeometry.windowSizeMeasureMode = HelloImGui::WindowSizeMeasureMode::ScreenCoords;

	//imgui窗口提供方式
	//p.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenWindow;
	p.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace;

	//加载字体
	p.callbacks.LoadAdditionalFonts = [this]() {
		ImFontGlyphRangesBuilder a;
		static ImVector<ImWchar>b;
		a.AddRanges(ImGui::GetIO().Fonts->GetGlyphRangesChineseFull());
		a.BuildRanges(&b);
		gFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyhbd.ttc", 25.0f, nullptr, b.Data); };
	//设置imgui样式
	{
		p.imGuiWindowParams.showMenuBar = true;
		p.imGuiWindowParams.showMenu_App = false;
		p.imGuiWindowParams.showMenu_App_Quit = false;
		p.imGuiWindowParams.showMenu_View = false;
		p.imGuiWindowParams.rememberStatusBarSettings = false;
		p.imGuiWindowParams.rememberTheme = false;
	}
	//对接函数
	{
		//GUI显示函数
		//p.callbacks.ShowGui = ShowGUI;
		p.dockingParams = CreateDockingParams();


		//窗口菜单显示函数
		p.callbacks.ShowMenus = ShowMENU;
	}
	//运行
	HelloImGui::Run(p);


	
}
