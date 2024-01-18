#ifndef GUI_HPP
#define GUI_HPP

#include <list>
#include <vector>
#include <mutex>
#include <atomic>

#if (__GNUC__ > 2) || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
#       define WMENU_PARAM_ATTR_UNUSED(param_name)         __attribute__((__unused__))       param_name
#else
#       define WMENU_PARAM_ATTR_UNUSED(param_name)         __pragma(warning(suppress:4100))  param_name
#endif

#define WMENU_PARAM_UNUSED(param_name) (void)(param_name)

#include "label/label.hpp"
#include "textBox/textBox.hpp"
#include "comboBox/comboBox.hpp"
#include "../commandLine/options/font/font.hpp"

enum class Position
{
	Top,
	Center,
	Bottom
};

class Gui
{
public:
	~Gui();

	static Gui* instance();

	int initialize(const HINSTANCE hInstance, int iCmdShow);

	friend LRESULT CALLBACK WindowHandler(HWND, UINT, WPARAM, LPARAM, Gui&);

	bool isRunningCheck() const;

	void setupGui(HWND hwnd);

	HWND hwnd = NULL;
	int width = -1;
	int height = -1;

	std::wstring name;
	std::string version;

	Label label;
	TextBox textBox;
	Position position = Position::Top;

private:
	static std::recursive_mutex m_mutex;
	static std::atomic<Gui*> m_gui;
};
LRESULT CALLBACK WindowHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, Gui& gui);

#endif
