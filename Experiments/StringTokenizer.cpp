#include "StringTokenizer.h"

#include <algorithm>

using namespace std;

StringTokenizer::TokenType StringTokenizer::nextToken()
{
    if (hasMoreTokens()) {
        auto found = search(
            start,
            original.end(),
            separator.begin(),
            separator.end()
        );

        if (found == start) {
            advance(start, 1);
            return { };
        }

        string_view token{ start, found };

        start = move (found);

        if (start != original.end()) {
            advance(start, separator.size());
        }
        
        return { token };
    }


    return { };
}

#ifdef __cpp_lib_generator
std::generator<string_view> Tokens() {
    std::string::iterator start = original.begin();

    while (start != original.end()) {
        auto found = search(
            start,
            original.end(),
            separator.begin(),
            separator.end()
        );

        if (found == start) {
            advance(start, 1);
            continue;
        }

        string_view token{ start, found };

        start = move(found);

        if (start != original.end()) {
            advance(start, separator.size());
        }

        co_yield token;
    }
}
#endif