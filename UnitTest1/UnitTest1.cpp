#include "pch.h"
#include "CppUnitTest.h"
#include "../73-1/73-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountPositiveAfterZero)
        {
            int rowCount = 4;
            int colCount = 4;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            int testData1[4][4] = {
                {0, 1, -1, 2},
                {3, 0, -2, 4},
                {5, 6, 7, 0},
                {0, 8, 9, 10}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = testData1[i][j];

            int count = 0;
            bool hasZero = CountPositiveAfterZero(a, rowCount, colCount, count);
            if (hasZero && count == 6) {
            }
            else {
            }

            int testData2[4][4] = {
                {1, -1, 1, 2},
                {3, 2, -2, 4},
                {5, 6, 7, 0},
                {0, -8, -9, -10}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = testData2[i][j];

            count = 0;
            hasZero = CountPositiveAfterZero(a, rowCount, colCount, count);
            if (hasZero && count == 0) {
            }
            else {
            }

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestFindSaddlePoints)
        {
            int rowCount = 4;
            int colCount = 4;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            int testData[4][4] = {
                {1, 2, 3, 4},
                {4, 3, 2, 1},
                {2, 3, 4, 1},
                {1, 4, 3, 2}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = testData[i][j];

            FindSaddlePoints(a, rowCount, colCount);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
