#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    char S[1001];
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%s", S);
        int panjang = strlen(S);
        printf("Case #%d: ", i+1);
        for (int j = panjang ; j >= 0; j--)
        {
            if (S[j] >= 'a' && S[j] <= 'z')
            {
                printf("%c", S[j] - 32);
            }
            else if (S[j] >= 'A' && S[j] <= 'Z')
            {
                printf("%c", S[j] + 32);
            }
                       
        }
        printf("\n");
    }
    return 0;
}