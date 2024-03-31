PROJECT_NAME = matrix
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
DEPS = $(PROJECT_NAME).h
SOURCE = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SOURCE))
LIB = $(PROJECT_NAME).a
TEST = test
GCOV = gcov_report
REP = report
UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
LIBS = $(shell pkg-config --cflags --libs check)
OPEN_REPORT = open
LEAKS = CK_FORK=no leaks --atExit -- ./test
endif
ifeq ($(UNAME), Linux)
LIBS = -lcheck -lsubunit -lrt -lm -lpthread -g
OPEN_REPORT = xdg-open
LEAKS = CK_FORK=no valgrind -s --leak-check=full --track-origins=yes ./test
endif


rebuild : clean all

all : $(LIB) $(TEST) $(GCOV)

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)	

$(LIB) : $(OBJ)
	ar rc $@ $^
	ranlib $@

$(TEST) : 
	checkmk clean_mode=1 test.check > ${TEST}.c
	$(CC) $(SOURCE) ${TEST}.c -o $@ $(LIBS)
	./$@

$(GCOV): $(TEST)
	$(CC) --coverage ${TEST}.c $(SOURCE) -o $(TEST) $(LIBS)
	./$(TEST)
	lcov -t "test" -o ${TEST}.info -c -d .
	genhtml -o $(REP) ${TEST}.info
	$(OPEN_REPORT) report/index.html

check:
	cp ../.clang-format ./
	clang-format -style=Google -n *.c *.h
	rm .clang-format

clean : 
	rm -rf ${TEST}.c $(TEST) *.gcno *.gcda *.gch ${TEST}.info $(REP) $(LIB) $(OBJ) 

leaks:	
	$(LEAKS)	