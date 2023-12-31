#include "shellbuiltin.h"

/**
 * my_atoi - Convert a string to an unsigned integer.
 * @str: The input string to convert.
 *
 * Return: Returns the converted unsigned integer value from the string.
 * If the string contains non-numeric characters or the value exceeds UINT_MAX,
 * it returns UINT_MAX.
 */
unsigned int my_atoi(char *str)
{
	atoi_t atou;

	atou.num = 0;
	size_t len = _strlen(str);

	for (atou.iterator = 0; atou.iterator < len; atou.iterator++)
	{
		if (UINT_MAX / 10 < atou.num)
			return (UINT_MAX);
		atou.num *= 10;
		atou.curr_digit = str[atou.iterator] - '0';
		if (UINT_MAX - atou.curr_digit < atou.num)
			return (UINT_MAX);
		atou.num += atou.curr_digit;
	}

	return (atou.num);
}

/**
 * free_all - frees all memory
 * @n: number of arguments
 * Return: void
 */
void free_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *ptr;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		ptr = va_arg(args, char *);
		free(ptr);
	}
	va_end(args);
}


/**
 * duplicateStringArray - Duplicate a string array.
 *
 * @array: The original string array to duplicate.
 *
 * Return: A new dynamically allocated array containing duplicated strings, or
 *         NULL on failure.
 */
char **duplicateStringArray(char **array)
{
	char **arr_dup = NULL;
	size_t length = 0, iterator;

	if (!array || !*array)
		return (NULL);

	while (array[length])
		length++;

	arr_dup = malloc(sizeof(*arr_dup) * (length + 1));
	if (arr_dup == NULL)
		return (NULL);

	for (iterator = 0; iterator < length; iterator++)
	{
		arr_dup[iterator] = _strdup(array[iterator]);
		if (arr_dup[iterator] == NULL)
		{
			while (iterator > 0)
			{
				free(arr_dup[--iterator]);
			}
			free(arr_dup);
			return (NULL);
		}
	}

	arr_dup[length] = NULL;
	return (arr_dup);
}

/**
 * merge_arrays - Concatenates two arrays of strings into a new array.
 * @array1: The first array of strings.
 * @array2: The second array of strings.
 *
 * Return: A newly allocated array containing the concatenated strings.
 *         NULL is returned in case of memory allocation failure.
 */
char **merge_arrays(char **array1, char **array2)
{
	char **new_arr;
	size_t arr_len1, arr_len2, new_len = 0;

	if (array1)
	{
		for (arr_len1 = 0; array1[arr_len1]; arr_len1++)
		    ;
	}
	if (array2)
	{
		for (arr_len2 = 0; array2[arr_len2]; arr_len2++)
		    ;
	}
	new_arr = malloc(sizeof(char *) * (arr_len1 + arr_len2 + 1));
	
	if (new_arr == NULL)
	    return (NULL);
	if (array1)
	{
		for (arr_len1 = 0; array1[arr_len1]; arr_len1++)
		    new_arr[new_len++] = _strdup(array1[arr_len1]);
	}
	if (array2)
	{
		for (arr_len2 = 0; array2[arr_len2]; arr_len2++)
		    new_arr[new_len++] = _strdup(array2[arr_len2]);
	}
	new_arr[new_len] = NULL;
	return (new_arr);
}