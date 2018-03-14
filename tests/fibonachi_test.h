#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text.h"
#include "_text.h"
}

TEST(showunderscoresTest, 1) {
    char* a = (char*) malloc (6);
    a[0] = 'a';
    a[1] = ' ';
    a[2] = 'b';
    a[3] = ' ';
    a[4] = 'c';
    a[5] = 0;
    char* b = (char*) malloc (6);
    b[0] = 'a';
    b[1] = '_';
    b[2] = 'b';
    b[3] = '_';
    b[4] = 'c';
    b[5] = 0;

    char* c = showunderscores_line(0, a);
    for (int i = 0; i < 5; i++)
        if (c[i] != b[i]) {
            free(a);
            free(b);
            free(c);
            FAIL();
        }

    free(a);
    free(b);
    free(c);
    SUCCEED();
}

TEST(showunderscoresTest, 2) {
    char* a = (char*) malloc(2);
    a[0] = ' ';
    a[1] = 0;
    char* b = (char*) malloc(2);
    b[0] = '_';
    b[1] = 0;

    char* c = showunderscores_line(0, a);
    if (c[0] != b[0]) {
        free(a);
        free(b);
        free(c);
        FAIL();
    } else if (strlen(c) != strlen(b)) {
        free(a);
        free(b);
        free(c);
        FAIL();
    }
    free(a);
    free(b);
    free(c);
    SUCCEED();
}

TEST(showunderscoresTest, 3) {
    char* a = (char*) malloc(1);
    a[0] = 0;
    showunderscores_line(0, a);
    SUCCEED();
}


//TEST(fibonachiTest, num0) {
//    ASSERT_EQ(fibonachi(0), 0);
//    ASSERT_EQ(fibonachi(1), 1);
//    ASSERT_EQ(fibonachi(2), 2);
//}

//TEST(fibonachiTest, greather2) {
//    ASSERT_EQ(fibonachi(5), 5);
//    ASSERT_EQ(fibonachi(10), 55);
//}

//TEST(fibonachiTest, negative) {
//    ASSERT_EQ(fibonachi(-1), 0);
//}

#endif // FIBONACHI_H
