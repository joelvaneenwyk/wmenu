#ifndef GUI_TEXTBOX_HPP
#define GUI_TEXTBOX_HPP

#include <Windows.h>

LRESULT CALLBACK TextBoxWindowHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class TextBox
{
public:
	static HWND hwnd;
	static size_t hwnd_id;
	static WNDPROC window_proc;

	static void createTextBox(HWND hWndParent, int x, int y, int width, int height, char* fontName);
};

#endif

//WNDPROC textbox_window_proc;
//friend LRESULT CALLBACK TextBoxWindowHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
