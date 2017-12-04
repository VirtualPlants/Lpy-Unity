#ifndef DEBUG_H_
#define DEBUG_H_

#include <string>

#ifndef _WIN32
#define __stdcall
#endif

typedef void(__stdcall *WriteCallback)(char *);

void Debug(const std::string &str);
void Warning(const std::string &str);
void Error(const std::string &str);

#endif
