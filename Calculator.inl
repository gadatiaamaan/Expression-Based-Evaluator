/**
 * Determines if the entered string is an integer.
 *
 * @param str The string to analyze.
 *
 * @return True if the string is an integer, false otherwise.
 */
inline bool Calculator::is_int(const std::string str)
{
    return std::regex_match(str, std::regex("^-?[0-9]+$"));
}
