/**
 * showunderscores.c  - программа для вывода текста
 * с заменой пробелов символами подчёркивания
 *
 * Copyright (c) 2017, Artem Zaicev <zaicev@cs.karelia.ru>
 *
 * This code licensed under a MIT-style license
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text.h"


//выводит строку с заменой пробелов
//символами нижнего подчёркивания
char* showunderscores_line(int index, char* contents);

void showunderscores(text txt)
{
    //добавляем курсор в текст
    print_cursor(txt);

    //прямой порядок следования, построчно
    //применяем функцию showunderscores_line
    process_forward(txt, showunderscores_line);

    //убираем курсор из текста
    remove_cursor(txt);
}

//выводит строку с заменой пробелов
//символами нижнего подчёркивания
char* showunderscores_line(int index, char* contents)
{
    //всегда получаем существующую строку
    assert(contents != NULL);

    //неиспользуемый параметр
    UNUSED(index);
    int i;
    int contents_length = strlen(contents) + 1;
    
    char* copy_of_contents = NULL;
    copy_of_contents = (char*) malloc (contents_length);
    for (i = 0; i < contents_length; i++)
	copy_of_contents[i] = contents[i];
    
    //заменяем пробелы в строке на
    //символы нижнего подчёркивания
    for (i = 0; i < contents_length; i++)
	if (copy_of_contents[i] == ' ')
	    copy_of_contents[i] = '_';
    //выводим полученную строку
    printf("%s", copy_of_contents);
    return copy_of_contents;
}
    
