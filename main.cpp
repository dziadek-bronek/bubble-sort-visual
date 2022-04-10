#include <iostream>
#include <unistd.h>

int nScreenWidth = 50;
int nScreenHeight = 25;
int nArrSize = nScreenWidth * nScreenHeight;

int main() {
	char screen[nArrSize];

	size_t nScreenWidthDec = nScreenWidth - 1;
	size_t nScreenHeightDec = nScreenHeight - 1;
	for(size_t i = 0; i < nArrSize; ++i) screen[i] = ' ';
	screen[nArrSize - 1] = 0;

	char* lineStart = screen;
	for(size_t i = 0; i < nScreenHeightDec; ++i, lineStart += nScreenWidth) lineStart[nScreenWidthDec] = '\n';

// setup   
    int data[nScreenWidthDec];
    for(int i = 0; i < nScreenWidthDec; ++i)
        data[i] = rand() % nScreenHeight;

    // lambda for printing
    auto print = [&]()
    {
        for(int x = 0; x < nScreenWidthDec; ++x)
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
            for(j = 0; j < nScreenWidthDec - i - 1; j++)
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
