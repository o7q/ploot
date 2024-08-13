#include "console.hpp"

void pause()
{
    std::cout << "Press a key to continue..." << std::endl;
    _getch();
}