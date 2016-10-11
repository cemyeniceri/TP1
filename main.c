//
// Created by Cem Yeniceri on 12/10/16.
//
#include <stdio.h>
#define SIZE 20


void get_value(int arr[])
{
    int index = 0;
    while(index < SIZE){
        printf("Enter next elements :\n");
        scanf("%d", &arr[index]);
        index++;
    }
}

void print_value(int arr[], int length)
{
    int index = 0;
    printf("{");
    while(index < length){
        printf("%d", arr[index]);
        index++;
    }
    printf("}\n");
}

int find_union(int array1[], int array2[], int union_array[]){
    int i=0;
    int intersection_array[SIZE];
    int intersectNumber = find_intersection(array1, array2, intersection_array);

    while(i<SIZE){
        union_array[i] = array1[i];
        i++;
    }

    i=0;
    int isIntersect;
    int k=0;
    while(i<SIZE){
        int j=0;
        isIntersect = 0;
        while(j<intersectNumber){
            if(array2[i]==intersection_array[j]){
                isIntersect = 1;
                break;
            }
            j++;
        }
        if(isIntersect==0) {
            union_array[SIZE+k] = array2[i];
            k++;
        }
        i++;
    }
    return (2*SIZE - intersectNumber);
}

int find_intersection(int array1[], int array2[], int intersection_array[])
{
    int i = 0, k = 0;
    while (i < SIZE)
    {
        int j = 0;
        while(j < SIZE){
            if(array1[i]==array2[j]){
                intersection_array[k] = array1[i];
                k++;
                break;
            }else{
                j++;
            }
        }
        i++;
    }
    return(k);
}

int main ()
{
    int arr1[SIZE];
    int arr2[SIZE];

    int union_array[2 * SIZE];
    int intersection_array[SIZE];

    printf("Enter elements of first array :\n");
    get_value(arr1);

    printf("Enter elements of second array :\n");
    get_value(arr2);

    print_value(arr1, SIZE);
    print_value(arr2, SIZE);

    printf("\nIntersection array : ");
    int numOfIntersectionElements = find_intersection(arr1, arr2, intersection_array);
    print_value(intersection_array, numOfIntersectionElements);

    printf("\nUnion array: ");

    int numOfUnionElements = find_union(arr1, arr2, union_array);
    print_value(union_array, numOfUnionElements);

    return 0;
}