#ifndef __MY_FUNC_H__
#define __MY_FUNC_H__

#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"

int menu(Tel **tel_list, int max); // 원형함수 선언
void insert(Tel **tel_list, int max, int count);
void print_all(Tel **tel_list, int count);
int delete_user(Tel **tel_list, int count);
void find_by_birth(Tel **tel_list, int count);
int RegFromFile_read(Tel **tel_list, int count);
void RegFromFile_write(Tel **tel_list, int count);
void sort(Tel **tel_list, int count);

#endif