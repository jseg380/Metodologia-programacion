###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 11
#
#		Fichero: makefile_11.mak
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


RELACION_EJERCICIOS = "Relación de Problemas IV"

PROYECTO = "Ejercicios 2, 3"


#··········································································

all:	preambulo \
		$(BIN)/IV_Demo-Matriz2D \
		$(BIN)/IV_Demo-Lista \
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


$(BIN)/IV_Demo-Matriz2D : $(OBJ)/IV_Demo-Matriz2D.o \
						  $(LIB)/libMatriz2D.a
	@echo
	@echo Creando ejecutable IV_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/IV_Demo-Matriz2D \
		   $(OBJ)/IV_Demo-Matriz2D.o -L$(LIB) -lMatriz2D

$(BIN)/IV_Demo-Lista : $(OBJ)/IV_Demo-Lista.o \
					   $(LIB)/libLista.a
	@echo
	@echo Creando ejecutable IV_Demo-Lista
	@echo
	g++ -o $(BIN)/IV_Demo-Lista \
		   $(OBJ)/IV_Demo-Lista.o -L$(LIB) -lLista


#··········································································
# OBJETOS


$(OBJ)/IV_Demo-Matriz2D.o : $(SRC)/IV_Demo-Matriz2D.cpp
	@echo
	@echo Creando objeto IV_Demo-Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/IV_Demo-Matriz2D.o \
			  $(SRC)/IV_Demo-Matriz2D.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/IV_Demo-Lista.o : $(SRC)/IV_Demo-Lista.cpp
	@echo
	@echo Creando objeto IV_Demo-Lista.o
	@echo
	g++ -c -o $(OBJ)/IV_Demo-Lista.o \
			  $(SRC)/IV_Demo-Lista.cpp -I$(INCLUDE) -std=c++14


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
					$(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBaseMatriz2D.h
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

# Lista ......................................

$(LIB)/libLista.a : $(OBJ)/Lista.o
	@echo
	@echo Creando biblioteca libLista.a
	@echo
	ar rvs $(LIB)/libLista.a \
		   $(OBJ)/Lista.o

# Objetos para crear libLista.a

$(OBJ)/Lista.o : $(SRC)/Lista.cpp \
				 $(INCLUDE)/TipoBase_Lista.h
	@echo
	@echo Creando objeto Lista.o
	@echo
	g++ -c -o $(OBJ)/Lista.o \
			  $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/IV_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Secuencia.o
	-rm $(OBJ)/IV_Demo-Lista.o
	-rm $(OBJ)/Lista.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/IV_Demo-Matriz2D
	-rm $(BIN)/IV_Demo-Lista
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libMatriz2D.a
	-rm $(LIB)/libLista.a
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
