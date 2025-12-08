#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int convertToBinary(int value);

int main()
{

    char hex;
    bool exit = false;

    while (!exit)
    {
        printf("Enter a hex digit (0-9, A-F) or X to exit: ");
        scanf(" %c", &hex); // space before %c consumes whitespace

        hex = toupper(hex);
        int value;

        if (hex == 'X')
        {
            exit = true;
            continue;
        }
        else if (hex >= '0' && hex <= '9')
        {
            // subtract ASCII '0' to get numeric value of hex
            value = hex - '0';
        }
        else if (hex >= 'A' && hex <= 'F')
        {
            // subtract ASCII 'A' and add 10 gets numeric value of hex
            value = hex - 'A' + 10;
        }
        else
        {
            printf("Invalid input.\n");
            continue;
        }

        int binary = convertToBinary(value);
        printf("%04d\n", binary);
    }

    printf("-\n");
    return 0;
}

int convertToBinary(int value)
{
    // Extract 4-bit binary using bitwise AND + shifting
    int b3 = (value >> 3) & 1; // most significant bit
    int b2 = (value >> 2) & 1;
    int b1 = (value >> 1) & 1;
    int b0 = value & 1; // least significant bit

    int binary = b3 * 1000 + b2 * 100 + b1 * 10 + b0;
    return binary;
}
