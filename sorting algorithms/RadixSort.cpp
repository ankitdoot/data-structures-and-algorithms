//sorting N  elements in range 1 to N^2 in O(N)
//Radix Sort Algorithm
#include <iostream>
using namespace std;

int get_max_ele(int arr[], int n)
{
    int max_ele = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_ele)
            max_ele = arr[i];
    }
    return max_ele;
}

void CountingSort(int arr[], int n, int ex)
{
    int output[n];
    int count_ite[10] = {0};
    for (int i = 0; i < n; i++)
    {
        ++count_ite[(arr[i] / ex) % 10];
    }
    for (int i = 1; i < 10; i++)
    {
        count_ite[i] += count_ite[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count_ite[(arr[i] / ex) % 10] - 1] = arr[i];
        --count_ite[(arr[i] / ex) % 10];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void RadixSort(int arr[], int n)
{
    int max_ele = get_max_ele(arr, n);
    for (int ex = 1; (max_ele / ex) > 0; ex *= 10)
    {
        CountingSort(arr, n, ex);
    }
}

int main()
{
    int n;
    cout << "enter no. of inputs : ";
    cin >> n;
    int arr[n];
    for (int i = n; i >= 1; i--)
    {
        arr[n - i] = i * i;
    }
    RadixSort(arr, n);

    cout << "\nSorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
//Radix sort is stable
//this is not an in-place sorting
/*
What is the running time of Radix Sort?
Let there be d digits in input integers.
Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers,
for example, for decimal system, b is 10. What is the value of d?
If k is the maximum possible value, then d would be O(logb(k)).
So overall time complexity is O((n+b) * logb(k)).
Which looks more than the time complexity of comparison based sorting algorithms
for a large k. Let us first limit k. Let k <= nc where c is a constant.
In that case, the complexity becomes O(nLogb(n)). But it still doesn't beat
comparison based sorting algorithms.
What if we make value of b larger?. What should be the value of b to make the time complexity linear?
If we set b as n, we get the time complexity as O(n). In other words, we can sort an array of integers
with range from 1 to nc if the numbers are represented in base n (or every digit takes log2(n) bits).*/
