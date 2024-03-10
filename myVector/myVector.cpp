#include <iostream>

template<typename T>
class SmartVector {
public:
    SmartVector() 
    {
        vec = new T[0];
    }

    SmartVector(const SmartVector&) = delete; // запрет конструктора присваивания
    SmartVector& operator=(const SmartVector&) = delete; // запрет копирования через оператор =

    T& at(int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::runtime_error("Error! Index out of bounds");
        }
        return vec[index];
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::runtime_error("Error! Index out of bounds");
        }
        return vec[index];
    }

    void push_back(T value)
    {
        if (_size != 0)
        {
            if (_size < _capacity)
            {
                vec[_size] = value;
            }
            else
            {
                _capacity = 2 * _size;
                T* temp = new T[_capacity];
                for (int i = 0; i < _size; ++i)
                {
                    temp[i] = vec[i];
                }
                delete[] vec;

                vec = new T[_capacity];
                for (int i = 0; i < _size; ++i)
                {
                    vec[i] = temp[i];
                }
                delete[] temp;
                vec[_size] = value;
            }
        }
        else
        {
            delete[] vec;
            _capacity = 2 * (_size + 1);
            vec = new T[_capacity];
            vec[_size] = value;
        }
        ++_size;
    }

    int size()
    {
        return _size;
    }

    int capacity()
    {
        return _capacity;
    }

    ~SmartVector()
    {
        delete[] vec;
    }


private:
    T* vec;
    int _size = 0;
    int _capacity = 0;
};

int main()
{
    SmartVector<int> vec;
    std::cout << "ater initialization:\n";
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
        std::cout << "after push_back vec[" << i << "]: " << vec.at(i) << std::endl;
        std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    }
}
