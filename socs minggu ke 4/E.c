#include <stdio.h>
#include <string.h>
int main()
{
    int T, i, j;
    char S[501];
    scanf("%d", &T);
    for(int k = 0; k < T; k++)
    {
        int sama = 0;
        scanf("%s", S);
        int panjang = strlen(S);
        printf("Case #%d: ", k+1);
        for (i = 0, j = panjang - 1; j >= 0; i++, j--)
        {
            if(S[i] != S[j])
            {
               sama++;
            }
        }
        if(sama > 1)
        {
            printf("Nah, it\'s not a palindrome\n");
        }
        else
        {
            printf("Yay, it\'s a palindrome\n");
        }
    }
    return 0;
}