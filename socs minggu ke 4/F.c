#include <stdio.h>

int main()
{
    char N[10000];
    scanf("%[^\n]", N);
    for (int i = 0; N[i] != '\0'; i++)
    {
        if (N[i] >= 'a' && N[i] <= 'z') N[i] = N[i] - 32; 
        switch (N[i])
        {
            case 'I':
                N[i] = '1';
                break;
            case 'R':
                N[i] = '2';
                break;
            case 'E':
                N[i] = '3';
                break;
            case 'A':
                N[i] = '4';
                break;
            case 'S':
                N[i] = '5';
                break;
            case 'G':
                N[i] = '6';
                break;
            case 'T':
                N[i] = '7';
                break;
            case 'B':
                N[i] = '8';
                break;
            case 'P':
                N[i] = '9';
                break;
            case 'O':
                N[i] = '0';
                break;
        }
    }
    printf("%s\n", N);
    return 0;
}