#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validation.h"

int getInt(char message[])
{
    int auxiliarInt;
    printf("%s" , message);
    scanf("%d" , &auxiliarInt);
    return auxiliarInt;
}


void getString(char message[], char input[])
{
    printf(message);
    scanf("%s", input);
}


float getFloat(char message[])
{
    float auxiliarFloat;
    printf("%s" , message);
    scanf("%f" , &auxiliarFloat);
    return auxiliarFloat;
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

int isPositive(float number)
{
    if(number > 0)
    {
        return 1;
    }
    return 0;
}
