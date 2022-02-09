.PHONY : execute clean

OUTPUT = program.exe
MAIN_DEPENDENCIES = main.o functions.o

$(OUTPUT) : $(MAIN_DEPENDENCIES)
	gcc $^ -o $@ -lm -Wall

%.o : %.c
	gcc $< -c

execute : $(OUTPUT)
	./$<

help : $(OUTPUT)
	./$< --help

clean : 
	rm *.o *.exe *.out
