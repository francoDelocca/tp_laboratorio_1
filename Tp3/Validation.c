#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validation.h"

int getInt(char message[])
{
    char auxiliarChar[25];
    printf("%s" , message);
    scanf("%s" , auxiliarChar);
    while(isANumber(auxiliarChar) == 0)
    {
        printf("Ingrese un numero valido\n");
        printf("%s" , message);
        scanf("%s" , auxiliarChar);
    }
    int auxiliarInt = atoi(auxiliarChar);
    return auxiliarInt;
}

char getChar(char message[])
{
    char auxiliarChar;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &auxiliarChar);
    return auxiliarChar;
}


void getString(char message[], char input[])
{
    printf(message);
    fflush(stdin);
    scanf("%s", input);
}

int isOnlyLetters(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int isANumber(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}


int isPositive(int number)
{
    if(number > 0)
    {
        return 1;
    }
    return 0;
}
