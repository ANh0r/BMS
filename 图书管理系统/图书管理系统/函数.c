 #define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define PATH_BOOK	"C:\\Users\\admin\\Desktop\\图书管理系统\\BOOK.txt"
#define PATH_STUDENT "C:\\Users\\admin\\Desktop\\图书管理系统\\STUDENT.txt"
#define PATH_PASS "C:\\Users\\admin\\Desktop\\图书管理系统\\PASSWORD.txt"

struct book//					为什么在函数中还要创建一个？？？？？？
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

//显示菜单
void menu()
{
	system("cls");
	printf("                   图书管理系统\n");
	printf("*-----------------------------------------------*\n");
	printf("*                  1:查看书籍                   *\n");
	printf("*                  2:增加书籍                   *\n");
	printf("*                  3:借阅图书                   *\n");
	printf("*                  4:归还图书                   *\n");
	printf("*                  5:查看已借出的图书           *\n");
	printf("*                  6:退出                       *\n");
	printf("*-----------------------------------------------*\n");
}

//建立文件（密码+图书文件+借阅文件）
void build_file()
{
	FILE *fp_pass, *fp_book, *fp_borrow;
	fp_pass = fopen(PATH_PASS, "w+");
	fp_borrow = fopen(PATH_STUDENT, "a+");
	fp_book = fopen(PATH_BOOK, "a+");
	if (fp_pass == NULL)
	{
		printf("未能打开文件");
		exit(1);
	}
	if (fp_borrow == NULL)
	{
		printf("未能打开文件");
		exit(1);
	}
	if (fp_book == NULL)
	{
		printf("未能打开文件");
		exit(1);
	}
	fclose(fp_pass);
	fclose(fp_book);
	fclose(fp_borrow);
}

//将初始密码导入文件,也可打开文本直接更改,初始密码:18271400-18271440，密码无法更改/添加。
void input_file_password()
{
	system("cls");
	int i = 0;
	FILE *fp_pass = fopen(PATH_PASS, "w+");
	if (fp_pass == NULL)
	{
		printf("未能打开文件");
		exit(1);
	}
	for (i = 18271400; i <= 18271440; i++)
	{
		fprintf(fp_pass, "%d\n", i);
	}
	fclose(fp_pass);
}

//输入密码进入界面,若成功输入，返回0，否则返回1,需要在函数外利用循环。
int  input_password()
{
	system("cls");
	int pass, true_pass; 
	FILE *fp;
	fp = fopen(PATH_PASS, "r+");
	if (fp == NULL)
	{
		printf("程序运行失败__无法打开密码文件");
		system("pause");
		exit(1);
	}
	printf("		请输入密码			\n");
	printf("		密码:");
	scanf("%d", &pass);
	while (fscanf(fp, "%d", &true_pass) != EOF)
	{
		if (true_pass == pass)
			return 0;
	}
	return 1;
}

//清空输入缓存区,直到换行符停止（包括清空换行符）
void clear_input()
{
	char ch;
	while ((ch = getchar()) != '\n');
}

//列出所有书籍
void search_book(struct book*phead)
{
	system("cls");
	printf("书籍名称\t\t作者\t\t借阅情况\n");
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

//检查书库中是否有借阅的书籍
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

//将书籍链表写入文件
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

//将链表中的书籍换成已借出
void borrow(struct book *phead, char book[20])
{
	while (phead != NULL)
	{
		if (strcmp(phead->name_book, book) == 0)
		{
			strcpy(phead->statue, "已借出");
			return;
		}
		phead = phead->next;
	}
}

//将学生链表输入文件
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

//将文件中的书籍换成未借出
void book_return(struct book *phead, char book[20])
{
	while (phead != NULL)
	{
		if (strcmp(phead->name_book, book) == 0)
		{
			strcpy(phead->statue, "未借出");
			return;
		}
		phead = phead->next;
	}
}

//列出所有借书名单
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


//下面是现有书籍
/*
《教父》		马里奥·普佐	未借出
《历史》 		希罗多德	未借出
《伯罗奔尼撒战争史》	修昔底德	未借出
《茶花女》		小仲马		未借出
《对话录》		柏拉图		未借出
《伦理学》 		亚里士多德	未借出
《埃涅阿斯记》		维吉尔		未借出
《希腊罗马英雄史》 	普鲁塔克	未借出
《80位共产党人的故事》	徐焰		未借出
《四世同堂》  		老舍		未借出
《神曲》 		但丁		未借出
《坎特伯雷故事集》	乔叟		未借出
《乌托邦》		托马斯.莫尔	未借出
《君王论》 		马基雅维利	未借出
《巨人传》 		拉伯雷		未借出
《堂·吉诃德》		塞万提斯	未借出
《箴言集》 		拉.洛希福考	未借出
《失乐园》 		米尔顿		未借出
《天路历程》 		约翰.班场	未借出
《一千零一夜》  	民众		未借出
《鲁宾孙漂流记》 	丹尼尔.笛福	未借出
《格列佛游记》 		斯威夫特特	未借出



还有学生信息的开头
书籍名称	学生姓名	性别	学号	借书日期

*/