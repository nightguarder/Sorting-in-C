#include <stdio.h>
//Tento zdrojovy kod jsem vypracoval zcela samostatne bez cizi pomoci
//Neokopiroval jsem ani neopsal jsem cizi zdrojove kody
//Nikdo me pri vypracovani neradil
//Pokud nektery radek porusuje toto pravidlo je oznacen komentarem
//NENI MOJE TVORBA
//Poruseni techto pravidel se povazuje za podvod, ktery lze potrestat VYLOUCENIM ZE STUDIA
//Cyril Steger učo. 36830

//Napište program, který setřídí pole. (minimem, bubble sort, merge sort, quicksort, ...)
//How quickSort works: https://www.youtube.com/watch?v=uXBnyYuwPe8
//How bubbleSort works: https://www.youtube.com/watch?v=euPlXW7dnlI

static int array[10] = {9, 17, 15, 1, 35, 23, 61, 70, 97, 5};
size_t arrayLength = sizeof(array)/sizeof(array[0]); //returns as int

void swap(int x, int y){
int temp=0; 
temp = x;
x = y;
y = temp;
}

void pSwap(int *xp,int *yp){
    int temp=0;
    temp = *xp;
    *xp = *yp;
}

int MinSort(){ //(On^2)
    int temp =0;

    for (size_t i = 0; i < arrayLength; i++)
    {
        for (size_t j = i +1 ; j < arrayLength; j++)
        {
            if (array[i]>array[j]){
                temp = array[i];
                array[i]=array[j];
                array[j]= temp;
            }
        }
    }
    for (size_t i = 0; i < arrayLength; i++)
        printf("%d, ",array[i]);

    return 0;
}
int bubbleSort(){ //O (n^2)
    int size = arrayLength;

    for (size_t i = 0; i < size-1; i++) //go through array
    {
        for (size_t j = 0; j < size - i -1; j++)
        {
            if (array[j]>array[j+1]) //compare each element of array 
                pSwap(&array[j],&array[j+1]);
        }
    }

    for (size_t i = 0; i < arrayLength; i++)
        printf("%d, ",array[i]);

    return 0;
}

int partition(int array[],int left, int right){

    int pivot= array[right]; //pivot is set to most right postition
    int i = left - 1;

    for ( int j = left; j < right; j++)
    {
        if (array[j]<=pivot) //if element is less than or equal to pointer
        {
            i++; //move the pointer
            pSwap(&array[i],&array[j]); //and swap
        }
    }
    pSwap(&array[i+1],&array[right]); //reset the pivot
    return i + 1;
}
int quickSort(int array[],int left, int right){ //O(n * log(n))

    int pivot = 0;
    if (left>right)
    {
        pivot = partition(array,left,right); //find pivot
        quickSort(array,left,pivot - 1); // Recursive call
        quickSort(array,pivot+1,right);
    }

    for (size_t i = 0; i < arrayLength; i++)
    printf("%d, ",array[i]);
    
    
    return 0;
}
int main(int argc, char **argv){
    printf("Unsorted array:\n");
    for (size_t i = 0; i < arrayLength; i++)
        printf("%d, ",array[i]);
    
    printf("\nMinArray:\n");
    MinSort();
    printf("\nBubbleSort:\n");
    bubbleSort();
    printf("\nQuickSort:\n");
    quickSort(array,0, arrayLength-1);
    
    return 0;
}