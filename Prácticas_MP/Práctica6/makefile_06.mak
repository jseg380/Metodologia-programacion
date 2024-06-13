###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 6
#
#		Fichero: makefile_06.mak
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


RELACION_EJERCICIOS = "Relación de ejercicios II"

PROYECTO = "Ejercicios 2, 6"


#··········································································

all:	preambulo \
		$(BIN)/II_Demo-VectorDinamico_basico \
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


$(BIN)/II_Demo-VectorDinamico_basico : \
							$(OBJ)/II_Demo-VectorDinamico_basico.o \
							$(LIB)/libFuncsVectorDinamico_basico.a
	@echo
	@echo Creando ejecutable II_Demo-VectorDinamico_basico
	@echo
	g++ -o $(BIN)/II_Demo-VectorDinamico_basico \
		   $(OBJ)/II_Demo-VectorDinamico_basico.o \
		   -L$(LIB) -lFuncsVectorDinamico_basico


#··········································································
# OBJETOS


$(OBJ)/II_Demo-VectorDinamico_basico.o : \
							$(SRC)/II_Demo-VectorDinamico_basico.cpp \
							$(INCLUDE)/FuncsVectorDinamico_basico.h
	@echo
	@echo Creando objeto II_Demo-VectorDinamico_basico.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-VectorDinamico_basico.o \
			  $(SRC)/II_Demo-VectorDinamico_basico.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS


$(LIB)/libFuncsVectorDinamico_basico.a : $(OBJ)/FuncsVectorDinamico_basico.o
	@echo
	@echo Creando biblioteca libFuncsVectorDinamico_basico.a
	@echo
	ar rvs $(LIB)/libFuncsVectorDinamico_basico.a \
		   $(OBJ)/FuncsVectorDinamico_basico.o

# (Objeto para crear la biblioteca)

$(OBJ)/FuncsVectorDinamico_basico.o : $(SRC)/FuncsVectorDinamico_basico.cpp \
									  $(INCLUDE)/FuncsVectorDinamico_basico.h
	@echo
	@echo Creando objeto FuncsVectorDinamico_basico.o
	@echo
	g++ -c -o $(OBJ)/FuncsVectorDinamico_basico.o \
			  $(SRC)/FuncsVectorDinamico_basico.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/II_Demo-VectorDinamico_basico.o
	-rm $(OBJ)/FuncsVectorDinamico_basico.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/II_Demo-VectorDinamico_basico
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libFuncsVectorDinamico_basico.a
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
