#include "label.hpp"
#include "../../util/util.hpp"
#include "../../commandLine/options/font/font.hpp"

void Label::createLabel(HWND hwnd, int x, int y, int width, int height, char* fontName, std::wstring text)
{
#ifdef _x86
  HINSTANCE hinstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
#else
  HINSTANCE hinstance = (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE);
#endif
  HWND hwndPrompt = CreateWindow(L"static", NULL,
    WS_CHILD | WS_VISIBLE,
    x, y, width, height,
    hwnd, NULL,
    hinstance, NULL);

  if (Font::instance()->name.exists)
  {
    Util::setFont(hwndPrompt, fontName,
      Font::instance()->size.exists ? (Font::instance()->size.value * 2) + (Font::instance()->size.value / 2) : 20,
      Font::instance()->size.exists ? Font::instance()->size.value : 8);
  }

  SetWindowText(hwndPrompt, text.c_str());
}
