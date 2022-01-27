#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>

#define MAX_NAME_LENGTH			16					// 이름의 최대 길이(1바이트 알파벳 기준)
#define MAX_MEMBERS				100					// 멤버의 최대 수
#define MAX_SUBJECT				5					// 과목 수
#define MAX_SUBJECT_NAME_LEN	32					// 과목명의 최대 길이

#define NOUSE_INDEX				-1					// 사용되지 않는 인덱스란 의미
#define FINAL_INDEX				MAX_MEMBERS-1		// 마지막 인덱스

typedef struct {
	int		unique_index;							// 배열에서 이 구조체가 몇번째 항목인지 알려주는 식별용 인덱스
	char	name[MAX_NAME_LENGTH+1]	;				// 이름
	int		score[MAX_SUBJECT];						// 점수
} MEMBER_INFO;

char g_subject[MAX_SUBJECT][MAX_SUBJECT_NAME_LEN] = {"국어","수학","영어","물리","사회"};	// 과목명 초기화


MEMBER_INFO	g_arrayMember[MAX_MEMBERS];				// 멤버정보 배열
int			g_memberCount;							// 현재 가입된 사용자 수

void	ManagerMenu();								// 메인 메뉴
void	ExitProgram();								// 종료
void	ClearScreen();								// 화면 클리어

void	Initialize();								// 초기화
int		AddMember();								// 멤버 등록
int		RemoveMember(int nIndex);					// 멤버 삭제
int		EditMemberInfo(int nIndex);					// 멤버 정보 수정
int		SearchMember();								// ID로 멤버의 배열 인덱스 얻어옴
int		IsExistName(char* pName);
void	ShowAllMember();							// 모든 멤버 정보를 출력

int		GetMsg(char* pMsg);							// 키보드로부터 문자열 입력받음
void 	InputName(MEMBER_INFO* pInfo);				// 이름 입력
void	InputScore(MEMBER_INFO* pInfo);				// 점수 입력
int		GetUnusedIndex();							// 현재 저장공간(배열)에서 미사용중인 인덱스를 리턴

int		ReadMemberData();							// 파일에 저장
int		WriteMemberData();							// 파일에서 로드

void	SortByName();								// 이름으로 정렬
void	SortByScore();								// 점수로 정렬
int		TotalSum(int nIndex);						// 인덱스에 해당하는 멤버의 총점을 구함

// 종료 처리 
void ExitProgram()
{
	ClearScreen();											// 화면을 지우고
	printf(" 이용해주셔서 감사합니다!  \n");					// 메세지 찍은 후
	getchar();
	exit(0);												// 프로그램을 즉시 종료 처리
}

// 화면을 지우는 함수 
void ClearScreen()
{
	system("cls");				//-> 윈도우 기반일때
	//system("clear");			//->리눅스 기반일때
}


void Initialize()
{
	int i;

	g_memberCount = 0;                                      // 멤버수 0으로 초기화 
	for(i = 0; i<MAX_MEMBERS ; i++)                         // 최대 멤버 수 만큼 반복    
	{
		memset(&g_arrayMember[i], 0, sizeof(MEMBER_INFO));  // 구조체를 통째로 0으로 초기화 한 후
		g_arrayMember[i].unique_index = NOUSE_INDEX;        // 인덱스값을 사용하지 않는 인덱스란 의미로 -1로 마킹
	}

}

int GetMsg(char* pMsg)
{
	if(gets(pMsg) == 0)
	{
		printf(" -> 입력된 내용이 없습니다\n");
		return 0;
	}
	if(strlen(pMsg) <= 0)
	{
		printf(" -> 입력된 내용이 없습니다\n");
		return 0;
	}

	if(pMsg[0] =='q' || pMsg[0] =='Q')						// 'q'가 입력되었을 경우 
		ExitProgram();										// 종료 함수 호출
	return 1;
}

void InputName(MEMBER_INFO* pInfo)
{
	char temp[256];

	while(1)															// 이름 입력
	{
		printf(" 이름을 입력해주세요 :");
		if(!GetMsg(temp))												// temp를 파라메터로 키보드 입력 함수 호출
			continue;
		if(IsExistName(temp) >= 0)										// 0이상이 리턴되면 존재함을 의미
		{
			printf(" 이미 존재하는 이름입니다.\n");
			continue;
		}
		if(strlen(temp) > MAX_NAME_LENGTH)
		{
			printf(" -> 이름이 너무 깁니다 (한글 최대 8자, 영문 16자).\n");
			continue;
		}
	
		strcpy(pInfo->name, temp);										// 이름 저장
		break;
	}
}

