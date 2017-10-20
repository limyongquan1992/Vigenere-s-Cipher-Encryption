#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string get_plaintext (void);
void vigenere (string s, string t);

int main (int argc, string argv[])
{
    // check for keyword input
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    
    // check for keyword validity
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    
    }
    
    // get user input
    string s = get_plaintext();
    
    // cipher the plaintext and print ciphertext
    vigenere(argv[1], s);
}

string get_plaintext (void)
{
    printf("plaintext: ");
    
    // get user input
    string s = get_string();
    return s;
}

void vigenere (string s, string t)
{
    printf("ciphertext: ");
    
    // convert keyword into an integer array - key
    int key[strlen(s)];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]))
        {
            key[i] = s[i]-65;
        }
        else
        {
            key[i] = s[i]-97;
        }
    
    }
    
    // declare an integer to iterate key array
    int j = 0;
    // iterate thru every plaintext to cipher it accordingly
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        // identify whether the plaintext's current character is a alphabet
        if (isalpha(t[i]))
        {
            // identify whether it is uppercase
            if (isupper(t[i]))
            {
                // move the alphabet according to key
                printf("%c", 65+((t[i]-65+(key[j]))%26));
                // increment j to iterate thru key array in a complete loop (when it is the last element in key array, start from 0)
                if (j == strlen(s)-1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                printf("%c", 97+((t[i]-97+(key[j]))%26));
                if (j == strlen(s)-1)
                {
                    j = 0;
                }
                else
                {
                    j++;
                }
            }
        }
        else
        {
            // print the original for non-alphabet
            printf("%c", t[i]);
        }
    }
    printf("\n");
}