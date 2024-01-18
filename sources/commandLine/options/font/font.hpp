#ifndef COMMANDLINE_OPTIONS_FONT_HPP
#define COMMANDLINE_OPTIONS_FONT_HPP

#include <mutex>
#include <atomic>
#include <windows.h>

struct Name
{
	char* value = NULL;
	bool exists = false;
};

struct Size
{
	int value = 0;
	bool exists = false;
};

class Font
{
public:
	~Font();

	static Font* instance();

	Name name;
	Size size;

private:
	static std::recursive_mutex m_mutex;
	static std::atomic<Font*> m_font;
};

#endif
