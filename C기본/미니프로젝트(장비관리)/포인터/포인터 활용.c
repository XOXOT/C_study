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
#define num_tool 50      //��񰹼�  (������)
#define ������ 0
#define ���˰� 1
#define �����Ȯ�ΰ� 21
#define ��üȮ�ΰ�  22
#define ����ĿȮ�ΰ� 23
#define ��ŸȮ�ΰ�  20
#define ���� 0
#define ���� 1
#define ��ȣ 1
#define �ҷ� 2
#define ����� 1
#define ��ü 2 
#define ����Ŀ 3
#define ��Ÿ 4
#define ���� 1


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
    int num;
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
    struct tool_info *next;
};

int check_list = 0; //�α��� ��ȯ �� ���������� ���� �� ȯ������ ������ ��� 

struct user_info list[num_user] = { {"system", "������", 22010001, ������, ���� } };
struct tool_info tool[num_tool];
struct tool_info *ptool[num_tool];
struct tool_info *head = &tool[0];

//struct tool_info *reset[num_tool];
int num_check_user = 1;   //ȸ�� �� Ȯ�ο� (���� ����)
int num_check_tool = 0; //��� �� Ȯ�ο� (���� ����) len


void main() 
{
    int mode, choose;
    int choose1 = 0;
    for (;;) {
        //head_message();
        mode = log_in();
        if (list[mode].right == ������) {
            for (;;) {
                system("cls");
                name_welcome();
                printf("\n1. ȸ������\n\n2. ������\n\n3. �α׾ƿ�\n\n");
                printf("��ȣ�� �Է����ּ��� : ");
                scanf("%d", &choose);
                if (choose == 1) {   //ȸ������
                    for (;;) {
                        main_page("ȸ������");
                        printf("��ȣ�� �Է��ϼ���. >>> ");
                        scanf("%d", &choose);
                        if (choose == 1) {
                            name_welcome();
                            system("cls");
                            make_user();
                        } //ȸ���������
                        else if (choose == 2) {
                            name_welcome();
                            system("cls");
                            member_search(); //ȸ��������ȸ
                        }
                        else if (choose == 3) {
                            name_welcome();
                            system("cls");
                            member_correction();
                        }
                        //ȸ����������
                        else if (choose == 4) {
                            name_welcome();
                            system("cls");
                            member_delete_restore();
                        }

                        else if (choose == 5) {
                            break;
                        }
                    }
                }

                else if (choose == 2) {   //�������
                    name_welcome();
                    for (;;) 
                    {
                        main_page("�������");
                        printf("��ȣ�� �Է��ϼ���. >>> ");
                        scanf("%d", &choose);
                        if (choose == 1) {
                            system("cls");
                            name_welcome();
                            toolmenu1();
                        }
                        else if (choose == 2) {
                            system("cls");
                            name_welcome();
                            printf("1.������ ��ȸ\n\n2.���� ����Ʈ ��ȸ\n\n");
                            printf("��ȣ�� �Է��ϼ���. >>> ");
                            scanf("%d", &choose1);
                            switch (choose1)
                            {
                            case 1:
                                toolmenu3();
                                break;
                            case 2:
                                search_node();
                                break;
                            }
                        }
                        else if (choose == 3) {
                            system("cls");
                            name_welcome();
                            toolmenu2();
                        }
                        else if (choose == 4) {
                            system("cls");
                            name_welcome();
                            toolmenu4();
                        }
                        else if (choose == 5) {
                            break;
                        }
                    }
                }

                else if (choose == 3) {  //�α׾ƿ�
                    break;
                }

                else {
                    printf("�߸� �Է��ϼ̽��ϴ�.\n");
                    continue;
                }
            }
        }

        else if (list[mode].right == ���˰�) {    //���˰� ������
            for (;;) {
                system("cls");
                name_welcome();
                printf("1. ����������\n\n2. �������\n\n3. �����������\n\n4. ���������ȸ\n\n5.�α׾ƿ�\n\n");
                printf("��ȣ�� �Է����ּ��� : ");
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

                else if (choose == 5) {  //�ڷΰ���
                    break;
                }
            }
        }

        else if (20 < list[mode].right && list[mode].right < 30) {  //Ȯ�ΰ� ������
            for (;;) {
                tool_check_be(list[mode].right);
                printf("��ȣ�� �Է����ּ��� : ");
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
    int mode = 0;
    system("cls");
    name_welcome();
    printf("1. %s ���\n\n", page);
    printf("2. %s ��ȸ\n\n", page);
    printf("3. %s ����\n\n", page);
    printf("4. %s ���� �� ����\n\n", page);
    //printf("5. %s����\n", page);  //������ ��ġ��
    printf("5. �ڷ� ����\n\n");
}  //�α��� �� ùȭ��
int tool_agree_page(char tool[]) {
    printf("1. %s ������ȸ\n", tool);
    printf("2. (%s) ������\n", tool);
    printf("3. �α׾ƿ�\n");
}
int head_message() {
    printf("WELCOM SYSTEM\n");
    printf("-------------\n");
}
int log_in(void) {
    head_message();
    int get_id;
    int i;
    char get_pw[length_pw + 1] = { '\0' };
 /*   int check_list, login_check = 0;*/
    int login_check = 0;
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
                    printf("\n�α��� ���Դϴ�.\n");
                    login_check++;
                    Sleep(1500);
                    system("cls");
                    return check_list;
                }
            }

            if ((login_check == 0) && (check_list == num_check_user - 1)) {
                system("cls");
                printf("���̵� ��й�ȣ�� �ٽ� �ѹ� Ȯ���� �ֽñ� �ٶ��ϴ�.\n");
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
        printf("�̸� : ");
        scanf("%s", &make.name);
        printf("�������� (0.������/1.���˰�/20.Ȯ�ΰ�)\n");
        printf("                            (1. �����/2. ��ü/3. ����Ŀ/0. ��Ÿ)\n��ȣ �Է� : ");
        scanf("%d", &make.right);
        make.user_del = ����;

        /*   if (make.right > 2) {
              printf("���� ������ �� �� �ϼ̽��ϴ�. �ٽ� �� �� Ȯ���� �ּ���.\n");
              continue;
           }*/

        printf("%s���� ȸ������ ����Ͻðڽ��ϱ�? (1.YES/2.NO)\n", make.name);
        scanf("%d", &check);

        if (check == 1) {
            list[num_check_user].id = make.id;
            strcpy(list[num_check_user].pw, make.pw);
            strcpy(list[num_check_user].name, make.name);
            list[num_check_user].right = make.right;
            list[num_check_user].user_del = make.user_del;
            printf("��ϵǾ����ϴ�.\n");
            num_check_user++;  //ȸ�� �� ����
            getch();
            return;
        }

        else if (check == 2) {
            printf("��ҵǾ����ϴ�.\n");
            getch();
            return;
        }
    }
}
int tool_checklist(void) {
    int check, tool_choose;
    int in_checklist[3];

    system("cls");
    printf("���� �𵨸� S/N �԰���\n");
    for (check = 0; check < num_check_tool; check++) {
        printf("%d. %s %s %s %d\n", check + 1, tool[check].toolname, tool[check].model, tool[check].SN, tool[check].in_date);
    }   //��� ��ȸ �Լ� �����ͼ� �Է��ϱ�.

    printf("��� ���� : ");
    scanf("%d", &tool_choose);
    for (check = 0; check < 2; check++) {
        puts(tool[tool_choose - 1].checklist[check + 1]);
        printf("1. ��ȣ / 2. �ҷ� : ");
        scanf("%d", &in_checklist[check + 1]);
        tool[tool_choose - 1].state[check + 1] = in_checklist[check + 1];
    }

    printf("�Է��� �Ϸ�Ǿ����ϴ�.");
    getch();

    return;
}
int member_search(void)  //��ȸ
{
    int num = 0;
    int find = 0;
    struct user_info temp;

    while (1)
    {
        system("cls");
        printf("\n1. �˻� ��ȸ\n\n");
        printf("2. ��ü ��ȸ\n\n");
        printf("3. �ڷ� ����\n\n");
        printf("��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &num);

        if (num == 3)
        {
            return;
        }

        if ((num != 1) && (num != 2) && (num != 3))
        {
            printf("�ٽ� �Է����ּ���\n");
            member_search();
        }

        switch (num)
        {
        case 1:
            while (1)
            {
                system("cls");
                int i;

                printf("\n1. �̸� �˻�\n\n");
                printf("2. ID �˻�\n\n");
                printf("3. �ڷ� ����\n\n");
                printf("��ȣ�� �Է��ϼ��� : ");
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

                        printf("ã�� ȸ���� �̸��� �Է����ּ��� : ");
                        scanf("%s", b);

                        printf("\nID          PW            �̸�          ����\n");
                        printf("=====================================================\n");


                        for (i = 0; i < num_user; i++)
                        {
                            if (strcmp(b, list[i].name) == 0)
                            {

                                printf("%d     %s       %s        ", list[i].id, list[i].pw, list[i].name);

                                switch (list[i].right)
                                {
                                case ������:
                                    printf("������\n");
                                    break;
                                case ���˰�:
                                    printf("���˰�\n");
                                    break;
                                case �����Ȯ�ΰ�:
                                    printf("�����Ȯ�ΰ�\n");
                                    break;
                                case ��üȮ�ΰ�:
                                    printf("��üȮ�ΰ�\n");
                                    break;
                                case ����ĿȮ�ΰ�:
                                    printf("����ĿȮ�ΰ�\n");
                                    break;
                                case ��ŸȮ�ΰ�:
                                    printf("��ŸȮ�ΰ�\n");
                                    break;
                                default:
                                    break;
                                }
                                find++;
                            }
                        }

                        if (find == 0)
                        {
                            printf("�ش� �л��� �����ϴ�. �ٽ� �Է��ϼ���!\n");
                        }
                        do
                        {
                            printf("���� ȭ������ ���ư��ðڽ��ϱ�? (1: ���� ȭ�� 2: �ٽ� ��ȸ)\n");
                            scanf("%d", &num);
                            if ((num != 1) && (num != 2))
                            {
                                printf("�߸� �Է��߽��ϴ�\n");
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
                        printf("ã�� ȸ���� id�� �Է����ּ���(���� �Է�) : ");
                        scanf("%d", &num);

                        printf("\nID          PW            �̸�          ����\n");
                        printf("=====================================================\n");

                        for (i = 0; i < num_user; i++)
                        {
                            if (num == list[i].id)
                            {
                                printf("%d     %s       %s        ", list[i].id, list[i].pw, list[i].name);
                                switch (list[i].right)
                                {
                                case ������:
                                    printf("������\n");
                                    break;
                                case ���˰�:
                                    printf("���˰�\n");
                                    break;
                                case �����Ȯ�ΰ�:
                                    printf("�����Ȯ�ΰ�\n");
                                    break;
                                case ��üȮ�ΰ�:
                                    printf("��üȮ�ΰ�\n");
                                    break;
                                case ����ĿȮ�ΰ�:
                                    printf("����ĿȮ�ΰ�\n");
                                    break;
                                case ��ŸȮ�ΰ�:
                                    printf("��ŸȮ�ΰ�\n");
                                    break;
                                default:
                                    break;
                                }
                                find++;
                            }
                        }

                        if (find == 0)
                        {
                            printf("�ش� ID�� �����ϴ�. �ٽ� �Է��ϼ���!\n");
                        }
                        do
                        {
                            printf("���� ȭ������ ���ư��ðڽ��ϱ�? (1: ���� ȭ�� 2: �ٽ� ��ȸ)\n");
                            scanf("%d", &num);
                            if ((num != 1) && (num != 2))
                            {
                                printf("�߸� �Է��߽��ϴ�\n");
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
            printf("����      ID         �̸�        ����\n");
            printf("=====================================\n");
            for (i = 0; i < num_user; i++)
            {
                if ((list[i].id > 0) && (list[i].user_del == ����))
                {
                    count++;
                    printf("%d        %d   %s      ", count, list[i].id, list[i].name);
                    switch (list[i].right)
                    {
                    case ������:
                        printf("������\n");
                        break;
                    case ���˰�:
                        printf("���˰�\n");
                        break;
                    case �����Ȯ�ΰ�:
                        printf("�����Ȯ�ΰ�\n");
                        break;
                    case ��üȮ�ΰ�:
                        printf("��üȮ�ΰ�\n");
                        break;
                    case ����ĿȮ�ΰ�:
                        printf("����ĿȮ�ΰ�\n");
                        break;
                    case ��ŸȮ�ΰ�:
                        printf("��ŸȮ�ΰ�\n");
                        break;
                    default:
                        break;
                    }
                }
            }
            printf("\n\n��ü ȸ�� ���� %d���Դϴ�.\n\n", count);
            printf("1. ID������ ����\n\n");
            printf("2. �̸������� ����\n\n");
            printf("3. �ڷ� ����\n\n");
            printf("��ȣ�� �Է��ϼ��� : ");
            scanf("%d", &num);
            if (num == 3)
            {
                break;
            }
            char blabla[100];

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
                printf("����    ID       �̸�      ����\n");
                printf("===============================\n");
                for (i = 0; i < num_user; i++)
                {
                    if ((list[i].id > 0) && (list[i].user_del == ����))
                    {
                        count++;
                        printf("%d    %d    %s   ", count, list[i].id, list[i].name);
                        switch (list[i].right)
                        {
                        case ������:
                            printf("������\n");
                            break;
                        case ���˰�:
                            printf("���˰�\n");
                            break;
                        case �����Ȯ�ΰ�:
                            printf("�����Ȯ�ΰ�\n");
                            break;
                        case ��üȮ�ΰ�:
                            printf("��üȮ�ΰ�\n");
                            break;
                        case ����ĿȮ�ΰ�:
                            printf("����ĿȮ�ΰ�\n");
                            break;
                        case ��ŸȮ�ΰ�:
                            printf("��ŸȮ�ΰ�\n");
                            break;
                        default:
                            break;
                        }
                    }
                }
                printf("�����Ͻ÷��� �ƹ�Ű�� �����ּ���");
                scanf("%s", blabla);
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
                printf("����    ID       �̸�      ����\n");
                printf("===============================\n");
                for (i = 0; i < num_user; i++)
                {
                    if ((list[i].id > 0) && (list[i].user_del == ����))
                    {
                        count++;
                        printf("%d    %d    %s   ", count, list[i].id, list[i].name);
                        switch (list[i].right)
                        {
                        case ������:
                            printf("������\n");
                            break;
                        case ���˰�:
                            printf("���˰�\n");
                            break;
                        case �����Ȯ�ΰ�:
                            printf("�����Ȯ�ΰ�\n");
                            break;
                        case ��üȮ�ΰ�:
                            printf("��üȮ�ΰ�\n");
                            break;
                        case ����ĿȮ�ΰ�:
                            printf("����ĿȮ�ΰ�\n");
                            break;
                        case ��ŸȮ�ΰ�:
                            printf("��ŸȮ�ΰ�\n");
                            break;
                        default:
                            break;
                        }
                    }
                }
                printf("�����Ͻ÷��� �ƹ�Ű�� �����ּ���");
                scanf("%s", blabla);
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
    int mode;
    system("cls");
    name_welcome();

    printf("��� ����մϴ�...\n\n");
    for (i = num_check_tool; i < num_check_tool + 1; i++)
    {
        printf("����(�з�)�� �Է��ϼ���\n\n1.�����\n\n2.��ü\n\n3.����Ŀ\n\n4.��Ÿ\n\n>>>");
        scanf("%d", &make.toolnum);

        if (make.toolnum == �����)
        {
            strcpy(make.toolname, "�����");
        }

        else if (make.toolnum == ��ü)
        {
            strcpy(make.toolname, "��ü");
        }

        else if (make.toolnum == ����Ŀ)
        {
            strcpy(make.toolname, "����Ŀ");
        }

        else if (make.toolnum == ��Ÿ)
        {
            strcpy(make.toolname, "��Ÿ");
        }

        else
        {
            printf("�߸��Է��߽��ϴ�.");
            getch();
            return 0;
        }

        printf("\n�𵨸��� �Է��ϼ���>>> ");
        scanf("%s", make.model);

        do {
            printf("\n�ø��� �ѹ� �Է�>>> ");
            scanf("%s", &make.SN);
            if (strlen(make.SN) > length_SN) //���ڿ� ���� �Լ� 
            {
                printf("�Է� ����!! �ø��� �ѹ��� ���Է��ϼ���.\n");
            }
        } while (strlen(make.SN) > length_SN);


        do {
            printf("\n�԰� �⵵�� �Է��ϼ���>>>");
            scanf("%d", &make.year);
            if (make.year > 9999)
            {
                printf("�Է� ����!! �԰�⵵�� ���Է��ϼ���.\n"); // ���ڿ��� ������ Ȯ ���������� 
            }
        } while (make.year > 9999);


        do {
            printf("\n�԰� ���� �Է��ϼ���>>>");
            scanf("%d", &make.month);
            if (make.month > 12)
            {
                printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n");
            }
        } while (make.month > 12);

        do {
            printf("\n�԰� ���� �Է��ϼ���>>>");
            scanf("%d", &make.day);
            if (make.day > 31)
            {
                printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n");
            }
        } while (make.day > 31);


        printf("\n���˻��� �ڵ� �Է� ��...\n");
        for (j = num_check_tool; j < num_user; j++)
        {
            if (make.toolnum == �����)
            {
                strcpy(make.checklist[1], "����� ���˻���1");
                strcpy(make.checklist[2], "����� ���˻���2");
            }

            else if (make.toolnum == ��ü)
            {
                strcpy(make.checklist[1], "��ü ���˻���1");
                strcpy(make.checklist[2], "��ü ���˻���2");
            }

            else if (make.toolnum == ����Ŀ)
            {
                strcpy(make.checklist[1], "����Ŀ ���˻���1");
                strcpy(make.checklist[2], "����Ŀ ���˻���2");
            }

            else if (make.toolnum == ��Ÿ)
            {
                strcpy(make.checklist[1], "��Ÿ ���˻���1");
                strcpy(make.checklist[2], "��Ÿ ���˻���2");
            }
            //gets(make.checklist[j]);
        }

        printf("\n----------------------------------------��� ���-----------------------------------------\n\n");

        printf("�з�\t�𵨸�\t�ø���ѹ�\t\t�԰���\t\t���˻���-1\t\t���˻���-2\n");
        printf("==============================================================================================\n");
        printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", make.toolname, make.model, make.SN, make.year, make.month, make.day, make.checklist[1], make.checklist[2]);

        printf("%s ��� ����Ͻðڽ��ϱ�? (1.YES/2.NO)\n", make.toolname);
        scanf("%d", &check);

        if (check == 1)
        {
            tool[num_check_tool] = make;
            ptool[num_check_tool] = &tool[num_check_tool];
            tool[num_check_tool].next = &tool[num_check_tool + 1];
            tool[num_check_tool + 1].next = NULL;
            //tool[i].toolnum = make.toolnum; // ��� �з� ���� 
            //strcpy(tool[i].toolname, make.toolname); //��� �з� ����
            //strcpy(tool[i].model, make.model); //�𵨸� 
            //strcpy(tool[i].SN, make.SN); // �ø��� �ѹ� 
            //tool[i].year = make.year;
            //tool[i].month = make.month;
            tool[i].tool_del = ����;

            strcpy(tool[i].checklist[1], make.checklist[1]);
            strcpy(tool[i].checklist[2], make.checklist[2]);
            strcpy(tool[i].agree, "n");
       
            printf("-----------------------------------------��� ���------------------------------------------\n\n");

            printf("�з�\t�𵨸�\t�ø���ѹ�\t\t�԰���\t\t���˻���-1\t\t���˻���-2\n");
            printf("==============================================================================================\n");
            printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day, tool[i].checklist[1], tool[i].checklist[2]);
            printf("��ϵǾ����ϴ�.\n");
            Sleep(2000);
            /*tool[num_check_tool] = make;*/
            tool[i].num = ++i;
            //reset[num_check_tool] = &tool[num_check_tool]; //�迭 �ʱ�ȭ
            num_check_tool++;  //��� �� ����
            return;
        }

        else if (check == 2)
        {
            printf("��ҵǾ����ϴ�.\n");
            Sleep(2000);
            return;
        }
    }
    printf("\n\n");
}
int toolmenu2() // ��� ����
{
    char name[20];
    int subject = 0;
    int i, j;
    int a;
    int mode = 0;
    int error = 0;

    system("cls");
    name_welcome();
    printf("-----------------------------------------��� ����------------------------------------------\n\n");

    printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
    printf("=======================================================================\n");
    for (i = 0; i < num_check_tool; i++)
    {
        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
    }

    printf("\n\n������ ��� �𵨸��� �Է����ּ���\n>>>");
    scanf("%s", name);

    for (i = 0; i < num_check_tool; i++)
    {
        if (!strcmp(name, tool[i].model))
        {
            error++;
            printf("\n� �׸��� �����Ͻðڽ��ϱ�?\n\n1. �з�\n\n2. �𵨸�\n\n3. �ø��� �ѹ�\n\n4. ���ο���\n\n5. �԰� �⵵\n\n6. �԰� ��\n\n7. �԰� ����\n\n>>>");
            scanf("%d", &subject);

            switch (subject)
            {

            case 1:
                if (subject == 1)
                {
                    printf("��� �з��� ��� �����Ͻðڽ��ϱ�?\n\n1.�����\n\n2. ��ü\n\n3. ����Ŀ\n\n4. ��Ÿ\n\n>>>");
                    scanf("%d", &tool[i].toolnum);

                    printf("���˻��� �ڵ� ���� ��...\n");
                    for (j = num_check_tool; j < 3; j++)
                    {
                        if (tool[i].toolnum == �����)
                        {
                            strcpy(tool[i].checklist[1], "����� ���˻���1");
                            strcpy(tool[i].checklist[2], "����� ���˻���2");
                        }

                        else if (tool[i].toolnum == ��ü)
                        {
                            strcpy(tool[i].checklist[1], "��ü ���˻���1");
                            strcpy(tool[i].checklist[2], "��ü ���˻���2");
                        }

                        else if (tool[i].toolnum == ����Ŀ)
                        {
                            strcpy(tool[i].checklist[1], "����Ŀ ���˻���1");
                            strcpy(tool[i].checklist[2], "����Ŀ ���˻���2");
                        }

                        else if (tool[i].toolnum == ��Ÿ)
                        {
                            strcpy(tool[i].checklist[1], "��Ÿ ���˻���1");
                            strcpy(tool[i].checklist[2], "��Ÿ ���˻���2");
                        }
                        //gets(make.checklist[j]);
                    }
                }

            case 2:
                if (subject == 2)
                {
                    printf("�𵨸��� ��� �����Ͻðڽ��ϱ�? >>");
                    scanf("%s", &tool[i].model);
                }

            case 3:
                if (subject == 3)
                {
                    do {
                        printf("�ø���ѹ��� ��� �����Ͻðڽ��ϱ�?\n\n>>>");
                        scanf("%s", &tool[i].SN);
                        if (strlen(tool[i].SN) > length_SN) //���ڿ� ���� �Լ� 
                        {
                            printf("�Է� ����!! �ø��� �ѹ��� ���Է��ϼ���.\n\n>>>");
                        }
                    } while (strlen(tool[i].SN) > length_SN);

                }

            case 4: //???????? ���⼭ ������ �����ؾ��Ѱ�
                if (subject == 4)
                {
                    printf("���ο��θ� ��� �����Ͻðڽ��ϱ�?\n\n'y' or 'n'\n\n>>>");
                    scanf("%s", &tool[i].agree);
                }

            case 5:
                if (subject == 5)
                {
                    do {
                        printf("�԰� �⵵�� ��� �����Ͻðڽ��ϱ�?\n\n>>>");
                        scanf("%d", &tool[i].year);
                        if (tool[i].year > 9999)
                        {
                            printf("�Է� ����!! �԰�⵵�� ���Է��ϼ���.\n\n>>>");
                        }
                    } while (tool[i].year > 9999);
                }

            case 6:
                if (subject == 6)
                {
                    do {
                        printf("�԰� ���� ��� �����Ͻðڽ��ϱ�?\n\n>>>");
                        scanf("%d", &tool[i].month);
                        if (tool[i].month > 12)
                        {
                            printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n\n>>>");
                        }
                    } while (tool[i].month > 12);
                }

            case 7:
                if (subject == 7)
                {
                    do {
                        printf("�԰� ���� ��� �����Ͻðڽ��ϱ�?\n\n>>>");
                        scanf("%d", &tool[i].day);
                        if (tool[i].day > 31)
                        {
                            printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n\n>>>");
                        }
                    } while (tool[i].day > 31);
                }
            default:
                break;
            }
            printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
            printf("===================================================================\n");
            printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            ptool[num_tool] = &tool[i];
            printf("\n������ �Ϸ�Ǿ����ϴ�.\n\n");
            Sleep(2000);
            return 0;
        }
        else
        {
            printf("�߸� �Է�! �ٽ� �ѹ� Ȯ�����ּ���\n\n");
        }

        if (tool[i].toolnum == �����)
        {
            strcpy(tool[i].toolname, "�����");
        }

        else if (tool[i].toolnum == ��ü)
        {
            strcpy(tool[i].toolname, "��ü");
        }

        else if (tool[i].toolnum == ����Ŀ)
        {
            strcpy(tool[i].toolname, "����Ŀ");
        }

        else if (tool[i].toolnum == ��Ÿ)
        {
            strcpy(tool[i].toolname, "��Ÿ");
        }
    }
    if (error == 0)
    {
        printf("�ش� ���� �����ϴ�. �ٽ� �ѹ� Ȯ�����ּ���\n\n");
        printf("\n��������� �̵��Ͻðڽ��ϱ�?\n");
        printf("\n1. �̵� \n\n2. �ڷΰ���\n");
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
int toolmenu3() //��ȸ
{
    char name[20];
    int tnum;
    int num;
    int i;
    int j;
    /*struct tool_info temp;*/
    struct tool_info *temp;
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0; //�� �� 
    int wrong = 0;
    char tname1[20];
    char tname2[20];

    int mode = 0;
    system("cls");
    name_welcome();

    printf("1. �˻� ��ȸ\n\n");
    printf("2. ��ü ��ȸ\n\n");
    printf("3. �з��� ��ȸ\n\n");
    printf("4. ��¥�� ��ȸ\n\n");
    printf("��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        system("cls");

        printf("�𵨸� �Է�:");
        scanf("%s", name);

        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");

        for (i = 0; i < num_check_tool; i++)
        {
            if (!strcmp(name, ptool[i]->model))
            {
                if (ptool[i]->tool_del == ����)
                {
                    printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
                }
                strcpy(tname1, ptool[i]->model);
                count5++;
                wrong++;
            }
        }

        //for (i = 0; i < num_check_tool; i++)
        //{
        //    if (!strcmp(name, tool[i].model))
        //    {
        //        if (tool[i].tool_del == ����)
        //        {
        //            printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
        //        }
        //        strcpy(tname1, tool[i].model);
        //        count5++;
        //        wrong++;
        //    }
        //}

        if (wrong == 0)
        {
            printf("�ش� ���� �����ϴ�. �ٽ� �Է��ϼ���. ");
        }

        printf("\n %s �� ������ %d �� �Դϴ�.\n", tname1, count5);
        printf("\n\n");
        break;

    case 2:
        system("cls");
        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");
        //for (i = 0; i < num_check_tool; i++)
        //{
        //    if (ptool[i]->tool_del == ����)
        //    {
        //        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
        //    }
        //    count++;
        //}

        for (i = 0; i < num_check_tool; i++)
        {
            if (tool[i].tool_del == ����)
            {
                printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            }
            count++;
        }

        int a;
        printf("\n\n ��ü ��� ������ %d �� �Դϴ�.\n\n", count);
        printf("\n");
        printf("1. �з��� �迭\n\n");
        printf("2. ��¥�� �迭\n\n");
        printf("\n");
        printf("��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &a);

        switch (a)
        {
        case 1: //�з� �� ��¥ �迭 
            system("cls");
            while (1)
            {
                //��¥ �迭 �� 
                for (i = 0; i < num_check_tool - 1; i++)
                {
                    for (j = 0; j < num_check_tool - 1 - i; j++)
                    {
                        if (ptool[j]->year > ptool[j + 1]->year)
                        {
                            temp = ptool[j];
                            ptool[j] = ptool[j + 1];
                            ptool[j + 1] = temp;
                        }
                        else if (ptool[j]->year == ptool[j + 1]->year)
                        {
                            if (ptool[j]->month > ptool[j + 1]->month)
                            {
                                temp = ptool[j];
                                ptool[j] = ptool[j + 1];
                                ptool[j + 1] = temp;
                            }
                            else if (ptool[j]->month == ptool[j + 1]->month)
                            {
                                if (ptool[j]->day > ptool[j + 1]->day)
                                {
                                    temp = ptool[j];
                                    ptool[j] = ptool[j + 1];
                                    ptool[j + 1] = temp;
                                }
                            }
                        }
                    }
                }

                //for (i = 0; i < num_check_tool - 1; i++)
                //{
                //    for (j = 0; j < num_check_tool - 1 - i; j++)
                //    {
                //        if (tool[j].year > tool[j + 1].year)
                //        {
                //            temp = tool[j];
                //            tool[j] = tool[j + 1];
                //            tool[j + 1] = temp;
                //        }
                //        else if (tool[j].year == tool[j + 1].year)
                //        {
                //            if (tool[j].month > tool[j + 1].month)
                //            {
                //                temp = tool[j];
                //                tool[j] = tool[j + 1];
                //                tool[j + 1] = temp;
                //            }
                //            else if (tool[j].month == tool[j + 1].month)
                //            {
                //                if (tool[j].day > tool[j + 1].day)
                //                {
                //                    temp = tool[j];
                //                    tool[j] = tool[j + 1];
                //                    tool[j + 1] = temp;
                //                }
                //            }
                //        }
                //    }
                //}

                //�з��� �迭 
                for (i = 0; i < num_check_tool; i++)
                {
                    for (j = 0; j < num_check_tool - 1 - i; j++)
                    {
                        if (ptool[j]->toolnum > ptool[j + 1]->toolnum)
                        {
                            temp = ptool[j];
                            ptool[j] = ptool[j + 1];
                            ptool[j + 1] = temp;
                        }
                    }
                }

                //for (i = 0; i < num_check_tool; i++)
                //{
                //    for (j = 0; j < num_check_tool - 1 - i; j++)
                //    {
                //        if (tool[j].toolnum > tool[j + 1].toolnum)
                //        {
                //            temp = tool[j];
                //            tool[j] = tool[j + 1];
                //            tool[j + 1] = temp;
                //        }
                //    }
                //}

                printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
                printf("===================================================================\n");
                for (i = 0; i < num_check_tool; i++)
                {
                    if (ptool[i]->tool_del == ����)
                    {
                        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
                    }
                    count1++;
                }

                //for (i = 0; i < num_check_tool; i++)
                //{
                //    if (tool[i].tool_del == ����)
                //    {
                //        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
                //    }
                //    count1++;
                //}

                printf("\n\n ��� ������ %d �� �Դϴ�.\n\n", count1);
                /*tool_reset(temp);*/
                break;
            }
            break;

        case 2: //��¥�� �迭(��������)
            system("cls");
            while (1)
            {
                for (i = 0; i < num_check_tool - 1; i++)
                {
                    for (j = 0; j < num_check_tool - 1 - i; j++)
                    {
                        if (ptool[j]->year > ptool[j + 1]->year)
                        {
                            temp = ptool[j];
                            ptool[j] = ptool[j + 1];
                            ptool[j + 1] = temp;
                        }
                        else if (ptool[j]->year == ptool[j + 1]->year)
                        {
                            if (ptool[j]->month > ptool[j + 1]->month)
                            {
                                temp = ptool[j];
                                ptool[j] = ptool[j + 1];
                                ptool[j + 1] = temp;
                            }
                            else if (ptool[j]->month == ptool[j + 1]->month)
                            {
                                if (ptool[j]->day > ptool[j + 1]->day)
                                {
                                    temp = ptool[j];
                                    ptool[j] = ptool[j + 1];
                                    ptool[j + 1] = temp;
                                }
                            }
                        }
                    }
                }

                //for (i = 0; i < num_check_tool - 1; i++)
                //{
                //    for (j = 0; j < num_check_tool - 1 - i; j++)
                //    {
                //        if (tool[j].year > tool[j + 1].year)
                //        {
                //            temp = tool[j];
                //            tool[j] = tool[j + 1];
                //            tool[j + 1] = temp;
                //        }
                //        else if (tool[j].year == tool[j + 1].year)
                //        {
                //            if (tool[j].month > tool[j + 1].month)
                //            {
                //                temp = tool[j];
                //                tool[j] = tool[j + 1];
                //                tool[j + 1] = temp;
                //            }
                //            else if (tool[j].month == tool[j + 1].month)
                //            {
                //                if (tool[j].day > tool[j + 1].day)
                //                {
                //                    temp = tool[j];
                //                    tool[j] = tool[j + 1];
                //                    tool[j + 1] = temp;
                //                }
                //            }
                //        }
                //    }
                //}
                printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
                printf("===================================================================\n");
                for (i = 0; i < num_check_tool; i++)
                {
                    if (ptool[i]->tool_del == ����)
                    {
                        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
                    }

                    //if (tool[i].tool_del == ����)
                    //{
                    //    printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
                    //}
                    count2++;
                }
                printf("\n\n ��ü ��� ������ %d �� �Դϴ�.\n\n", count2);
                /*tool_reset(temp);*/
                break;
            }
            break;
        }

            printf("\n\n");
            break;

    case 3: //���� 
        system("cls");

        printf("�з� ��ȣ �Է� \n 1.�����\n 2. ��ü\n 3. ����Ŀ\n 4. ��Ÿ\n  >>>");
        scanf("%d", &tnum);


        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");

        for (i = 0; i < num_check_tool; i++)
        {
            if (ptool[i]->toolnum == tnum)
            {
                if (ptool[i]->tool_del == ����)
                {
                    printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
                    strcpy(tname2, ptool[i]->toolname);
                }
                count3++;
                wrong++;
            }

            //if (tool[i].toolnum == tnum)
            //{
            //    if (tool[i].tool_del == ����)
            //    {
            //        printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            //        strcpy(tname2, tool[i].toolname);
            //    }
            //    count3++;
            //    wrong++;
            //}
        }
        if (wrong == 0)
        {
            printf("\n�ش� ���� �����ϴ�. �ٽ� �Է��ϼ���. \n");
        }

        printf("\n %s�� ������ %d �� �Դϴ�.\n", tname2, count3);
        printf("\n\n");
        break;


    case 4: //(��¥�� ��������)
        system("cls");

        for (i = 0; i < num_check_tool - 1; i++)
        {
            for (j = 0; j < num_check_tool - 1 - i; j++)
            {
                if (ptool[j]->year > ptool[j + 1]->year)
                {
                    temp = ptool[j];
                    ptool[j] = ptool[j + 1];
                    ptool[j + 1] = temp;
                }
                else if (ptool[j]->year == ptool[j + 1]->year)
                {
                    if (ptool[j]->month > ptool[j + 1]->month)
                    {
                        temp = ptool[j];
                        ptool[j] = ptool[j + 1];
                        ptool[j + 1] = temp;
                    }
                    else if (ptool[j]->month == ptool[j + 1]->month)
                    {
                        if (ptool[j]->day > ptool[j + 1]->day)
                        {
                            temp = ptool[j];
                            ptool[j] = ptool[j + 1];
                            ptool[j + 1] = temp;
                        }
                    }
                }
            }
        }

        //for (i = 0; i < num_check_tool - 1; i++)
        //{
        //    for (j = 0; j < num_check_tool - 1 - i; j++)
        //    {
        //        if (tool[j].year > tool[j + 1].year)
        //        {
        //            temp = tool[j];
        //            tool[j] = tool[j + 1];
        //            tool[j + 1] = temp;
        //        }
        //        else if (tool[j].year == tool[j + 1].year)
        //        {
        //            if (tool[j].month > tool[j + 1].month)
        //            {
        //                temp = tool[j];
        //                tool[j] = tool[j + 1];
        //                tool[j + 1] = temp;
        //            }
        //            else if (tool[j].month == tool[j + 1].month)
        //            {
        //                if (tool[j].day > tool[j + 1].day)
        //                {
        //                    temp = tool[j];
        //                    tool[j] = tool[j + 1];
        //                    tool[j + 1] = temp;
        //                }
        //            }
        //        }
        //    }
        //}

        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");
        for (i = 0; i < num_check_tool; i++)
        {
            if (tool[i].tool_del == ����)
            {
                printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", ptool[i]->toolname, ptool[i]->model, ptool[i]->SN, ptool[i]->agree, ptool[i]->year, ptool[i]->month, ptool[i]->day);
            }
            count4++;

            //if (tool[i].tool_del == ����)
            //{
            //    printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            //}
            //count4++;
        }
        printf("\n\n ��ü ��� ������ %d �� �Դϴ�.\n\n", count4);
        break;
    }
    
    printf("\n\n");
    printf("���ư��Ƿ��� �ƹ�Ű�� ��������\n");
    getch();
    system("cls");
}
int toolmenu4() {
    int i, del_find = 0, del_check;
    char del_choose[length_model];
    int num;
    int mode = 0;
    system("cls");
    name_welcome();

    printf("1. ���� \n\n");
    printf("2. ���� \n\n");
    printf("3. �ڷΰ���\n\n");
    printf("��ȣ �Է� : ");
    scanf("%d", &num);

    if (num == 1) {
        system("cls");
        printf("����  �з�       �𵨸�        �ø���ѹ�       �԰���      ����\n");
        printf("=================================================================\n");
        for (i = 0; i < num_check_tool; i++)
        {
            printf(" %d   %3s %15s %15s   %4d-%2d-%2d ", i + 1, tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day);
            if (tool[i].tool_del == ����) printf("   ����\n");
            else printf("\n");
        }

        printf("\n������ �𵨸��� �Է��ϼ��� : ");
        scanf("%s", del_choose);
        for (i = 0; i < num_check_tool; i++) {
            if (strcmp(tool[i].model, del_choose) == 0) {
                printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n ��ȣ �Է� : ");
                scanf("%d", &del_check);
                if (del_check == 1) {
                    printf("�����Ǿ����ϴ�.\n");
                    tool[i].tool_del = ����;
                    del_find++;
                    getch();
                    return;
                }
                else if (del_check == 2) {
                    printf("��ҵǾ����ϴ�.\n");
                    getch();
                    return;
                }
            }
        }

        if (del_find == 0) {
            printf("�ش� ��� �����ϴ�.\n");
            getch();
        }
    }

    else if (num == 2) {
        system("cls");
        printf("����  �з�       �𵨸�        �ø���ѹ�       �԰���      ����\n");
        printf("=================================================================\n");
        for (i = 0; i < num_check_tool; i++)
        {
            printf(" %d   %3s %15s %15s   %4d-%2d-%2d ", i + 1, tool[i].toolname, tool[i].model, tool[i].SN, tool[i].year, tool[i].month, tool[i].day);
            if (tool[i].tool_del == ����) printf("   ����\n");
            else printf("\n");
        }

        printf("������ �𵨸��� �Է��ϼ��� : ");
        scanf("%s", del_choose);
        for (i = 0; i < num_check_tool; i++) {
            if (strcmp(tool[i].model, del_choose) == 0) {
                printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n ��ȣ �Է� : ");
                scanf("%d", &del_check);
                if (del_check == 1) {
                    printf("�����Ǿ����ϴ�.\n");
                    tool[i].tool_del = ����;
                    del_find++;
                    getch();
                    return;
                }
                else if (del_check == 2) {
                    printf("��ҵǾ����ϴ�.\n");
                    getch();
                    return;
                }
            }
        }

        if (del_find == 0) {
            printf("�ش� ��� �����ϴ�.\n");
            getch();
        }
    }

    else if (num == 3) return;

    else if ((num != 1) && (num != 2))
    {
        printf("�ٽ� �Է��ϼ���.\n");
        toolmenu4();
    }
}
int member_correction(void) // ����
{
    system("cls");
    int num, i = 0;
    struct user_info make;
    int mode = 0;
    system("cls");
    name_welcome();
    printf("����    ID       �̸�      ����\n");
    printf("===============================\n");

    for (i = 0; i < num_user; i++)
    {
        if ((list[i].id > 0) && (list[i].user_del == ����))
        {
            printf("%d    %d    %s   ", i + 1, list[i].id, list[i].name);
            switch (list[i].right)
            {
            case ������:
                printf("������\n");
                break;
            case ���˰�:
                printf("���˰�\n");
                break;
            case �����Ȯ�ΰ�:
                printf("�����Ȯ�ΰ�\n");
                break;
            case ��üȮ�ΰ�:
                printf("��üȮ�ΰ�\n");
                break;
            case ����ĿȮ�ΰ�:
                printf("����ĿȮ�ΰ�\n");
                break;
            case ��ŸȮ�ΰ�:
                printf("��ŸȮ�ΰ�\n");
                break;
            default:
                break;
            }
        }
    }

    while (1)
    {
        int name_count = 0, name_find = 0;

        printf("\n\n������ ȸ���� ID�� �Է����ּ��� : ");
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
                printf("\n� �׸��� �����Ͻðڽ��ϱ�?\n\n");
                printf("1. ID\n\n");
                printf("2. PW\n\n");
                printf("3. �̸�\n\n");
                printf("4. ����\n\n");
                printf("5. ��ü����\n\n");
                printf("6. �ڷΰ���\n\n");
                scanf("%d", &num);
                if ((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5) && (num != 6))
                {
                    printf("�߸� �Է��߽��ϴ�. �ٽ� �Է����ּ���");
                }
            } while ((num != 1) && (num != 2) && (num != 3) && (num != 4) && (num != 5) && (num != 6));

            switch (num)
            {
            case 1:
                printf("\nID�� �����ϼ���.\n");
                printf("ID : ");
                scanf("%d", &make.id);
                do
                {
                    printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
                    scanf("%d", &num);
                    if ((num != 1) && (num != 2))
                    {
                        printf("�߸� �Է��߽��ϴ�\n");
                    }
                } while ((num != 1) && (num != 2));
                if (num == 1)
                {
                    list[name_count - 1].id = make.id;
                }
                break;

            case 2:
                printf("\nPW�� �����ϼ���.\n");
                printf("pw : ");
                scanf("%s", make.pw);
                do
                {
                    printf("�����Ͻðڽ��ϱ�? (1.YES / 2.NO)\n");
                    scanf("%d", &num);
                    if ((num != 1) && (num != 2))
                    {
                        printf("�߸� �Է��߽��ϴ�\n");
                    }
                } while ((num != 1) && (num != 2));
                if (num == 1)
                {
                    strcpy(list[name_count - 1].pw, make.pw);
                }
                break;

            case 3:
                printf("\n�̸��� �����ϼ���.\n");
                printf("�̸� : ");
                scanf("%s", make.name);
                do
                {
                    printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
                    scanf("%d", &num);
                    if ((num != 1) && (num != 2))
                    {
                        printf("�߸� �Է��߽��ϴ�\n");
                    }
                } while ((num != 1) && (num != 2));
                if (num == 1)
                {
                    strcpy(list[name_count - 1].name, make.name);
                }
                break;

            case 4:
                printf("\n������ �����ϼ���.\n(0:������, 1:���˰�, 21:�����Ȯ�ΰ�, 22:��üȮ�ΰ� 23:����ĿȮ�ΰ� 24:��ŸȮ�ΰ�\n");
                do
                {
                    printf("���� : ");
                    scanf("%d", &make.right);
                    if ((make.right != ������) && (make.right != ���˰�) && (make.right != �����Ȯ�ΰ�) && (make.right != ��üȮ�ΰ�) && (make.right != ����ĿȮ�ΰ�) && (make.right != ��ŸȮ�ΰ�))
                    {
                        printf("�ش��ϴ� ������ �����ϴ�\n");
                    }
                } while ((make.right != ������) && (make.right != ���˰�) && (make.right != �����Ȯ�ΰ�) && (make.right != ��üȮ�ΰ�) && (make.right != ����ĿȮ�ΰ�) && (make.right != ��ŸȮ�ΰ�));
                do
                {
                    printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
                    scanf("%d", &num);
                    if ((num != 1) && (num != 2))
                    {
                        printf("�߸� �Է��߽��ϴ�\n");
                    }
                } while ((num != 1) && (num != 2));
                if (num == 1)
                {
                    list[name_count - 1].right = make.right;
                }
                break;
            case 5:
                printf("\nID,PW,�̸�,������ �����ϼ���.\n");
                printf("ID : ");
                scanf("%d", &make.name);
                printf("PW : ");
                scanf("%s", &make.pw);
                printf("�̸� : ");
                scanf("%s", &make.name);
                do
                {
                    printf("����(0:������, 1:���˰�, 21:�����Ȯ�ΰ�, 22:��üȮ�ΰ� 23:����ĿȮ�ΰ� 24:��ŸȮ�ΰ�):  ");
                    scanf("%d", &make.right);
                    if ((make.right != ������) && (make.right != ���˰�) && (make.right != �����Ȯ�ΰ�) && (make.right != ��üȮ�ΰ�) && (make.right != ����ĿȮ�ΰ�) && (make.right != ��ŸȮ�ΰ�))
                    {
                        printf("�ش��ϴ� ������ �����ϴ�\n");
                    }
                } while ((make.right != ������) && (make.right != ���˰�) && (make.right != �����Ȯ�ΰ�) && (make.right != ��üȮ�ΰ�) && (make.right != ����ĿȮ�ΰ�) && (make.right != ��ŸȮ�ΰ�));
                do
                {
                    printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
                    scanf("%d", &num);
                    if ((num != 1) && (num != 2))
                    {
                        printf("�߸� �Է��߽��ϴ�\n");
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
                printf("�ش��ϴ� ȸ���� �����ϴ�. (1 : �ڷΰ��� 2: �ٽ� �Է�)\n");
                scanf("%d", &num);
                if ((num != 1) && (num != 2))
                {
                    printf("�߸� �Է��߽��ϴ�\n");
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
int member_delete_restore(void) //��������
{
    while (1)
    {
        system("cls");
        int num;
        int count = 0;
        int id_find = 0;
        int i;
        struct user_info make;
        int mode = 0;
        system("cls");
        name_welcome();

        printf("1. ���� \n\n");
        printf("2. ���� \n\n");
        printf("3. �ڷΰ���\n\n");
        scanf("%d", &num);

        if (num == 3)
        {
            return;
        }
        if ((num != 1) && (num != 2))
        {
            printf("�ٽ� �Է��ϼ���!!\n");
            Sleep(1000);
            member_delete_restore();
        }
        switch (num)
        {
        case 1:
            system("cls");
            printf("����    ID       �̸�\n");
            printf("===============================\n");
            for (i = 0; i < num_user; i++)
            {
                if ((list[i].id > 0) && (list[i].user_del == ����))
                {
                    count++;
                    printf(" %d     %d   %s\n\n", count, list[i].id, list[i].name);
                }
            }

            while (1)
            {
                printf("������ ID�� �Է��ϼ��� : ");
                scanf("%d", &num);

                for (i = 0; i < num_user; i++)
                {
                    if (num == list[i].id)
                    {
                        make.user_del = ����;
                        id_find++;
                        do
                        {
                            printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
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
                        printf("�ش��ϴ� ID�� �����ϴ�.(1 : �ڷΰ��� 2: �ٽ� �Է�)\n");
                        scanf("%d", &num);
                        if ((num != 1) && (num != 2))
                        {
                            printf("�߸� �Է��߽��ϴ�\n");
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
            printf("����    ID       �̸�      ����\n");
            printf("=================================\n");

            for (i = 0; i < num_user; i++)
            {
                if (list[i].id > 0)
                {
                    count++;
                    printf(" %d     %d   %s", count, list[i].id, list[i].name);
                    if (list[i].user_del == ����)
                    {
                        printf("   ����\n");
                    }
                }
            }

            while (1)
            {
                printf("\n\n������ ID�� �Է��ϼ��� : ");
                scanf("%d", &num);

                for (i = 0; i < num_user; i++)
                {
                    if (num == list[i].id)
                    {
                        make.user_del = ����;
                        printf("�����Ͻðڽ��ϱ� ? (1.YES / 2.NO)\n");
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
                        printf("�ش��ϴ� ID�� �����ϴ�.(1 : �ڷΰ��� 2: �ٽ� �Է�)\n");
                        scanf("%d", &num);
                        if ((num != 1) && (num != 2))
                        {
                            printf("�߸� �Է��߽��ϴ�\n");
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
    int mode = 0;
    system("cls");
    name_welcome();

    if (right == 21) tool_agree_page("�����");
    else if (right == 22) tool_agree_page("��ü");
    else if (right == 23) tool_agree_page("����Ŀ");
    else if (right == 20) tool_agree_page("��Ÿ");
}
int tool_agree1(int right) {
    int i, j;
    int mode = 0;
    system("cls");
    name_welcome();

    printf("�з�   �𵨸�     �ø���ѹ�   ���ο���    �԰���     ���˳��� �� ���\n");
    printf("=============================================================================\n");
    for (i = 0; i < num_check_tool; i++) {
        if (tool[i].toolnum == right - 20) {
            if (tool[i].tool_del == ����)
                printf("%s     %s        %s        %s   %d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            for (j = 1; j < 3; j++) {   //3�� �ӽ� ���˰���
                printf("%d. %s : ", j, tool[i].checklist[j]);
                if (tool[i].state[j] == 0) printf("������\n");
                else if (tool[i].state[j] == 1) printf("��ȣ\n");
                else if (tool[i].state[j] == 2) printf("�ҷ�\n");
            }
            printf("-----------------------------------------------------------------------------\n");
        }
    }
}
int tool_agree2(int right) {
    int agree;
    char name[20];
    int i, j;
    int mode = 0;
    system("cls");
    name_welcome();

    printf("�з�   �𵨸�     �ø���ѹ�   ���ο���    �԰���     ���˳��� �� ���\n");
    printf("=============================================================================\n");
    for (i = 0; i < num_check_tool; i++) {
        if (tool[i].toolnum == list[right].right - 20) {
            if (tool[i].tool_del == ����) printf("%s     %s        %s        %s   %d-%d-%d\n", tool[i].toolname, tool[i].model, tool[i].SN, tool[i].agree, tool[i].year, tool[i].month, tool[i].day);
            for (j = 1; j < 3; j++) {   //3�� �ӽ� ���˰���
                printf("%d. %s : ", j, tool[i].checklist[j]);
                if (tool[i].state[j] == 0) printf("������\n");
                else if (tool[i].state[j] == 1) printf("��ȣ\n");
                else if (tool[i].state[j] == 2) printf("�ҷ�\n");
            }

            if (tool[i].agree_check != 0) {
                printf("<�̹� �����ϼ̽��ϴ�.> ");
                printf("Ȯ�ΰ� : %s\n", list[right].name);
            }

            else if (tool[i].agree_check == 0) {
                printf("�ش� ��� ���� ���� (1. YES / 2. NO) (���� �� öȸ �Ұ� !) : ");
                scanf("%d", &agree);
                if (agree == 1) {
                    printf("���� : ");
                    scanf("%s", name);
                    printf("<�����ϼ̽��ϴ�.>\n");
                    strcpy(tool[i].agree, "����");
                    getch();
                    tool[i].agree_check++;
                }
                else if (agree == 2) {
                    printf("�����");
                }
            }
            printf("-----------------------------------------------------------------------------\n");
        }
    }
}

int tool_reset(struct tool_info *reset)
{
    int i, j = 0;

    for (i = 0; i < num_check_tool; i++)
    {
        for (j = 0; j < num_check_tool - 1 - i; j++)
        {
            if (ptool[j]->num > ptool[j + 1]->num)
            {
                reset = ptool[j];
                ptool[j] = ptool[j + 1];
                ptool[j + 1] = reset;
            }
        }
    }
}

int name_welcome(void)
{
    printf("-----------------------%s�� ȯ���մϴ�.----------------------------\n\n\n",list[check_list].name);
}

struct tool_info* createNode() 
{

    //int n_;
    //char n_id[20], n_dept[20], n_name[20], n_blood[20];
    //float n_height, n_weight;

    //int num;
    //int in_date;
    //int tool_del;
    //char agree[10];
    //int state[5];
    //int year, month, day;
    //char toolname[length_tool];
    //int toolnum;
    //char model[length_model];
    //char SN[length_SN];
    //char checklist[5][200];
    //int agree_check;

    struct tool_info* temp = (struct tool_info*)malloc(sizeof(struct tool_info));

    int i, j;
    int check;
    struct tool_info make;
    int mode;
    system("cls");
    name_welcome();

    printf("��� ����մϴ�...\n\n");
    for (i = num_check_tool; i < num_check_tool + 1; i++)
    {
        printf("����(�з�)�� �Է��ϼ���\n\n1.�����\n\n2.��ü\n\n3.����Ŀ\n\n4.��Ÿ\n\n>>>");
        scanf("%d", &make.toolnum);

        if (make.toolnum == �����)
        {
            strcpy(make.toolname, "�����");
        }

        else if (make.toolnum == ��ü)
        {
            strcpy(make.toolname, "��ü");
        }

        else if (make.toolnum == ����Ŀ)
        {
            strcpy(make.toolname, "����Ŀ");
        }

        else if (make.toolnum == ��Ÿ)
        {
            strcpy(make.toolname, "��Ÿ");
        }

        else
        {
            printf("�߸��Է��߽��ϴ�.");
            getch();
            return 0;
        }

        printf("\n�𵨸��� �Է��ϼ���>>> ");
        scanf("%s", make.model);

        do {
            printf("\n�ø��� �ѹ� �Է�>>> ");
            scanf("%s", &make.SN);
            if (strlen(make.SN) > length_SN) //���ڿ� ���� �Լ� 
            {
                printf("�Է� ����!! �ø��� �ѹ��� ���Է��ϼ���.\n");
            }
        } while (strlen(make.SN) > length_SN);


        do {
            printf("\n�԰� �⵵�� �Է��ϼ���>>>");
            scanf("%d", &make.year);
            if (make.year > 9999)
            {
                printf("�Է� ����!! �԰�⵵�� ���Է��ϼ���.\n"); // ���ڿ��� ������ Ȯ ���������� 
            }
        } while (make.year > 9999);


        do {
            printf("\n�԰� ���� �Է��ϼ���>>>");
            scanf("%d", &make.month);
            if (make.month > 12)
            {
                printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n");
            }
        } while (make.month > 12);

        do {
            printf("\n�԰� ���� �Է��ϼ���>>>");
            scanf("%d", &make.day);
            if (make.day > 31)
            {
                printf("�Է� ����!! �԰� ���� ���Է��ϼ���.\n");
            }
        } while (make.day > 31);


        printf("\n���˻��� �ڵ� �Է� ��...\n");
        for (j = num_check_tool; j < num_user; j++)
        {
            if (make.toolnum == �����)
            {
                strcpy(make.checklist[1], "����� ���˻���1");
                strcpy(make.checklist[2], "����� ���˻���2");
            }

            else if (make.toolnum == ��ü)
            {
                strcpy(make.checklist[1], "��ü ���˻���1");
                strcpy(make.checklist[2], "��ü ���˻���2");
            }

            else if (make.toolnum == ����Ŀ)
            {
                strcpy(make.checklist[1], "����Ŀ ���˻���1");
                strcpy(make.checklist[2], "����Ŀ ���˻���2");
            }

            else if (make.toolnum == ��Ÿ)
            {
                strcpy(make.checklist[1], "��Ÿ ���˻���1");
                strcpy(make.checklist[2], "��Ÿ ���˻���2");
            }
            //gets(make.checklist[j]);
        }

        printf("\n----------------------------------------��� ���-----------------------------------------\n\n");

        printf("�з�\t�𵨸�\t�ø���ѹ�\t\t�԰���\t\t���˻���-1\t\t���˻���-2\n");
        printf("==============================================================================================\n");
        printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", make.toolname, make.model, make.SN, make.year, make.month, make.day, make.checklist[1], make.checklist[2]);

        printf("%s ��� ����Ͻðڽ��ϱ�? (1.YES/2.NO)\n", make.toolname);
        scanf("%d", &check);

        if (check == 1)
        {
            temp->toolnum = make.toolnum; // ��� �з� ���� 
            strcpy(temp->toolname, make.toolname); //��� �з� ����
            strcpy(temp->model, make.model); //�𵨸� 
            strcpy(temp->SN, make.SN); // �ø��� �ѹ� 
            temp->year = make.year;
            temp->month = make.month;
            temp->day = make.day;
            strcpy(temp->checklist[1], make.checklist[1]);
            strcpy(temp->checklist[2], make.checklist[2]);
            strcpy(temp->agree, "n");
            temp->tool_del = ����;

            printf("-----------------------------------------��� ���------------------------------------------\n\n");

            printf("�з�\t�𵨸�\t�ø���ѹ�\t\t�԰���\t\t���˻���-1\t\t���˻���-2\n");
            printf("==============================================================================================\n");
            printf("%.10s\t%.20s\t%.20s\t%20d-%d-%d\t%s\t%.20s \n\n", temp->toolname, temp->model, temp->SN, temp->year, temp->month, temp->day, temp->checklist[1], temp->checklist[2]);
            printf("��ϵǾ����ϴ�.\n");
            Sleep(2000);
            //ptool[num_check_tool] = &tool[num_check_tool];
            num_check_tool++;  //��� �� ����

            temp->next = NULL;

            return temp;
        }

        else if (check == 2)
        {
            printf("��ҵǾ����ϴ�.\n");
            Sleep(2000);
            return;
        }
    }
}

int toolmenu1_link(struct tool_info* *head)
{
    //���޹��� ���� �����ϴ� ���ο� ��带 ����.
    struct tool_info *newtool_info = createNode();
    // ��忡 �ƹ��͵� ���� ���
    // ��, ���� ��尡 �ϳ��� ���� ���
    if (*head == NULL)
    {
        // ��忡 ������ ��带 ����
        *head = newtool_info;
    }
    else
    {
        struct tool_info* temp = *head;
        // ������ ��带 ã�� ����
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // ������ ����� ��� ���� ������ ��� ����
        temp->next = newtool_info;
    }

}

int search_node() 
{
    char name[20];
    int tnum;
    int num;
    int i;
    int j;
    /*struct tool_info temp;*/
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0; //�� �� 
    int wrong = 0;
    char tname1[20];
    char tname2[20];
    int mode = 0;
    struct tool_info* temp = head;

    system("cls");
    name_welcome();

    printf("1. �˻� ��ȸ\n\n");
    printf("2. ��ü ��ȸ\n\n");
    printf("��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        system("cls");

        printf("�𵨸� �Է�:");
        scanf("%s", name);

        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");
        while ((temp->next) != NULL) //head������ �����ͺ��� �����Ͽ�
        {
            if (!strcmp(name, temp->model))
            {
                if (temp->tool_del == ����)
                {
                    printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", temp->toolname, temp->model, temp->SN, temp->agree, temp->year, temp->month, temp->day);
                }
                wrong++;
                count5++;
            }
            temp = temp->next;
        }
        if (wrong == 0)
        {
            printf("�ش� ���� �����ϴ�. �ٽ� �Է��ϼ���. ");
            break;
        }

        printf("\n %s �� ������ %d �� �Դϴ�.\n", name, count5);
        printf("\n\n");
        temp = head;
        break;

    case 2:
        system("cls");
        printf("�з�\t�𵨸�\t�ø���ѹ�\t���ο���\t�԰���\n");
        printf("===================================================================\n");
        while ((temp->next) != NULL) //head������ �����ͺ��� �����Ͽ�
        {
            count++;
            if (tool->tool_del == ����)
            {
                printf("%.10s\t%.20s\t%.20s\t\t%.10s\t%12d-%d-%d\n", temp->toolname, temp->model, temp->SN, temp->agree, temp->year, temp->month, temp->day);
                temp = temp->next;
            }
        }
    }

    printf("\n\n");
    printf("���ư��Ƿ��� �ƹ�Ű�� ��������\n");
    getch();
    system("cls");
}