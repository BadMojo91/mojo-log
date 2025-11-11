#ifndef MOJO_LOG_H
#define MOJO_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * mojo-log.h - Header-only logging utility for C/C++
 *
 * Features:
 *   - Info, warning, error, and custom log levels
 *   - Optional colored output (ANSI escape codes)
 *   - Timestamp support (with optional color)
 *   - File and line number in log output
 *   - Compile-time log level control
 *   - Macro wrappers with configurable output (timestamp, file/line, order)
 *
 * Usage:
 *   #define MOJO_LOG_USE_COLOR    // Enable colored output (optional)
 *   #define MOJO_LOG_LEVEL MOJO_LOG_LEVEL_INFO // Set minimum log level (optional)
 *   #define MOJO_LOG_LAYOUT_ORDER (MOJO_LOG_LAYOUT_TIMESTAMP | MOJO_LOG_LAYOUT_TAG | MOJO_LOG_LAYOUT_FILELINE | MOJO_LOG_LAYOUT_MESSAGE)
 *   #include "mojo-log.h"
 *
 *   LogInfo("Hello %s!", "world");
 *   LogWarning("This is a warning: %d", 42);
 *   LogError("Something went wrong: %s", err_msg);
 *   LogCustom("CUSTOM", "Custom log message");
 */

// ===== ANSI Color Codes (for easy customization) =====
#define MOJO_ANSI_RESET        "\x1b[0m"
#define MOJO_ANSI_BOLD         "\x1b[1m"
#define MOJO_ANSI_DIM          "\x1b[2m"
#define MOJO_ANSI_UNDERLINE    "\x1b[4m"
#define MOJO_ANSI_BLINK        "\x1b[5m"
#define MOJO_ANSI_REVERSE      "\x1b[7m"
#define MOJO_ANSI_HIDDEN       "\x1b[8m"

#define MOJO_ANSI_BLACK        "\x1b[30m"
#define MOJO_ANSI_RED          "\x1b[31m"
#define MOJO_ANSI_GREEN        "\x1b[32m"
#define MOJO_ANSI_YELLOW       "\x1b[33m"
#define MOJO_ANSI_BLUE         "\x1b[34m"
#define MOJO_ANSI_MAGENTA      "\x1b[35m"
#define MOJO_ANSI_CYAN         "\x1b[36m"
#define MOJO_ANSI_WHITE        "\x1b[37m"
#define MOJO_ANSI_BRIGHT_BLACK   "\x1b[90m"
#define MOJO_ANSI_BRIGHT_RED     "\x1b[91m"
#define MOJO_ANSI_BRIGHT_GREEN   "\x1b[92m"
#define MOJO_ANSI_BRIGHT_YELLOW  "\x1b[93m"
#define MOJO_ANSI_BRIGHT_BLUE    "\x1b[94m"
#define MOJO_ANSI_BRIGHT_MAGENTA "\x1b[95m"
#define MOJO_ANSI_BRIGHT_CYAN    "\x1b[96m"
#define MOJO_ANSI_BRIGHT_WHITE   "\x1b[97m"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

// ===== Color Codes =====
#ifdef MOJO_LOG_USE_COLOR
#define MOJO_LOG_COLOR_RESET      MOJO_ANSI_RESET
#define MOJO_LOG_COLOR_INFO       MOJO_ANSI_GREEN
#define MOJO_LOG_COLOR_WARN       MOJO_ANSI_YELLOW
#define MOJO_LOG_COLOR_ERROR      MOJO_ANSI_RED
#define MOJO_LOG_COLOR_CUSTOM     MOJO_ANSI_CYAN
#define MOJO_LOG_COLOR_TIMESTAMP  MOJO_ANSI_BRIGHT_BLACK
#else
#define MOJO_LOG_COLOR_RESET      ""
#define MOJO_LOG_COLOR_INFO       ""
#define MOJO_LOG_COLOR_WARN       ""
#define MOJO_LOG_COLOR_ERROR      ""
#define MOJO_LOG_COLOR_CUSTOM     ""
#define MOJO_LOG_COLOR_TIMESTAMP  ""
#endif

// ===== Log Level Enum =====
typedef enum {
    MOJO_LOG_LEVEL_INFO = 0,
    MOJO_LOG_LEVEL_WARNING = 1,
    MOJO_LOG_LEVEL_ERROR = 2,
    MOJO_LOG_LEVEL_CUSTOM = 3
} MOJO_LogLevel;

// ===== Compile-time Log Level Control =====
#ifndef MOJO_LOG_LEVEL
#define MOJO_LOG_LEVEL MOJO_LOG_LEVEL_INFO
#endif

// ===== Layout Order Bitmask =====
#define MOJO_LOG_LAYOUT_TIMESTAMP  (1 << 0)
#define MOJO_LOG_LAYOUT_FILELINE   (1 << 1)
#define MOJO_LOG_LAYOUT_TAG        (1 << 2)
#define MOJO_LOG_LAYOUT_MESSAGE    (1 << 3)

// Default: timestamp, tag, file/line, message (in that order)
#ifndef MOJO_LOG_LAYOUT_ORDER
#define MOJO_LOG_LAYOUT_ORDER (MOJO_LOG_LAYOUT_TIMESTAMP | MOJO_LOG_LAYOUT_TAG | MOJO_LOG_LAYOUT_FILELINE | MOJO_LOG_LAYOUT_MESSAGE)
#endif

