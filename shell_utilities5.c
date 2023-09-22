#include "myqoute.h"

/**
  * _isident - checks if the character is a valid identifier character
  * @c: character to check
 * Return: If c is an identifier character, return 1. Otherwise, return 0.
  */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}


/**
 * is_numeric - Check if a string consists of numeric digits.
 * @str: The input string to check.
 *
 * Return: Returns true (1) if the entire string consists of numeric digits, or false (0) otherwise.
 */
bool is_numeric(const char *str)
{
    if (str)
    {
        while (*str)
        {
            if (!_isdigit(*str++))
               return (false);
        }
        return (true);
    }
    return (false);
}


/**
 * _isquote - check if a character is a quote
 * @c: the character to check
 * Return: If c is a quote, return 1. Otherwise, return 0.
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}

/**
 * _isspace - check if a character is whitespace
 * @c: the character to check
 * Return: If c is whitespace, return 1. Otherwise, return 0.
 */
bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}

/**
 * Checks if a character is a special escape character within double quotes.
 *
 * @param c The character to check.
 * @return 1 if the character is a double quote, dollar sign, or backslash;
 *         0 otherwise.
 */
int is_double_quote_escape(char c)
{
  return (c == '"' || c == '$' || c == '\\');
}

