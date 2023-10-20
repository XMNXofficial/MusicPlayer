#pragma once
#include "bass.h"
#include <string>
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
	bool play();
	bool pause();
	bool stop();
	float getVolume();
	bool setVolume(float volume);
};