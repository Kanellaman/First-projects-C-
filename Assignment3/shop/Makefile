#Compiler
CC=gcc

#.c files
Files=shop.c shopdp.c
#.o Files
OBJS=shop.o

#Executable
EXEC=exe

#Parameters for run
ARGS=3 12 12 6

#input file
INPUT= < em.txt

#Create executable
$(EXEC):$(OBJS)
	$(CC) $(Files) -o $(EXEC)

#Run
run: $(EXEC)
	./$(EXEC) 
#$(ARGS) $(INPUT)

#debug
debug: 
	$(CC) -g3 $(Files) -o $(EXEC) 
	gdb -q $(EXEC)

#memory-loss
memory:
	make
	valgrind --leak-check=full -s ./$(EXEC) $(ARGS) $(INPUT)
#--leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
		 ./executable exampleParam1 \
https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks 

#Clear
clean:
	rm -f $(OBJS) $(EXEC) 	