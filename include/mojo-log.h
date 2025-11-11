#ifndef MOJO_LOG_H
#define MOJO_LOG_H

#include <string.h>
#include <stdio.h>


// ========== User Configurable ===========
// Feel free to modify these settings to 
// suit your needs.
// ========================================

// ----------------------------------------
// MOJO_LOG_LINESTYLE Options:
// ----------------------------------------
//    MOJO_LOG_LINE_SINGLE - Single line log output.
//    MOJO_LOG_LINE_MULTI  - Multi line log output, trys to wrap long lines based on .
#define MOJO_LOG_LINESTYLE            MOJO_LOG_LINE_SINGLE
#define MOJO_LOG_MAX_LINE_LENGTH      1024


// ----------------------------------------
// MOJO_LOG_BRACKETSTYLE Options:
// ----------------------------------------
//    MOJO_LOG_BRACKET_NONE "BRACKET_STYLE"
//    MOJO_LOG_BRACKET_SQUARE "[BRACKET_STYLE]"
//    MOJO_LOG_BRACKET_CURLY "{BRACKET_STYLE}"
//    MOJO_LOG_BRACKET_PARENTHESIS "(BRACKET_STYLE)"
//    MOJO_LOG_BRACKET_ANGLE "<BRACKET_STYLE>"
#define MOJO_LOG_DEFAULT_BRACKETSTYLE MOJO_LOG_BRACKET_SQUARE

// ----------------------------------------
// Color Options:
// ----------------------------------------
// Uncomment the following line to enable colored log output.
// #define MOJO_LOG_ENABLE_COLOR
// ----------------------------------------

#define MOJO_LOG_INFO_COLOR        M_ANSICOLOR_CYAN
#define MOJO_LOG_WARNING_COLOR     M_ANSICOLOR_YELLOW
#define MOJO_LOG_ERROR_COLOR       M_ANSICOLOR_RED

#define MOJO_LOG_COLORED_BRACKETS  TRUE
#define MOJO_LOG_BRACKET_COLOR     M_ANSICOLOR_WHITE

// Custom log levels colors
#define MOJO_LOG_CUSTOM_0_COLOR      M_ANSICOLOR_MAGENTA
#define MOJO_LOG_CUSTOM_1_COLOR      M_ANSICOLOR_BLUE
#define MOJO_LOG_CUSTOM_2_COLOR      M_ANSICOLOR_WHITE
#define MOJO_LOG_CUSTOM_3_COLOR      M_ANSICOLOR_GREEN
#define MOJO_LOG_CUSTOM_4_COLOR      M_ANSICOLOR_CYAN
#define MOJO_LOG_CUSTOM_5_COLOR      M_ANSICOLOR_YELLOW
#define MOJO_LOG_CUSTOM_6_COLOR      M_ANSICOLOR_RED
#define MOJO_LOG_CUSTOM_7_COLOR      M_ANSICOLOR_MAGENTA
#define MOJO_LOG_CUSTOM_8_COLOR      M_ANSICOLOR_BLUE
#define MOJO_LOG_CUSTOM_9_COLOR      "\" // example custom color purple




// ========== End User Configurable =======

typedef enum {
    M_ANSICOLOR_RESET,
    M_ANSICOLOR_RED,
    M_ANSICOLOR_GREEN,
    M_ANSICOLOR_YELLOW,
    M_ANSICOLOR_BLUE,
    M_ANSICOLOR_MAGENTA,
    M_ANSICOLOR_CYAN,
    M_ANSICOLOR_WHITE
} M_AnsiColor;

static const char* M_ansi_color_codes[] = {
    "\033[0m",   // M_ANSICOLOR_RESET
    "\033[31m",  // M_ANSICOLOR_RED
    "\033[32m",  // M_ANSICOLOR_GREEN
    "\033[33m",  // M_ANSICOLOR_YELLOW
    "\033[34m",  // M_ANSICOLOR_BLUE
    "\033[35m",  // M_ANSICOLOR_MAGENTA
    "\033[36m",  // M_ANSICOLOR_CYAN
    "\033[37m"   // M_ANSICOLOR_WHITE
};

typedef enum {
    MOJO_LOG_LINE_SINGLE,
    MOJO_LOG_LINE_MULTI,
}MOJO_LogLineStyle;

typedef enum {
    MOJO_LOG_BRACKET_NONE,        // "BRACKET_STYLE"
    MOJO_LOG_BRACKET_SQUARE,      // [BRACKET_STYLE]
    MOJO_LOG_BRACKET_CURLY,       // {BRACKET_STYLE}
    MOJO_LOG_BRACKET_PARENTHESIS, // (BRACKET_STYLE)
    MOJO_LOG_BRACKET_ANGLE        // <BRACKET_STYLE>
} MOJO_LogBracketStyle;

typedef struct {
    MOJO_LogLineStyle lineStyle;
    MOJO_LogBracketStyle bracketStyle;
}MOJO_LogStyle;

 
#ifdef __cplusplus
extern "C" {
#endif

void MOJO_Log_SetLogStyle(Mojo_LogStyle style);

void LogInfo(const char* format, ...);
void LogWarning(const char* format, ...);
void LogError(const char* format, ...);

#ifdef __cplusplus
}
#endif
#endif /* MOJO_LOG_H */
