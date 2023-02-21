#include <iostream>


int main()

{

int *arr,c=1,i=0,j=1;

arr = (int*)malloc(sizeof(int));

printf("enter array : ");

while(c!='\n')

scanf("%d",&c);    //read the input from keyboard standard input

//re-allocate (resize) memory for integer read to be stored

arr = (int*)realloc(arr,j*sizeof(arr));

arr[i] = c;  //store read integer by making pointer point to c

i++;
j++;

free(arr); //important step the pointer declared must be made free

return 0;

}