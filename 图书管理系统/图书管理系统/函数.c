 #define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define PATH_BOOK	"C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\BOOK.txt"
#define PATH_STUDENT "C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\STUDENT.txt"
#define PATH_PASS "C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\PASSWORD.txt"

struct book//					Ϊʲô�ں����л�Ҫ����һ��������������
{
	char name_book[30];
	char author[30];
	char statue[10];
	struct book *next;
};
struct student
{
	char name_student[10];
	char data[20];
	char sex[6];
	char name_book[30];
	char student_number[20];
	struct student *next;
};

//��ʾ�˵�
void menu()
{
	system("cls");
	printf("                   ͼ�����ϵͳ\n");
	printf("*-----------------------------------------------*\n");
	printf("*                  1:�鿴�鼮                   *\n");
	printf("*                  2:�����鼮                   *\n");
	printf("*                  3:����ͼ��                   *\n");
	printf("*                  4:�黹ͼ��                   *\n");
	printf("*                  5:�鿴�ѽ����ͼ��           *\n");
	printf("*                  6:�˳�                       *\n");
	printf("*-----------------------------------------------*\n");
}

//�����ļ�������+ͼ���ļ�+�����ļ���
void build_file()
{
	FILE *fp_pass, *fp_book, *fp_borrow;
	fp_pass = fopen(PATH_PASS, "w+");
	fp_borrow = fopen(PATH_STUDENT, "a+");
	fp_book = fopen(PATH_BOOK, "a+");
	if (fp_pass == NULL)
	{
		printf("δ�ܴ��ļ�");
		exit(1);
	}
	if (fp_borrow == NULL)
	{
		printf("δ�ܴ��ļ�");
		exit(1);
	}
	if (fp_book == NULL)
	{
		printf("δ�ܴ��ļ�");
		exit(1);
	}
	fclose(fp_pass);
	fclose(fp_book);
	fclose(fp_borrow);
}

//����ʼ���뵼���ļ�,Ҳ�ɴ��ı�ֱ�Ӹ���,��ʼ����:18271400-18271440�������޷�����/��ӡ�
void input_file_password()
{
	system("cls");
	int i = 0;
	FILE *fp_pass = fopen(PATH_PASS, "w+");
	if (fp_pass == NULL)
	{
		printf("δ�ܴ��ļ�");
		exit(1);
	}
	for (i = 18271400; i <= 18271440; i++)
	{
		fprintf(fp_pass, "%d\n", i);
	}
	fclose(fp_pass);
}

//��������������,���ɹ����룬����0�����򷵻�1,��Ҫ�ں���������ѭ����
int  input_password()
{
	system("cls");
	int pass, true_pass; 
	FILE *fp;
	fp = fopen(PATH_PASS, "r+");
	if (fp == NULL)
	{
		printf("��������ʧ��__�޷��������ļ�");
		system("pause");
		exit(1);
	}
	printf("		����������			\n");
	printf("		����:");
	scanf("%d", &pass);
	while (fscanf(fp, "%d", &true_pass) != EOF)
	{
		if (true_pass == pass)
			return 0;
	}
	return 1;
}

//������뻺����,ֱ�����з�ֹͣ��������ջ��з���
void clear_input()
{
	char ch;
	while ((ch = getchar()) != '\n');
}

//�г������鼮
void search_book(struct book*phead)
{
	system("cls");
	printf("�鼮����\t\t����\t\t�������\n");
	while (phead !=NULL)
	{
		printf("%s", phead->name_book);
		if (strlen(phead->name_book) > 14)
			printf("\t");
		else
			printf("\t\t");
		printf("%s",phead->author);
		if (strlen(phead->author) > 7)
			printf("\t");
		else
			printf("\t\t");
		printf("%s",phead->statue);
		printf("\n");
		phead = phead->next;
	}
}

//���������Ƿ��н��ĵ��鼮
int check_book(struct book *phead,char*book)
{
	while (phead != NULL)
	{
		if (strcmp( phead->name_book, book) == 0)
			return 0;
		else
			phead = phead->next;
	}
	return 1;
}

