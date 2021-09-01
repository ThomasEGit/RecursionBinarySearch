// RecursionBinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int BinarySearch(int InputSearchArray[], int NumberToFind, int FirstPos, int LastPos)
{
    int FoundLocation;
    if (FirstPos > LastPos)
    {
        cout << "can't find";
        return -1;
        //Dude they straight up picked a number not even in the array
    }
    else
    {
        if (NumberToFind == InputSearchArray[FirstPos+(LastPos-FirstPos)/2])
        {
            FoundLocation = FirstPos + (LastPos-FirstPos)/2;
            return FoundLocation;
            //Found either at the very start or through recursion
        }
        else if (NumberToFind > InputSearchArray[FirstPos + (LastPos-FirstPos)/2])
        {
           FoundLocation = BinarySearch(InputSearchArray, NumberToFind, ((FirstPos + (LastPos-FirstPos)/2) + 1), LastPos );
           //Top half
        }
        else
        {
           FoundLocation = BinarySearch(InputSearchArray, NumberToFind, FirstPos, ((FirstPos + (LastPos-FirstPos)/2) - 1));
           //Bottom half
        }
    }
    return FoundLocation;
}

int main()
{
    int SearchArray[] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << BinarySearch(SearchArray, 5, 0, 9);
}
