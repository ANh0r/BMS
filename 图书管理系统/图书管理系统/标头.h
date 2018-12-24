#pragma once





void menu(void);//显示菜单

void build_file(void);//建立文件（密码+图书文件+借阅文件）

void input_file_password(void);////将初始密码导入文件,也可打开文本直接更改,初始密码:18271400-18271440

int  input_password(void);//输入密码进入界面,若成功输入，返回0，否则返回1,需要在函数外利用循环

void clear_input(void);//清空输入缓存区,直到换行符停止（包括清空换行符）

void search_book(struct book*phead);//列出文件中所有书籍


int check_book(struct book *phead, char*book);//检查书库中是否有借阅的书籍,有则返回0，否则返回1

void into_file_book(struct book *phead);//将书籍链表写入文件;


void borrow(struct book *phead, char book[20]);//将链表中的书籍换成已借出

void into_file_student(struct student *phead);//将学生链表输入文件

void book_return(struct book *phead, char book[20]);//将文件中的书籍换成未借出

void search_student(struct student *phead);//列出所有借书名单