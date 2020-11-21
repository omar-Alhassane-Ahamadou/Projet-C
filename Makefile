
CFLAGS=-g
LDFLAGS=

all : test

test_Lecture :  Lecture.o
	g++ -o test_Lecture $^ $(LDFLAGS)
#test_Aigle :  Animal.o Carnivore.o Aigle.o test_aigle.o
#	g++ -o test_Aigle $^ $(LDFLAGS)
# test_Autruche :  Animal.o Herbivore.o Autruche.o test_Autruche.o
# 		g++ -o test_Autruche $^ $(LDFLAGS)
# test_FormeBase :  dessin_phelma.o Point.o FormeBase.o
# 		g++ -o test_FormeBase $^ $(LDFLAGS)
#
# test_Cercle :  dessin_phelma.o Point.o FormeBase.o cercle.o test_cercle.o MesImages.o BmpIO.o
# 				g++ -o test_Cercle $^ $(LDFLAGS)
#
# test_Cercleplein :  dessin_phelma.o Point.o FormeBase.o cercleplein.o test_cercleplein.o MesImages.o BmpIO.o
# 								g++ -o test_Cercleplein $^ $(LDFLAGS)
#
# test_Rectangle :  dessin_phelma.o Point.o FormeBase.o rectangle.o test_rectangle.o MesImages.o BmpIO.o
# 								g++ -o test_Rectangle $^ $(LDFLAGS)
#
# test_Rectangleplein :  dessin_phelma.o Point.o FormeBase.o rectangleplein.o test_rectangleplein.o MesImages.o BmpIO.o
# 																g++ -o test_Rectangleplein $^ $(LDFLAGS)
#
# test_Lignehorizontale :  dessin_phelma.o Point.o FormeBase.o lignehorizontale.o test_lignehorizontale.o MesImages.o BmpIO.o
# 																																g++ -o test_Horizontale $^ $(LDFLAGS)
#
# test1 :  dessin_phelma.o Point.o FormeBase.o rectangleplein.o test1.o MesImages.o BmpIO.o cercleplein.o
# 												g++ -o test1 $^ $(LDFLAGS)
#
# test2 :  dessin_phelma.o Point.o FormeBase.o rectangle.o cercle.o lignehorizontale.o rectangleplein.o test2.o MesImages.o BmpIO.o cercleplein.o
# 													g++ -o test2 $^ $(LDFLAGS)
#
# test3 :  dessin_phelma.o Point.o FormeBase.o rectangle.o cercle.o lignehorizontale.o rectangleplein.o test3.o MesImages.o BmpIO.o cercleplein.o
# 															g++ -o test3 $^ $(LDFLAGS)
#
# testclone :  dessin_phelma.o Point.o FormeBase.o rectangle.o cercle.o lignehorizontale.o rectangleplein.o testclone.o MesImages.o BmpIO.o cercleplein.o
# 													g++ -o testclone $^ $(LDFLAGS)


%.o:%.cc
	g++ $(CFLAGS) -c -g $^

clean:
	rm -f *.o *~ test
# rm -f *.o *~ test test_dessin_phelma
