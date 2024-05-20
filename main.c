#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void twoSumDescription();
void AddTwoNumbersDescription();


typedef struct theList{
    int num;
    struct theList * next;
}myList;

myList * inputForList(myList * list, int num){
    myList * newNode = (myList *)malloc(sizeof(myList));
    newNode->num = num;
    newNode->next = NULL;
    if(list == NULL){
        list = newNode;
    }else{
        myList * pointer;
        pointer = list;
        while(pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = newNode;
    }
    return list;
}

int convertListToInt(myList * list){
    myList * copyList = list;
    int num = 0, increaseDigit = 1, start = 1; //345 ----------- 3 ---- 30 + 4 = 34,
    while(copyList != NULL){
        num = copyList->num + ((increaseDigit) * num) ;
        increaseDigit = 10;
        copyList = copyList->next;
    }

    return num;
}

myList * resultSumNumbers(myList * l1, myList * l2, myList * sumList){
    //printf("\nFor first list: %d", convertListToInt(l1));
    //printf("\nFor second list: %d\n", convertListToInt(l2));
    int sumOfTwo = convertListToInt(l1) + convertListToInt(l2);
    char stringNum[100];
    itoa(sumOfTwo, stringNum, 10);
    //printf("Sum: %s\n", stringNum);
    //printf("size:  %s", stringNum);
    stringNum[strlen(stringNum)] = '\0';
    for(int i = 0; i < strlen(stringNum); i++){
        sumList = inputForList(sumList, (stringNum[i] - '0'));
    }
    return sumList;

}

void displayList(myList * list){
    myList * copyList = list;
    while(copyList != NULL){
        printf(" %d ", copyList->num);
        copyList = copyList->next;
    }
    printf("]\n");
}

void AddTwoNumbers(){
    AddTwoNumbersDescription();
    int num, select;
    myList * list1 = NULL;
    myList * list2 = NULL;
    myList * sumList = NULL;
    while(true){
        printf("Enter a number for a first list: \n");
        scanf("%d", &num);
        list1 = inputForList(list1, num);
        printf("stop adding number? \n1.Yes\n2.No\nSelect---> ");
        scanf("%d", &select);
        if(!(select == 1)){
            break;
        }
    }
    printf("Your first list [");
    displayList(list1);
    while(true){
        printf("Enter a number for a second list: \n");
        scanf("%d", &num);
        list2 = inputForList(list2, num);
        printf("stop adding number? \n1.Yes\n2.No\nSelect---> ");
        scanf("%d", &select);
        if(!(select == 1)){
            break;
        }
    }
    printf("Your second list [");
    displayList(list1);
    printf("---------------------------------\n");
    printf("You entered\nlist1 = [ ");
    displayList(list1);
    printf("list2 = [");
    displayList(list2);
    sumList = resultSumNumbers(list1, list2, sumList);
    printf("Result: [");
    displayList(sumList);


}

int * twoSumResult(int * nums, int sizeNum, int target){
    int * result = (int *)malloc(sizeof(int ) * 3);

    for(int i = 0; i < sizeNum; i++){
        for(int j = 0; j < sizeNum; j++){
            if(!(i == j) && ((nums[i] + nums[j]) == target)){
                result[0] = i;
                result[1] = j;
                result[2] = '\0';
                break;
            }
        }
    }
    return result;
}

void twoSum(){
    twoSumDescription();
    int * nums,sizeNum, target;
    printf("Enter how many number: ");
    scanf("%d", &sizeNum);
    nums = (int *)malloc(sizeof(int) * sizeNum);
    for(int i = 0; i < sizeNum; i++){
        printf("Enter [%d] number: ", i + 1);
        scanf("%d", &nums[i]);
    }
    printf("Enter a target: ");
    scanf("%d", &target);
    printf("You intered, target = %d, sizeNum = %d, nums = ", target, sizeNum);
    for(int i = 0; i < sizeNum; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    int * numsResult = twoSumResult(nums, sizeNum, target);

    printf("Result: [ %d %d]\n", numsResult[1], numsResult[0]);
}

char * reverse(char * string){
    char * copyString;
    copyString = (char *)malloc(strlen(string));
    int j = 0;
    for(int i = strlen(string) - 1; i >= 0; i--){
        copyString[j] = string[i];
        j++;
    }
    copyString[strlen(string)] = '\0';

    return copyString;
}

void reverseString(){
    char * string;
    string = (char *)malloc(sizeof(char) * 100);
    printf("\nEnter string: ");
    scanf(" %[^\n]", string);
    printf("result: %s\n", reverse(string));
}

void menuText(){
    printf("0. Terminate Program\n");
    printf("1. Reverse String\n");
    printf("2. Two Sum\n");
    printf("3. Add Two Numbers\n");
    printf("select ---> ");
}

void menu(int select){
    switch(select){
    case 1:
        reverseString();
        break;
    case 2:
        twoSum();
        break;
    case 3:
        AddTwoNumbers();
        break;
    default:
        printf("Invalid Input... terminate program");
    }
}

int main(){
    int select;
    while(true){
        menuText();
        scanf("%d", &select);
        menu(select);
        if(select == 0){
            break;
        }
    }


    return 0;
}




void twoSumDescription(){
    printf("Example-----------------------------------------------\nEnter size of number : 3\n");
    printf("You entered [1,2,3]\n");
    printf("Enter target: 4\n");
    printf("You entered 4\n");
    printf("output: [0, 2] because 1 + 3 is 4 where 1 is in index 0 and 3 is index index 2\n");
    printf("That's two sum, enjoy.............\n");
    printf("------------------------------------------------------\n");

}

void AddTwoNumbersDescription(){
    printf("Example-----------------------------------------------\n");
    printf("You have 2 linked list, \n");
    printf("List1 have 3 nodes which is 3 -> 4 -> 5\n");
    printf("List2 have 4 nodes which is 5 -> 9 -> 4 -> 1\n");
    printf("Add these lists. \n");
    printf("Result: [6 2 8 6]\n");
    printf("because 345 + 5941 = 6286\n");
    printf("That's add two numbers, enjoy.............\n");
    printf("------------------------------------------------------\n");
}
