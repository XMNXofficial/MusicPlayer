#include "core.hpp"
#include <iconv.h>

core::core()
{
	if (BASS_Init(-1, 44100, BASS_UNICODE, NULL, NULL))
	{
		initOK = true;
	}
	else
	{
		initOK = false;
	}
}

core::~core()
{
	BASS_StreamFree(stream);//释放流
	BASS_Free();//释放BASS.DLL
	stream = NULL;//释放stream
}

bool core::loadFile(const std::string filePath)
{
	char* temp_in = new char[1024];
	wchar_t* temp_out = new wchar_t[1024];
	memset(temp_in, 0, 1024);
	memset(temp_out, 0, 1024);
	char* temp_in_backup = temp_in;
	wchar_t* temp_out_backup = temp_out;
	strcpy(temp_in, filePath.c_str());
	size_t in_length = strlen(temp_in) + 1;
	size_t out_buffer_length = 1024;
	iconv_t temp_iconv = iconv_open("wchar_t", "UTF-8");
	int temp_code = iconv(temp_iconv, &temp_in_backup, &in_length, (char**)&temp_out_backup, &out_buffer_length);
	iconv_close(temp_iconv);
	stream = BASS_StreamCreateFile(FALSE, temp_out, 0, 0, 0);
	if (stream)
	{
		return true;
	}
	else
	{
		return false;
	}
	delete[]temp_in;
	delete[]temp_out;
}

bool core::loadFolder(const std::string folderPath)
{
	return false;
}


audioInformation core::getAudioInfo()//取id3v2
{
	return{};
}

bool core::play()
{
	if (BASS_ChannelPlay(stream, FALSE))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool core::pause()
{
	if (BASS_ChannelPause(stream))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool core::stop()
{
	if (BASS_ChannelStop(stream))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool core::isPlaying()
{
	if (BASS_ChannelIsActive(stream) == BASS_ACTIVE_PLAYING)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float core::getVolume()
{
	float volume;
	BASS_ChannelGetAttribute(stream, BASS_ATTRIB_VOL, &volume);
	return volume;
}

bool core::setVolume(float volume)
{
	if (BASS_ChannelSetAttribute(stream, BASS_ATTRIB_VOL, volume))
	{
		return true;
	}
	else
	{
		return false;
	}
}