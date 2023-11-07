#include "common.h"
#include "window.h"



int main() 
{
    sf::VideoMode vm(1920, 1080);
    string name = "Name";
    Window mainWindow(vm, name);

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
