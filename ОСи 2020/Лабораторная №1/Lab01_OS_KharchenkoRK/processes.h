
#include <Windows.h>
#include <iostream>


void createProcessHeader(LPSTR commandLineForCreator, STARTUPINFO* sti, PROCESS_INFORMATION* processInfo) {
    if (CreateProcess(NULL, commandLineForCreator, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, sti, processInfo))
    {
        WaitForSingleObject(processInfo->hProcess, INFINITE);
        CloseHandle(processInfo->hProcess);
        CloseHandle(processInfo->hThread);
    }
    else {
        std::cout << GetLastError();
    }
}

void freeMemory(STARTUPINFO* sti) {
    ZeroMemory(sti, sizeof(STARTUPINFO));
    sti->cb = sizeof(STARTUPINFO);
}