#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>

#define MAX_NAME_LENGTH			16					// �̸��� �ִ� ����(1����Ʈ ���ĺ� ����)
#define MAX_MEMBERS				100					// ����� �ִ� ��
#define MAX_SUBJECT				5					// ���� ��
#define MAX_SUBJECT_NAME_LEN	32					// ������� �ִ� ����

#define NOUSE_INDEX				-1					// ������ �ʴ� �ε����� �ǹ�
#define FINAL_INDEX				MAX_MEMBERS-1		// ������ �ε���

typedef struct {
	int		unique_index;							// �迭���� �� ����ü�� ���° �׸����� �˷��ִ� �ĺ��� �ε���
	char	name[MAX_NAME_LENGTH+1]	;				// �̸�
	int		score[MAX_SUBJECT];						// ����
} MEMBER_INFO;

char g_subject[MAX_SUBJECT][MAX_SUBJECT_NAME_LEN] = {"����","����","����","����","��ȸ"};	// ����� �ʱ�ȭ


MEMBER_INFO	g_arrayMember[MAX_MEMBERS];				// ������� �迭
int			g_memberCount;							// ���� ���Ե� ����� ��

void	ManagerMenu();								// ���� �޴�
void	ExitProgram();								// ����
void	ClearScreen();								// ȭ�� Ŭ����

void	Initialize();								// �ʱ�ȭ
int		AddMember();								// ��� ���
int		RemoveMember(int nIndex);					// ��� ����
int		EditMemberInfo(int nIndex);					// ��� ���� ����
int		SearchMember();								// ID�� ����� �迭 �ε��� ����
int		IsExistName(char* pName);
void	ShowAllMember();							// ��� ��� ������ ���

int		GetMsg(char* pMsg);							// Ű����κ��� ���ڿ� �Է¹���
void 	InputName(MEMBER_INFO* pInfo);				// �̸� �Է�
void	InputScore(MEMBER_INFO* pInfo);				// ���� �Է�
int		GetUnusedIndex();							// ���� �������(�迭)���� �̻������ �ε����� ����

int		ReadMemberData();							// ���Ͽ� ����
int		WriteMemberData();							// ���Ͽ��� �ε�

void	SortByName();								// �̸����� ����
void	SortByScore();								// ������ ����
int		TotalSum(int nIndex);						// �ε����� �ش��ϴ� ����� ������ ����

// ���� ó�� 
void ExitProgram()
{
	ClearScreen();											// ȭ���� �����
	printf(" �̿����ּż� �����մϴ�!  \n");					// �޼��� ���� ��
	getchar();
	exit(0);												// ���α׷��� ��� ���� ó��
}

// ȭ���� ����� �Լ� 
void ClearScreen()
{
	system("cls");				//-> ������ ����϶�
	//system("clear");			//->������ ����϶�
}


void Initialize()
{
	int i;

	g_memberCount = 0;                                      // ����� 0���� �ʱ�ȭ 
	for(i = 0; i<MAX_MEMBERS ; i++)                         // �ִ� ��� �� ��ŭ �ݺ�    
	{
		memset(&g_arrayMember[i], 0, sizeof(MEMBER_INFO));  // ����ü�� ��°�� 0���� �ʱ�ȭ �� ��
		g_arrayMember[i].unique_index = NOUSE_INDEX;        // �ε������� ������� �ʴ� �ε����� �ǹ̷� -1�� ��ŷ
	}

}

int GetMsg(char* pMsg)
{
	if(gets(pMsg) == 0)
	{
		printf(" -> �Էµ� ������ �����ϴ�\n");
		return 0;
	}
	if(strlen(pMsg) <= 0)
	{
		printf(" -> �Էµ� ������ �����ϴ�\n");
		return 0;
	}

	if(pMsg[0] =='q' || pMsg[0] =='Q')						// 'q'�� �ԷµǾ��� ��� 
		ExitProgram();										// ���� �Լ� ȣ��
	return 1;
}

void InputName(MEMBER_INFO* pInfo)
{
	char temp[256];

	while(1)															// �̸� �Է�
	{
		printf(" �̸��� �Է����ּ��� :");
		if(!GetMsg(temp))												// temp�� �Ķ���ͷ� Ű���� �Է� �Լ� ȣ��
			continue;
		if(IsExistName(temp) >= 0)										// 0�̻��� ���ϵǸ� �������� �ǹ�
		{
			printf(" �̹� �����ϴ� �̸��Դϴ�.\n");
			continue;
		}
		if(strlen(temp) > MAX_NAME_LENGTH)
		{
			printf(" -> �̸��� �ʹ� ��ϴ� (�ѱ� �ִ� 8��, ���� 16��).\n");
			continue;
		}
	
		strcpy(pInfo->name, temp);										// �̸� ����
		break;
	}
}

