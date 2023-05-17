#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void charCountInput()
{
    int m, i, len, l;
    char m2[100];
    char data[100], final[100];
    printf("enter the number of data units: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("enter the data unit %d: ", i + 1);
        scanf("%s", data);
        len = strlen(data);
        l = len + 1;
        sprintf(m2, "%c", l + 48);
        strcat(m2, data);
        strcat(final, m2);
    }
    printf("the character count frame input will be: %s", final);
}
void charCountOutput()
{
    int i, len, j;
    char str[100];
    printf("enter formatted string: ");
    scanf("%s", str);
    len = strlen(str);
    // printf("%d",len);
    i = 0;
    while (str[i] != '\0')
    {
        printf(" %d", i);
        if (isdigit(str[i]) != 0)
        {
            for (j = i + 1; j < (str[i] - 48); j++)
            {
                printf("%c", str[j]);
            }
            // printf(" %d %d",str[i],i);
            i += (str[i] - 48);
        }

        printf(" %d", i);
    }
}

void byteStuffing()
{
    char a[20], b[20];
    int i, n, j;
    // char f,s;
    printf("Enter the size of the frame : ");
    scanf("%d", &n);
    n = n * 2;
    printf("\nEnter the characters in frame : \n");
    for (i = 0; i < n; i++)
        scanf("%c", &a[i]);
    printf("\n FRAME \n ");
    for (i = 0; i < n; i++)
        printf("%c", a[i]);

    b[0] = '#';
    j = 1;
    for (i = 0; i < n; i++)
    {
        if (a[i] == '#')
        {
            b[j] = '$';
            j++;
            b[j] = a[i];
        }
        else if (a[i] == '$')
        {
            b[j] = '$';
            j++;
            b[j] = a[i];
        }
        else
            b[j] = a[i];

        j++;
    }
    printf("\nRESULT\n");

    b[j] = '#';
    printf("%s", b);
}

void byteDestuffing()
{
    char a[20], b[20];
    int i, n, j;
    // char f,s;
    printf("\nEnter the characters: \n");
    scanf("%s", a);
    n = strlen(a);

    // b[0]='#';
    j = 0;
    for (i = 0; i < n; i++, j++)
    {
        if (a[i] == '$')
        {
            i++;
            b[j] = a[i];
        }

        else
            b[j] = a[i];
    }
    printf("\nRESULT\n");

    // b[j]='#';
    printf("%s", b);
}

void bitStuffing()
{
    int a[100], b[100];
    int n, q, r, s, count = 1, x;
    printf("enter the number of bits: ");
    scanf("%d", &n);
    printf("enter the data: ");
    for (q = 0; q < n; q++)
    {
        scanf("%d", &a[q]);
    }
    q = 0;
    b[0] = 0;
    b[1] = 1;
    b[2] = 1;
    b[3] = 1;
    b[4] = 1;
    b[5] = 1;
    b[6] = 0;
    s = 7;

    while (q < n)
    {
        // count=0;
        if (a[q] == 1)
        {
            b[s] = a[q];
            // count++;

            for (r = q + 1; r < n && count < 5 && a[r] == 1; r++)
            {
                s++;
                b[s] = a[r];
                count++;
                if (count == 5)
                {
                    s++;
                    b[s] = 0;
                    count = 0;
                }
                q = r;
            }
        }
        else
        {
            b[s] = a[q];
        }
        s++;
        q++;
    }

    b[s] = 0;
    b[s + 1] = 1;
    b[s + 2] = 1;
    b[s + 3] = 1;
    b[s + 4] = 1;
    b[s + 5] = 1;
    b[s + 6] = 0;
    // b[s+7]=0;
    s += 7;
    for (q = 0; q < s; q++)
    {
        printf("%d", b[q]);
    }
}

void bitDestuffing()
{
    int a[100], b[100];
    int n, q, r, s, count = 1, x;
    printf("enter the number of bits: ");
    scanf("%d", &n);
    printf("enter the data: ");
    for (q = 0; q < n; q++)
    {
        scanf("%d", &a[q]);
    }
    q = 0;
    // b[0]=0;
    // b[1]=1;
    // b[2]=1;
    // b[3]=1;
    // b[4]=1;
    // b[5]=1;
    // b[6]=0;
    s = 0;

    while (q < n)
    {
        // count=0;
        if (a[q] == 1)
        {
            b[s] = a[q];
            // count++;

            for (r = q + 1; r < n && count < 5 && a[r] == 1; r++)
            {
                s++;
                b[s] = a[r];
                count++;

                if (count == 5)
                {
                    r++;
                    // b[s]=0;
                    count = 0;
                }
                q = r;
            }
        }
        else
        {
            b[s] = a[q];
        }
        s++;
        q++;
    }

    // b[s]=0;
    // b[s+1]=1;
    // b[s+2]=1;
    // b[s+3]=1;
    // b[s+4]=1;
    // b[s+5]=1;
    // b[s+6]=0;

    // s+=7;
    for (q = 0; q < s; q++)
    {
        printf("%d", b[q]);
    }
}

void main()
{
    int n, opt;
    printf("enter the option:  ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        charCountInput();
        break;
    case 2:
        charCountOutput();
        break;

    case 3:
        byteStuffing();
        break;
    case 4:
        byteDestuffing();
        break;

    case 5:
        bitStuffing();
        break;
    case 6:
        bitDestuffing();
        break;

    default:
        printf("not an option");
        break;
    }
}