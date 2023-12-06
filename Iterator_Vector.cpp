#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Vector
{
private:
    T* vector;
    int size;
public:
    Vector(int n)
    {
        vector = new T[n];
        size = n;
        for (int i = 0; i < size; ++i)
        {
            vector[i] = std::rand() % 100;
        }
    }

    ~Vector()
    {
        delete[] vector;
    }

    class Iterator
    {
    private:
        T* data;
    public:
        Iterator(T* data_)
            :data(data_)
        {}

        Iterator& operator ++()
        {
            ++data;
            return *this;
        }

        Iterator operator++(int)
        {
            data++;
            return Iterator(data-1);
        }

        Iterator operator+(const T& b)
        {
            return Iterator(data + b);
        }

        Iterator& operator+=(const T& b)
        {
            data += b;
            return *this;
        }

        Iterator& operator --()
        {
            --data;
            return *this;
        }

        Iterator operator--(int)
        {
            data--;
            return Iterator(data + 1);
        }
        
        Iterator operator -(const T& b)
        {
            return Iterator(data - b);
        }

        bool operator ==(const Iterator& it2)
        {
            return data == it2.data;
        }

        bool operator !=(const Iterator& it2)
        {
            return data != it2.data;
        }

        bool operator >=(const Iterator& it2)
        {
            return data >= it2.data;
        }

        bool operator >(const Iterator& it2)
        {
            return data > it2.data;
        }

        bool operator <(const Iterator& it2)
        {
            return data < it2.data;
        }

        T& operator *()
        {
            return *data;
        }
    };

    Iterator begin()
    {
        return Iterator(vector);
    }

    Iterator end()
    {
        return Iterator(vector + size);
    }
};

int main()
{
    std::vector<int> numbers{ 6,9,2,4,1 };
    std::sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    Vector<int> data(10);
    for (Vector<int>::Iterator i = data.begin(); i != data.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::sort(data.begin(), data.end());
}