#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int partition(int *arr,int start ,int end);

/**
*@brief swapVal()
*@param  a the first number 
*@param  b the second number 
*
The function swapVal takes in two pointer arguments of the type int and would swap them.
*/
void swapVal(int * a,int * b)
{
    int res;
    res =*a;
    *a=*b;
    *b=res;
}
/**
 * @brief partition()
 * @param arr 
 * @param start index
 * @param end index
 * @return index
 * 
 * The function partition takes in array as well as the start and the end index of the array. 
 * The main part of the quick sort algorithm happens in this phase. 
 * We take a pivot element. In this case it would be the last element.
 * initiliase ind as start-1.
 * Run the loop from start to the end index. 
 * If the element is less than the pivot then increment the index and swap the element with element at position ind
 * And at last swap the current element with the pivot element.
 *
 */

int partition(int *arr,int start,int end)
{
    int pivot = arr[end];
    int ind = start - 1;

    for(int j=start;j!=end;j++)
    {
        if(arr[j]<pivot)
        {
            ind++;
            swapVal(&arr[ind],&arr[j]);
        }

    }
    swapVal(&arr[ind+1],&arr[pivot]);
    return ind +1;
}
/**
 * @brief quicksort()
 * @param arr
 * @param start index
 * @param end index
 * If start is less than end index partition the array and recurisvely call the quick sort algorithm on both the partitions. 
 */
void quickSort( int *arr,int start,int end)
{
    if(start < end)
    {
        int part_ind = partition(arr,start, end);
        quickSort(arr,start,part_ind-1);
        quickSort(arr,part_ind+1,end);
        
    }
  
}
//array display function
void display(int *arr,int size)
{
    std::cout<<std::endl;
    for(int i=0;i<=size;i++)
    {
     cout<<arr[i]<<" ";
    }
}

/**
 * @brief find3Numbers()
 * @param A - array
 * @param arr_size - size of the array
 * @param sum - Sum of the triplet provided
 * 
 * @return triplet vector 
 * 
 * Sort the array - Use quicksort funtion for that. 
 * Note: I could have used std::sort function to sort the array by passing it as a reference. But I decided not to go with it and rather have my own sort function 
 * 
 * a+b+c=sum
 * Naive approach would be using 3 loops to find the triplet. But thats a Brute force approach and would consume more resources for large cases.
 * So I have reduced it to 2 loops
 * a+b=sum-c
 * Only when this condtion is true add the array elements of the respective index to the triplet vector
 * Decrement z only if the sum of A[i],A[j],A[z] is greater than the given sum.
 * Return the triplet vector
 * 
 */
vector<int> find3Numbers(int *A, int arr_size,int sum)
{
    vector<int> triplet;
    //sort the array
    quickSort(A,0,arr_size-1);
   
   //use a two pointer approach to 
    for(int i=0;i<arr_size-2;i++)
    {
        int z = arr_size-1;
        for(int j=i+1;j<arr_size-1;j++)
        {
                
                if(A[i]+A[j]==sum-A[z])
                {
                    triplet.push_back(A[i]);
                    triplet.push_back(A[j]);
                    triplet.push_back(A[z]);
                }
                if(A[i]+A[j]+A[z]>sum)
                    z--;
            
        }
    }
    return triplet;
}



int main()
{
    int A[] = { 1, 2, 3,4,5};
    
    int sum = 8;
    int arr_size = sizeof(A) / sizeof(A[0]);
    vector<int> triplet;
    triplet=find3Numbers(A, arr_size, sum);
    
    if(triplet.size()==0)
        cout<<"There is no triplet in the array whose sum is equal to:"<<sum<<endl;
    
    //display the elements in the triplet vector 
    for(const auto i: triplet)
        cout<<i<<" ";
    
    return 0;
}
