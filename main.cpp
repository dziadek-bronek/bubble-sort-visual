#include <iostream>
#include <ctime>
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
	lineStart[-1] = 0;

// setup   
    int data[nScreenWidth];
	std::srand(std::time(nullptr));
    for(int i = 0; i < nScreenWidth; ++i)
        data[i] = rand() % nScreenHeight;

    // lambda for printing
    auto print = [&]()
    {
        for(int x = 0; x < nScreenWidth; ++x)
        {
            for(int y = 0;  y < nScreenHeight; ++y) {
				screen[y * nScreenWidthInc + x] = (y <= data[x]) ? 'X' : ' ';
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
