#define _CRT_SECURE_NO_WARNINGS
#define PATH_BOOK	"C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\BOOK.txt"
#define PATH_STUDENT "C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\STUDENT.txt"
#define PATH_PASS "C:\\Users\\admin\\Desktop\\ͼ�����ϵͳ\\PASSWORD.txt"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include<string.h>
#include"��ͷ.h"

//�������main�����й����к���ʹ�ã�
struct book
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




int main()
{
	build_file();//�����ļ�.
	input_file_password();//�趨�����ʼ����
	while (input_password())
	{
		printf("���������������������.\n");
		Sleep(1000);
		printf("�ȴ���ת");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
	}
	while (1)
	{
		int choose = 0;
		printf("����ɹ�.\n");
		Sleep(1000);
		printf("�ȴ���ת");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		menu();//��ʾ�˵�
	//���鼮�ı�
		FILE *fp_book = fopen(PATH_BOOK, "r");
		if (fp_book == NULL)
		{
			printf("δ�ܴ��ļ�_BOOK");
			exit(1);
		}
		//���������鼮������
		struct book *phead_book = (struct book*)malloc(sizeof(struct book));
		if (phead_book == NULL)
		{
			printf("δ�ܳɹ������ڴ�");
			system("pause");
			exit(1);
		}
		struct book *ptail_book = phead_book;
		struct book *pnew_book = phead_book;
		//���ļ��е���������ͷ����
		fscanf(fp_book, "%s", &phead_book->name_book);
		fscanf(fp_book, "%s", &phead_book->author);
		fscanf(fp_book, "%s", &phead_book->statue);
		//ѭ����ȡ�ļ����ݽ����µĽṹ��
		char judge_next[30];
		while (fscanf(fp_book, "%s", judge_next) != EOF)
		{
			pnew_book = (struct book*)malloc(sizeof(struct book));
			if (pnew_book == NULL)
			{
				printf("δ�ܳɹ������ڴ�");
				system("pause");
				exit(1);
			}
			ptail_book->next = pnew_book;
			ptail_book = pnew_book;
			ptail_book->next = NULL;
			strcpy(ptail_book->name_book, judge_next);
			fscanf(fp_book, "%s", &ptail_book->author);
			fscanf(fp_book, "%s", &ptail_book->statue);
		}
		fclose(fp_book);



		//��ѧ���ı�
		FILE *fp_student = fopen(PATH_STUDENT, "r");
		if (fp_book == NULL)
		{
			printf("δ�ܴ��ļ�_STUDENT");
			exit(1);
		}
		//���������鼮������
		struct student *phead_student = (struct student*)malloc(sizeof(struct student));
		if (phead_student == NULL)
		{
			printf("δ�ܳɹ������ڴ�");
			system("pause");
			exit(1);
		}
		struct student *ptail_student = phead_student;
		struct student *pnew_student = phead_student;
		ptail_student->next = NULL;
		//���ļ��е��������������Ҹ������ݵ���Ŀ��������
		fscanf(fp_book, "%s", &phead_student->name_book);
		fscanf(fp_book, "%s", &phead_student->name_student);
		fscanf(fp_book, "%s", &phead_student->sex);
		fscanf(fp_book, "%s", &phead_student->student_number);
		fscanf(fp_book, "%s", &phead_student->data);
		//ѭ�������µĽṹ��,���ı����������ݵ�ѧ����������;
		while (fscanf(fp_book, "%s", judge_next) != EOF)
		{
			pnew_student = (struct student*)malloc(sizeof(struct student));
			if (pnew_student == NULL)
			{
				printf("δ�ܳɹ������ڴ�");
				system("pause");
				exit(1);
			}
			ptail_student->next = pnew_student;
			ptail_student = pnew_student;
			ptail_student->next = NULL;
			strcpy(ptail_student->name_book, judge_next);
			fscanf(fp_student, "%s", &ptail_student->name_student);
			fscanf(fp_student, "%s", &ptail_student->sex);
			fscanf(fp_student, "%s", &ptail_student->student_number);
			fscanf(fp_student, "%s", &ptail_student->data);
		}
		fclose(fp_student);


		
		printf("*************������ѡ��*****************\n");
		scanf("%d",&choose);
		if (choose == 1)
		{
			search_book(phead_book);
			getchar();
			system("pause");
			printf("\n\n------------����9����������-------------");
			printf("\n------------�����������˳�����-----------");
			scanf("%d", &choose);
			if (choose == 9) 
			{
				continue;
			}
			else
			{
				system("cls");
				printf("׼���˳��������Ժ󡣡���");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				exit(0);
			}
		}

		else
		if(choose == 2)
		{
			system("cls");
			pnew_book = (struct book*)malloc(sizeof(struct book));
			if (pnew_book == NULL)
			{
				printf("δ�ܳɹ������ڴ�");
				system("pause");
				exit(1);
			}
			ptail_book->next = pnew_book;
			ptail_book = pnew_book;
			ptail_book->next = NULL;
			printf("*******************************************\n");
			printf("����Ҫ�����鼮������,�������������:");
			scanf("%s", ptail_book->name_book);
			printf("\n�����鼮������:");
			scanf("%s", ptail_book->author);
			strcpy(ptail_book->statue, "δ���");
			into_file_book(phead_book);//������д���ļ�
			printf("\n���Ե�");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".\n");
			printf("�������,��ѡ��.\n");
			printf("*************����9����������**************\n");
			printf("*************�������������˳�����*********\n");
			scanf("%d", &choose);
			if (choose == 9)
				continue;
			else
			{
				system("cls");
				printf("׼���˳��������Ժ󡣡���");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				exit(0);
			}
		}
		
		
		else
		if (choose == 3)
		{
			system("cls");
			pnew_student = (struct student*)malloc(sizeof(struct student));
			if (pnew_student == NULL)
			{
				printf("δ�ܳɹ������ڴ�");
				system("pause");
				exit(1);
			}
			//��ӽ���ѧ����Ϣ
			char name_book[20];
			ptail_student->next = pnew_student;
			ptail_student = pnew_student;
			ptail_student->next = NULL;
			printf("\n����������������������ţ�");
			scanf("%s",name_book);
			if (check_book(phead_book, name_book) == 1)
			{
				printf("ͼ���û������鼮�������Ա��Ӻ�����");
				continue;
			}
			else
			{

				strcpy(ptail_student->name_book, name_book);
				printf("\n������ѧ������:");
				scanf("%s", ptail_student->name_student);
				printf("\n������ѧ���Ա�");
				scanf("%s", ptail_student->sex);
				printf("\n������ѧ��ѧ��:");
				scanf("%s", ptail_student->student_number);
				printf("\n�������������:");
				scanf("%s", ptail_student->data);
				borrow(phead_book, name_book);//���ļ��е��鼮�����ѽ��
			}
			/*printf("%s", ptail_student->name_book);
			int i=0;
			ptail_student->name_book[20] = '\0';
			for (i = 0; i < 30; i++)
			{
				if (ptail_student->name_book[i] == '\0')
					printf("����");
			}*/
			into_file_student(phead_student);//��ѧ�����������ļ�
			into_file_book(phead_book);//���鼮�б������ļ�
			printf("\n�����У���ȴ�.\n");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			printf("\n������ϣ����������");
			printf("\n\n------------����9����������-------------");
			printf("\n------------�����������˳�����-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("׼���˳��������Ժ󡣡���");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				exit(0);
			}
		}
		
		else
		if (choose == 4)
		{
			printf("������黹���鼮������������:");
			char name_book[20];
			scanf("%s", name_book);
			book_return(phead_book, name_book);//���һ���������鼮���ı�����δ���
			//��ѧ���ӽ���������ɾȥ
			struct student *pold = phead_student;
			pnew_student = phead_student;
			while (pnew_student != NULL)
			{
				if (strcmp(pnew_student->name_student, name_book) == 0)
				{
					pold->next = pnew_student->next;
					free(pnew_student);
				}
				pnew_student = pnew_student->next;
			}
			into_file_student(phead_student);//��ѧ�����������ļ�
			system("pause");
			printf("\n\n------------����9����������-------------");
			printf("\n------------�����������˳�����-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("׼���˳��������Ժ󡣡���");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				exit(0);
			}
		}

		else
		if(choose == 5)
		{
			search_student(phead_student);
			system("pause");
			printf("\n\n------------����9����������-------------");
			printf("\n------------�����������˳�����-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("׼���˳��������Ժ󡣡���");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				Sleep(1000);
				system("cls");
				printf("\n׼���˳��������Ժ�");
				exit(0);
			}
		}
		else
		if(choose == 6)
		{
			system("cls");
			printf("********************************\n");
			printf("-------�����˳�����-------------\n");
			Sleep(500);
			printf("---------------3---------------\n");
			Sleep(500);
			printf("---------------2---------------\n");
			Sleep(500);
			printf("---------------1---------------\n");
			Sleep(500);
			exit(0);
		}

		//�ͷ�
		struct book *pfree_book;
		struct student *pfree_student;
		while (phead_book != NULL)
		{
			pfree_book = phead_book->next;
			free(phead_book);
			phead_book = pfree_book;
		}
		while (phead_student != NULL)
		{
			pfree_student = phead_student->next;
			free(phead_student);
			phead_student = pfree_student;
		}

	}
	return 0;
}






