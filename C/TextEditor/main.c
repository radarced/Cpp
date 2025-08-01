#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    char Text[1028];

    // Save the original mode
    GetConsoleMode(hStdin, &mode);

    // Disable line input and echo
    DWORD newMode = mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleMode(hStdin, newMode);

    INPUT_RECORD record;
    DWORD events;

    printf("Press 'q' to quit...\n");

    int Count= 0 ;

    while (1) {
        ReadConsoleInput(hStdin, &record, 1, &events);

        if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
            char c = record.Event.KeyEvent.uChar.AsciiChar;
            if (c) {
                printf("You pressed: %c\n", c);
                Text[Count] = c;
                Count++;
                printf(Text);
                if (c == 'q') break;
            }
        }
    }

    // Restore original mode
    SetConsoleMode(hStdin, mode);
    return 0;
}
