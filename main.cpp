#include <iostream>
#include <unistd.h>

char sAppName[] { "Bubble Sort Visualization" };
int nScreenWidth = 80;
int nScreenHeight = 30;
int nArrSize = nScreenWidth * nScreenHeight;

int main() {
	/*
    SMALL_RECT rectWindow = { 0, 0, static_cast<short>(nScreenWidth - 1), static_cast<short>(nScreenHeight - 1) };
	*/
	char* screen = new char[nArrSize + 1];

	for(size_t i = 0; i < nArrSize; ++i) screen[i] = ' ';
	/*
	for(int i = 0; i < nArrSize; i++)
    {
        screen[i].Char.AsciiChar = ' ';
        screen[i].Attributes = 0x0000;
    }
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	*/

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
                    screen[y * nScreenWidth + x] = 'X';
                else
                    screen[y * nScreenWidth + x] = ' ';
            }
        }

		char* lineStart = screen;;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		for(size_t i = 0; i < nScreenHeight; lineStart += nScreenWidth, ++i) {
			char* tmpIdx = lineStart + nScreenWidth;
			char tmp = *tmpIdx;
			*tmpIdx = 0;
			std::cout << lineStart << std::endl;
			*tmpIdx = tmp;
		}
	    // WriteConsoleOutput(hConsole, screen, { static_cast<short>(nScreenWidth), static_cast<short>(nScreenHeight) }, { 0,0 }, &rectWindow);
    };

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
			usleep(500000);
        }

    // display
        // write to title bar of console     
		/*
        char s[128];
		sprintf(s, " | %s | ", sAppName);
        SetConsoleTitleA(s);

        // display frame
	    WriteConsoleOutput(hConsole, screen, { static_cast<short>(nScreenWidth), static_cast<short>(nScreenHeight) }, { 0,0 }, &rectWindow);
		*/

    delete[] screen;
    
    return 0;
}
