// https://en.cppreference.com/w/cpp/regex/basic_regex

#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
 
void match_and_print(const std::string& text, const std::regex& pattern)
{
    std::sregex_iterator it(text.begin(), text.end(), pattern), it_end;
    int count = 0;
    for (; it != it_end; ++it)
    {
        const std::smatch& match = *it;
        std::cout << ++count << ". " << std::quoted(match.str()) << '\n';
    }
    std::cout << (count ? "\n" : "no match found\n\n");
}
 
int main()
{
    const std::string text = "Hello, World! 12345";
 
    // Matches one or more digits
    std::string pattern_text = "\\d+";
    std::cout << "digits (" << pattern_text << "):\n";
    auto pattern = std::regex(pattern_text);
    match_and_print(text, pattern);
 
    // Matches one or more characters split by space
    pattern_text = "[^\\s]+";
    std::cout << "words (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text);
    match_and_print(text, pattern);
 
    // Matches one or more characters split by space
    pattern_text = "[a-zA-Z]+";
    std::cout << "words without symbols and digits (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text);
    match_and_print(text, pattern);
 
    // Matches one non digits, non alphabet
    pattern_text = "[^0-9A-Za-z]";
    std::cout << "symbol (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text);
    match_and_print(text, pattern);
 
    // Matches one or more lowercase
    pattern_text = "[a-z]+";
    std::cout << "lowercase (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text);
    match_and_print(text, pattern);
 
    // Matches one or more lowercase with std::regex::icase flag
    pattern_text = "[a-z]+";
    std::cout << "lowercase with ignore case flag (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text, std::regex::icase);
    match_and_print(text, pattern);
 
    // Matches basic POSIX regular expression
    pattern_text = "[[:digit:]]+";
    std::cout << "basic POSIX regex (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text, std::regex::basic);
    match_and_print(text, pattern);
 
    // Matches extended POSIX regular expression
    pattern_text = "[[:digit:]]+";
    std::cout << "extended POSIX regex (" << pattern_text << "):\n";
    pattern = std::regex(pattern_text, std::regex::extended);
    match_and_print(text, pattern);
    return 0;
}