proj2: main.o 
	g++ -g -o proj2 -std=c++11  main.o

main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp

test:
	./proj2 < test.txt

clean:
	rm -f *~ *.o proj2

tar:
	mkdir $lLiu_Young_Miniproject_2
	cp -r makefile main.cpp dict.txt Report.odt $lLiu_Young_Miniproject_2
	tar cvzf $lLiu_Young_Miniproject_2.tar.gz $lLiu_Young_Miniproject_2
	rm -rf $lLiu_Young_Miniproject_2
