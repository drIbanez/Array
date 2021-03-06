#include <iostream>
#include "array.h"
#include <stdexcept>

using namespace std;

void arrayBracketsTest();

int main()
{
    arrayBracketsTest();
    Array<int, 3> my_ar = {4,5,6};
    my_ar.Show();
    cout << endl;
    my_ar[1] = 7;
    my_ar.Show();
    cout << endl;
    cout << my_ar[0] << endl;
    return 0;
}

void arrayBracketsTest()
{
    try
    {
        Array<int, 2> test_ar = {1,2};

        int x = test_ar[0];

        if (x != 1)
        {
            cout << __LINE__ << endl;
            cout << "Test failed! Digital mismatch." << endl;
            return;
        }

        test_ar[0] = 3;
        int x2 = test_ar[0];

        if (x2 != 3)
        {
            cout << __LINE__ << endl;
            cout << "Test failed! Digital mismatch during reassigment." << endl;
            return;
        }
        try
        {
             test_ar[345345] = 34;
             cout << __LINE__;
             cout << "Test failed! Assigment out of array size range." << endl;
             return;
        }
        catch (invalid_argument &e)
        {
            cout << "Error occured: " << e.what() << endl;
            cout << "Expected exception, valid case." << endl;
        }
        catch(...)
        {
            cout << "Unspecified exception occured." << endl;
            return;
        }
        cout << "Test complete!" << endl;
    }
    catch(...)
    {
        cout << "Unspecified exception occured." << endl;
        return;
    }
    cout << "Test complete!" << endl;
}
