#include <stdio.h>
#define size 5

int arr[size];
void input();
void insert(int value);
void search(int value);
void delete(int value);
void printAll();

int main(){
  int num, del, find;
  input();

  printf("Enter %d values:\n", size);
  for(int i = 0; i < size; i++){
    scanf("%d", &num);
    insert(num);
  } 

  printf("Enter an element to search: ");
  scanf("%d", &find);
  search(find);

  printf("Enter an element to delete: ");
  scanf("%d", &del);
  delete(del);

  printf("All the elements are:\n");
  printAll();

  return 0;
}

void input(){
  for(int i = 0; i < size; i++)
    arr[i] = -1;
}

void insert(int value){
  int key = value % size;
  if(arr[key] == -1)
    arr[key] = value;
  else
    printf("Position %d already filled with %d\n", key, arr[key]);
}

void search(int value){
  int key = value % size;
  if(arr[key] == value)
    printf("Found at position %d\n", key);
  else
    printf("Not found\n");
}

void delete(int value){
  int key = value % size;
  if(arr[key] == value)
    arr[key] = -1;
  else
    printf("Element not found\n");
}

void printAll(){
  for(int i = 0; i < size; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
}