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

    void remove(int a, int n = 1)
    {
        if (n <= 0)
        {
            return;
        }
        int index = find_index(a);
        if (index == -1)
        {
            return;
        }
        if (data[index].count <= n)
        {
            for (int i = index; i < size - 1; ++i)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
        else
        {
            data[index].count -= n;
        }
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            cout << data[i].val << " (" << data[i].count << ")\n";
        }
    }

    bool is_subset(const multiset& other) const
    {
        for (int i = 0; i < size; ++i)
        {
            int idx = other.find_index(data[i].val);
            if (idx == -1 || other.data[idx].count < data[i].count)
            {
                return false;
            }
        }
        return true;
    }

    multiset union_with(const multiset& other) const
    {
        multiset result;
        for (int i = 0; i < size; ++i)
        {
            result.add(data[i].val, data[i].count);
        }
        for (int i = 0; i < other.size; ++i)
        {
            int idx = result.find_index(other.data[i].val);
            if (idx == -1)
            {
                result.add(other.data[i].val, other.data[i].count);
            }
            else if (other.data[i].count > result.data[idx].count)
            {
                result.data[idx].count = other.data[i].count;
            }
        }
        return result;
    }

    multiset intersection_with(const multiset& other) const
    {
        multiset result;
        for (int i = 0; i < size; ++i)
        {
            int idx = other.find_index(data[i].val);
            if (idx != -1)
            {
                int min_count = data[i].count < other.data[idx].count
                                    ? data[i].count
                                    : other.data[idx].count;
                result.add(data[i].val, min_count);
            }
        }
        return result;
    }

    multiset difference_with(const multiset& other) const
    {
        multiset result;
        for (int i = 0; i < size; ++i)
        {
            int count = data[i].count;
            int idx = other.find_index(data[i].val);
            if (idx != -1)
            {
                count -= other.data[idx].count;
            }
            if (count > 0)
            {
                result.add(data[i].val, count);
            }
        }
        return result;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    multiset M1, M2;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        M1.add(x);
    }

    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        M2.add(x);
    }

    cout << "M1:\n";
    M1.print();

    cout << "\nM2:\n";
    M2.print();

    cout << "\nM1 ∪ M2:\n";
    multiset uni = M1.union_with(M2);
    uni.print();

    cout << "\nM1 ∩ M2:\n";
    multiset inter = M1.intersection_with(M2);
    inter.print();

    cout << "\nM1 \\ M2:\n";
    multiset diff = M1.difference_with(M2);
    diff.print();

    cout << "\nCzy M1 ⊆ M2? ";
    cout << (M1.is_subset(M2) ? "Tak" : "Nie") << endl;

    return 0;
}
