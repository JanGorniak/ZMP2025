#include <iostream>

using namespace std;

struct Pair
{
    int val;
    int count;
};

class multiset
{
private:
    Pair* data;
    int size;
    int cap;

    int find_index(int val) const
    {
        for (int i = 0; i < size; ++i)
        {
            if (data[i].val == val)
            {
                return i;
            }
        }
        return -1;
    }

    void expand()
    {
        cap *= 2;
        Pair* new_data = new Pair[cap];
        for (int i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    bool subset_sum_rec(int index, int sum, int* used) const
    {
        if (index == size)
        {
            if (sum == 0)
            {
                int total_used = 0;
                for (int i = 0; i < size; ++i)
                {
                    total_used += used[i];
                }
                return total_used > 0;
            }
            return false;
        }

        for (int i = 0; i <= data[index].count; ++i)
        {
            used[index] = i;
            if (subset_sum_rec(index + 1, sum + i * data[index].val, used))
            {
                return true;
            }
        }

        return false;
    }

    void print_subset(int* used) const
    {
        cout << "{ ";
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < used[i]; ++j)
            {
                cout << data[i].val << " ";
            }
        }
        cout << "}\n";
    }

public:
    multiset(int init_cap = 10)
    {
        cap = init_cap;
        data = new Pair[cap];
        size = 0;
    }

    ~multiset()
    {
        delete[] data;
    }

    void add(int a, int n = 1)
    {
        if (n <= 0)
        {
            return;
        }

        int index = find_index(a);
        if (index != -1)
        {
            data[index].count += n;
        }
        else
        {
            if (size == cap)
            {
                expand();
            }
            data[size++] = {a, n};
        }
    }

    bool has_zero_sum_subset() const
    {
        int* used = new int[size];
        for (int i = 0; i < size; ++i)
        {
            used[i] = 0;
        }

        bool found = subset_sum_rec(0, 0, used);

        if (found)
        {
            cout << "Znaleziono pod-multizbior o sumie 0.\n";
            print_subset(used);
        }
        else
        {
            cout << "Nie znaleziono pod-multizbioru o sumie 0.\n";
        }

        delete[] used;
        return found;
    }
};

int main()
{
    int n;
    cin >> n;

    multiset M;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        M.add(x);
    }

    M.has_zero_sum_subset();

    return 0;
}
