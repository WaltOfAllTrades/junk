#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool only_digits(string arg);
bool one_arg(int arg_count);

int main(int argc, string argv[])
{
    // Program must run with a single command-line argument
    // Every character in argv[1] must be a digit
    if (one_arg(argc) == false || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
        // Convert argv[1] from string to int
        int key = atoi(argv[1]);

        // Prompt user for plaintext input
        string ptext = get_string("plaintext: ");

        // Establish length of plaintext
        int len = strlen(ptext);
        // Establish an array of chars (aka string) - to recieve rotated ciphertext - the length of the plaintext plus room for null terminator
        char ctext[len + 1];
        // Set the final element of the ciphertext array to the null terminator
        ctext[len] = '\0';

        // For each element in the plaintext array:
        for (int i = 0; i < len; i++)
        {
            // Rotate the character if it's a letter
            if (isalpha(ptext[i]) != 0)
            {
                // Establish the starting number for uppercase alphabetical chars
                int startpoint = 65;
                // If char ptext[i] is lowercase, set starting number for lowercase alphabetical chars
                if (isupper(ptext[i]) == 0)
                {
                    startpoint = 97;
                }
                // Calculate and write the rotated char to ciphertext
                ctext[i] = ((ptext[i] - startpoint + key) % 26) + startpoint;
            }
            // If char is not a letter, write it, unchanged, to the ciphertext string
            else
            {
                ctext[i] = ptext[i];
            }
        }
        // Print ciphertext
        printf("ciphertext: %s\n", (string) cipher);
        return 0;
}

// Program must run with a single command-line argument
bool one_arg(int arg_count)
    {
        bool one_arg_bool = false;
        if (arg_count == 2)
        {
            one_arg_bool = true;
        }
        return one_arg_bool;
    }

// Every character in argv[1] must be a digit
bool only_digits(string arg)
    {
        bool only_digits_bool = true;
        int len = strlen(arg);
        for (int i = 0; i < len; i++)
        {
            // if not a digit set bool to false
            if (isdigit(arg[i]) == 0)
            {
                only_digits_bool = false;
            }
        }
        return only_digits_bool;
    }
