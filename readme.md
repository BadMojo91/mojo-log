# mojo-log

**mojo-log** is a header-only logging utility for C and C++ projects. It provides colorful, flexible, and highly configurable log output with zero dependencies.

---

## ✨ Features

- **Header-only:** Just include one file, no linking required.
- **Log Levels:** Info, Warning, Error, and Custom tags.
- **Colorful Output:** ANSI color support, easily customizable.
- **Timestamps:** Optional, colored, and configurable.
- **File/Line Info:** Optional, for easy debugging.
- **Configurable Layout:** Control the order and presence of log elements.
- **C and C++ Compatible:** Works out-of-the-box in both languages.
- **Compile-time Log Level Filtering:** Remove unwanted logs at compile time.
- **Simple Macros:** Easy-to-use `LogInfo`, `LogWarning`, `LogError`, `LogCustom`.

---

## 🚀 Quick Start

1. **Add the header to your project:**
   ```
   #include "mojo-log.h"
   ```

2. **(Optional) Enable color and configure layout:**
   ```c
   #define MOJO_LOG_USE_COLOR
   #define MOJO_LOG_LAYOUT_ORDER (MOJO_LOG_LAYOUT_TIMESTAMP | MOJO_LOG_LAYOUT_TAG | MOJO_LOG_LAYOUT_FILELINE | MOJO_LOG_LAYOUT_MESSAGE)
   #include "mojo-log.h"
   ```

3. **Use the logging macros:**
   ```c
   LogInfo("Hello, %s!", "world");
   LogWarning("This is a warning: %d", 42);
   LogError("Something went wrong: %s", "error details");
   LogCustom("NETWORK", "Custom log with tag: %d", 123);
   ```

---

## 🛠️ Configuration

### Enable Color Output

Define `MOJO_LOG_USE_COLOR` before including the header:
```c
#define MOJO_LOG_USE_COLOR
#include "mojo-log.h"
```

### Set Minimum Log Level

Only logs at or above this level will be compiled in:
```c
#define MOJO_LOG_LEVEL MOJO_LOG_LEVEL_WARNING
#include "mojo-log.h"
```
Available levels: `MOJO_LOG_LEVEL_INFO`, `MOJO_LOG_LEVEL_WARNING`, `MOJO_LOG_LEVEL_ERROR`, `MOJO_LOG_LEVEL_CUSTOM`

### Configure Log Layout

Control which elements appear and in what order:
```c
#define MOJO_LOG_LAYOUT_ORDER (MOJO_LOG_LAYOUT_TIMESTAMP | MOJO_LOG_LAYOUT_TAG | MOJO_LOG_LAYOUT_FILELINE | MOJO_LOG_LAYOUT_MESSAGE)
#include "mojo-log.h"
```
- `MOJO_LOG_LAYOUT_TIMESTAMP`
- `MOJO_LOG_LAYOUT_TAG`
- `MOJO_LOG_LAYOUT_FILELINE`
- `MOJO_LOG_LAYOUT_MESSAGE`

Combine with `|` to set your preferred order.

### Customize Colors

Edit the ANSI color defines at the top of `mojo-log.h` to match your style or theme.

---

## 📝 Example Code

```c
#define MOJO_LOG_USE_COLOR
#include "mojo-log.h"

int main() {
    LogInfo("Info message: %d", 1);
    LogWarning("Warning: %s", "be careful!");
    LogError("Error: %f", 3.14);
    LogCustom("CUSTOM", "Custom log: %c", 'X');
    return 0;
}
```

**Sample Output:**
```
[12:34:56] [INFO] [main.c:5] Info message: 1
[12:34:56] [WARN] [main.c:6] Warning: be careful!
[12:34:56] [ERROR] [main.c:7] Error: 3.140000
[12:34:56] [CUSTOM] [main.c:8] Custom log: X
```
*(Colors shown in supported terminals)*

---

## 💡 Tips

- Use `-DMOJO_LOG_USE_COLOR` and other defines in your build system for global configuration.
- You can easily disable all logs below a certain level for production builds.
- The header is safe to include in multiple translation units.

---

## 📄 License

MIT License

---

## 🙏 Credits

Created by BadMojo.  
