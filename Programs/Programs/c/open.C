#include<windows.h>
int main()
{
    ShellExecute(NULL,"open","C:\\Windows\\System32\\cmd.exe",NULL,NULL,SW_SHOWNORMAL);
    return 0;
}
