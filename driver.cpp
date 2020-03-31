#include <iostream>

using namespace std;

void printArray(int* ar, int begin, int end)
{
    for(int i = begin; i <= end; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void merger(int* ar, int begin1, int end1, int begin2, int end2 )
{

int a = begin1;
int z = end1;
int y = end2;
int b = begin2;

int temp[y];

int count = begin1;

while(a <= z && b <= y)
{
//while statement will continue to repeat until it reaches the end of the list

if(ar[a] < ar[b])

{
    temp[count] = ar[a];
    a++;
    count++;
}

else
{
    temp[count] = ar[b];
    b++;
    count++;

}

}

while(a <= z){

    temp[count] = ar[a];
    count++;
    a++;



}

while(b <= y){

    temp[count] = ar[b];
    count++;
    b++;
}

for(int i = begin1; i < count; i++){
    ar[i] = temp[i];
}
}


//which portion of the array am I mergeSorting....
void mergeSort(int* ar, int begin, int end)
{
    //cout << "Merge Sorting: ";
    //printArray(ar, begin, end);

    //if it is not a 1 list (not trivially sorted)
    if(begin != end)
    {
        //divide in half and call mergeSort on each half
        int begin1 = begin;
        int end1 = (end + begin) / 2;
        int begin2 = end1 + 1;
        int end2 = end;

        //call mergesort on the first half
        mergeSort(ar, begin1, end1);

        //call mergesort on the second half
        //this will not fire until the entire 
        //first half is dealt with
        mergeSort(ar, begin2, end2);

        //now perform the merge step
        //cout << "Now we have to merge!!!!\n Start to cry Clancy!!!\n";

        merger(ar, begin1, end1, begin2, end2);
    }
    
    
    
}

int main()
{
    int ar[5] = {7,2,1,4,3};
    mergeSort(ar, 0, 4);
    printArray(ar, 0, 4);
    return 0;
}