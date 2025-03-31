#include <Windows.h>

#include "ui/user-interface.hpp"

UserInterface _ui;

int main() {
  SetConsoleOutputCP(CP_UTF8);
  _ui.run();
  return 0;
}
