CC				= gcc
CCLINK			= g++
LIBS			=
CCOPTIONS 		= -Wall -pedantic -std=gnu11 -g
LDOPTIONS		=

TEST    = test_tower_of_hanoi
PROGRAM = tower_of_hanoi

COMMON_HDRS      = config.h general.h 
LIBRARY_FILES    = toh_visualizer shortcut
ASSIGNMENT_FILES = toh_board toh_disk toh_solver
MAIN_DRIVER      = toh_main_driver
TEST_DRIVER      = toh_test_driver

LIBRARY_H        = $(addsuffix .h, $(LIBRARY_FILES))
ASSIGNMENT_H     = $(addsuffix .h, $(ASSIGNMENT_FILES))
ASSIGNMENT_C     = $(addsuffix .c, $(ASSIGNMENT_FILES)) $(MAIN_DRIVER).c

HDRS			 = $(ASSIGNEMT_H) $(SHARED_HDRS) $(COMMON_HDRS) $(LIBRARY_H)
TESTOBJECT       = $(TEST_DRIVER).o
MAINOBJECT       = $(MAIN_DRIVER).o
LIBRARY_OBJS     = $(addsuffix .o, $(LIBRARY_FILES))
TEST_OBJS        = $(addprefix test_, $(addsuffix .o, $(ASSIGNMENT_FILES)))
MAIN_OBJ         = $(addsuffix .o, $(ASSIGNMENT_FILES))
OBJS             = $(LIBRARY_OBJS) $(MAIN_OBJ) $(TEST_OBJS)

DOXY             = doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	rm -f index.html
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

%.o: %.c
	$(CC) $(CCOPTIONS) -c $<

#sets project as sample solution
setsample:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name).sample $(name);)

#sets project as assignment
setassignment:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name).assignment $(name);)

# defines current state of project as sample solution
definesample:
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name) $(name).sample;)

# defines current sate of project as assignment
defineassignment :
	$(foreach name, $(ASSIGNMENT_H) $(ASSIGNMENT_C), cp $(name) $(name).assignment;)

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setassignment
	make doxy
	rm -rf ../assignment
	mkdir ../assignment
	cp -R * ../assignment
	cp .gitignore ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall
