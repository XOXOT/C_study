#include <stdio.h>
 

int sum(int size, int arr[][10]) // ����
{
 int i,j;
 for(i=0;i<=size;i++)
 {
 for(j=0;j<=2;j++)
 arr[i][3] += arr[i][j];
 }
 return 0;
}
 
int avg(int size, int arr[][10]) // ���
{
 int i;
 for(i=0;i<=size;i++)
 {
   arr[i][4] = arr[i][3]/3; 
 }
 return 0;
}
 
int main()
{
 char name[6][10]={0};
 int arr[6][10]={0};
 int i,j,k;
 int size =2;
 
 for(i=0;i<=size;i++) //�Է� �Լ�
 {
  printf("�л��� �̸��� �Է��ϼ���\n");
  scanf("%s", name[i]);
  printf("�л��� ���� ���� ���� ������ �Է��ϼ���\n");
  for(j=0;j<=2;j++)
  {
  
     scanf("%d", &arr[i][j]);
  
  }
 } 
 sum(size,arr); //����  
 avg(size,arr); // ���
 
 for(i=0; i<=size ; i++) // ���� ���ϱ�
 {
 if(arr[i][4]>=90)
  arr[i][5] ='A';
 else if(arr[i][4]>=80)
  arr[i][5] ='B';
 else if(arr[i][4]>=70)
  arr[i][5] ='C';
 else if(arr[i][4]>=60)
  arr[i][5] ='D';
 else
  arr[i][5] ='F';
 }
  
 for(i=0;i<=size;i++){//�ʱ�ȭ �ض�.
  arr[i][6] =1;
 }
 for(i=0;i<=size;i++) // ���� ���ϱ�
 {

  for(k=i+1; k<=size; k++){
   if(arr[i][3] > arr[k][3]){
    arr[k][6] +=1;}
   else if(arr[i][3] < arr[k][3]){
    arr[i][6] +=1;}
   else{
    arr[i][6] +=0;
       arr[k][6] +=0;
   }
   
  }
 }
 
 printf("�̸�  ����  ����   ����   ����   ���  ����  ����   ���� ����   ���� ���\n"); 
 
for(i=0 ; i<=size; i++)  // �� ���� ���
 {
  printf("%s",name[i]);
  for(j=0;j<=4;j++){
   printf("%d " , arr[i][j]);
  }
     printf("%c ",arr[i][5]);
        printf("%d ",arr[i][6]);
  
 printf("\n");
 }

 return 0;
}