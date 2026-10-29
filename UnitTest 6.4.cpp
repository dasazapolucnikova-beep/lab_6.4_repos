#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.4/Project 6.4.cpp" // Підключення файлу з реалізацією функцій

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
    TEST_CLASS(UnitTest64)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Тестування функції MinAbs
            const int n = 5;
            int a[n] = { -7, 4, -2, 9, 3 };

            // Очікуваний мінімальний за модулем елемент: |-2| = 2
            int expectedMin = 2;
            int actualMin = MinAbs(a, n);

            Assert::AreEqual(expectedMin, actualMin);
        }

        TEST_METHOD(TestSumAbsAfterZero)
        {
            // Тестування обчислення суми модулів після першого нуля
            const int n = 6;
            int a[n] = { 3, -5, 0, -2, 4, -1 };

            // Після 0 стоять елементи: -2, 4, -1
            // Сума модулів: |-2| + |4| + |-1| = 2 + 4 + 1 = 7
            int expectedSum = 7;
            int actualSum = SumAbsAfterZero(a, n);

            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}