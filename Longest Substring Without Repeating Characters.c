#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main(){

    char input[] = "pwwkew";
    char existString[100];
    char ChartoString[2];
    int count = 0;
    int longestStr = 0;


    for(int i = 0; i < strlen(input); i++){
        char * ptr = strchr(existString, input[i]);
        if(ptr == NULL){
            ChartoString[0] = input[i];
            ChartoString[1] = '\0';
            count += 1;
            strcat(existString, ChartoString);
            if(longestStr < count){
                longestStr = count;
            }
        }else{
            strcpy(existString, "");
            i = i - 1;
            count = 0;
        }
    }
    printf("output: %d", longestStr);

    return 0;
}

