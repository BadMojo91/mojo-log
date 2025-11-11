#define MOJO_LOG_USE_COLOR
#include "mojo-log.h"
int main(void) {
    // Basic log messages
    LogInfo("This is an info message: %d", 123);
    LogWarning("This is a warning message: %s", "be careful!");
    LogError("This is an error message: %f", 3.14);
    LogCustom("CUSTOM", "This is a custom log message with tag: %s", "TAG");

   
    return 0;
}