void InputScore(MEMBER_INFO* pInfo)
{
	char temp[256];
	int i;
	for(i=0 ; i< MAX_SUBJECT ; i++)
	{
		while(1)															// �̸� �Է�
		{
			printf(" %s ������ �Է����ּ��� :", g_subject[i]);
			if(!GetMsg(temp))												// temp�� �Ķ���ͷ� Ű���� �Է� �Լ� ȣ��
				continue;
			if(atoi(temp) < 0 || atoi(temp)>100)							// ������ ��ȯ�� temp�� ������ ������ ����ִ���
			{
				printf(" -> ���� ������ �߸��Ǿ����ϴ� (0 ~ 100).\n");
				continue;
			}
	
			pInfo->score[i] = atoi(temp);										// ���� ����
			break;
		}
	}

}

int GetUnusedIndex()
{
	int i;

	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)			// ������ ���� �ε��� ��ȯ
			return i;
	}

	return NOUSE_INDEX;												// ����Ҽ� �ִ� �ε����� ����.
}

int IsExistName(char* pName)
{
	int i;

	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)			// �̻������ �ε������
			continue;												// �н�
		if(strcmp(g_arrayMember[i].name, pName) == 0)				// ��ġ�ϴ� �̸��� �����ϸ�
			return 1;												// 1�� ����
	}

	return -1;
}


void ShowAllMember()
{
	int i,j;
	int count;
	
	count = 0;
	ClearScreen();
	printf("[���� ���] \n");
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)
			continue;
		printf("[%3d]%-16s ", i+1, g_arrayMember[i].name);					// �̸� ���
		for(j=0 ; j<MAX_SUBJECT ; j++)
			printf("%s:%3d ",g_subject[j], g_arrayMember[i].score[j]);		// ���񺰷� ���� ���
		count++;
		printf(" ����:%3d\n",TotalSum(i));														// ������ �����
	}
	printf("�� ���� : %d  <�ƹ�Ű�� �����ּ���!!>", count);
	getchar();
}


int AddMember()
{
	MEMBER_INFO tempInfo;			// �ӽ� ����ü ����
	int index;						// ���� �Ҵ� ���� �ε���i

	printf("[���� ���� �߰�]\n\n");

	index = GetUnusedIndex();		// ���ο� ���� ����(�ε���) �Ҵ����
	tempInfo.unique_index = index;	// �ε��� �ӽ� ����ü�� ����
	InputName(&tempInfo);			// �̸� �Է¹޾� �ӽ� ����ü�� ����
	InputScore(&tempInfo);			// ���� �Է¹޾� �ӽ� ����ü�� ����
	memcpy(&g_arrayMember[index], &tempInfo, sizeof(MEMBER_INFO)); // ������ �ο����� �迭 �ε����� �����Ͽ� �ӽ� ����ü�� ���� ���� �迭�� ����
	g_memberCount++;				// �� ����� 1 ����
	printf(" ���� ������ �߰��Ǿ����ϴ�.\n");
	getchar();
	return 1;
}

// ���� ����. �ϴ��� ����� ��.
int RemoveMember(int nIndex)
{
	char temp[256];

	printf("[���� ���� ����]\n\n");

	printf(" ���� ������ ���Ͻʴϱ�? (y):");
	GetMsg(temp);
	if(temp[0] !='y' && temp[0]!='Y')									// �ٽ� �ѹ� Ȯ�� ����
	{
		printf(" ���θ޴��� ���ư��ϴ�.\n");
		getchar();
		return 0;
	}

	printf(" %s �� ������ �����Ǿ����ϴ�.\n", g_arrayMember[nIndex].name);		
	memset(&g_arrayMember[nIndex], 0, sizeof(MEMBER_INFO));					// �־��� �ε����� ����ü �ʱ�ȭ
	g_arrayMember[nIndex].unique_index = NOUSE_INDEX;						// �ε����� ����������
	g_memberCount--;														// �� ����� ����

	getchar();
	return 1;
}

int SearchMember()
{
	char temp[256];
	int nResult;

	while(1)
	{
		printf(" -> �̸��� �Է����ּ��� :");
		GetMsg(temp);
			
		nResult = IsExistName(temp);									// �����ϴ� �̸��̶�� ������� �迭�� �ε���
		if(nResult>=0)													// �ε����� 0�̻��̸�
			return nResult;												// �״�� ����

		printf(" �ش� �̸��� �������� �ʽ��ϴ�..!\n");	
		getchar();	
		return nResult;													// �׷��� �ʴٸ� ������ ���Ѱ��̹Ƿ� -1�� ���ϵ�
	}

	return NOUSE_INDEX;	
}

