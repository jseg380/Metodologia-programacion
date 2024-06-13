###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 9
#
#		Fichero: makefile_09.mak
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


RELACION_EJERCICIOS = "Relación de Problemas III"

PROYECTO = "Ejercicio 2"


#··········································································

all:	preambulo \
		$(BIN)/III_Demo-Matriz2D \
		despedida

#··········································································

preambulo:
	@echo
	@echo ---------------------------------------------------------
	@echo
	@echo "   METODOLOGÍA DE LA PROGRAMACIÓN"
	@echo
	@echo "   Autor: Juan Manuel Segura Duarte"
	@echo
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


$(BIN)/III_Demo-Matriz2D : $(OBJ)/III_Demo-Matriz2D.o \
						   $(LIB)/libMatriz2D.a
	@echo
	@echo Creando ejecutable III_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/III_Demo-Matriz2D \
		   $(OBJ)/III_Demo-Matriz2D.o -L$(LIB) -lMatriz2D


#··········································································
# OBJETOS


$(OBJ)/III_Demo-Matriz2D.o : $(SRC)/III_Demo-Matriz2D.cpp
	@echo
	@echo Creando objeto III_Demo-Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/III_Demo-Matriz2D.o \
			  $(SRC)/III_Demo-Matriz2D.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS

# Matriz2D ......................................

$(LIB)/libMatriz2D.a : $(OBJ)/Matriz2D.o \
					   $(OBJ)/Secuencia.o
	@echo
	@echo Creando biblioteca libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a \
		   $(OBJ)/Matriz2D.o \
		   $(OBJ)/Secuencia.o

# Objetos para crear libMatriz2D.a

$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp \
					$(INCLUDE)/Matriz2D.h
	@echo
	@echo Creando objeto Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/Matriz2D.o \
			  $(SRC)/Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
					 $(INCLUDE)/Secuencia.h \
					 $(INCLUDE)/TipoBase_Secuencia.h
	@echo
	@echo Creando objeto Secuencia.o
	@echo
	g++ -c -o $(OBJ)/Secuencia.o \
			  $(SRC)/Secuencia.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/III_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Secuencia.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/III_Demo-Matriz2D
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libMatriz2D.a
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
