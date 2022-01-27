#include <stdio.h>
 

int sum(int size, int arr[][10]) // 총점
{
 int i,j;
 for(i=0;i<=size;i++)
 {
 for(j=0;j<=2;j++)
 arr[i][3] += arr[i][j];
 }
 return 0;
}
 
int avg(int size, int arr[][10]) // 평균
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
 
 for(i=0;i<=size;i++) //입력 함수
 {
  printf("학생의 이름을 입력하세요\n");
  scanf("%s", name[i]);
  printf("학생의 국어 영어 수학 점수를 입력하세요\n");
  for(j=0;j<=2;j++)
  {
  
     scanf("%d", &arr[i][j]);
  
  }
 } 
 sum(size,arr); //총합  
 avg(size,arr); // 평균
 
 for(i=0; i<=size ; i++) // 학점 구하기
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
  
 for(i=0;i<=size;i++){//초기화 해라.
  arr[i][6] =1;
 }
 for(i=0;i<=size;i++) // 석차 구하기
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
 
 printf("이름  국어  영어   수학   총점   평균  학점  석차   과목별 총점   과목별 평균\n"); 
 
for(i=0 ; i<=size; i++)  // 각 값을 출력
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