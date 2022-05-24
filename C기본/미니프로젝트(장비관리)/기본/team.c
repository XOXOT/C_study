#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define length_pw 15
#define length_name 20
#define length_tool 20
#define length_model 20
#define length_SN 20
#define num_user 50
#define num_tool 50      //장비갯수  (미전파)
#define 관리자 0
#define 점검관 1
#define 모니터확인관 21
#define 본체확인관  22
#define 스피커확인관 23
#define 기타확인관  20
#define 유지 0
#define 삭제 1
#define 양호 1
#define 불량 2
#define 모니터 1
#define 본체 2 
#define 스피커 3
#define 기타 4
#define 승인 1


struct user_info
{
	char pw[length_pw];
	char name[length_name];
	int id;
	int right;
	int user_del;
};

struct tool_info
{
	int in_date;
	int tool_del;
	char agree[10];
	int state[5];
	int year, month, day;
	char toolname[length_tool];
	int toolnum;
	char model[length_model];
	char SN[length_SN];
	char checklist[5][200];
	int agree_check;
};

struct user_info list[num_user] = { {"system", "관리자", 22010001, 관리자, 유지 } };
struct tool_info tool[num_tool];
int num_check_user = 1;   //회원 수 확인용 (삭제 포함)
int num_check_tool = 0; //장비 수 확인용 (삭제 포함)


