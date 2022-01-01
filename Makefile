.PHONY : execute clean

OUTPUT = programa.exe
MAIN_DEPENDENCIES = main-team-5.o functions-team-5.o

execute : $(OUTPUT)

$(OUTPUT) : $(MAIN_DEPENDENCIES)
	gcc $^ -o $@ -lm
	./$@

%.o : %.c
	gcc $< -c

clean : 
	rm *.o *.exe