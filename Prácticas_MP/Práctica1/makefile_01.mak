###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 1
#
#		Fichero: makefile_01.mak
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

PROYECTO = 'Modularización de Kaprekar'


#··········································································

all:	preambulo \
		$(BIN)/Kaprekar \
		$(BIN)/main_Kaprekar \
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


$(BIN)/Kaprekar : $(OBJ)/Kaprekar.o
	@echo
	@echo Creando ejecutable Kaprekar
	@echo
	g++ -o $(BIN)/Kaprekar \
		   $(OBJ)/Kaprekar.o

$(BIN)/main_Kaprekar : $(OBJ)/main_Kaprekar.o \
					   $(OBJ)/funciones_Kaprekar.o
	@echo
	@echo Creando ejecutable main_Kaprekar
	@echo
	g++ -o $(BIN)/main_Kaprekar \
		   $(OBJ)/main_Kaprekar.o \
		   $(OBJ)/funciones_Kaprekar.o


#··········································································
# OBJETOS


$(OBJ)/Kaprekar.o : $(SRC)/Kaprekar.cpp
	@echo
	@echo Creando objeto Kaprekar.o
	@echo
	g++ -c -o $(OBJ)/Kaprekar.o \
			  $(SRC)/Kaprekar.cpp -I$(INCLUDE)

$(OBJ)/main_Kaprekar.o : $(SRC)/main_Kaprekar.cpp
	@echo
	@echo Creando objeto main_Kaprekar.o
	@echo
	g++ -c -o $(OBJ)/main_Kaprekar.o \
			  $(SRC)/main_Kaprekar.cpp -I$(INCLUDE)

$(OBJ)/funciones_Kaprekar.o : $(SRC)/funciones_Kaprekar.cpp \
							  $(INCLUDE)/funciones_Kaprekar.h
	@echo
	@echo Creando objeto funciones_Kaprekar.o
	@echo
	g++ -c -o $(OBJ)/funciones_Kaprekar.o \
			  $(SRC)/funciones_Kaprekar.cpp -I$(INCLUDE)


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/Kaprekar.o
	-rm $(OBJ)/main_Kaprekar.o
	-rm $(OBJ)/funciones_Kaprekar.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/Kaprekar
	-rm $(BIN)/main_Kaprekar
	
	@echo
	@echo ... ejecutables borrados
	@echo

mr.proper : clean-objs clean-bins
