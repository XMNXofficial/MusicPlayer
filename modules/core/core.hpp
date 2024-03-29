#pragma once
#include <bass.h>
#include <string>

struct audioInformation
{
	std::string AudioName = "";
	std::string SingerName = "";
};

class core
{
private:
	HSTREAM stream = NULL;
	bool initOK = false;
public:
	core();
	~core();
	bool isInitOK() { return initOK; };
	bool loadFile(const std::string filePath);
	bool loadFolder(const std::string folderPath);
	audioInformation getAudioInfo();
	bool play();
	bool pause();
	bool stop();
	bool isPlaying();
	float getVolume();
	bool setVolume(float volume);
};
