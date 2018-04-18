include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES +=     INPUT_DIR=\\\"$$PWD\\\"

HEADERS +=     tst_test1.h \
    ../app/myfunc.h \
    fibonachi_test.h \
    ../app/common.h \
    ../app/text.h \
    ../app/_text.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/showunderscores.c \
    ../app/cursors.c \
    ../app/process_forward.c \
    ../app/create_text.c \
    ../app/load.c \
    ../app/remove_all.c \
    ../app/append_line.c

INCLUDEPATH += ../app
