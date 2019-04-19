//  main.cpp
//  BitWiseOperations
//
//  Created by venkata bethamcharla on 4/18/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>

int binarySearch(int x, int *ref_array, int size);
int binarySearch_V2(int x, int ref_array[], int size);

int main()
{
    int ref_array_0[10] = {4, 5, 6, 7, 8, 9, 10, 15, 142, 1250};
    int searchLoc = binarySearch(141, &ref_array_0[0], 10);
    printf("searchLoc: %d \n", searchLoc);

    int ref_array_1[10] = {400, 500, 600, 700, 800, 900, 1000, 1501, 14223, 125034};
    searchLoc = binarySearch(500, &ref_array_1[0], 10);
    printf("searchLoc: %d \n", searchLoc);
    
    int ref_array_2[10] = {400, 500, 600, 700, 800, 900, 1000, 1501, 14223, 125034};
    searchLoc = binarySearch_V2(500, &ref_array_2[0], 10);
    printf("searchLoc: %d \n", searchLoc);
    
    return 0;
}


int binarySearch(int x, int ref_array[], int size)
{
    int low, high, mid;
    low = 0;
    high = size-1;
    
    while (low <= high)
    {
        mid = (low+high)/2;
        
        if (x > ref_array[mid])
        {
            low = mid+1;
        }
        else if (x < ref_array[mid])
        {
            high = mid-1;
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}


int binarySearch_V2(int x, int ref_array[], int size)
{
    int low, high, mid;
    low = 0;
    high = size-1;
    mid = (low+high)/2;
    
    while (low <= high && x != ref_array[mid])
    {
        if (x > ref_array[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        mid = (low+high)/2;
    }

    if (x==ref_array[mid])
        return mid;
    else
        return -1;
}
