#include <iostream>
#include <Windows.h>
#include <thread>

char sAppName[] { "Bubble Sort Visualization" };
int nScreenWidth = 120;
int nScreenHeight = 40;
int nArrSize = nScreenWidth * nScreenHeight;

int main() {
    SMALL_RECT rectWindow = { 0, 0, static_cast<short>(nScreenWidth - 1), static_cast<short>(nScreenHeight - 1) };
    CHAR_INFO* screen = new CHAR_INFO[nArrSize];
	for(int i = 0; i < nArrSize; i++)
    {
        screen[i].Char.AsciiChar = ' ';
        screen[i].Attributes = 0x0000;
    }
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);

// setup   
    int data[nScreenWidth];
    for(int i = 0; i < nScreenWidth; ++i)
        data[i] = rand() % nScreenHeight;

    // lambda for printing
    auto print = [&]()
    {
        for(int x = 0; x < nScreenWidth; ++x)
        {
            for(int y = nScreenHeight - 1; y >= 0; --y)
            {
                if(data[x] <= y)
                    screen[y * nScreenWidth + x].Attributes = 0x00F0;
                else
                    screen[y * nScreenWidth + x].Attributes = 0x0000;
            }
        }

        char s[128];
		sprintf_s(s, 128, " | %s | ", sAppName);
        SetConsoleTitleA(s);

        // display frame
	    WriteConsoleOutput(hConsole, screen, { static_cast<short>(nScreenWidth), static_cast<short>(nScreenHeight) }, { 0,0 }, &rectWindow);
    };

    while(true)
    {
    // input
        if(GetAsyncKeyState('R'))           // reset
            for(int i = 0; i < nScreenWidth; ++i)
                data[i] = rand() % nScreenHeight;


        if(!GetAsyncKeyState(VK_SPACE))     // dont start until space is pressed
        {
            print();
            continue;
        }                                      

    // logic
        //sort start
        int i, j;
        bool swapped;
        for(i = 0; i < nScreenWidth - 1; i++)
        {
            swapped = false;
            for(j = 0; j < nScreenWidth - i - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    std::swap(data[j], data[j + 1]);
                    swapped = true;
                    // print
                    print();
                }
            }

            if(swapped == false)
                break;
        }

    // display
        // write to title bar of console     
        char s[128];
		sprintf_s(s, 128, " | %s | ", sAppName);
        SetConsoleTitleA(s);

        // display frame
	    WriteConsoleOutput(hConsole, screen, { static_cast<short>(nScreenWidth), static_cast<short>(nScreenHeight) }, { 0,0 }, &rectWindow);
    }

    delete[] screen;
    
    return 0;
}
