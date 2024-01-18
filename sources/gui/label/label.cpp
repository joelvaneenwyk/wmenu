#include "label.hpp"
#include "../../util/util.hpp"
#include "../../commandLine/options/font/font.hpp"

void Label::createLabel(HWND hwnd, int x, int y, int width, int height, char* fontName, std::wstring text)
{
  LONG_PTR hinstance = GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
  HWND hwndPrompt = CreateWindow(
    L"static",                    // class name
    NULL,                         // window name
    WS_CHILD | WS_VISIBLE,
    x, y, width, height,
    hwnd, 
    NULL,                         // hmenu
    reinterpret_cast<HINSTANCE>(hinstance), 
    NULL);

  if (Font::instance()->name.exists)
  {
    Util::setFont(hwndPrompt, fontName,
      Font::instance()->size.exists ? (Font::instance()->size.value * 2) + (Font::instance()->size.value / 2) : 20,
      Font::instance()->size.exists ? Font::instance()->size.value : 8);
  }

  SetWindowText(hwndPrompt, text.c_str());
}