void main() {
	int mode, choose;
	for (;;) {
		head_message();
		mode = log_in();
		if (list[mode].right == 관리자) {
			for (;;) {
				system("cls");
				printf("1. 회원관리\n2. 장비관리\n3. 로그아웃\n");
				printf("번호를 입력해주세요 : ");
				scanf("%d", &choose);
				if (choose == 1) {   //회원정보
					for (;;) {
						main_page("회원정보");
						printf("번호를 입력하세요. >> ");
						scanf("%d", &choose);
						if (choose == 1) {
							system("cls");
							make_user();
						} //회원정보등록
						else if (choose == 2) {
							system("cls");
							member_search(); //회원정보조회
						}
						else if (choose == 3) {
							system("cls");
							member_correction();
						}
						//회원정보수정
						else if (choose == 4) {
							member_delete_restore();
						}

						else if (choose == 5) {
							break;
						}
					}
				}

				else if (choose == 2) {   //장비정보
					for (;;) {
						main_page("장비정보");
						printf("번호를 입력하세요. >> ");
						scanf("%d", &choose);
						if (choose == 1) {
							system("cls");
							toolmenu1();
						}
						else if (choose == 2) {
							system("cls");
							toolmenu3();
						}
						else if (choose == 3) {
							system("cls");
							toolmenu2();
						}
						else if (choose == 4) {
							system("cls");
							toolmenu4();
						}
						else if (choose == 5) {
							break;
						}
					}
				}

				else if (choose == 3) {  //로그아웃
					break;
				}

				else {
					printf("잘 못 입력하셨습니다.\n");
					continue;
				}
			}
		}

		else if (list[mode].right == 점검관) {    //점검관 페이지
			for (;;) {
				system("cls");
				printf("1. 장비정보등록\n2. 장비점검\n3. 장비정보수정\n4. 장비정보조회\n5.로그아웃\n");
				printf("번호를 입력해주세요 : ");
				scanf("%d", &choose);
				if (choose == 1) {
					toolmenu1();
				}

				else if (choose == 2) {
					tool_checklist();
				}

				else if (choose == 3) {
					toolmenu2();
				}

				else if (choose == 4) {
					toolmenu3();
				}

				else if (choose == 5) {  //뒤로가기
					break;
				}
			}
		}

		else if (20 < list[mode].right && list[mode].right < 30) {  //확인관 페이지
			for (;;) {
				tool_check_be(list[mode].right);
				printf("번호를 입력해주세요 : ");
				scanf("%d", &choose);

				if (choose == 1) {
					tool_agree1(list[mode].right);
				}

				if (choose == 2) {
					tool_agree2(mode);
				}

				if (choose == 3) {
					break;
				}
			}
		}
	}
}
int main_page(char page[]) {
	system("cls");
	printf("1. %s 등록\n\n", page);
	printf("2. %s 조회\n\n", page);
	printf("3. %s 수정\n\n", page);
	printf("4. %s 삭제 및 복구\n\n", page);
	//printf("5. %s복구\n", page);  //삭제와 합치기
	printf("5. 뒤로 가기\n\n");
}  //로그인 후 첫화면
int tool_agree_page(char tool[]) {
	printf("1. %s 정보조회\n", tool);
	printf("2. (%s) 장비승인\n", tool);
	printf("3. 로그아웃\n");
}
int head_message() {
	printf("-------------WELCOM SYSTEM------------\n");
	printf("--------------------------------------\n");
}
int log_in(void) {
	int get_id;
	int i;
	char get_pw[length_pw + 1] = { '\0' };
	int check_list, login_check = 0;
	for (;;) {
		printf("ID : ");
		scanf("%d", &get_id);
		printf("PW : ");
		for (i = 0; i < length_pw; i++) {
			get_pw[i] = getch();
			if (get_pw[i] == 13) {
				get_pw[i] = '\0';
				break;
			}
			putch('*');
		}
		//scanf("%s", &get_pw);

		for (check_list = 0; check_list < num_check_user; check_list++) {
			if (get_id == list[check_list].id) {
				if (strcmp(get_pw, list[check_list].pw) == 0) {
					printf("\n로그인 중입니다.\n");
					login_check++;
					Sleep(1500);
					system("cls");
					return check_list;
				}
			}

			if ((login_check == 0) && (check_list == num_check_user - 1)) {
				system("cls");
				printf("아이디 비밀번호를 다시 한번 확인해 주시길 바랍니다.\n");
				break;
			}
		}
	}
}
int make_user() {

	struct user_info make;
	int check;
	for (;;) {
		printf("ID : ");
		scanf("%d", &make.id);
		printf("PW : ");
		scanf("%s", &make.pw);
		printf("이름 : ");
		scanf("%s", &make.name);
		printf("권한지정 (0.관리자/1.점검관/20.확인관)\n");
		printf("                            (1. 모니터/2. 본체/3. 스피커/0. 기타)\n번호 입력 : ");
		scanf("%d", &make.right);
		make.user_del = 유지;

		/*	if (make.right > 2) {
				printf("권한 지정을 잘 못 하셨습니다. 다시 한 번 확인해 주세요.\n");
				continue;
			}*/

		printf("%s님을 회원으로 등록하시겠습니까? (1.YES/2.NO)\n", make.name);
		scanf("%d", &check);

		if (check == 1) {
			list[num_check_user].id = make.id;
			strcpy(list[num_check_user].pw, make.pw);
			strcpy(list[num_check_user].name, make.name);
			list[num_check_user].right = make.right;
			list[num_check_user].user_del = make.user_del;
			printf("등록되었습니다.\n");
			num_check_user++;  //회원 수 증가
			getch();
			return;
		}

		else if (check == 2) {
			printf("취소되었습니다.\n");
			getch();
			return;
		}
	}
}
int tool_checklist(void) {
	int check, tool_choose;
	int in_checklist[3];

	system("cls");
	printf("장비명 모델명 S/N 입고일\n");
	for (check = 0; check < num_check_tool; check++) {
		printf("%d. %s %s %s %d\n", check + 1, tool[check].toolname, tool[check].model, tool[check].SN, tool[check].in_date);
	}   //장비 조회 함수 가져와서 입력하기.

	printf("장비 선택 : ");
	scanf("%d", &tool_choose);
	for (check = 0; check < 2; check++) {
		puts(tool[tool_choose - 1].checklist[check + 1]);
		printf("1. 양호 / 2. 불량 : ");
		scanf("%d", &in_checklist[check + 1]);
		tool[tool_choose - 1].state[check + 1] = in_checklist[check + 1];
	}

	printf("입력이 완료되었습니다.");
	getch();

	return;
}
int member_search(void)  //조회
{
	int num = 0;
	int find = 0;
	struct user_info temp;

	while (1)
	{
		system("cls");
		printf("\n1. 검색 조회\n\n");
		printf("2. 전체 조회\n\n");
		printf("3. 뒤로 가기\n\n");
		printf("번호를 입력하세요 : ");
		scanf("%d", &num);

		if (num == 3)
		{
			return;
		}

		if ((num != 1) && (num != 2) && (num != 3))
		{
			printf("다시 입력해주세요\n");
			member_search();
		}

		switch (num)
		{
		case 1:
			while (1)
			{
				system("cls");
				int i;

				printf("\n1. 이름 검색\n\n");
				printf("2. ID 검색\n\n");
				printf("3. 뒤로 가기\n\n");
				printf("번호를 입력하세요 : ");
				scanf("%d", &num);

				if (num == 3)
				{
					break;
				}

				switch (num)
				{
				case 1:
					system("cls");

					while (1)
					{
						char b[length_name];

						printf("찾을 회원의 이름을 입력해주세요 : ");
						scanf("%s", b);

						printf("\n    ID              PW             이름             권한\n");
						printf("============================================================\n");


						for (i = 0; i < num_user; i++)
						{
							if (strcmp(b, list[i].name) == 0)
							{

								printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);

								switch (list[i].right)
								{
								case 관리자:
									printf("관리자\n");
									break;
								case 점검관:
									printf("점검관\n");
									break;
								case 모니터확인관:
									printf("모니터확인관\n");
									break;
								case 본체확인관:
									printf("본체확인관\n");
									break;
								case 스피커확인관:
									printf("스피커확인관\n");
									break;
								case 기타확인관:
									printf("기타확인관\n");
									break;
								default:
									break;
								}
								find++;
							}
						}

						if (find == 0)
						{
							printf("해당 학생은 없습니다. 다시 입력하세요!\n");
						}
						do
						{
							printf("이전 화면으로 돌아가시겠습니까? (1: 이전 화면 2: 다시 조회)\n");
							scanf("%d", &num);
							if ((num != 1) && (num != 2))
							{
								printf("잘못 입력했습니다\n");
							}
						} while ((num != 1) && (num != 2));
						if (num == 1)
						{
							break;
						}
						else
						{
							continue;
						}
					}
					break;

				case 2:
					system("cls");

					while (1)
					{
						printf("찾을 회원의 ID를 입력해주세요(숫자 입력) : ");
						scanf("%d", &num);

						printf("\n    ID              PW             이름             권한\n");
						printf("============================================================\n");

						for (i = 0; i < num_user; i++)
						{
							if (num == list[i].id)
							{
								printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
								switch (list[i].right)
								{
								case 관리자:
									printf("관리자\n");
									break;
								case 점검관:
									printf("점검관\n");
									break;
								case 모니터확인관:
									printf("모니터확인관\n");
									break;
								case 본체확인관:
									printf("본체확인관\n");
									break;
								case 스피커확인관:
									printf("스피커확인관\n");
									break;
								case 기타확인관:
									printf("기타확인관\n");
									break;
								default:
									break;
								}
								find++;
							}
						}

						if (find == 0)
						{
							printf("해당 ID는 없습니다. 다시 입력하세요!\n");
						}
						do
						{
							printf("이전 화면으로 돌아가시겠습니까? (1: 이전 화면 2: 다시 조회)\n");
							scanf("%d", &num);
							if ((num != 1) && (num != 2))
							{
								printf("잘못 입력했습니다\n");
							}
						} while ((num != 1) && (num != 2));
						if (num == 1)
						{
							break;
						}
						else
						{
							continue;
						}
					}
					break;
				}
			}
			break;

		case 2:
			system("cls");
			int i, j, count = 0;
			printf("\n    ID              PW             이름             권한\n");
			printf("============================================================\n");
			for (i = 0; i < num_user; i++)
			{
				if ((list[i].id > 0) && (list[i].user_del == 유지))
				{
					count++;
					printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
					switch (list[i].right)
					{
					case 관리자:
						printf("관리자\n");
						break;
					case 점검관:
						printf("점검관\n");
						break;
					case 모니터확인관:
						printf("모니터확인관\n");
						break;
					case 본체확인관:
						printf("본체확인관\n");
						break;
					case 스피커확인관:
						printf("스피커확인관\n");
						break;
					case 기타확인관:
						printf("기타확인관\n");
						break;
					default:
						break;
					}
				}
			}
			printf("\n\n전체 회원 수는 %d명입니다.\n\n", count);
			printf("1. ID순으로 정렬\n\n");
			printf("2. 이름순으로 정렬\n\n");
			printf("3. 뒤로 가기\n\n");
			printf("번호를 입력하세요 : ");
			scanf("%d", &num);
			if (num == 3)
			{
				break;
			}

			switch (num)
			{
			case 1:
				count = 0;
				for (i = 0; i < num_user; i++)
				{
					for (j = 0; j < num_user - 1 - i; j++)
					{
						if (list[i].id > list[i + 1].id)
						{
							temp = list[j];
							list[j] = list[j + 1];
							list[j + 1] = temp;
						}
					}
				}
				printf("\n    ID              PW             이름             권한\n");
				printf("============================================================\n");
				for (i = 0; i < num_user; i++)
				{
					if ((list[i].id > 0) && (list[i].user_del == 유지))
					{
						count++;
						printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
						switch (list[i].right)
						{
						case 관리자:
							printf("관리자\n");
							break;
						case 점검관:
							printf("점검관\n");
							break;
						case 모니터확인관:
							printf("모니터확인관\n");
							break;
						case 본체확인관:
							printf("본체확인관\n");
							break;
						case 스피커확인관:
							printf("스피커확인관\n");
							break;
						case 기타확인관:
							printf("기타확인관\n");
							break;
						default:
							break;
						}
					}
				}
				printf("종료하시려면 아무키나 눌러주세요");
				getch();
				break;
			case 2:
				count = 0;
				for (i = 0; i < num_user; i++)
				{
					for (j = 0; j < num_user - 1 - i; j++)
					{
						if (strcmp(list[i].name, list[i + 1].name) > 0)
						{
							temp = list[j];
							list[j] = list[j + 1];
							list[j + 1] = temp;
						}
					}
				}
				printf("\n    ID              PW             이름             권한\n");
				printf("============================================================\n");
				for (i = 0; i < num_user; i++)
				{
					if ((list[i].id > 0) && (list[i].user_del == 유지))
					{
						count++;
						printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
						switch (list[i].right)
						{
						case 관리자:
							printf("관리자\n");
							break;
						case 점검관:
							printf("점검관\n");
							break;
						case 모니터확인관:
							printf("모니터확인관\n");
							break;
						case 본체확인관:
							printf("본체확인관\n");
							break;
						case 스피커확인관:
							printf("스피커확인관\n");
							break;
						case 기타확인관:
							printf("기타확인관\n");
							break;
						default:
							break;
						}
					}
				}
				printf("종료하시려면 아무키나 눌러주세요");
				getch();
				break;
			default:
				break;
			}
			break;
		}
	}
}
int toolmenu1()
{
	int i, j;
	int check;
	struct tool_info make;

	printf("장비를 등록합니다...\n\n");
	for (i = num_check_tool; i < num_check_tool + 1; i++)
	{
		printf("장비명(분류)를 입력하세요\n\n1.모니터\n\n2.본체\n\n3.스피커\n\n4.기타\n\n>>>");
		scanf("%d", &make.toolnum);

		if (make.toolnum == 모니터)
		{
			strcpy(make.toolname, "모니터");
		}

		else if (make.toolnum == 본체)
		{
			strcpy(make.toolname, "본체");
		}

		else if (make.toolnum == 스피커)
		{
			strcpy(make.toolname, "스피커");
		}

		else if (make.toolnum == 기타)
		{
			strcpy(make.toolname, "기타");
		}

		else {
			printf("잘 못 입력하셨습니다.\n");
			getch();
			return;
		}
		printf("\n모델명을 입력하세요>>> ");
		scanf("%s", make.model);

		do {
			printf("\n시리얼 넘버 입력>>> ");
			scanf("%s", &make.SN);
			if (strlen(make.SN) > length_SN) //문자열 길이 함수 
			{
				printf("입력 오류!! 시리얼 넘버를 재입력하세요.\n");
			}
		} while (strlen(make.SN) > length_SN);


		do {
			printf("\n입고 년도를 입력하세요>>>");
			scanf("%d", &make.year);
			if (make.year > 9999)
			{
				printf("입력 오류!! 입고년도를 재입력하세요.\n"); // 문자열을 넣으면 확 지나가버림 
			}
		} while (make.year > 9999);


		do {
			printf("\n입고 월을 입력하세요>>>");
			scanf("%d", &make.month);
			if (make.month > 12)
			{
				printf("입력 오류!! 입고 월을 재입력하세요.\n");
			}
		} while (make.month > 12);

		do {
			printf("\n입고 일을 입력하세요>>>");
			scanf("%d", &make.day);
			if (make.day > 31)
			{
				printf("입력 오류!! 입고 일을 재입력하세요.\n");
			}
		} while (make.day > 31);


		printf("\n점검사항 자동 입력 중...\n");
		for (j = num_check_tool; j < 3; j++)
		{
			if (make.toolnum == 모니터)
			{
				strcpy(make.checklist[1], "모니터 점검사항1");
				strcpy(make.checklist[2], "모니터 점검사항2");
			}

			else if (make.toolnum == 본체)
			{
				strcpy(make.checklist[1], "본체 점검사항1");
				strcpy(make.checklist[2], "본체 점검사항2");
			}

			else if (make.toolnum == 스피커)
			{
				strcpy(make.checklist[1], "스피커 점검사항1");
				strcpy(make.checklist[2], "스피커 점검사항2");
			}

			else if (make.toolnum == 기타)
			{
				strcpy(make.checklist[1], "기타 점검사항1");
				strcpy(make.checklist[2], "기타 점검사항2");
			}
			//gets(make.checklist[j]);
		}

		printf("\n----------------------------------------장비 등록-----------------------------------------\n\n");

		printf("분류\t모델명\t시리얼넘버\t\t입고일\t\t점검사항-1\t\t점검사항-2\n");
		printf("==============================================================================================\n");
		printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", make.toolname, make.model, make.SN, make.year, make.month, make.day, make.checklist[1], make.checklist[2]);

		printf("%s 장비를 등록하시겠습니까? (1.YES/2.NO)\n", make.toolname);
		scanf("%d", &check);

		if (check == 1)
		{
			tool[i].toolnum = make.toolnum; // 장비 분류 숫자 
			strcpy(tool[i].toolname, make.toolname); //장비 분류 문자
			strcpy(tool[i].model, make.model); //모델명 
			strcpy(tool[i].SN, make.SN); // 시리얼 넘버 
			tool[i].year = make.year;
			tool[i].month = make.month;
			tool[i].day = make.day;
			strcpy(tool[i].checklist[1], make.checklist[1]);
			strcpy(tool[i].checklist[2], make.checklist[2]);
			strcpy(tool[i].agree, "n");

			printf("-----------------------------------------장비 등록------------------------------------------\n\n");

			printf("분류\t모델명\t시리얼넘버\t\t입고일\t\t점검사항-1\t\t점검사항-2\n");
			printf("==============================================================================================\n");
			printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day, tool[i].checklist[1], tool[i].checklist[2]);
			printf("등록되었습니다.\n");
			Sleep(2000);
			num_check_tool++;  //장비 수 증가
			return;
		}

		else if (check == 2)
		{
			printf("취소되었습니다.\n");
			Sleep(2000);
			return;
		}
	}
	printf("\n\n");
}
int toolmenu2() // 장비 수정
{
	char name[20];
	int subject = 0;
	int i, j;
	int a;
	int error = 0;

	system("cls");
	
	printf("-----------------------------------------장비 수정------------------------------------------\n\n");

	printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
	printf("=======================================================================\n");
	for (i = 0; i < num_check_tool; i++)
	{
		printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
	}

	printf("\n\n수정할 장비 모델명을 입력해주세요\n>>>");
	scanf("%s", name);

	for (i = 0; i < num_check_tool; i++)
	{
		if (!strcmp(name, tool[i].model))
		{
			error++;
			printf("\n어떤 항목을 수정하시겠습니까?\n\n1. 분류\n\n2. 모델명\n\n3. 시리얼 넘버\n\n4. 승인여부\n\n5. 입고 년도\n\n6. 입고 달\n\n7. 입고 일자\n\n>>>");
			scanf("%d", &subject);

			switch (subject)
			{

			case 1:
				if (subject == 1)
				{
					printf("장비 분류를 어떻게 수정하시겠습니까?\n\n1.모니터\n\n2. 본체\n\n3. 스피커\n\n4. 기타\n\n>>>");
					scanf("%d", &tool[i].toolnum);

					printf("점검사항 자동 수정 중...\n");
					for (j = num_check_tool; j < 3; j++)
					{
						if (tool[i].toolnum == 모니터)
						{
							strcpy(tool[i].checklist[1], "모니터 점검사항1");
							strcpy(tool[i].checklist[2], "모니터 점검사항2");
						}

						else if (tool[i].toolnum == 본체)
						{
							strcpy(tool[i].checklist[1], "본체 점검사항1");
							strcpy(tool[i].checklist[2], "본체 점검사항2");
						}

						else if (tool[i].toolnum == 스피커)
						{
							strcpy(tool[i].checklist[1], "스피커 점검사항1");
							strcpy(tool[i].checklist[2], "스피커 점검사항2");
						}

						else if (tool[i].toolnum == 기타)
						{
							strcpy(tool[i].checklist[1], "기타 점검사항1");
							strcpy(tool[i].checklist[2], "기타 점검사항2");
						}
						//gets(make.checklist[j]);
					}
				}

			case 2:
				if (subject == 2)
				{
					printf("모델명을 어떻게 수정하시겠습니까? >>");
					scanf("%s", &tool[i].model);
				}

			case 3:
				if (subject == 3)
				{
					do {
						printf("시리얼넘버를 어떻게 수정하시겠습니까?\n\n>>>");
						scanf("%s", &tool[i].SN);
						if (strlen(tool[i].SN) > length_SN) //문자열 길이 함수 
						{
							printf("입력 오류!! 시리얼 넘버를 재입력하세요.\n\n>>>");
						}
					} while (strlen(tool[i].SN) > length_SN);

				}

			case 4: //???????? 여기서 수정이 가능해야한가
				if (subject == 4)
				{
					printf("승인여부를 어떻게 수정하시겠습니까?\n\n'y' or 'n'\n\n>>>");
					scanf("%s", &tool[i].agree);
				}

			case 5:
				if (subject == 5)
				{
					do {
						printf("입고 년도를 어떻게 수정하시겠습니까?\n\n>>>");
						scanf("%d", &tool[i].year);
						if (tool[i].year > 9999)
						{
							printf("입력 오류!! 입고년도를 재입력하세요.\n\n>>>");
						}
					} while (tool[i].year > 9999);
				}

			case 6:
				if (subject == 6)
				{
					do {
						printf("입고 윌을 어떻게 수정하시겠습니까?\n\n>>>");
						scanf("%d", &tool[i].month);
						if (tool[i].month > 12)
						{
							printf("입력 오류!! 입고 월을 재입력하세요.\n\n>>>");
						}
					} while (tool[i].month > 12);
				}

			case 7:
				if (subject == 7)
				{
					do {
						printf("입고 일을 어떻게 수정하시겠습니까?\n\n>>>");
						scanf("%d", &tool[i].day);
						if (tool[i].day > 31)
						{
							printf("입력 오류!! 입고 일을 재입력하세요.\n\n>>>");
						}
					} while (tool[i].day > 31);
				}
			default:
				break;
			}
			printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
			printf("===================================================================\n");
			printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
			printf("\n변경이 완료되었습니다.\n\n");
			Sleep(2000);
			return 0;
		}
		else
		{
			printf("잘못 입력! 다시 한번 확인해주세요\n\n");
		}

		if (tool[i].toolnum == 모니터)
		{
			strcpy(tool[i].toolname, "모니터");
		}

		else if (tool[i].toolnum == 본체)
		{
			strcpy(tool[i].toolname, "본체");
		}

		else if (tool[i].toolnum == 스피커)
		{
			strcpy(tool[i].toolname, "스피커");
		}

		else if (tool[i].toolnum == 기타)
		{
			strcpy(tool[i].toolname, "기타");
		}
	}
	if (error == 0)
	{
		printf("해당 모델이 없습니다. 다시 한번 확인해주세요\n\n");
		printf("\n장비등록으로 이동하시겠습니까?\n");
		printf("\n1. 이동 \n\n2. 뒤로가기\n");
		printf(">>>");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			system("cls");
			toolmenu1();
			break;
		case 2:
			return 0;
			break;
		}
		Sleep(2000);
	}
}
int toolmenu3() //조회
{
	char name[20];
	int tnum;
	int num;
	int i;
	int j;
	struct tool_info temp;
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0; //모델 수 
	int wrong = 0;
	char tname1[20];
	char tname2[20];

	system("cls");
	printf("1. 검색 조회\n\n");
	printf("2. 전체 조회\n\n");
	printf("3. 분류별 조회\n\n");
	printf("4. 날짜별 조회\n\n");
	printf("번호를 입력하세요 : ");
	scanf("%d", &num);

	switch (num)
	{
	case 1:
		system("cls");

		printf("모델명 입력:");
		scanf("%s", name);

		printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
		printf("===================================================================\n");

		for (i = 0; i < num_check_tool; i++)
		{
			if (!strcmp(name, tool[i].model))
			{
				if (tool[i].tool_del == 유지)
				{
					printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
				}
				strcpy(tname1, tool[i].model);
				count5++;
				wrong++;
			}
		}
		if (wrong == 0)
		{
			printf("해당 모델은 없습니다. 다시 입력하세요. ");
		}

		printf("\n %s 모델 개수는 %d 개 입니다.\n", tname1, count5);
		printf("\n\n");
		break;

	case 2:
		system("cls");
		printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
		printf("===================================================================\n");
		for (i = 0; i < num_check_tool; i++)
		{
			if (tool[i].tool_del == 유지)
			{
				printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
			}
			count++;
		}

		int a;
		printf("\n\n 전체 장비 개수는 %d 개 입니다.\n\n", count);
		printf("\n");
		printf("1. 분류별 배열\n\n");
		printf("2. 날짜별 배열\n\n");
		printf("\n");
		printf("번호를 입력하세요 : ");
		scanf("%d", &a);

		switch (a)
		{
		case 1: //분류 후 날짜 배열 
			system("cls");
			while (1)
			{
				//날짜 배열 후 
				for (i = 0; i < num_check_tool - 1; i++)
				{
					for (j = 0; j < num_check_tool - 1 - i; j++)
					{
						if (tool[j].year > tool[j + 1].year)
						{
							temp = tool[j];
							tool[j] = tool[j + 1];
							tool[j + 1] = temp;
						}
						else if (tool[j].year == tool[j + 1].year)
						{
							if (tool[j].month > tool[j + 1].month)
							{
								temp = tool[j];
								tool[j] = tool[j + 1];
								tool[j + 1] = temp;
							}
							else if (tool[j].month == tool[j + 1].month)
							{
								if (tool[j].day > tool[j + 1].day)
								{
									temp = tool[j];
									tool[j] = tool[j + 1];
									tool[j + 1] = temp;
								}
							}
						}
					}
				}

				//분류별 배열 
				for (i = 0; i < num_check_tool; i++)
				{
					for (j = 0; j < num_check_tool - 1 - i; j++)
					{
						if (tool[j].toolnum > tool[j + 1].toolnum)
						{
							temp = tool[j];
							tool[j] = tool[j + 1];
							tool[j + 1] = temp;
						}
					}
				}

				printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
				printf("===================================================================\n");
				for (i = 0; i < num_check_tool; i++)
				{
					if (tool[i].tool_del == 유지)
					{
						printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
					}
					count1++;
				}
				printf("\n\n 장비 개수는 %d 개 입니다.\n\n", count1);
				break;
			}
			break;

		case 2: //날짜별 배열(오름차순)
			system("cls");
			while (1)
			{
				for (i = 0; i < num_check_tool - 1; i++)
				{
					for (j = 0; j < num_check_tool - 1 - i; j++)
					{
						if (tool[j].year > tool[j + 1].year)
						{
							temp = tool[j];
							tool[j] = tool[j + 1];
							tool[j + 1] = temp;
						}
						else if (tool[j].year == tool[j + 1].year)
						{
							if (tool[j].month > tool[j + 1].month)
							{
								temp = tool[j];
								tool[j] = tool[j + 1];
								tool[j + 1] = temp;
							}
							else if (tool[j].month == tool[j + 1].month)
							{
								if (tool[j].day > tool[j + 1].day)
								{
									temp = tool[j];
									tool[j] = tool[j + 1];
									tool[j + 1] = temp;
								}
							}
						}
					}
				}
				printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
				printf("===================================================================\n");
				for (i = 0; i < num_check_tool; i++)
				{
					if (tool[i].tool_del == 유지)
					{
						printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
					}
					count2++;
				}
				printf("\n\n 전체 장비 개수는 %d 개 입니다.\n\n", count2);
				break;
			}
			break;
		}

		printf("\n\n");
		break;

	case 3: //오류 
		system("cls");

		printf("분류 번호 입력 \n 1.모니터\n 2. 본체\n 3. 스피커\n 4. 기타\n  >>>");
		scanf("%d", &tnum);


		printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
		printf("===================================================================\n");

		for (i = 0; i < num_check_tool; i++)
		{
			if (tool[i].toolnum == tnum)
			{
				if (tool[i].tool_del == 유지)
				{
					printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
					strcpy(tname2, tool[i].toolname);
				}
				count3++;
				wrong++;
			}
		}
		if (wrong == 0)
		{
			printf("\n해당 모델은 없습니다. 다시 입력하세요. \n");
		}

		printf("\n %s의 개수는 %d 개 입니다.\n", tname2, count3);
		printf("\n\n");
		break;


	case 4: //(오름차순)
		system("cls");

		for (i = 0; i < num_check_tool - 1; i++)
		{
			for (j = 0; j < num_check_tool - 1 - i; j++)
			{
				if (tool[j].year > tool[j + 1].year)
				{
					temp = tool[j];
					tool[j] = tool[j + 1];
					tool[j + 1] = temp;
				}
				else if (tool[j].year == tool[j + 1].year)
				{
					if (tool[j].month > tool[j + 1].month)
					{
						temp = tool[j];
						tool[j] = tool[j + 1];
						tool[j + 1] = temp;
					}
					else if (tool[j].month == tool[j + 1].month)
					{
						if (tool[j].day > tool[j + 1].day)
						{
							temp = tool[j];
							tool[j] = tool[j + 1];
							tool[j + 1] = temp;
						}
					}
				}
			}
		}
		printf("분류\t모델명\t시리얼넘버\t승인여부\t입고일\n");
		printf("===================================================================\n");
		for (i = 0; i < num_check_tool; i++)
		{
			if (tool[i].tool_del == 유지)
			{
				printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
			}
			count4++;
		}
		printf("\n\n 전체 장비 개수는 %d 개 입니다.\n\n", count4);
		break;
	}
	printf("\n\n");
	printf("돌아가실려면 아무키를 누르세요\n");
	getch();
	system("cls");
}
int toolmenu4() {
	int i, del_find = 0, del_check;
	char del_choose[length_model];
	int num;

	printf("1. 삭제 \n\n");
	printf("2. 복구 \n\n");
	printf("3. 뒤로가기\n\n");
	printf("번호 입력 : ");
	scanf("%d", &num);

	if (num == 1) {
		system("cls");
		printf("순번  분류       모델명        시리얼넘버       입고일      상태\n");
		printf("=================================================================\n");
		for (i = 0; i < num_check_tool; i++)
		{
			printf(" %d   %3s %15s %15s   %4d-%2d-%2d ", i + 1, tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day);
			if (tool[i].tool_del == 삭제) printf("   삭제\n");
			else printf("\n");
		}

		printf("\n삭제할 모델명을 입력하세요 : ");
		scanf("%s", del_choose);
		for (i = 0; i < num_check_tool; i++) {
			if (strcmp(tool[i].model, del_choose) == 0) {
				printf("삭제하시겠습니까 ? (1.YES / 2.NO)\n 번호 입력 : ");
				scanf("%d", &del_check);
				if (del_check == 1) {
					printf("삭제되었습니다.\n");
					tool[i].tool_del = 삭제;
					del_find++;
					getch();
					return;
				}
				else if (del_check == 2) {
					printf("취소되었습니다.\n");
					getch();
					return;
				}
			}
		}

		if (del_find == 0) {
			printf("해당 장비가 없습니다.\n");
			getch();
		}
	}

	else if (num == 2) {
		system("cls");
		printf("순번  분류       모델명        시리얼넘버       입고일      상태\n");
		printf("=================================================================\n");
		for (i = 0; i < num_check_tool; i++)
		{
			printf(" %d   %3s %15s %15s   %4d-%2d-%2d ", i + 1, tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day);
			if (tool[i].tool_del == 삭제) printf("   삭제\n");
			else printf("\n");
		}

		printf("복구할 모델명을 입력하세요 : ");
		scanf("%s", del_choose);
		for (i = 0; i < num_check_tool; i++) {
			if (strcmp(tool[i].model, del_choose) == 0) {
				printf("복구하시겠습니까 ? (1.YES / 2.NO)\n 번호 입력 : ");
				scanf("%d", &del_check);
				if (del_check == 1) {
					printf("복구되었습니다.\n");
					tool[i].tool_del = 유지;
					del_find++;
					getch();
					return;
				}
				else if (del_check == 2) {
					printf("취소되었습니다.\n");
					getch();
					return;
				}
			}
		}

		if (del_find == 0) {
			printf("해당 장비가 없습니다.\n");
			getch();
		}
	}

	else if (num == 3) return;

	else if ((num != 1) && (num != 2))
	{
		printf("다시 입력하세요.\n");
		toolmenu4();
	}
}
int member_correction(void) // 수정
{
	system("cls");
	int num, i = 0;
	struct user_info make;

	printf("\n    ID              PW             이름             권한\n");
	printf("============================================================\n");

	for (i = 0; i < num_user; i++)
	{
		if ((list[i].id > 0) && (list[i].user_del == 유지))
		{
			printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
			switch (list[i].right)
			{
			case 관리자:
				printf("관리자\n");
				break;
			case 점검관:
				printf("점검관\n");
				break;
			case 모니터확인관:
				printf("모니터확인관\n");
				break;
			case 본체확인관:
				printf("본체확인관\n");
				break;
			case 스피커확인관:
				printf("스피커확인관\n");
				break;
			case 기타확인관:
				printf("기타확인관\n");
				break;
			default:
				break;
			}
		}
	}

	while (1)
	{
		int name_count = 0, name_find = 0;

		printf("\n\n수정할 회원의 ID를 입력해주세요 : ");
		scanf("%d", &num);

		for (i = 0; i < num_user; i++)
		{
			if (list[i].id == num)
			{
				name_count++;
				name_find++;
				break;
			}
			name_count++;
		}

		if (name_find == 1)
		{
			do
			{
				printf("\n어떤 항목을 수정하시겠습니까?\n\n");
				printf("1. ID\n\n");
				printf("2. PW\n\n");
				printf("3. 이름\n\n");
				printf("4. 권한\n\n");
				printf("5. 전체수정\n\n");
				printf("6. 뒤로가기\n\n");
				scanf("%d", &num);
				if ((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5) && (num != 6))
				{
					printf("잘못 입력했습니다. 다시 입력해주세요\n");
				}
			} while ((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5) && (num != 6));

			switch (num)
			{
			case 1:
				printf("\nID를 수정하세요.\n");
				printf("ID : ");
				scanf("%d", &make.id);
				do
				{
					printf("수정하시겠습니까 ? (1.YES / 2.NO)\n");
					scanf("%d", &num);
					if ((num != 1) && (num != 2))
					{
						printf("잘못 입력했습니다\n");
					}
				} while ((num != 1) && (num != 2));
				if (num == 1)
				{
					list[name_count - 1].id = make.id;
				}
				break;

			case 2:
				printf("\nPW를 수정하세요.\n");
				printf("PW : ");
				scanf("%s", make.pw);
				do
				{
					printf("수정하시겠습니까? (1.YES / 2.NO)\n");
					scanf("%d", &num);
					if ((num != 1) && (num != 2))
					{
						printf("잘못 입력했습니다\n");
					}
				} while ((num != 1) && (num != 2));
				if (num == 1)
				{
					strcpy(list[name_count - 1].pw, make.pw);
				}
				break;

			case 3:
				printf("\n이름을 수정하세요.\n");
				printf("이름 : ");
				scanf("%s", make.name);
				do
				{
					printf("수정하시겠습니까 ? (1.YES / 2.NO)\n");
					scanf("%d", &num);
					if ((num != 1) && (num != 2))
					{
						printf("잘못 입력했습니다\n");
					}
				} while ((num != 1) && (num != 2));
				if (num == 1)
				{
					strcpy(list[name_count - 1].name, make.name);
				}
				break;

			case 4:
				printf("\n권한을 수정하세요.\n(0:관리자, 1:점검관, 21:모니터확인관, 22:본체확인관 23:스피커확인관 24:기타확인관\n");
				do
				{
					printf("권한 : ");
					scanf("%d", &make.right);
					if ((make.right != 관리자) && (make.right != 점검관) && (make.right != 모니터확인관) && (make.right != 본체확인관) && (make.right != 스피커확인관) && (make.right != 기타확인관))
					{
						printf("해당하는 권한이 없습니다\n");
					}
				} while ((make.right != 관리자) && (make.right != 점검관) && (make.right != 모니터확인관) && (make.right != 본체확인관) && (make.right != 스피커확인관) && (make.right != 기타확인관));
				do
				{
					printf("수정하시겠습니까 ? (1.YES / 2.NO)\n");
					scanf("%d", &num);
					if ((num != 1) && (num != 2))
					{
						printf("잘못 입력했습니다\n");
					}
				} while ((num != 1) && (num != 2));
				if (num == 1)
				{
					list[name_count - 1].right = make.right;
				}
				break;
			case 5:
				printf("\nID,PW,이름,권한을 수정하세요.\n");
				printf("ID : ");
				scanf("%d", &make.name);
				printf("PW : ");
				scanf("%s", &make.pw);
				printf("이름 : ");
				scanf("%s", &make.name);
				do
				{
					printf("권한(0:관리자, 1:점검관, 21:모니터확인관, 22:본체확인관 23:스피커확인관 24:기타확인관):  ");
					scanf("%d", &make.right);
					if ((make.right != 관리자) && (make.right != 점검관) && (make.right != 모니터확인관) && (make.right != 본체확인관) && (make.right != 스피커확인관) && (make.right != 기타확인관))
					{
						printf("해당하는 권한이 없습니다\n");
					}
				} while ((make.right != 관리자) && (make.right != 점검관) && (make.right != 모니터확인관) && (make.right != 본체확인관) && (make.right != 스피커확인관) && (make.right != 기타확인관));
				do
				{
					printf("수정하시겠습니까 ? (1.YES / 2.NO)\n");
					scanf("%d", &num);
					if ((num != 1) && (num != 2))
					{
						printf("잘못 입력했습니다\n");
					}
				} while ((num != 1) && (num != 2));
				if (num == 1)
				{
					list[name_count - 1].id = make.id;
					strcpy(list[name_count - 1].pw, make.pw);
					strcpy(list[name_count - 1].name, make.name);
					list[name_count - 1].right = make.right;
				}
				break;

			case 6:
				member_correction();
				break;

			default:
				break;
			}
		}
		else
		{
			do
			{
				printf("해당하는 회원은 없습니다. (1 : 뒤로가기 2: 다시 입력)\n");
				scanf("%d", &num);
				if ((num != 1) && (num != 2))
				{
					printf("잘못 입력했습니다\n");
				}
			} while ((num != 1) && (num != 2));
			if (num == 1)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		system("cls");
		break;
	}
}
int member_delete_restore(void) //삭제복구
{
	while (1)
	{
		system("cls");
		int num;
		int count = 0;
		int id_find = 0;
		int i;
		struct user_info make;

		printf("1. 삭제 \n\n");
		printf("2. 복구 \n\n");
		printf("3. 뒤로가기\n\n");
		scanf("%d", &num);

		if (num == 3)
		{
			return;
		}
		if ((num != 1) && (num != 2))
		{
			printf("다시 입력하세요!!\n");
			Sleep(1000);
			member_delete_restore();
		}
		switch (num)
		{
		case 1:
			system("cls");
			printf("\n    ID              PW             이름             권한\n");
			printf("============================================================\n");
			for (i = 0; i < num_user; i++)
			{
				if ((list[i].id > 0) && (list[i].user_del == 유지))
				{
					count++;
					printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
				}
			}

			while (1)
			{
				printf("삭제할 ID를 입력하세요 : ");
				scanf("%d", &num);

				for (i = 0; i < num_user; i++)
				{
					if (num == list[i].id)
					{
						make.user_del = 삭제;
						id_find++;
						do
						{
							printf("삭제하시겠습니까 ? (1.YES / 2.NO)\n");
							scanf("%d", &num);
						} while ((num != 1) && (num != 2));
						if (num == 1)
						{
							list[i].user_del = make.user_del;
							break;
						}
						else {
							break;
						}
					}
				}

				if (id_find == 0)
				{
					do
					{
						printf("해당하는 ID가 없습니다.(1 : 뒤로가기 2: 다시 입력)\n");
						scanf("%d", &num);
						if ((num != 1) && (num != 2))
						{
							printf("잘못 입력했습니다\n");
						}
					} while ((num != 1) && (num != 2));
					if (num == 1)
					{
						break;
					}
					else
					{
						continue;
					}
				}
				break;
			}
			break;

		case 2:
			system("cls");
			printf("\n    ID              PW             이름             권한\n");
			printf("============================================================\n");

			for (i = 0; i < num_user; i++)
			{
				if (list[i].id > 0)
				{
					count++;
					printf("%10d%15s%15s           ", list[i].id, list[i].pw, list[i].name);
					if (list[i].user_del == 삭제)
					{
						printf("   삭제\n");
					}
				}
			}

			while (1)
			{
				printf("\n\n복구할 ID를 입력하세요 : ");
				scanf("%d", &num);

				for (i = 0; i < num_user; i++)
				{
					if (num == list[i].id)
					{
						make.user_del = 유지;
						printf("복구하시겠습니까 ? (1.YES / 2.NO)\n");
						scanf("%d", &num);
						if (num == 1)
						{
							list[i].user_del = make.user_del;
						}
						id_find++;
						break;
					}
				}
				if (id_find == 0)
				{
					do
					{
						printf("해당하는 ID가 없습니다.(1 : 뒤로가기 2: 다시 입력)\n");
						scanf("%d", &num);
						if ((num != 1) && (num != 2))
						{
							printf("잘못 입력했습니다\n");
						}
					} while ((num != 1) && (num != 2));
					if (num == 1)
					{
						break;
					}
					else
					{
						continue;
					}
				}
				break;
			}
			break;
		}
	}
}
int tool_check_be(int right) {
	if (right == 21) tool_agree_page("모니터");
	else if (right == 22) tool_agree_page("본체");
	else if (right == 23) tool_agree_page("스피커");
	else if (right == 20) tool_agree_page("기타");
}
int tool_agree1(int right) {
	int i, j;
	system("cls");
	printf(" 분류       모델명        시리얼넘버     승인여부     입고일  \n");
	printf("==============================================================\n");
	for (i = 0; i < num_check_tool; i++) {
		if (tool[i].toolnum == right - 20) {
			if (tool[i].tool_del == 유지)
				printf("%7s %15s %15s %6s      %4d-%2d-%2d \n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
			for (j = 1; j < 3; j++) {   //3은 임시 점검갯수
				printf("%d. %s : ", j, tool[i].checklist[j]);
				if (tool[i].state[j] == 0) printf("미점검\n");
				else if (tool[i].state[j] == 1) printf("양호\n");
				else if (tool[i].state[j] == 2) printf("불량\n");
			}
			printf("-----------------------------------------------------------------------------\n");
		}
	}
}
int tool_agree2(int right) {
	int agree;
	char name[20];
	int i, j;
	system("cls");
	printf(" 분류       모델명        시리얼넘버     승인여부     입고일  \n");
	printf("==============================================================\n");
	for (i = 0; i < num_check_tool; i++) {
		if (tool[i].toolnum == list[right].right - 20) {
			if (tool[i].tool_del == 유지) printf("%7s %15s %15s %6s      %4d-%2d-%2d \n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
			for (j = 1; j < 3; j++) {   //3은 임시 점검갯수
				printf("%d. %s : ", j, tool[i].checklist[j]);
				if (tool[i].state[j] == 0) printf("미점검\n");
				else if (tool[i].state[j] == 1) printf("양호\n");
				else if (tool[i].state[j] == 2) printf("불량\n");
			}

			if (tool[i].agree_check != 0) {
				printf("<이미 승인하셨습니다.> ");
				printf("확인관 : %s\n", list[right].name);
			}

			else if (tool[i].agree_check == 0) {
				printf("해당 장비 승인 여부 (1. YES / 2. NO) (승인 후 철회 불가 !) : ");
				scanf("%d", &agree);
				if (agree == 1) {
					printf("서명 : ");
					scanf("%s", name);
					printf("<승인하셨습니다.>\n");
					strcpy(tool[i].agree, "승인");
					getch();
					tool[i].agree_check++;
				}
				else if (agree == 2) {
					printf("비승인");
				}
			}
			printf("-----------------------------------------------------------------------------\n");
		}
	}
}