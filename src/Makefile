.PHONY : execute clean

OUTPUT = program.exe
MAIN_DEPENDENCIES = main-team-15.o functions-team-15.o

$(OUTPUT) : $(MAIN_DEPENDENCIES)
	gcc $^ -o $@ -lm -Wall

%.o : %.c
	gcc $< -c

execute : $(OUTPUT)
	./$<

clean : 
	rm *.o *.exe *.out
