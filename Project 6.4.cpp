#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Формування масиву за допомогою ГВЧ
void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// 2. Виведення масиву у вигляді рядка з форматним виведенням
void Print(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// 1.1. Обчислення мінімального за модулем елемента
int MinAbs(const int* a, const int n)
{
    int minVal = abs(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) < minVal)
            minVal = abs(a[i]);
    }
    return minVal;
}

// Пошук індексу першого нуля (-1, якщо нулів немає)
int FindFirstZero(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            return i;
    }
    return -1;
}

// 1.2. Обчислення суми модулів елементів після першого нуля
int SumAbsAfterZero(const int* a, const int n)
{
    int zeroIdx = FindFirstZero(a, n);
    if (zeroIdx == -1 || zeroIdx == n - 1)
        return 0; // Нуля немає або він останній

    int sum = 0;
    for (int i = zeroIdx + 1; i < n; i++)
        sum += abs(a[i]);

    return sum;
}

// 2. Перетворення масиву: парні індекси в першу половину, непарні — в другу
void Transform(int* a, const int n)
{
    int* temp = new int[n];
    int idx = 0;

    // Спочатку копіюємо елементи з парних позицій (0, 2, 4...)
    for (int i = 0; i < n; i += 2)
        temp[idx++] = a[i];

    // Потім копіюємо елементи з непарних позицій (1, 3, 5...)
    for (int i = 1; i < n; i += 2)
        temp[idx++] = a[i];

    // Повертаємо збережені елементи назад у масив
    for (int i = 0; i < n; i++)
        a[i] = temp[i];

    delete[] temp;
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    if (n <= 0)
    {
        cerr << "Error: Invalid array size!" << endl;
        return 1;
    }

    // Виділення пам'яті під динамічний масив
    int* a = new int[n];

    int Low = -10, High = 10;
    Create(a, n, Low, High);

    cout << "Initial array:" << endl;
    Print(a, n);

    cout << "Min abs element = " << MinAbs(a, n) << endl;

    int zeroIdx = FindFirstZero(a, n);
    if (zeroIdx != -1)
        cout << "Sum of abs elements after first zero = " << SumAbsAfterZero(a, n) << endl;
    else
        cout << "Zero element not found in the array." << endl;

    Transform(a, n);

    cout << "Modified array:" << endl;
    Print(a, n);

    // Звільнення динамічної пам'яті
    delete[] a;

    return 0;
}