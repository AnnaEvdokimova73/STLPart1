#include <iostream>
#include <array>
#include <map>

class Functor {
public:
    Functor() : _count{ 0 }, _sum{ 0 } {}

    void operator()(const int& elem)
    {
        _sum += elem;
        if (elem % 3 == 0)
            ++_count;
    }

    int get_sum() const { return _sum; }

private:
    int _count;
    int _sum;
};


int main()
{
    std::string str{ "Hello World!!" };
    std::map<char, int> strMap;
    std::multimap<int, char, std::greater<int>> mapRes;

    for (const char& el : str)
    {
        if (strMap[el] == 0)
        {
            int count = 1;
            strMap[el] = count;
            // strMap.insert(std::make_pair(el, i));
        }
        else
        {
            strMap[el] += 1;
        }
    }

    // for (const auto& [sym, count] : mapRes)
    for (const auto& el : strMap)
    {
        //mapRes[el.second] = el.first;
        mapRes.insert(std::make_pair(el.second, el.first));
    }

    std::cout << "[IN]: " << str << std::endl;
    std::cout << "[OUT]:" << std::endl;
    for (const auto& el : mapRes)
    {
        std::cout << el.second << ": " << el.first << std::endl;
    }
}
