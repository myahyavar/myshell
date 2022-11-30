proje: myshell writef execx

myshell: myshell.c
	gcc myshell.c -o myshell
	
writef: writef.c
	gcc writef.c -o writef
			
tekrar: execx.c
	gcc execx.c -o execx

clear: 
	rm -rf *o clear
