#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0;
    std::vector<int> vec;
    std::cout << "[IN]:\n";
    std::cin >> count;

    do
    {
        int num = 0;
        std::cin >> num;
        vec.push_back(num);
        --count;
    } while (count != 0);

    std::sort(vec.begin(), vec.end(), [](auto& lh, auto& rh) { return lh > rh; });

    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    std::cout << "[OUT]:\n";
    for (const auto& el : vec)
    {
        std::cout << el << std::endl;
    }
}
