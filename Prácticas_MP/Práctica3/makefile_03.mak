###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 3
#
#		Fichero: makefile_03.mak
#
###########################################################################

#··········································································
# Macros


HOME = .

BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj
SRC = $(HOME)/src

PROYECTO = 'Ejercicios 6, 7, 8'


#··········································································

all:	preambulo \
		clean-objs \
		clean-bins \
		$(BIN)/I_PosMayor_Basico \
		$(BIN)/I_OrdenaVector.cpp \
		$(BIN)/I_OrdenayMezclaVectores.cpp
		despedida

#··········································································

preambulo:
	@echo
	@echo ---------------------------------------------------------
	@echo
	@echo "   METODOLOGÍA DE LA PROGRAMACIÓN"
	@echo "   Autor: Juan Manuel Segura Duarte"
	@echo "   Proyecto: $(PROYECTO)"
	@echo
	@echo ---------------------------------------------------------
	@echo
	@echo
	@echo Creando ejecutables ...
	@echo
	@echo

despedida:
	@echo
	@echo ... ejecutables creados
	@echo

#··········································································
# EJECUTABLES


$(BIN)/I_PosMayor_Basico : $(OBJ)/I_PosMayor_Basico.o
	@echo
	@echo Creando ejecutable I_PosMayor_Basico
	@echo
	g++ -o $(BIN)/I_PosMayor_Basico \
		   $(OBJ)/I_PosMayor_Basico.o


#··········································································
# OBJETOS


$(OBJ)/I_PosMayor_Basico.o : $(SRC)/I_PosMayor_Basico.cpp
	@echo
	@echo Creando objeto I_PosMayor_Basico.o
	@echo
	g++ -c -o $(OBJ)/I_PosMayor_Basico.o \
			  $(SRC)/I_PosMayor_Basico.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArryaInt.cpp \
								 $(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando objeto ProcesamientoArrayInt.o
	@echo
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o \
			  $(SRC)/ProcesamientoArrayInt.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp
	@echo
	@echo Creando objeto GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
			  $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS





#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/I_PosMayor_Basico.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/I_PosMayor_Basico
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/nombre_biblioteca
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
