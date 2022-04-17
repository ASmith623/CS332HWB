FILE = shelly
FILEB = uab_sh
build: $(FILE)
	gcc -Wall -g $(FILE).c -o $(FILEB) -lm

run:
	./$(FILEB)
