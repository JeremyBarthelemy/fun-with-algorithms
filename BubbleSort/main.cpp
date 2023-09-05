#include <iostream>

int main()
{
    const size_t kArrayLen{12};
    int myArray[kArrayLen]{99, 82, 1, 5, 2, 7, 8, 14, 46, 95, 77, -1};

    bool finished{false};
    while (!finished)
    {
        bool swapOccurred{false};
        for (int x = 0; x < kArrayLen - 1; ++x)
        {
            if (myArray[x] > myArray[x+1])
            {
                int temp = myArray[x+1];
                myArray[x+1] = myArray[x];
                myArray[x] = temp;

                swapOccurred = true;
            }
            else if (myArray[x] == myArray[x+1])
            {
                std::cout << "Error! Two values in array are the same! Exiting!" << std::endl;
                return -1;
            }
        }

        // We are finished sorting
        if (!swapOccurred)
        {
            finished = true;
        }
    }

    // Print out final array
    for (int x = 0; x < kArrayLen; ++x)
    {
        std::cout << myArray[x] << ", ";
    }

    return 0;
}
