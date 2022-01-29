.PHONY : execute clean

OUTPUT = program.exe
MAIN_DEPENDENCIES = main-team-15.o functions-team-15.o

execute : $(OUTPUT)

$(OUTPUT) : $(MAIN_DEPENDENCIES)
	gcc $^ -o $@ -lm
	./$@

%.o : %.c
	gcc $< -c

clean : 
	rm *.o *.exe *.out
