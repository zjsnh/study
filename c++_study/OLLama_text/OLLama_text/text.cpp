#include <windows.h>
#include <iostream>
#include <string>

int main() {
    std::wstring command = L"ollama run qwen"; // 确保路径正确
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa;

    // 设置安全属性，使得管道可以被子进程继承
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    HANDLE hReadPipe, hWritePipe;
    // 创建用于子进程标准输入的管道
    if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0)) {
        std::cerr << "CreatePipe failed (" << GetLastError() << ").\n";
        return 1;
    }

    HANDLE hReadOutputPipe, hWriteOutputPipe;
    // 创建用于读取子进程输出的管道
    if (!CreatePipe(&hReadOutputPipe, &hWriteOutputPipe, &sa, 0)) {
        std::cerr << "CreatePipe for output failed (" << GetLastError() << ").\n";
        return 1;
    }

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags |= STARTF_USESTDHANDLES; // 使用标准输入输出
    si.hStdOutput = hWriteOutputPipe;   // 设置输出管道
    si.hStdError = hWriteOutputPipe;     // 设置错误输出管道
    si.hStdInput = hReadPipe;            // 设置输入管道

    if (!CreateProcess(
        NULL,
        const_cast<WCHAR*>(command.c_str()),
        NULL,
        NULL,
        TRUE, // 允许子进程继承句柄
        0,
        NULL,
        NULL,
        &si,
        &pi)
        ) {
        std::cerr << "CreateProcess failed (" << GetLastError() << ").\n";
        return 1;
    }
    else
    {
        std::cout << "create id:" << pi.hProcess << std::endl;
    }

    // 关闭不再使用的管道端
    CloseHandle(hReadPipe);
    CloseHandle(hWriteOutputPipe);

    std::string input;
    // 进入循环，读取用户输入并发送给子进程
    while (true) {
        std::cout << "Enter command (or type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        // 将输入写入管道
        DWORD bytesWritten;
        WriteFile(hWritePipe, input.c_str(), input.size(), &bytesWritten, NULL);
        WriteFile(hWritePipe, "\n", 1, &bytesWritten, NULL); // 发送换行符

        // 读取子进程的输出
        char buffer[128];
        DWORD bytesRead;
        while (ReadFile(hReadOutputPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
            buffer[bytesRead] = '\0'; // 确保字符串结束
            std::cout << "Output: " << buffer;
        }
    }

    // 关闭写入端管道
    CloseHandle(hWritePipe);
    CloseHandle(hReadOutputPipe);

    // 等待子进程结束
    WaitForSingleObject(pi.hProcess, INFINITE);

    // 清理
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
