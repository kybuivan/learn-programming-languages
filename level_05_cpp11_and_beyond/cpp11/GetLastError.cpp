#define WIN32_LEAN_AND_MEAN
#include <system_error>
#include <windows.h>

#include <iostream>

[[noreturn]] void PrintError(const char *name)
{
    DWORD err = GetLastError();

    std::string message = std::system_category().message(err);

    std::cerr << "ERROR:" << name << ": " << err << ": " << message << std::endl;

    ExitProcess(err);
}

int main()
{
    // intentionally generate an error

    if (!GetProcessId(nullptr))
        PrintError("GetProcessId");
}
