#include <Chairloader/Private/StringUtils.h>

std::string_view TrimStringView(std::string_view s, const char* spaces)
{
    size_t begin = s.find_first_not_of(spaces);
    size_t end = s.find_last_not_of(spaces) + 1;
    begin = std::min(begin, s.size());
    end = std::min(end, s.size() + 1);

    if (begin == end)
        return std::string_view();
    else
        return s.substr(begin, end - begin);
}