/*
	//����ͼ��
	pnew_book = (struct book*)malloc(sizeof(struct book));
	if (pnew_book == NULL)
	{
		printf("δ�ܳɹ������ڴ�");
		system("pause");
		exit(1);
	}
	ptail_book->next = pnew_book;
	ptail_book = pnew_book;
	ptail_book->next = NULL;
	printf("����Ҫ�����鼮������,�������������:");
	scanf("%s", ptail_book->name_book);
	printf("�����鼮������");
	scanf("%s", ptail_book->author);
	strcpy(ptail_book->statue, "δ���");
	//�˴�����һ����ͼ������д���ļ��ĺ���
	


	
	//�������
	pnew_student = (struct student*)malloc(sizeof(struct student));
	if (pnew_student == NULL)
	{
		printf("δ�ܳɹ������ڴ�");
		system("pause");
		exit(1);
	}
	//��ӽ���ѧ����Ϣ
	char name_book[20];
	ptail_student->next = pnew_student;
	ptail_student = pnew_student;
	ptail_student->next = NULL;
	printf("\n����������������������ţ�");
	scanf("%s", name_book);
	if (check_book(phead_book, name_book) == 1)
	{
		printf("ͼ���û������鼮�������Ա��Ӻ�����");
	}
	else
	{
		strcpy(ptail_book->name_book, name_book);
		printf("\n������ѧ������:");
		scanf("%s", ptail_student->name_student);
		printf("\n������ѧ���Ա�");
		scanf("%s", ptail_student->sex);
		printf("\n������ѧ��ѧ��:");
		scanf("%s", ptail_student->student_number);
		printf("�������������:");
		scanf("%s", ptail_student->data);
	}//���һ���������鼮���ı������ѽ��;


	//����

	printf("������黹���鼮������������:");
	scanf("%s", name_book);
	//���һ���������鼮���ı�����δ���
	//��ѧ���ӽ���������ɾȥ
	struct student *pold=phead_book;
	while (pnew_student != NULL)
	{
		if (strcpy(pnew_student->name_student, name_book) == 0)
		{
			pold->next = pnew_student->next;
		}
		pnew_student = pnew_student->next;
	}
	
	















	system("pause");
	return 0;
}*/