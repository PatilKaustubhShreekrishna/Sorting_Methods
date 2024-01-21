#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void getdata(int* , int);
void show(int*,int,const char*);
void Insertion_Sort(int* , int);

int main()
{
    int length;
    int* arr = NULL;

    puts("\nEnter the Length of An array - ");
    scanf("%d",&length);

    if(length < 0)
    {
        puts("\nInvalid Array Length\n");
        exit(EXIT_FAILURE);
    }

    arr =(int*)malloc(length * sizeof(int));

    if(arr == NULL)
    {
        puts("\nError In Memory Allocation\n");
        exit(EXIT_FAILURE);
    }

    getdata( arr , length);

    show(arr , length , "\nArray Before Sorting --->\n");

    Insertion_Sort(arr , length);

    show(arr , length , "\nArray After Sorting --->\n");

    exit(EXIT_SUCCESS);

    free(arr);

    arr =NULL;

    return 0;

}

void getdata(int* a , int n)  //n is array Length of ARRAY a;
{
    int i;
    srand(time(0));
    for(i=0 ;i<n ;i++)
    {
        a[i] = (rand() % 1000);
    }

}

void show(int* a , int n ,const char * msg)
{
    int i;
    puts(msg);
    for(i=0 ; i<n ; i++)
    {
        printf("%d   " , a[i]);
    }
    printf("\n--------------------------------------------------------------------------------------------------\n");
}


void Insertion_Sort(int* a , int n )
{
    int itr,temp, empty;

    for( itr=1 ; itr<n ; itr++)
    {
        temp = a[itr] ;
        empty  = itr;
        while(empty>0 && a[empty-1] > temp)
        {
            a[empty] = a[empty-1];
            empty--;
        }
        a[empty] = temp;

        
    }
}