//���鼮����д���ļ�
void into_file_book(struct book *phead)
{
	FILE *fp_book = fopen(PATH_BOOK, "w");
	while(phead != NULL)
	{
		fprintf(fp_book,"%s", phead->name_book);
		if (strlen(phead->name_book) > 14)
			fprintf(fp_book,"\t");
		else
			fprintf(fp_book,"\t\t");
		fprintf(fp_book,"%s", phead->author);
		if (strlen(phead->author) > 7)
			fprintf(fp_book,"\t");
		else
			fprintf(fp_book,"\t\t");
		fprintf(fp_book,"%s", phead->statue);
		fprintf(fp_book,"\n");
		phead = phead->next;
	}
	fclose(fp_book);
}

//�������е��鼮�����ѽ��
void borrow(struct book *phead, char book[20])
{
	while (phead != NULL)
	{
		if (strcmp(phead->name_book, book) == 0)
		{
			strcpy(phead->statue, "�ѽ��");
			return;
		}
		phead = phead->next;
	}
}

//��ѧ�����������ļ�
void into_file_student(struct student *phead)
{
	FILE *fp_student = fopen(PATH_STUDENT, "w");
	while (phead != NULL)
	{
		fprintf(fp_student,"%s",phead->name_book);
		if (strlen(phead->name_book) > 14)
			fprintf(fp_student, "\t");
		else
			fprintf(fp_student, "\t\t");
		fprintf(fp_student,"%s",phead->name_student);
		if (strlen(phead->name_student) > 7)
			fprintf(fp_student,"\t");
		else
			fprintf(fp_student,"\t\t");
		fprintf(fp_student,"%s",phead->sex);
		fprintf(fp_student,"\t\t");
		fprintf(fp_student,"%s",phead->student_number);
		fprintf(fp_student,"\t\t");
		fprintf(fp_student,"%s",phead->data);
		fprintf(fp_student,"\t\t");
		fprintf(fp_student,"\n");
		phead = phead->next;
	}
	fclose(fp_student);
}

//���ļ��е��鼮����δ���
void book_return(struct book *phead, char book[20])
{
	while (phead != NULL)
	{
		if (strcmp(phead->name_book, book) == 0)
		{
			strcpy(phead->statue, "δ���");
			return;
		}
		phead = phead->next;
	}
}

//�г����н�������
void search_student(struct student *phead)
{
	system("cls");
	while (phead != NULL)
	{
		printf("%s", phead->name_book);
		if (strlen(phead->name_book) > 14)
			printf("\t");
		else
			printf("\t\t");
		printf("%s", phead->name_student);
		if (strlen(phead->name_student) > 7)
			printf("\t");
		else
			printf("\t\t");
		printf("%s", phead->sex);
		printf("\t");
		printf("%s", phead->student_number);
		printf("\t");
		printf("%s", phead->data);
		printf("\n");
		phead = phead->next;
	}
}


//�����������鼮
/*
���̸���		����¡�����	δ���
����ʷ�� 		ϣ�޶��	δ���
�����ޱ�����ս��ʷ��	�����׵�	δ���
���軨Ů��		С����		δ���
���Ի�¼��		����ͼ		δ���
������ѧ�� 		����ʿ���	δ���
��������˹�ǡ�		ά����		δ���
��ϣ������Ӣ��ʷ�� 	��³����	δ���
��80λ�������˵Ĺ��¡�	����		δ���
������ͬ�á�  		����		δ���
�������� 		����		δ���
�����ز��׹��¼���	����		δ���
�����а		����˹.Ī��	δ���
�������ۡ� 		�����ά��	δ���
�����˴��� 		������		δ���
���á���ڭ�¡�		������˹	δ���
�����Լ��� 		��.��ϣ����	δ���
��ʧ��԰�� 		�׶���		δ���
����·���̡� 		Լ��.�ೡ	δ���
��һǧ��һҹ��  	����		δ���
��³����Ư���ǡ� 	�����.�Ѹ�	δ���
�����з��μǡ� 		˹��������	δ���



����ѧ����Ϣ�Ŀ�ͷ
�鼮����	ѧ������	�Ա�	ѧ��	��������

*/