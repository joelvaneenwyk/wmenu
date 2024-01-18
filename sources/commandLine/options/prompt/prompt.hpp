#ifndef COMMAND_LINE_OPTIONS_PROMPT_HPP
#define COMMAND_LINE_OPTIONS_PROMPT_HPP

#include <mutex>
#include <atomic>
#include <string>

class Prompt
{
public:
	~Prompt();

	static Prompt* instance();

	bool exists = false;
	std::wstring value;
	int length = 0;

private:
	static std::recursive_mutex m_mutex;
	static std::atomic<Prompt*> m_prompt;
};

#endif
