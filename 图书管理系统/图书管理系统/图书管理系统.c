#define _CRT_SECURE_NO_WARNINGS
#define PATH_BOOK	"C:\\Users\\admin\\Desktop\\图书管理系统\\BOOK.txt"
#define PATH_STUDENT "C:\\Users\\admin\\Desktop\\图书管理系统\\STUDENT.txt"
#define PATH_PASS "C:\\Users\\admin\\Desktop\\图书管理系统\\PASSWORD.txt"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include<string.h>
#include"标头.h"

//链表放在main函数中供所有函数使用；
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
	build_file();//建立文件.
	input_file_password();//设定输入初始密码
	while (input_password())
	{
		printf("密码输入错误，请重新输入.\n");
		Sleep(1000);
		printf("等待跳转");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
	}
	while (1)
	{
		int choose = 0;
		printf("输入成功.\n");
		Sleep(1000);
		printf("等待跳转");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		menu();//显示菜单
	//打开书籍文本
		FILE *fp_book = fopen(PATH_BOOK, "r");
		if (fp_book == NULL)
		{
			printf("未能打开文件_BOOK");
			exit(1);
		}
		//创建关于书籍的链表
		struct book *phead_book = (struct book*)malloc(sizeof(struct book));
		if (phead_book == NULL)
		{
			printf("未能成功分配内存");
			system("pause");
			exit(1);
		}
		struct book *ptail_book = phead_book;
		struct book *pnew_book = phead_book;
		//将文件中的数据输入头链表
		fscanf(fp_book, "%s", &phead_book->name_book);
		fscanf(fp_book, "%s", &phead_book->author);
		fscanf(fp_book, "%s", &phead_book->statue);
		//循环读取文件数据建立新的结构体
		char judge_next[30];
		while (fscanf(fp_book, "%s", judge_next) != EOF)
		{
			pnew_book = (struct book*)malloc(sizeof(struct book));
			if (pnew_book == NULL)
			{
				printf("未能成功分配内存");
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



		//打开学生文本
		FILE *fp_student = fopen(PATH_STUDENT, "r");
		if (fp_book == NULL)
		{
			printf("未能打开文件_STUDENT");
			exit(1);
		}
		//创建关于书籍的链表
		struct student *phead_student = (struct student*)malloc(sizeof(struct student));
		if (phead_student == NULL)
		{
			printf("未能成功分配内存");
			system("pause");
			exit(1);
		}
		struct student *ptail_student = phead_student;
		struct student *pnew_student = phead_student;
		ptail_student->next = NULL;
		//将文件中的数据输入链表并且根据数据的数目创建链表
		fscanf(fp_book, "%s", &phead_student->name_book);
		fscanf(fp_book, "%s", &phead_student->name_student);
		fscanf(fp_book, "%s", &phead_student->sex);
		fscanf(fp_book, "%s", &phead_student->student_number);
		fscanf(fp_book, "%s", &phead_student->data);
		//循环建立新的结构体,从文本中输入数据到学生的链表中;
		while (fscanf(fp_book, "%s", judge_next) != EOF)
		{
			pnew_student = (struct student*)malloc(sizeof(struct student));
			if (pnew_student == NULL)
			{
				printf("未能成功分配内存");
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


		
		printf("*************请输入选项*****************\n");
		scanf("%d",&choose);
		if (choose == 1)
		{
			search_book(phead_book);
			getchar();
			system("pause");
			printf("\n\n------------输入9返回主界面-------------");
			printf("\n------------输入其他数退出程序-----------");
			scanf("%d", &choose);
			if (choose == 9) 
			{
				continue;
			}
			else
			{
				system("cls");
				printf("准备退出程序，请稍后。。。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后");
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
				printf("未能成功分配内存");
				system("pause");
				exit(1);
			}
			ptail_book->next = pnew_book;
			ptail_book = pnew_book;
			ptail_book->next = NULL;
			printf("*******************************************\n");
			printf("输入要增加书籍的书名,必须带上书名号:");
			scanf("%s", ptail_book->name_book);
			printf("\n输入书籍的作者:");
			scanf("%s", ptail_book->author);
			strcpy(ptail_book->statue, "未借出");
			into_file_book(phead_book);//将数据写入文件
			printf("\n请稍等");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".\n");
			printf("操作完成,请选择.\n");
			printf("*************输入9返回主界面**************\n");
			printf("*************输入其他数字退出程序*********\n");
			scanf("%d", &choose);
			if (choose == 9)
				continue;
			else
			{
				system("cls");
				printf("准备退出程序，请稍后。。。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后");
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
				printf("未能成功分配内存");
				system("pause");
				exit(1);
			}
			//添加借书学生信息
			char name_book[20];
			ptail_student->next = pnew_student;
			ptail_student = pnew_student;
			ptail_student->next = NULL;
			printf("\n请输入借阅书名，带书名号：");
			scanf("%s",name_book);
			if (check_book(phead_book, name_book) == 1)
			{
				printf("图书馆没有这个书籍，请管理员添加后重试");
				continue;
			}
			else
			{

				strcpy(ptail_student->name_book, name_book);
				printf("\n请输入学生姓名:");
				scanf("%s", ptail_student->name_student);
				printf("\n请输入学生性别：");
				scanf("%s", ptail_student->sex);
				printf("\n请输入学生学号:");
				scanf("%s", ptail_student->student_number);
				printf("\n请输入借阅日期:");
				scanf("%s", ptail_student->data);
				borrow(phead_book, name_book);//将文件中的书籍换成已借出
			}
			/*printf("%s", ptail_student->name_book);
			int i=0;
			ptail_student->name_book[20] = '\0';
			for (i = 0; i < 30; i++)
			{
				if (ptail_student->name_book[i] == '\0')
					printf("存在");
			}*/
			into_file_student(phead_student);//将学生链表输入文件
			into_file_book(phead_book);//将书籍列表输入文件
			printf("\n借阅中，请等待.\n");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			printf("\n借阅完毕，请继续操作");
			printf("\n\n------------输入9返回主界面-------------");
			printf("\n------------输入其他数退出程序-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("准备退出程序，请稍后。。。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后");
				exit(0);
			}
		}
		
		else
		if (choose == 4)
		{
			printf("请输入归还的书籍，带上书名号:");
			char name_book[20];
			scanf("%s", name_book);
			book_return(phead_book, name_book);//添加一个函数将书籍中文本换成未借出
			//将学生从借书名单中删去
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
			into_file_student(phead_student);//将学生链表输入文件
			system("pause");
			printf("\n\n------------输入9返回主界面-------------");
			printf("\n------------输入其他数退出程序-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("准备退出程序，请稍后。。。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后");
				exit(0);
			}
		}

		else
		if(choose == 5)
		{
			search_student(phead_student);
			system("pause");
			printf("\n\n------------输入9返回主界面-------------");
			printf("\n------------输入其他数退出程序-----------");
			scanf("%d", &choose);
			if (choose == 9)
			{
				continue;
			}
			else
			{
				system("cls");
				printf("准备退出程序，请稍后。。。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后。");
				Sleep(1000);
				system("cls");
				printf("\n准备退出程序，请稍后");
				exit(0);
			}
		}
		else
		if(choose == 6)
		{
			system("cls");
			printf("********************************\n");
			printf("-------正在退出程序-------------\n");
			Sleep(500);
			printf("---------------3---------------\n");
			Sleep(500);
			printf("---------------2---------------\n");
			Sleep(500);
			printf("---------------1---------------\n");
			Sleep(500);
			exit(0);
		}

		//释放
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
	//增加图书
	pnew_book = (struct book*)malloc(sizeof(struct book));
	if (pnew_book == NULL)
	{
		printf("未能成功分配内存");
		system("pause");
		exit(1);
	}
	ptail_book->next = pnew_book;
	ptail_book = pnew_book;
	ptail_book->next = NULL;
	printf("输入要增加书籍的书名,必须带上书名号:");
	scanf("%s", ptail_book->name_book);
	printf("输入书籍的作者");
	scanf("%s", ptail_book->author);
	strcpy(ptail_book->statue, "未借出");
	//此处加上一个将图书链表写入文件的函数
	


	
	//添加链表
	pnew_student = (struct student*)malloc(sizeof(struct student));
	if (pnew_student == NULL)
	{
		printf("未能成功分配内存");
		system("pause");
		exit(1);
	}
	//添加借书学生信息
	char name_book[20];
	ptail_student->next = pnew_student;
	ptail_student = pnew_student;
	ptail_student->next = NULL;
	printf("\n请输入借阅书名，带书名号：");
	scanf("%s", name_book);
	if (check_book(phead_book, name_book) == 1)
	{
		printf("图书馆没有这个书籍，请管理员添加后重试");
	}
	else
	{
		strcpy(ptail_book->name_book, name_book);
		printf("\n请输入学生姓名:");
		scanf("%s", ptail_student->name_student);
		printf("\n请输入学生性别：");
		scanf("%s", ptail_student->sex);
		printf("\n请输入学生学号:");
		scanf("%s", ptail_student->student_number);
		printf("请输入借阅日期:");
		scanf("%s", ptail_student->data);
	}//添加一个函数将书籍中文本换成已借出;


	//还书

	printf("请输入归还的书籍，带上书名号:");
	scanf("%s", name_book);
	//添加一个函数将书籍中文本换成未借出
	//将学生从借书名单中删去
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