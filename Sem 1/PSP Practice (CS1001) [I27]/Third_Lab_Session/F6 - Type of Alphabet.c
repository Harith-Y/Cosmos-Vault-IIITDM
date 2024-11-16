//Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{

    char a;
    printf("Please enter any Alphabet : ");
    scanf("%c", &a);

    if (a == 'b' || a == 'c' || a == 'd' || a == 'f' || a == 'g' || a == 'h' || a == 'j' || a == 'k' || a == 'l' || a == 'm' || a == 'n' || a == 'p' || a == 'q' || a == 'r' || a == 's' || a == 't' || a == 'v' || a == 'w' || a == 'x' || a == 'y' || a == 'z' || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'B' || a == 'C' || a == 'D' || a == 'F' || a == 'G' || a == 'H' || a == 'J' || a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'P' || a == 'Q' || a == 'R' || a == 'S' || a == 'T' || a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == 'Z')
    {

        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
            {
            printf("%c is a vowel ", a);

            if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
                printf("and it is lowercase.");
            else
                printf("and it is uppercase.");
            }
        else
            {
            printf("%c is a consonant ",a);
            
            if (a == 'b' || a == 'c' || a == 'd' || a == 'f' || a == 'g' || a == 'h' || a == 'j' || a == 'k' || a == 'l' || a == 'm' || a == 'n' || a == 'p' || a == 'q' || a == 'r' || a == 's' || a == 't' || a == 'v' || a == 'w' || a == 'x' || a == 'y' || a == 'z')
                printf("and it is lowercase.");
            else
                printf("and it is uppercase.");
            }
    }

    else if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
        printf("Please Enter a Valid Alphabet and not a digit or number !");
    else
        printf("Please Enter a Valid Alphabet and not a Special Charecter !");

}
