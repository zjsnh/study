#include <windows.h>
#include <iostream>
#include <string>

int main() {
    std::wstring command = L"ollama run qwen"; // ȷ��·����ȷ
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa;

    // ���ð�ȫ���ԣ�ʹ�ùܵ����Ա��ӽ��̼̳�
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

    HANDLE hReadPipe, hWritePipe;
    // ���������ӽ��̱�׼����Ĺܵ�
    if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0)) {
        std::cerr << "CreatePipe failed (" << GetLastError() << ").\n";
        return 1;
    }

    HANDLE hReadOutputPipe, hWriteOutputPipe;
    // �������ڶ�ȡ�ӽ�������Ĺܵ�
    if (!CreatePipe(&hReadOutputPipe, &hWriteOutputPipe, &sa, 0)) {
        std::cerr << "CreatePipe for output failed (" << GetLastError() << ").\n";
        return 1;
    }

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags |= STARTF_USESTDHANDLES; // ʹ�ñ�׼�������
    si.hStdOutput = hWriteOutputPipe;   // ��������ܵ�
    si.hStdError = hWriteOutputPipe;     // ���ô�������ܵ�
    si.hStdInput = hReadPipe;            // ��������ܵ�

    if (!CreateProcess(
        NULL,
        const_cast<WCHAR*>(command.c_str()),
        NULL,
        NULL,
        TRUE, // �����ӽ��̼̳о��
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

    // �رղ���ʹ�õĹܵ���
    CloseHandle(hReadPipe);
    CloseHandle(hWriteOutputPipe);

    std::string input;
    // ����ѭ������ȡ�û����벢���͸��ӽ���
    while (true) {
        std::cout << "Enter command (or type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        // ������д��ܵ�
        DWORD bytesWritten;
        WriteFile(hWritePipe, input.c_str(), input.size(), &bytesWritten, NULL);
        WriteFile(hWritePipe, "\n", 1, &bytesWritten, NULL); // ���ͻ��з�

        // ��ȡ�ӽ��̵����
        char buffer[128];
        DWORD bytesRead;
        while (ReadFile(hReadOutputPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
            buffer[bytesRead] = '\0'; // ȷ���ַ�������
            std::cout << "Output: " << buffer;
        }
    }

    // �ر�д��˹ܵ�
    CloseHandle(hWritePipe);
    CloseHandle(hReadOutputPipe);

    // �ȴ��ӽ��̽���
    WaitForSingleObject(pi.hProcess, INFINITE);

    // ����
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
