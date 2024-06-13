###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 7
#
#		Fichero: makefile_07.mak
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


RELACION_EJERCICIOS = "Relación de problemas II"

PROYECTO = "Ejercicio 8"


#··········································································

all:	preambulo \
		$(BIN)/II_Robot_Tablero \
		despedida

#··········································································

preambulo:
	@echo
	@echo ---------------------------------------------------------
	@echo
	@echo "   METODOLOGÍA DE LA PROGRAMACIÓN"
	@echo "   Autor: Juan Manuel Segura Duarte"
	@echo "   $(RELACION_EJERCICIOS)"
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


$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
						  $(LIB)/libMatriz2D.a
	@echo
	@echo Creando ejecutable II_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/II_Demo-Matriz2D \
		   $(OBJ)/II_Demo-Matriz2D.o \
		   -L$(LIB) -lMatriz2D

$(BIN)/II_Robot_Tablero : $(OBJ)/II_Robot_Tablero.o \
						  $(OBJ)/FuncsRobotTablero.o \
						  $(LIB)/libMatriz2D.a \
						  $(LIB)/libFuncsVectorDinamico.a
	@echo
	@echo Creando ejecutable II_Robot_Tablero
	@echo
	g++ -o $(BIN)/II_Robot_Tablero \
		   $(OBJ)/II_Robot_Tablero.o \
		   $(OBJ)/FuncsRobotTablero.o \
		   -L$(LIB) -lMatriz2D -lFuncsVectorDinamico


#··········································································
# OBJETOS


$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
							$(INCLUDE)/Matriz2D.h
	@echo
	@echo Creando objeto II_Demo-Matriz2D
	@echo
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o \
			  $(SRC)/II_Demo-Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/II_Robot_Tablero.o : $(SRC)/II_Robot_Tablero.cpp \
							$(INCLUDE)/Matriz2D.h
	@echo
	@echo Creando objeto II_Robot_Tablero.o
	@echo
	g++ -c -o $(OBJ)/II_Robot_Tablero.o \
			  $(SRC)/II_Robot_Tablero.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/FuncsRobotTablero.o : $(SRC)/FuncsRobotTablero.cpp \
							   $(INCLUDE)/FuncsRobotTablero.h
	@echo
	@echo Creando objeto FuncsRobotTablero.o
	@echo
	g++ -c -o $(OBJ)/FuncsRobotTablero.o \
			  $(SRC)/FuncsRobotTablero.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS


$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o
	@echo
	@echo Creando biblioteca libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a \
		   $(OBJ)/Matriz2D.o

$(LIB)/libFuncsVectorDinamico.a : $(OBJ)/FuncsVectorDinamico.o
	@echo
	@echo Creando biblioteca libFuncsVectorDinamico.a
	@echo
	ar rvs $(LIB)/libFuncsVectorDinamico.a \
		   $(OBJ)/FuncsVectorDinamico.o


# (Objeto para crear la biblioteca)

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp \
					$(INCLUDE)/Matriz2D.h
	@echo
	@echo Creando objeto Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/Matriz2D.o \
			  $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
						  $(INCLUDE)/FuncsVectorDinamico.h \
						  $(INCLUDE)/TipoBase.h
	@echo
	@echo Creando objeto FuncsVectorDinamico.o
	@echo
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o \
			  $(SRC)/FuncsVectorDinamico.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/II_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/II_Robot_Tablero.o
	-rm $(OBJ)/FuncsRobotTablero.o
	-rm $(OBJ)/FuncsVectorDinamico.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/II_Demo-Matriz2D
	-rm $(BIN)/II_Robot_Tablero
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libMatriz2D.a
	-rm $(LIB)/libFuncsVectorDinamico.a
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
