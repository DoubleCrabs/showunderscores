#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>
#include <fcntl.h>

#define OUTPUT 1
#define BUFFER_SIZE 1024

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

TEST(showunderscoresFullTest, 4) {
    char* test1_path = (char *) malloc (sizeof(char) * 1024);
    sprintf(test1_path, "%s/input-output/t1.txt", INPUT_DIR);

    char* test2_path = (char *) malloc (sizeof(char) * 1024);
    sprintf(test2_path, "%s/input-output/t2.txt", INPUT_DIR);

    char* test_out_path = (char *) malloc (sizeof(char) * 1024);
    sprintf(test_out_path, "%s/input-output/t_out.txt", INPUT_DIR);


    text txt = create_text();
    load(txt, test1_path);

    int outFd = open(test_out_path, O_WRONLY|O_CREAT,  S_IRUSR|S_IWUSR);
    int oldOutput = dup(OUTPUT);
    dup2(outFd, OUTPUT);
    showunderscores(txt);
    close(outFd);
    dup2(oldOutput, OUTPUT);

    int f1 = open(test_out_path, O_RDONLY);
    int f2 = open(test2_path, O_RDONLY);
    int f1Length, f2Length;
    char* buf1 = (char*) malloc (sizeof(char) * BUFFER_SIZE);
    char* buf2 = (char*) malloc (sizeof(char) * BUFFER_SIZE);

    do {
        f1Length = read(f1, buf1, BUFFER_SIZE);
        f2Length = read(f2, buf2, BUFFER_SIZE);
        ASSERT_EQ(f1Length, f2Length);
        for (int i = 0; i < f1Length; i++)
            ASSERT_EQ(buf1[i], buf2[i]);
    } while (f1Length > 0);

    close(f1);
    close(f2);
    free(txt);
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
