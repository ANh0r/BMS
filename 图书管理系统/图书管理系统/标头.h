#pragma once





void menu(void);//��ʾ�˵�

void build_file(void);//�����ļ�������+ͼ���ļ�+�����ļ���

void input_file_password(void);////����ʼ���뵼���ļ�,Ҳ�ɴ��ı�ֱ�Ӹ���,��ʼ����:18271400-18271440

int  input_password(void);//��������������,���ɹ����룬����0�����򷵻�1,��Ҫ�ں���������ѭ��

void clear_input(void);//������뻺����,ֱ�����з�ֹͣ��������ջ��з���

void search_book(struct book*phead);//�г��ļ��������鼮


int check_book(struct book *phead, char*book);//���������Ƿ��н��ĵ��鼮,���򷵻�0�����򷵻�1

void into_file_book(struct book *phead);//���鼮����д���ļ�;


void borrow(struct book *phead, char book[20]);//�������е��鼮�����ѽ��

void into_file_student(struct student *phead);//��ѧ�����������ļ�

void book_return(struct book *phead, char book[20]);//���ļ��е��鼮����δ���

void search_student(struct student *phead);//�г����н�������