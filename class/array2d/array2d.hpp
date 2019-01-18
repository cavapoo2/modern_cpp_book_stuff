#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

template <class T, size_t R, size_t C>
class array2d
{
    typedef T value_type;
    typedef value_type *iterator;
    typedef value_type const *const_iterator;

    std::vector<T> arr;

  public:
    array2d() : arr(R * C) {}
    explicit array2d(std::initializer_list<T> l) : arr(l) {}
    constexpr T *data() noexcept { return arr.data(); }
    constexpr T const *data() const noexcept { return arr.data(); }

    constexpr T &at(size_t const r, size_t const c)
    {
        return arr.at(r * C + c);
    }

    constexpr T const &at(size_t const r, size_t const c) const
    {
        return arr.at(r * C + c);
    }

    constexpr T &operator()(size_t const r, size_t const c)
    {
        return arr[r * C + c];
    }

    constexpr T const &operator()(size_t const r, size_t const c) const
    {
        return arr[r * C + c];
    }

    constexpr bool empty() const noexcept
    {
        return R == 0 || C == 0;
    }

    constexpr size_t size(int const rank) const
    {
        if (rank == 1)
            return R;
        else if (rank == 2)
            return C;
        throw std::out_of_range("Rank is out of range!");
    }

    void fill(T const &value)
    {
        std::fill(std::begin(arr), std::end(arr), value);
    }

    void swap(array2d &other) noexcept
    {
        arr.swap(other.arr);
    }

    const_iterator begin() const { return arr.data(); }
    const_iterator end() const { return arr.data() + arr.size(); }
    iterator begin() { return arr.data(); }
    iterator end() { return arr.data() + arr.size(); }

    friend std::ostream &operator<<(std::ostream &os, const array2d &arr)
    {
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                os << arr.at(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }
};
