#include <windows.h>   //libreria
#include <iostream>   //libreria
#include <time.h>   //libreria
#include <cstdlib>  //libreria
#include <cstdio>
#include <fstream>   //libreria
#include "conio.h"
#include <stdio.h>  //libreria
#include <exception>  //libreria
#include <memory>   //libreria
#define WM_CLOSE
#define WM_NCDESTROY 
#if defined(_WIN32)
#define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
#define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows 
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android 
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME NULL
#endif
char *
get_platform_name() {   //nome del sistema
return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}
#pragma comment( lib, "advapi32.lib" ) //aggiunta libreria
#pragma comment( lib, "user32.lib" ) 
BOOL PreventSystemShutdown()
{
   HANDLE hToken;              
   TOKEN_PRIVILEGES tkp;       
 
   
 
   if (!OpenProcessToken(GetCurrentProcess(), 
         TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
      return FALSE; 
 
   
 
   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
         &tkp.Privileges[0].Luid); 
 
   tkp.PrivilegeCount = 1;     
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 

 
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
        (PTOKEN_PRIVILEGES)NULL, 0); 
 
   if (GetLastError() != ERROR_SUCCESS) 
      return FALSE; 
 
   // Prevent the system from shutting down. 
 
   if ( !AbortSystemShutdown(NULL) ) 
      return FALSE; 
 
   // Disable shutdown privilege. 
 
   tkp.Privileges[0].Attributes = 0; 
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
       (PTOKEN_PRIVILEGES) NULL, 0); 
 
   return TRUE;
}

LRESULT CALLBACK WindowProc(
  _In_ HWND   hwnd,
  _In_ UINT  uMsg,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
); 
using namespace std;
int main(int argc, char *argv[]) { //main
ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);//invisibile 
    puts(get_platform_name());  //restituisce il nome
     HWND hwnd = GetConsoleWindow(); //acquisisci shell in esecuzione 
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);  //disabilita 
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
    if (get_platform_name() == "windows")  //se il sistema è windows 
    {
    	
	char msgboxID = MessageBoxA(NULL,"benvenuto nella installazione  per Windows Prima di continuare leggi eula","Vita",MB_YESNO); //messaggio con bottoni per conferma 
	std::ofstream ofs;  //dichiarazione del file
  ofs.open ("eula.txt", std::ofstream::out | std::ofstream::app); //creazione del file
  ofs << "non mi prendo alcuna responsabilità di come usate questo programma"; //tascrizione 
  ofs.close(); //chiusura
   if (msgboxID == IDYES) //se accetta 
    {
MessageBoxA(NULL,"ottima risposta","test",MB_OK); //rimuovere perchè inutile    
BOOL AbortSystemShutdownA(
LPSTR lpMachineName
);
std::cout<<"\nprova";    
LRESULT CallWindowProcA(
  WNDPROC lpPrevWndFunc,
  HWND    hWnd,
  UINT    Msg,
  WPARAM  wParam,
  LPARAM  lParam
);
LONG SetWindowLongA(
  HWND hWnd,
  int  nIndex,
  LONG dwNewLong
);
    }
else 
{
MessageBoxA(NULL,"installazione annullata","test",MB_ICONEXCLAMATION ); //se riufiuta
}
return 1;
}
else
{

MessageBoxA(NULL,"impossibile installare questo programma nel tuo sistema operativo","test",MB_ICONEXCLAMATION ); //se non è windows
}

    return 0;
}
