
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    // First, we need a set of non-repeating integers that are order in ascending fashion.
    std::vector<int> fullSet = {1, 2, 3, 4, 5, 6, 7, 23, 34, 45, 56, 67, 78, 89, 90, 93, 101, 122, 134,
                                144, 156, 178, 222, 353, 888, 999,  1000};

    std::cout << "The set contains " << fullSet.size() << " elements." << std::endl;

    // For now, let's try finding the number "5" in the full set
    int numberToFind = 5;

    bool finished(false);
    auto innerSet = fullSet;
    int iteration = 0;
    while (!finished)
    {

        std::cout << "VECTOR:  ";
        for (const auto& it : innerSet)
        {
            std::cout << it << ", ";
        }
        std::cout << std::endl;

        if (innerSet.empty())
        {
            std::cout << "Looks like we couldn't find your number in the set!" << std::endl;
            finished = true;
        }
        else
        {
            // 1. Divide the set size by 2, check the item located there's value and compare against what you are trying to find
            int location = innerSet.size() / 2;
            int valueRead(innerSet.at(location));

            std::cout << "LOCATION: " << location << " VALUE AT LOCATION: " << valueRead << " NUM REMAINING ELEMENTS IN SET: " << innerSet.size() << std::endl;

            std::vector<int> tempVector;

            if (valueRead == numberToFind) // If equal, we're done! Grab location of where it was
            {
                std::cout << "We found a match!" << std::endl;
                finished = true;
            }
            else if (valueRead < numberToFind) // If less than what we want, discard lefthand side, set the next iteration's set from the righthand side
            {
                std::cout << "Less than what we want, discarding left half of number set" << std::endl;

                std::copy(innerSet.begin() + location + 1, innerSet.end(), back_inserter(tempVector));
            }
            else // Else, discard righthand side, set the next iteration's set from the lefthand side
            {
                std::cout << "More than what we want, discarding right half of number set" << std::endl;


                std::copy(innerSet.begin(), innerSet.begin() + location, back_inserter(tempVector));
            }

            innerSet = tempVector;
            ++iteration;
        }
    }

    std::cout << "Returning after " << iteration << " iterations!" << std::endl;

    return 0;
}
