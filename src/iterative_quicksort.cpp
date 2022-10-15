#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>

class RandomNumberGenerator
{
private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;

public:
    RandomNumberGenerator(int const min, int const max) noexcept : gen{std::random_device{}()}, dist(min, max) {}
    int operator()() noexcept { return dist(gen); }
};

constexpr static auto print_vector{[](auto const &v) noexcept
{
    using A = typename std::remove_reference<decltype(v)>::type;
    using B = typename std::remove_const<A>::type;
    using C = typename B::value_type;
    std::cout << '[';
    std::copy(std::cbegin(v), std::cend(v), std::ostream_iterator<C>(std::cout, ", "));
    std::cout << "]\n";
}};

constexpr static auto quick_sort{[](auto &v) noexcept
{
    std::stack<typename std::remove_reference<decltype(v)>::type::iterator> stack;
    stack.push(std::begin(v));
    stack.push(std::end(v));
    while (!stack.empty())
    {
        auto const high{stack.top()};
        stack.pop();
        auto const low{stack.top()};
        stack.pop();
        auto const half_distance{std::distance(low, high) / 2};
        auto const pivot_iter{std::next(low, half_distance)};
        auto const pivot_elem{*pivot_iter};
        auto const middle1{std::partition(low, high, [pivot_elem](auto const elem) noexcept { return elem < pivot_elem; })};
        auto const middle2{std::partition(middle1, high, [pivot_elem](auto const elem) noexcept { return elem <= pivot_elem; })};
        if (low != middle1)
        {
            stack.push(low);
            stack.push(middle1);
        }
        if (middle2 != high)
        {
            stack.push(middle2);
            stack.push(high);
        }
    }
}};

constexpr static auto generate_vector{[](auto &generator, auto const n) noexcept
{
    std::vector<int> v(n);
    std::generate_n(std::begin(v), n, generator);
    return v;
}};

int main()
{
    auto rng{RandomNumberGenerator(0, 100)};
    auto v{generate_vector(rng, 10)};
    print_vector(v);
    quick_sort(v);
    print_vector(v);
    return 0;
}
