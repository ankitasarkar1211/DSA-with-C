#include<stdio.h>

void delete(int nums[],int del,int n);

int main(){
  int n,nums[100],del;
  printf("Enter no. of elements: ");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(int i=0;i<n;i++)
    scanf("%d",&nums[i]);
  printf("Array before deletion:\n");
  for(int i=0;i<n;i++)
    printf("%d ",nums[i]);

  printf("\nEnter the index of the element to delete: ");
  scanf("%d",&del);

  delete(nums,del,n);

  printf("Array after deletion:\n");
  for(int i=0;i<n-1;i++)
    printf("%d ",nums[i]);

  return 0;

}
void delete(int nums[],int del,int n){
  nums[del]=-1;
  int i=del;
  while(i<n-1){
    nums[i]=nums[i+1];
    i++;
  }
}