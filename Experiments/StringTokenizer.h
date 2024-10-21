#pragma once

#include <string>
#include <optional>

#if (defined(__has_include) && __has_include(<generator>))
#include <generator>
#endif


class StringTokenizer
{
private:
	 std::string original;

	//int currInd = 0;
	 std::string::iterator start;
	 std::string_view separator = " ";

	 typedef std::optional<std::string_view> TokenType;

public:
	StringTokenizer(const std::string& orig, const std::string_view& separator) : original(orig),
		start(original.begin()), separator(separator) {}

	StringTokenizer(const std::string& orig, const int start = 0, const std::string_view& separator = " ") : original(orig),
		start (std::next(original.begin(), start)), separator(separator) {}

	bool hasMoreTokens() const { return start != original.end(); }

	TokenType nextToken();

#ifdef __cpp_lib_generator
	std::generator<std::string_view> Tokens();

	static std::generator<std::string_view> GenerateTokens(const std::string& orig, const int start = 0, const std::string_view& separator = " ") {
		StringTokenizer tokenizer{ orig, start, separator };
		return tokenizer.Tokens();
	}

	static std::generator<std::string_view> GenerateTokens(const std::string& orig, const std::string_view& separator) {
		StringTokenizer tokenizer{ orig, separator };
		return tokenizer.Tokens();
	}
#endif

};

