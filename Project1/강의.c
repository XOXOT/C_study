#include <stdio.h>

int main(void)
{
	////������ ������ ���� ���� =%d
	//int age = 12; /*int�κ��� �ڷ����� ���� �κ� age�� ������, 12�� �� ��*/
	//	printf("%d\n", age); 
	//	age = 13;
	//	printf("%d\n", age);

	////�Ǽ��� ������ ���� ���� =%f, %lf
	//float f = 46.5;
	//printf("%.2f\n", f);
	//double d = 4.428;
	//printf("%.2lf\n", d);

	////����� ���� ���� = const
	//int YEAR = 2000; �̷��� �ϸ�
	//YEAR = 3000 �ع����� �ٲ�ϱ� ����ó�� �ٲ� ����� ����� ���� �빮�� ������ ���
	//const int YEAR = 2000; /*const�� ����*/
	//printf("�¾  �⵵: %d\n", YEAR);

	////printf�� ���� ����
	//����
	//int add = 3 + 7; /*���� ��� �� add ������ 10�� �� */
	//printf("3 + 7 = %d\n", add);
	//printf("%d * %d = %d\n", 3, 7, 3*7);

	////scanf�� ���� ����
	//Ű���� �Է��� �޾Ƽ� ����

	//���ڸ� Ȱ���� ����1
	//int input;
	//printf("���� �Է��ϼ���:");
	//scanf("%d", &input); //input�տ� &�� input�̶�� ������ ���ǵ� ���� ���� �Է� �޴´ٴ� �ǹ�
	//printf("�Է°�:%d\n",input);

	//���ڸ� Ȱ���� ����2
	//int one, two, three;
	//printf("3���� ������ �Է��ϼ��� :");
	//scanf("%d %d %d", &one, &two, &three);
	//printf("ù��° ��: %d\n", one);
	//printf("�ι�° ��: %d\n", two);
	//printf("����° ��: %d\n", three);

	//���ڸ� Ȱ���� ����
	//����(�� ����)=%c, ���ڿ�(�� ���� �̻��� ���� ����)=%s
	//char c = 'A';
	//printf("%c\n", c);

	//char str[256]; //���ȣ�� �迭�ν� �켱 ���� 256���� �߸���ٴ� �ǹ̷� ���߿� �ٽ� ���
	//scanf("%s", str, sizeof(str)); //scanf���� ���ڴ� ���� &�� ǥ�ø� ������ ������ sizeof�� �Ἥ ���� ������ ������� ���⼭�� strũ�� ��ŭ ����
	//printf("%s\n", str);

	//������Ʈ
	//�������� �������� ������ �Լ� (���� �ۼ�)
	//�̸�? ����? ������? Ű? ���˸�?
	
	//1. �̸�
	char name[256];
	printf("����� �̸���?");
	scanf("%s", name, sizeof(name));

	//2. ����
	int age;
	printf("����� ���̴�?");
	scanf("%d", &age);

	//3. ������
	float weight;
	printf("����� �����Դ�?");
	scanf("%f", &weight);

	//4. Ű
	double height;
	printf("����� Ű��?");
	scanf("%lf", &height);

	//5. ���˸�
	char what[256];
	printf("����� ���˸���?");
	scanf("%s", what,sizeof(what));

	//6. ���� ���� ��� 
	printf("\n\n-----������ ����-----\n\n");
	printf("�̸�            : %s\n", name);
	printf("����            : %d\n", age);
	printf("������          : %.2f\n", weight);
	printf("Ű              : %.2lf\n", height);
	printf("���˸�          : %s\n", what);

	return 0;
}
//�ڷ����̶� ������ �Ǽ��� ������ �� ���� �ڷ� ���¸� ��Ÿ��
//���� ���ϴ� �� 
//��� ������ �ʴ� ��
//���� -1,0,1,-2 �Ҽ����� ���� ��
//�Ǽ� -.2.0, 1.3 �Ҽ����� ���� ��