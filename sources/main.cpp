#include "gui/gui.hpp"

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
  WMENU_PARAM_UNUSED(hPrevInstance);
  WMENU_PARAM_UNUSED(lpCmdLine);
  return Gui::instance()->initialize(hInstance, nShowCmd);
}