// ===== Timestamp Printing =====
static inline void MOJO_LOG_print_timestamp(void) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    if (t)
        printf(MOJO_LOG_COLOR_TIMESTAMP "[%02d:%02d:%02d] " MOJO_LOG_COLOR_RESET,
               t->tm_hour, t->tm_min, t->tm_sec);
}

// ===== File/Line Printing =====
static inline void MOJO_LOG_print_fileline(const char* file, int line) {
    if (file)
        printf("[%s:%d] ", file, line);
}

// ===== Core Logging Functions =====
static inline void MOJO_LOG_INFO(const char* format, ...) {
#if MOJO_LOG_LEVEL <= MOJO_LOG_LEVEL_INFO
    va_list args;
    va_start(args, format);
    printf(MOJO_LOG_COLOR_INFO);
    vprintf(format, args);
    printf(MOJO_LOG_COLOR_RESET "\n");
    va_end(args);
#endif
}

static inline void MOJO_LOG_WARNING(const char* format, ...) {
#if MOJO_LOG_LEVEL <= MOJO_LOG_LEVEL_WARNING
    va_list args;
    va_start(args, format);
    printf(MOJO_LOG_COLOR_WARN);
    vprintf(format, args);
    printf(MOJO_LOG_COLOR_RESET "\n");
    va_end(args);
#endif
}

static inline void MOJO_LOG_ERROR(const char* format, ...) {
#if MOJO_LOG_LEVEL <= MOJO_LOG_LEVEL_ERROR
    va_list args;
    va_start(args, format);
    printf(MOJO_LOG_COLOR_ERROR);
    vprintf(format, args);
    printf(MOJO_LOG_COLOR_RESET "\n");
    va_end(args);
#endif
}

static inline void MOJO_LOG_CUSTOM(const char* tag, const char* format, ...) {
#if MOJO_LOG_LEVEL <= MOJO_LOG_LEVEL_CUSTOM
    (void)tag;
    va_list args;
    va_start(args, format);
    printf(MOJO_LOG_COLOR_CUSTOM);
    vprintf(format, args);
    printf(MOJO_LOG_COLOR_RESET "\n");
    va_end(args);
#endif
}

// ===== Macro Wrappers for Timestamp, File, and Line =====
#define MOJO_LOG_INFO_F(fmt, ...)    do { MOJO_LOG_print_timestamp(); MOJO_LOG_INFO("[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); } while(0)
#define MOJO_LOG_WARNING_F(fmt, ...) do { MOJO_LOG_print_timestamp(); MOJO_LOG_WARNING("[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); } while(0)
#define MOJO_LOG_ERROR_F(fmt, ...)   do { MOJO_LOG_print_timestamp(); MOJO_LOG_ERROR("[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); } while(0)
#define MOJO_LOG_CUSTOM_F(tag, fmt, ...) do { MOJO_LOG_print_timestamp(); MOJO_LOG_CUSTOM(tag, "[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__); } while(0)

// ======= Macro Dispatcher Helpers =======
// (Deprecated: use MOJO_LOG_LAYOUT_ORDER instead)
// #ifndef MOJO_LOG_SHOW_TIMESTAMP
// #define MOJO_LOG_SHOW_TIMESTAMP 0
// #endif
// #ifndef MOJO_LOG_SHOW_FILELINE
// #define MOJO_LOG_SHOW_FILELINE 0
// #endif

// Internal macro to build log prefix according to layout order
#define MOJO_LOG_BUILD_PREFIX(tag, color, file, line) \
    do { \
        if (MOJO_LOG_LAYOUT_ORDER & MOJO_LOG_LAYOUT_TIMESTAMP) MOJO_LOG_print_timestamp(); \
        if ((MOJO_LOG_LAYOUT_ORDER & MOJO_LOG_LAYOUT_TAG) && tag) printf("%s[%s]%s ", color, tag, MOJO_LOG_COLOR_RESET); \
        if (MOJO_LOG_LAYOUT_ORDER & MOJO_LOG_LAYOUT_FILELINE) MOJO_LOG_print_fileline(file, line); \
    } while(0)

// ======= User-facing Macros =======
#define LogInfo(fmt, ...)    do { \
    MOJO_LOG_BUILD_PREFIX("INFO", MOJO_LOG_COLOR_INFO, __FILE__, __LINE__); \
    MOJO_LOG_INFO(fmt, ##__VA_ARGS__); \
} while(0)

#define LogWarning(fmt, ...) do { \
    MOJO_LOG_BUILD_PREFIX("WARN", MOJO_LOG_COLOR_WARN, __FILE__, __LINE__); \
    MOJO_LOG_WARNING(fmt, ##__VA_ARGS__); \
} while(0)

#define LogError(fmt, ...)   do { \
    MOJO_LOG_BUILD_PREFIX("ERROR", MOJO_LOG_COLOR_ERROR, __FILE__, __LINE__); \
    MOJO_LOG_ERROR(fmt, ##__VA_ARGS__); \
} while(0)

#define LogCustom(tag, fmt, ...) do { \
    MOJO_LOG_BUILD_PREFIX(tag, MOJO_LOG_COLOR_CUSTOM, __FILE__, __LINE__); \
    MOJO_LOG_CUSTOM(tag, fmt, ##__VA_ARGS__); \
} while(0)

#ifdef __cplusplus
}
#endif

#endif // MOJO_LOG_H