void InputScore(MEMBER_INFO* pInfo)
{
	char temp[256];
	int i;
	for(i=0 ; i< MAX_SUBJECT ; i++)
	{
		while(1)															// 이름 입력
		{
			printf(" %s 점수를 입력해주세요 :", g_subject[i]);
			if(!GetMsg(temp))												// temp를 파라메터로 키보드 입력 함수 호출
				continue;
			if(atoi(temp) < 0 || atoi(temp)>100)							// 정수로 변환한 temp가 적정한 범위에 들어있는지
			{
				printf(" -> 점수 범위가 잘못되었습니다 (0 ~ 100).\n");
				continue;
			}
	
			pInfo->score[i] = atoi(temp);										// 점수 저장
			break;
		}
	}

}

int GetUnusedIndex()
{
	int i;

	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)			// 사용되지 않은 인덱스 반환
			return i;
	}

	return NOUSE_INDEX;												// 사용할수 있는 인덱스가 없음.
}

int IsExistName(char* pName)
{
	int i;

	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)			// 미사용중인 인덱스라면
			continue;												// 패스
		if(strcmp(g_arrayMember[i].name, pName) == 0)				// 일치하는 이름이 존재하면
			return 1;												// 1을 리턴
	}

	return -1;
}


void ShowAllMember()
{
	int i,j;
	int count;
	
	count = 0;
	ClearScreen();
	printf("[성적 출력] \n");
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index == NOUSE_INDEX)
			continue;
		printf("[%3d]%-16s ", i+1, g_arrayMember[i].name);					// 이름 찍고
		for(j=0 ; j<MAX_SUBJECT ; j++)
			printf("%s:%3d ",g_subject[j], g_arrayMember[i].score[j]);		// 과목별로 점수 찍고
		count++;
		printf(" 총점:%3d\n",TotalSum(i));														// 총점도 찍어줌
	}
	printf("총 개수 : %d  <아무키나 눌러주세요!!>", count);
	getchar();
}


int AddMember()
{
	MEMBER_INFO tempInfo;			// 임시 구조체 선언
	int index;						// 새로 할당 받을 인덱스i

	printf("[성적 정보 추가]\n\n");

	index = GetUnusedIndex();		// 새로운 저장 공간(인덱스) 할당받음
	tempInfo.unique_index = index;	// 인덱스 임시 구조체에 저장
	InputName(&tempInfo);			// 이름 입력받아 임시 구조체에 저장
	InputScore(&tempInfo);			// 점수 입력받아 임시 구조체에 저장
	memcpy(&g_arrayMember[index], &tempInfo, sizeof(MEMBER_INFO)); // 위에서 부여받은 배열 인덱스를 참조하여 임시 구조체를 실제 전역 배열에 복사
	g_memberCount++;				// 총 멤버수 1 증가
	printf(" 성적 정보가 추가되었습니다.\n");
	getchar();
	return 1;
}

// 정보 삭제. 일단은 만들어 둠.
int RemoveMember(int nIndex)
{
	char temp[256];

	printf("[성적 정보 삭제]\n\n");

	printf(" 정말 삭제를 원하십니까? (y):");
	GetMsg(temp);
	if(temp[0] !='y' && temp[0]!='Y')									// 다시 한번 확인 절차
	{
		printf(" 메인메뉴로 돌아갑니다.\n");
		getchar();
		return 0;
	}

	printf(" %s 의 성적이 삭제되었습니다.\n", g_arrayMember[nIndex].name);		
	memset(&g_arrayMember[nIndex], 0, sizeof(MEMBER_INFO));					// 주어진 인덱스로 구조체 초기화
	g_arrayMember[nIndex].unique_index = NOUSE_INDEX;						// 인덱스는 사용안함으로
	g_memberCount--;														// 총 멤버수 감소

	getchar();
	return 1;
}

