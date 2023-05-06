#include <string>
#include <algorithm>
#include <functional>

template<typename Predicate>
void trimString(std::string& str, Predicate pred) {
    auto left = std::find_if_not(str.begin(), str.end(), pred);
    str.erase(str.begin(), left);
    auto right = std::find_if_not(str.rbegin(), str.rend(), pred);
    str.erase(right.base(), str.end());
}
