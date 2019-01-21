#include "joinStrings.hpp"
#include<assert.h>
#include<vector>
int main()
{
    using namespace std::string_literals;
    std::vector<std::string> v1{"this", "is", "an", "example"};
    std::vector<std::string> v2{"example"};
    std::vector<std::string> v3{};
    assert(join_strings(v1, " ") == "this is an example"s);
    assert(join_strings(v2, " ") == "example"s);
    assert(join_strings(v3, " ") == ""s);
}