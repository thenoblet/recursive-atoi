#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(string input);

int main(void)
{
    //get an integer from the user
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    //get the length of the input
    int len = strlen(input);

    //base case
    if (len == 0)
    {
        return 0;
    }

    //convert char to numeric
    int converted_char = input[len - 1] - '0';

    //remove the last character from the string
    input[len - 1] = '\0';

    return converted_char + 10 * convert(input);
}