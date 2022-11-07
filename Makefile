build: 01_arbreAVL.cpp 02_arbreAVL.cpp 03_arbreAVL.cpp 04_arbreAVL.cpp 05_arbreAVL.cpp 06_arbreAVL.cpp 07_arbreAVL.cpp 08_arbreAVL.cpp 09_arbreAVL.cpp 01_livre.cpp 02_livre.cpp 03_livre.cpp 01_librairie.cpp 02_librairie.cpp 03_librairie.cpp
	g++ 01_arbreAVL.cpp -o 01_arbreAVL
	g++ 02_arbreAVL.cpp -o 02_arbreAVL
	g++ 03_arbreAVL.cpp -o 03_arbreAVL
	g++ 04_arbreAVL.cpp -o 04_arbreAVL
	g++ 05_arbreAVL.cpp -o 05_arbreAVL
	g++ 06_arbreAVL.cpp -o 06_arbreAVL
	g++ 07_arbreAVL.cpp -o 07_arbreAVL
	g++ 08_arbreAVL.cpp -o 08_arbreAVL
	g++ 09_arbreAVL.cpp -o 09_arbreAVL
	g++ 01_livre.cpp -o 01_livre
	g++ 02_livre.cpp -o 02_livre
	g++ 03_livre.cpp -o 03_livre
	g++ 01_librairie.cpp -o 01_librairie
	g++ 02_librairie.cpp -o 02_librairie
	g++ 03_librairie.cpp -o 03_librairie

avl: 01_arbreAVL 02_arbreAVL 03_arbreAVL 04_arbreAVL 05_arbreAVL 06_arbreAVL 07_arbreAVL 08_arbreAVL 09_arbreAVL
	./01_arbreAVL
	./02_arbreAVL
	./03_arbreAVL
	./04_arbreAVL
	./05_arbreAVL
	./06_arbreAVL
	./07_arbreAVL
	./08_arbreAVL
	./09_arbreAVL

livre: 01_livre 02_livre 03_livre
	./01_livre
	./02_livre
	./03_livre

librairie: 01_librairie 02_librairie 03_librairie
	./01_librairie
	./02_librairie
	./03_librairie

full: avl livre librairie

clean:
	test -f 01_arbreAVL && rm ??_arbreAVL
	test -f 01_livre && rm ??_livre
	test -f 01_librairie && rm ??_librairie