int TotalSum(int nIndex)
{
	int i;
	int sum = 0;														// �հ� �ʱ�ȭ
	for(i=0 ; i< MAX_SUBJECT ; i++)
		sum = sum + g_arrayMember[nIndex].score[i];						// �迭�� ����� ������ ���� ���س�����.

	return sum;
}


void SortByScore()
{
	int i,j, count;
	MEMBER_INFO list[MAX_MEMBERS];						// �ӽ� ���� �غ�
	MEMBER_INFO temp;

	count = 0;
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index != NOUSE_INDEX)				// �ε����� ������ ��, �� ������̶��
		{
			memcpy(&list[i], &g_arrayMember[i], sizeof(MEMBER_INFO));	// �ش� ����ü�� ���ο� �迭 list�� ����
			count++;																
		}
	}

	// ���� �������� ���� ���� 
	for(i=0 ; i< count-1; i++)											
	{
		for(j=i+1; j< count ; j++)										
		{
			if(TotalSum(i) < TotalSum(j))								// i��° ����������� j��° ����� ������ ��� ���Ͽ� j�� Ŭ��� �¹ٲ۴�.
			{
				memcpy(&temp, &list[i], sizeof(MEMBER_INFO));			// �ӽ� ����ü�� i��° ������ ����ϰ� 
				memcpy(&list[i], &list[j], sizeof(MEMBER_INFO));		// i��°�� j��° ������ ���
				memcpy(&list[j], &temp, sizeof(MEMBER_INFO));			// �ٽ� j��°�� �ӽ� ����ü�� ����س��Ҵ� i��° ������ ���
			}
		}
	}

		memcpy(g_arrayMember, &list, sizeof(MEMBER_INFO)*count);		// list �迭�� ������ g_arrayMember �迭�� ���� (����� �ݿ�)

	printf(" ����(��������)���� ������ �Ϸ� �Ǿ����ϴ�..!\n");
	getchar();
}

void SortByName()
{
	int i,j, count;
	MEMBER_INFO list[MAX_MEMBERS];						// �ӽ� ���� �غ�
	MEMBER_INFO temp;

	count = 0;
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index != NOUSE_INDEX)				// �ε����� ������ ��, �� ������̶��
		{
			memcpy(&list[i], &g_arrayMember[i], sizeof(MEMBER_INFO));	// �ش� ����ü�� ���ο� �迭 list�� ����
			count++;
		}
	}

	// ���� �������� ���� ���� 
	for(i=0 ; i< count-1; i++)											
	{
		for(j=i+1; j< count ; j++)										
		{
			if(strcmp(list[i].name, list[j].name) > 0 )					// ���ڿ� �񱳴� strcmp�Լ��� ���
			{
				memcpy(&temp, &list[i], sizeof(MEMBER_INFO));			// �ӽ� ����ü�� i��° ������ ����ϰ� 
				memcpy(&list[i], &list[j], sizeof(MEMBER_INFO));		// i��°�� j��° ������ ���
				memcpy(&list[j], &temp, sizeof(MEMBER_INFO));			// �ٽ� j��°�� �ӽ� ����ü�� ����س��Ҵ� i��° ������ ���
			}
		}
	}

		memcpy(g_arrayMember, &list, sizeof(MEMBER_INFO)*count);		// list �迭�� ������ g_arrayMember �迭�� ���� (����� �ݿ�)

	printf(" ������ ������ ������ �Ϸ� �Ǿ����ϴ�..!\n");
	getchar();
}


