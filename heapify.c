#include <stdio.h>

void swap(int *a, int *b);
void heapify(int arr[],int *size,int i);
void insert(int arr[],int newNum,int *size);
void delete(int arr[],int del,int *size);
void print(int arr[],int *size);

int main(){
  int arr[100],n,i,del,size=0;
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    insert(arr,arr[i],&size);
  }
  printf("Heapified array is:\n");
  print(arr,&size);

  printf("\nEnter a element to delete: ");
  scanf("%d",&del);
  delete(arr,del,&size);

  printf("New heapified array is:\n");
  print(arr,&size);

  return 0;
}
void swap(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
void heapify(int arr[],int *size,int i){
  if(*size==1)
    printf("Only one element in the array\n");
  else{
    int largest=i;
    int leftIndex=2*i+1;
    int rightIndex=2*i+2;

    if(leftIndex<*size && arr[leftIndex]>arr[largest]){
      swap(&arr[leftIndex],&arr[largest]);
      largest=leftIndex;
      heapify(arr,size,largest);
    }
    else if(rightIndex<*size && arr[rightIndex]>arr[largest]){
      swap(&arr[rightIndex],&arr[largest]);
      largest=rightIndex;
      heapify(arr,size,largest);
    }
  }
}
void insert(int arr[],int newNum,int *size){
  if(*size==0){
    arr[*size]=newNum;
    (*size)++;
  }
  else{
    arr[*size]=newNum;
    (*size)++;
  }
  for(int i=(*size/2)-1;i>=0;i--){
    heapify(arr,size,i);
  }
}
void delete(int arr[],int del,int *size){
  int delIndex=-1;
  for(int i=0;i<*size;i++){
    if(arr[i]==del){
      delIndex=i;
      break;
    }
  }
  if(delIndex==-1){
    printf("Element not found\n");
  }
  else{
    if(delIndex!=*size-1){
      swap(&arr[delIndex],&arr[*size-1]);
    }
    (*size)--;
  }
  for(int i=(*size/2)-1;i>=0;i--){
    heapify(arr,size,i);
  }
  
}
void print(int arr[],int *size){
  for(int i=0;i<*size;i++)
    printf("%d ",arr[i]);
}