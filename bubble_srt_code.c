#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void getdata(int* , int);
void show(int* , int , const char *);
int bubble_sort(int* , int);
void swap(int* , int*);
int main()
{
    int length , val;
    int* arr = NULL;

    puts("\nEnter length of Array - ");
    scanf("%d" , &length);

    if(length < 0)
    {
        puts("\nInvalid array length\n");
        exit(EXIT_FAILURE);
    }

    arr =(int*)malloc(length* sizeof(int));

    if(arr == NULL)
    {
        puts("\nError in Memory Allocation");
        exit(EXIT_FAILURE);
    }

    getdata(arr , length) ;

    show(arr , length ,"\nArray Before Sorting --->\n");

    val =bubble_sort(arr , length );

    show(arr , length , "\nArray After Sorting --->\n");
    printf("\nIterations done to Sort Array = %d\n" ,val );

    exit(EXIT_SUCCESS);

    free(arr);

    arr= NULL;

    return 0 ;

}

void getdata(int* a, int n)
{
    int i;
    srand(time(0));
    for(i=0 ; i< n ; i++)
    {
        a[i] = rand() % 1000;
    }
}

void show(int* a, int n , const char * msg)
{
    int i;
    puts(msg);
    for(i=0 ; i<n ; i++)
    {
        printf("%d   ", a[i]);
    }

    puts("\n--------------------------------------------------------------------------------\n");
}

int bubble_sort(int* a, int n)
{
    int i ,flag, itr;

    for(itr=1 ; itr<n ; itr++)
    {
        flag = 0;
        for(i=0 ; i< (n-itr) ; i++)
        {
            if(a[i] > a[i+1])
            {
                swap( (a+i) , (a+i+1));
                flag =1;
            }
        }
        if(flag != 1)
        {
            break;
        }
    }

    return itr;
}

void swap(int* a, int* b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}