int SearchMember()
{
	char temp[256];
	int nResult;

	while(1)
	{
		printf(" -> 이름을 입력해주세요 :");
		GetMsg(temp);
			
		nResult = IsExistName(temp);									// 존재하는 이름이라면 결과값은 배열의 인덱스
		if(nResult>=0)													// 인덱스가 0이상이면
			return nResult;												// 그대로 리턴

		printf(" 해당 이름은 존재하지 않습니다..!\n");	
		getchar();	
		return nResult;													// 그렇지 않다면 구하지 못한것이므로 -1이 리턴됨
	}

	return NOUSE_INDEX;	
}

int TotalSum(int nIndex)
{
	int i;
	int sum = 0;														// 합계 초기화
	for(i=0 ; i< MAX_SUBJECT ; i++)
		sum = sum + g_arrayMember[nIndex].score[i];						// 배열에 저장된 점수의 합을 구해나간다.

	return sum;
}


void SortByScore()
{
	int i,j, count;
	MEMBER_INFO list[MAX_MEMBERS];						// 임시 공간 준비
	MEMBER_INFO temp;

	count = 0;
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index != NOUSE_INDEX)				// 인덱스가 존재할 때, 즉 사용중이라면
		{
			memcpy(&list[i], &g_arrayMember[i], sizeof(MEMBER_INFO));	// 해당 구조체를 새로운 배열 list에 복사
			count++;																
		}
	}

	// 이하 전형적인 버블 정렬 
	for(i=0 ; i< count-1; i++)											
	{
		for(j=i+1; j< count ; j++)										
		{
			if(TotalSum(i) < TotalSum(j))								// i번째 멤버의총점과 j번째 멤버의 총점을 대소 비교하여 j가 클경우 맞바꾼다.
			{
				memcpy(&temp, &list[i], sizeof(MEMBER_INFO));			// 임시 구조체에 i번째 정보를 기록하고 
				memcpy(&list[i], &list[j], sizeof(MEMBER_INFO));		// i번째에 j번째 정보를 기록
				memcpy(&list[j], &temp, sizeof(MEMBER_INFO));			// 다시 j번째에 임시 구조체에 기록해놓았던 i번째 정보를 기록
			}
		}
	}

		memcpy(g_arrayMember, &list, sizeof(MEMBER_INFO)*count);		// list 배열의 내용을 g_arrayMember 배열에 복사 (결과를 반영)

	printf(" 성적(내림차순)으로 정렬이 완료 되었습니다..!\n");
	getchar();
}

void SortByName()
{
	int i,j, count;
	MEMBER_INFO list[MAX_MEMBERS];						// 임시 공간 준비
	MEMBER_INFO temp;

	count = 0;
	for(i=0 ; i<MAX_MEMBERS ; i++)
	{
		if(g_arrayMember[i].unique_index != NOUSE_INDEX)				// 인덱스가 존재할 때, 즉 사용중이라면
		{
			memcpy(&list[i], &g_arrayMember[i], sizeof(MEMBER_INFO));	// 해당 구조체를 새로운 배열 list에 복사
			count++;
		}
	}

	// 이하 전형적인 버블 정렬 
	for(i=0 ; i< count-1; i++)											
	{
		for(j=i+1; j< count ; j++)										
		{
			if(strcmp(list[i].name, list[j].name) > 0 )					// 문자열 비교는 strcmp함수를 사용
			{
				memcpy(&temp, &list[i], sizeof(MEMBER_INFO));			// 임시 구조체에 i번째 정보를 기록하고 
				memcpy(&list[i], &list[j], sizeof(MEMBER_INFO));		// i번째에 j번째 정보를 기록
				memcpy(&list[j], &temp, sizeof(MEMBER_INFO));			// 다시 j번째에 임시 구조체에 기록해놓았던 i번째 정보를 기록
			}
		}
	}

		memcpy(g_arrayMember, &list, sizeof(MEMBER_INFO)*count);		// list 배열의 내용을 g_arrayMember 배열에 복사 (결과를 반영)

	printf(" 가나다 순으로 정렬이 완료 되었습니다..!\n");
	getchar();
}


