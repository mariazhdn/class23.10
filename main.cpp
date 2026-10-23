#include <iostream>
using namespace std;

class Sorting
{
    int* _arr = nullptr;
    size_t _size = 0;
    public:

    Sorting(int* arr, size_t size)
    {
        if(size != 0 && arr != nullptr)
        {
            _size = size;
            _arr = new int[size];
            for(size_t i = 0; i < _size; ++i)
            {
                _arr[i] = arr[i];
            }
        }
    }

    int* get_arr()
    {
        return _arr;
    }

    void gnome_sort_asc()
    {
        int count = 0;
        if(_size > 1 && _arr != nullptr)
        {
            size_t i = 0;
            while(i < _size - 1)
            {
                if(_arr[i] > _arr[i + 1])
                {
                    swap(_arr[i], _arr[i + 1]);
                    if (i == 0) { ++i; }
                    else { --i; }

                    count++;
                }
                else { ++i; }
            }
        }
        cout << "Swap count: " << count << endl;
    }

    void stupid_sort_asc() 
    {
        if (_arr == nullptr || _size <= 1) return;

        int temp;
        int count = 0;

        for (int i = 0; i < (int)_size - 1; i++)
        {
            if (_arr[i] > _arr[i + 1])
            {
                temp = _arr[i];
                _arr[i] = _arr[i + 1];
                _arr[i + 1] = temp;
                i = -1;

                count++;
            }
        }
        cout << "Swap count: " << count << endl;
    }

    ~Sorting()
    {
        if(_arr != nullptr)
        {
            delete[] _arr;
        }
    }
};

void fill_array_randomly(int* arr, size_t size, int min_val = 0, int max_val = 100)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
}

int main ()
{
    srand(time(0));

    size_t n;
    cout << "Enter n: ";
    cin >> n;

    if (n > 0)
    {
        int* arr = new int[n];
        fill_array_randomly(arr, n);
        // for (size_t i = 0; i < n; i++)
        // {
        //     cout << "Enter arr[" << i << "]: ";
        //     cin >> arr[i];
        // }
        cout << endl;
        Sorting sort(arr, n);

        int* arr1 = new int[n];
        fill_array_randomly(arr1, n);
        // for (size_t i = 0; i < n; i++)
        // {
        //     cout << "Enter arr1[" << i << "]: ";
        //     cin >> arr1[i];
        // }
        cout << endl;
        Sorting sort1(arr1, n);


        cout << "Arr at first: ";
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
        cout << "Arr1 at first: ";
        for (size_t i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        cout << endl;



        cout << "\nGnome sort: " << endl;

        sort.gnome_sort_asc();
        int* sortArr = sort.get_arr();
        cout << "Sorted: : ";
        for (size_t i = 0; i < n; i++)
        {
            cout << sortArr[i] << " ";
        }
        cout << endl;



        cout << "\nStupid sort: " << endl;

        sort1.stupid_sort_asc();
        int* sort1Arr = sort1.get_arr();
        cout << "Sorted: : ";
        for (size_t i = 0; i < n; i++)
        {
            cout << sort1Arr[i] << " ";
        }
        cout << endl;
        


        delete[] arr;
        delete[] arr1;
    }

    return 0;
}