#include <string>
#include <algorithm>
#include <functional>

template<typename Predicate>
std::string trimString(std::string_view str, Predicate pred)
{
    auto left = std::find_if_not(str.begin(), str.end(), pred);
    auto right = std::find_if_not(str.rbegin(), str.rend(), pred);
    return std::string(left, right.base());
}