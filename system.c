#include <stdlib.h>
#include "system.h"

// Clear the screen (platform-independent)
void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
