
#include <windows.h> 
#include <stdio.h> 
											
const  char   FileName[ ]    = "Old_OICQ.exe"; 
const  long   PATCH_SIZE     = 3; 
void          *BaseAddr      = (void *)0x0042A9D2L; 

const char             NewBytes[] = { 0xE9, 0x22, 0x01 }; 
const char             OldBytes[] = { 0x53, 0x68, 0x80 };
char                   TmpBytes[3];
     
void main(void) 
{ 
    STARTUPINFO            StartInfo; 
    PROCESS_INFORMATION    ProcessInfo; 
    unsigned long          OldProtect; 
    unsigned long          BytesWritten; 
    unsigned long          BytesRead; 
    int                    k, len;
    char                   Path[512];

    printf("AD remover for OICQ 2000 buid 1115.\n");
    printf("Coded by Netguy.\n");
    printf("Please wait while OICQ is loading...\n");

    __try 
    { 
        GetModuleFileName(NULL, Path, 512);
        len = lstrlen(Path);
        Path[len - 8] = '\0';
        SetCurrentDirectory(Path);

        ZeroMemory(& StartInfo, sizeof(StartInfo)); 
        StartInfo.cb = sizeof(StartInfo); 
        if (CreateProcess(  FileName,
                            NULL, 
                            NULL,
                            NULL,
                            FALSE,
                            NULL,
                            NULL,
                            NULL,
                            &StartInfo,  
                            &ProcessInfo 
                        ) == 0) 
        { 
            __leave; 
        } 

        if (WaitForInputIdle(ProcessInfo.hProcess, INFINITE) != 0) 
        { 
            __leave; 
        } 



        if (VirtualProtectEx(ProcessInfo.hProcess, BaseAddr, PATCH_SIZE, 
                PAGE_READWRITE, &OldProtect) == 0) 
        { 
            __leave; 
        } 

        if (ReadProcessMemory(ProcessInfo.hProcess,  BaseAddr,  TmpBytes,  PATCH_SIZE, 
                &BytesRead) == 0) 
        {
            __leave;
        }

        k = 0;
        while(OldBytes[k] == TmpBytes[k]) k++;
        if (k < PATCH_SIZE)  __leave;

        WriteProcessMemory(ProcessInfo.hProcess,
			BaseAddr,
			NewBytes,
			PATCH_SIZE,   
			&BytesWritten);
    } 
    __finally 
    { 
        if (ProcessInfo.hProcess) 
        { 
            CloseHandle(ProcessInfo.hProcess); 
            CloseHandle(ProcessInfo.hThread); 
        } 
    } 
} 
