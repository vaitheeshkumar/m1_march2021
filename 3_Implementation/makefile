PROJ_NAME = snake
TEST_PROJ_NAME = tests

SRC = src/logic.c

TEST_SRC = test/tests.c\
unity/unity.c

INC = -Iinc\
-Iunity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	
	gcc -o snake main.c src/logic.c src/displayscore.c -lncurses

run: all
	./snake

test: $(SRC) $(TEST_SRC)
	gcc -lm $^ $(INC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC)) 
	./tests.out


coverage:${PROJECT_NAME}
	
	gcov -a main.c

doc:
	make -C doc
$(BUILD_DIR):
	mkcom $(BUILD_DIR)

clean:
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