void ManagerMenu()
{
	char temp[256];
	int i;
	

	ClearScreen();
	printf(" ============================== \n");
	printf("    성적 관리 시스템   \n");
	printf(" ============================== \n");
	printf(" =  현재 등록된 정보 개수 : %2d  = \n",g_memberCount);
	printf(" ------------------------------ \n");
	printf(" 1. 성적 (이름/점수) 추가 \n");
	printf(" 2. 성적 검색 및 수정\n");
	printf(" 3. 성적 삭제\n");
	printf(" 4. 저장\n");
	printf(" 5. 불러오기\n");
	printf(" 6. 가나다 정렬(이름)\n");
	printf(" 7. 총점 정렬(점수)\n");
	printf(" 8. 점수 목록 출력\n");
	printf(" -> 원하는 기능을 입력해주세요(q:어디서나 즉시 종료) :");
	GetMsg(temp);
	i = atoi(temp);
	switch(i)
	{
	case 1:
		{
			AddMember();						// 멤버(학생) 추가 함수 호출
		}
		break;
	case 2:
		{
            int nMemberIndex;
            nMemberIndex = SearchMember();		// 멤버의 인덱스를 먼저 구하는 함수
            if(nMemberIndex>=0)					// 존재하면 인덱스가 0이상이므로
                InputScore(g_arrayMember+nMemberIndex);	// 멤버 정보 수정하는 함수를 호출
		}
		break;
	case 3:
		{
            int nMemberIndex;
            nMemberIndex = SearchMember();		// 멤버의 인덱스를 먼저 구하는 함수
            if(nMemberIndex>=0)					// 존재하면 인덱스가 0이상이므로
                RemoveMember(nMemberIndex);		// 멤버 정보를 삭제하는 함수를 호출
		}
		break;
	case 4:
		{
			WriteMemberData();					// 파일로 저장
		}
		break;
	case 5:
		{
			Initialize();						// 먼저 현재 정보를 모두 초기화하고
			ReadMemberData();					// 파일에서 읽어오기
		}
		break;
	case 6:
		{
			SortByName();						// 성적 정보 이름순으로 정렬
		}
		break;
	case 7:
		{
			SortByScore();						// 성적 정보 점수 순으로 정렬(내림차순)
		}
		break;
	case 8:
		{
			ShowAllMember();					// 성적 정보 출력
		}
		break;


	}
}

// 파일 헤더 구조체. 파일에 몇명의 멤버 정보가 들었는지 알려주는 역할을 한다.
typedef struct
{
	char	szDesc[64];
	int		nVersion;
	int		nCount;
} FILE_HEADER;

#define HEADER_TITLE	"MemberInfomationList"	// 파일명 지정
#define HEADER_VERSION	10						// 버젼 명시 (사실상 무의미)

int WriteMemberData()
{
	FILE* f;
	FILE_HEADER header;
	int i;

	f = fopen("memberdata.dat", "wb");			// 파일을 쓰기 및 이진 모드로 열고
	if(f == 0)
	{
		printf(" can't file create \n");
		fclose(f);
		return 0;
	}
	else
	{
		strcpy(header.szDesc, HEADER_TITLE);	// 헤더 타이틀
		header.nVersion = HEADER_VERSION;		// 버젼
		header.nCount = g_memberCount;			// 학생 수

		fwrite(&header, sizeof(FILE_HEADER), 1, f); // 위에서 만든 헤더를 먼저 기록하고
		for(i=0 ; i<MAX_MEMBERS ; i++)				// 배열을 차례대로 순회하면서
		{
			if(g_arrayMember[i].unique_index == NOUSE_INDEX)		// 현재 사용중인 배열이 아니면 패스
				continue;
			fwrite(&g_arrayMember[i], sizeof(MEMBER_INFO), 1, f);	// 사용중이면 저장
		}
	}
	fclose(f);

	printf(" saved member data.\n");

}

// 파일 로드는 저장과 동일한 절차대로 작업하되, 쓰는 대신 읽는 동작이 이루어진다.
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

		nCount = header.nCount;					// 헤더에 기록된 수만큼
		for(i=0 ; i< nCount; i++)				// 루프를 돌며
		{
			fread(&tempInfo, sizeof(MEMBER_INFO), 1, f);		// 파일에서 읽어들이고
			memcpy(&g_arrayMember[tempInfo.unique_index], &tempInfo, sizeof(MEMBER_INFO)); // 배열에 저장한다
			g_memberCount++;
		}

		printf(" loaded member data.\n");
	}
	fclose(f);

}

int main()
{
	Initialize();					// 각종 변수 초기화 

	while(1)
	{
        ManagerMenu();              // 메인 메뉴 호출 
	}

	getch();
	return 0;
}