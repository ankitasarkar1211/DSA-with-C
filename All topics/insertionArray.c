#include<stdio.h>

void insert(int nums[],int val,int idx,int n);

int main(){
  int n,nums[100],idx,val;
  printf("Enter no. of elements: ");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(int i=0;i<n;i++)
    scanf("%d",&nums[i]);
  printf("Array before insertion:\n");
  for(int i=0;i<n;i++)
    printf("%d ",nums[i]);

  printf("\nEnter the element to insert: ");
  scanf("%d",&val);
  printf("\nEnter the index where you want to insert the element: ");
  scanf("%d",&idx);

  insert(nums,val,idx,n);

  printf("Array after insertion:\n");
  for(int i=0;i<n+1;i++)
    printf("%d ",nums[i]);

  return 0;

}

void insert(int nums[],int val,int idx,int n){
  int i=n+1,j=idx;
  while(i>idx){
    nums[i]=nums[i-1];
    i--;
  }
  nums[idx]=val;
}