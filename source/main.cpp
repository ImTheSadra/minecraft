#include <windows.h>

#include "app.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    App app = App();

    app.run();

    return 0;
}