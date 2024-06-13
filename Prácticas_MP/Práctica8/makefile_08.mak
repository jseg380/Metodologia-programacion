###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 8
#
#		Fichero: makefile_08.mak
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


RELACION_EJERCICIOS = "Relacion de Problemas II"

PROYECTO = "Ejercicios 17, 19, 20"


#··········································································

all:	preambulo \
		$(BIN)/II_Demo-Lista \
		$(BIN)/II_EstadisticaBasica_ListaAleatoria \
		$(BIN)/II_Invierte_Lista \
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


$(BIN)/II_Demo-Lista : $(OBJ)/II_Demo-Lista.o \
					   $(LIB)/libLista.a
	@echo
	@echo Creando ejecutable II_Demo-Lista
	@echo
	g++ -o $(BIN)/II_Demo-Lista \
		   $(OBJ)/II_Demo-Lista.o -L$(LIB) -lLista

$(BIN)/II_EstadisticaBasica_ListaAleatoria : \
						$(OBJ)/II_EstadisticaBasica_ListaAleatoria.o \
						$(LIB)/libLista.a
	@echo
	@echo Creando ejecutable II_EstadisticaBasica_ListaAleatoria
	@echo
	g++ -o $(BIN)/II_EstadisticaBasica_ListaAleatoria \
		   $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o \
		   -L$(LIB) -lLista

$(BIN)/II_Invierte_Lista : $(OBJ)/II_Invierte_Lista.o \
							   $(LIB)/libLista.a
	@echo
	@echo Creando ejecutable II_Invierte_Lista
	@echo
	g++ -o $(BIN)/II_Invierte_Lista \
		   $(OBJ)/II_Invierte_Lista.o -L$(LIB) -lLista


#··········································································
# OBJETOS


$(OBJ)/II_Demo-Lista.o : $(SRC)/II_Demo-Lista.cpp \
						 $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h
	@echo
	@echo Creando objeto II_Demo-Lista.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-Lista.o \
			  $(SRC)/II_Demo-Lista.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/II_EstadisticaBasica_ListaAleatoria.o : \
						 $(SRC)/II_EstadisticaBasica_ListaAleatoria.cpp \
						 $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h
	@echo
	@echo Creando objeto II_EstadisticaBasica_ListaAleatoria.o
	@echo
	g++ -c -o $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o \
			  $(SRC)/II_EstadisticaBasica_ListaAleatoria.cpp \
			  -I$(INCLUDE) -std=c++14

$(OBJ)/II_Invierte_Lista.o : $(SRC)/II_Invierte_Lista.cpp \
						 $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h
	@echo
	@echo Creando objeto II_Invierte_Lista.o
	@echo
	g++ -c -o $(OBJ)/II_Invierte_Lista.o \
			  $(SRC)/II_Invierte_Lista.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS

# Lista ...............................

$(LIB)/libLista.a : $(OBJ)/Lista.o $(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando biblioteca libLista.a
	@echo
	ar rvs $(LIB)/libLista.a \
		   $(OBJ)/Lista.o \
		   $(OBJ)/GeneradorAleatorioEnteros.o

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h
	@echo
	@echo Creando objeto Lista.o
	@echo
	g++ -c -o $(OBJ)/Lista.o \
			  $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
								 $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo
	@echo Creando objeto GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
			  $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

# (Error suppress)
# Redirecciona los errores para que no se muestren cuando no se haya podido
# borrar un archivo debido a que no existía
# 2> /dev/null ignora el error de rm
# || true ignora el error de make
ERROR_SUP = 2> /dev/null || true

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/II_Demo-Lista.o $(ERROR_SUP)
	-rm $(OBJ)/II_EstadisticaBasica_ListaAleatoria.o $(ERROR_SUP)
	-rm $(OBJ)/II_Invierte_Lista.o $(ERROR_SUP)
	-rm $(OBJ)/Lista.o $(ERROR_SUP)
	-rm $(OBJ)/GeneradorAleatorioEnteros.o $(ERROR_SUP)
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/II_Demo-Lista $(ERROR_SUP)
	-rm $(BIN)/II_EstadisticaBasica_ListaAleatoria $(ERROR_SUP)
	-rm $(BIN)/II_Invierte_Lista $(ERROR_SUP)
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libLista.a $(ERROR_SUP)
	
	@echo
	@echo ... bibliotecas borradas
	@echo

mr.proper : clean-objs clean-bins clean-libs
