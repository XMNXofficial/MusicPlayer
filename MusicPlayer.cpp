#include "MusicPlayer.hpp"
#include <hello_imgui.h>
using namespace std;
void showgui();
ImFont* gFont = nullptr;

int main()
{
	HelloImGui::RunnerParams p;
	p.appWindowParams.windowGeometry.size = { 800, 600 };
	p.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenWindow;
	p.callbacks.ShowGui = showgui;
	p.callbacks.LoadAdditionalFonts = []() {
		ImFontGlyphRangesBuilder a;
		static ImVector<ImWchar>b;
		a.AddRanges(ImGui::GetIO().Fonts->GetGlyphRangesChineseFull());
		a.BuildRanges(&b);
		gFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyhbd.ttc", 20.0f, nullptr, b.Data); };
	HelloImGui::Run(p);
	return 0;
}
void showgui()
{

}