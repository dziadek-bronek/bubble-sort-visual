#include <iostream>
#include <unistd.h>

int nScreenWidth = 50;
int nScreenHeight = 25;

size_t nScreenWidthInc = nScreenWidth + 1;
size_t nScreenHeightDec = nScreenHeight - 1;

int nArrSize = nScreenWidthInc * nScreenHeight;

int main() {
	char screen[nArrSize];

	for(size_t i = 0; i < nArrSize; ++i) screen[i] = ' ';

	char* lineStart = screen;
	for(size_t i = 0; i < nScreenHeightDec; ++i, lineStart += nScreenWidthInc) lineStart[nScreenWidth] = '\n';
	screen[nArrSize - 1] = 0;

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
                    screen[y * nScreenWidthInc + x] = 'X';
                else
                    screen[y * nScreenWidthInc + x] = ' ';
            }
        }

		char* lineStart = screen;;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << screen << std::endl;
		usleep(100000);
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
                    print();
                }
            }

            if(swapped == false)
                break;
        }

    return 0;
}