void ManagerMenu()
{
	char temp[256];
	int i;
	

	ClearScreen();
	printf(" ============================== \n");
	printf("    ���� ���� �ý���   \n");
	printf(" ============================== \n");
	printf(" =  ���� ��ϵ� ���� ���� : %2d  = \n",g_memberCount);
	printf(" ------------------------------ \n");
	printf(" 1. ���� (�̸�/����) �߰� \n");
	printf(" 2. ���� �˻� �� ����\n");
	printf(" 3. ���� ����\n");
	printf(" 4. ����\n");
	printf(" 5. �ҷ�����\n");
	printf(" 6. ������ ����(�̸�)\n");
	printf(" 7. ���� ����(����)\n");
	printf(" 8. ���� ��� ���\n");
	printf(" -> ���ϴ� ����� �Է����ּ���(q:��𼭳� ��� ����) :");
	GetMsg(temp);
	i = atoi(temp);
	switch(i)
	{
	case 1:
		{
			AddMember();						// ���(�л�) �߰� �Լ� ȣ��
		}
		break;
	case 2:
		{
            int nMemberIndex;
            nMemberIndex = SearchMember();		// ����� �ε����� ���� ���ϴ� �Լ�
            if(nMemberIndex>=0)					// �����ϸ� �ε����� 0�̻��̹Ƿ�
                InputScore(g_arrayMember+nMemberIndex);	// ��� ���� �����ϴ� �Լ��� ȣ��
		}
		break;
	case 3:
		{
            int nMemberIndex;
            nMemberIndex = SearchMember();		// ����� �ε����� ���� ���ϴ� �Լ�
            if(nMemberIndex>=0)					// �����ϸ� �ε����� 0�̻��̹Ƿ�
                RemoveMember(nMemberIndex);		// ��� ������ �����ϴ� �Լ��� ȣ��
		}
		break;
	case 4:
		{
			WriteMemberData();					// ���Ϸ� ����
		}
		break;
	case 5:
		{
			Initialize();						// ���� ���� ������ ��� �ʱ�ȭ�ϰ�
			ReadMemberData();					// ���Ͽ��� �о����
		}
		break;
	case 6:
		{
			SortByName();						// ���� ���� �̸������� ����
		}
		break;
	case 7:
		{
			SortByScore();						// ���� ���� ���� ������ ����(��������)
		}
		break;
	case 8:
		{
			ShowAllMember();					// ���� ���� ���
		}
		break;


	}
}

// ���� ��� ����ü. ���Ͽ� ����� ��� ������ ������� �˷��ִ� ������ �Ѵ�.
typedef struct
{
	char	szDesc[64];
	int		nVersion;
	int		nCount;
} FILE_HEADER;

#define HEADER_TITLE	"MemberInfomationList"	// ���ϸ� ����
#define HEADER_VERSION	10						// ���� ��� (��ǻ� ���ǹ�)

int WriteMemberData()
{
	FILE* f;
	FILE_HEADER header;
	int i;

	f = fopen("memberdata.dat", "wb");			// ������ ���� �� ���� ���� ����
	if(f == 0)
	{
		printf(" can't file create \n");
		fclose(f);
		return 0;
	}
	else
	{
		strcpy(header.szDesc, HEADER_TITLE);	// ��� Ÿ��Ʋ
		header.nVersion = HEADER_VERSION;		// ����
		header.nCount = g_memberCount;			// �л� ��

		fwrite(&header, sizeof(FILE_HEADER), 1, f); // ������ ���� ����� ���� ����ϰ�
		for(i=0 ; i<MAX_MEMBERS ; i++)				// �迭�� ���ʴ�� ��ȸ�ϸ鼭
		{
			if(g_arrayMember[i].unique_index == NOUSE_INDEX)		// ���� ������� �迭�� �ƴϸ� �н�
				continue;
			fwrite(&g_arrayMember[i], sizeof(MEMBER_INFO), 1, f);	// ������̸� ����
		}
	}
	fclose(f);

	printf(" saved member data.\n");

}

// ���� �ε�� ����� ������ ������� �۾��ϵ�, ���� ��� �д� ������ �̷������.
int ReadMemberData()
{
	FILE* f;
	FILE_HEADER header;
	int i, nCount;
	MEMBER_INFO tempInfo;

	f = fopen("memberdata.dat", "rb");
	if(f == 0)
	{
		printf(" can't file open\n");
		return 0;
	}
	else
	{
		fread(&header, sizeof(FILE_HEADER), 1,f);
		if(strcmp(header.szDesc, HEADER_TITLE) != 0 || header.nVersion != HEADER_VERSION)
		{
			printf("invalid header file. can't read member data.\n");
			fclose(f);
			return 0;
		}

		nCount = header.nCount;					// ����� ��ϵ� ����ŭ
		for(i=0 ; i< nCount; i++)				// ������ ����
		{
			fread(&tempInfo, sizeof(MEMBER_INFO), 1, f);		// ���Ͽ��� �о���̰�
			memcpy(&g_arrayMember[tempInfo.unique_index], &tempInfo, sizeof(MEMBER_INFO)); // �迭�� �����Ѵ�
			g_memberCount++;
		}

		printf(" loaded member data.\n");
	}
	fclose(f);

}

int main()
{
	Initialize();					// ���� ���� �ʱ�ȭ 

	while(1)
	{
        ManagerMenu();              // ���� �޴� ȣ�� 
	}

	getch();
	return 0;
}