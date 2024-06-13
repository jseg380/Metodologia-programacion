#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# JUAN MANUEL SEGURA DUARTE
#
# makefile_04.mak
#
# makefile para la sesión de prácticas 4
#
# Ejercicios realizados : 9, 10
#
#############################################################################


# MACROS

HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include


#········································································

all: inicio \
	 clean-objs \
	 clean-bins \
	 $(BIN)/I_Ley_DHondt \
	 $(BIN)/I_EratostenesFactoresPrimos \
	 final


inicio:
	@echo
	@echo Creando ejecutables...
	@echo

final:
	@echo
	@echo ...Ejecutables creados
	@echo

#········································································
# EJECUTABLES


$(BIN)/I_Ley_DHondt : $(OBJ)/I_Ley_DHondt.o \
				  $(OBJ)/FuncionesLeyDhondt.o
	@echo
	@echo Creando ejecutable LeyDhondt
	@echo
	g++ -o $(BIN)/I_Ley_DHondt \
		   $(OBJ)/I_Ley_DHondt.o \
		   $(OBJ)/FuncionesLeyDhondt.o

$(BIN)/I_EratostenesFactoresPrimos : $(OBJ)/I_EratostenesFactoresPrimos.o
	@echo
	@echo Creando ejecutable I_EratostenesFactoresPrimos
	@echo
	g++ -o $(BIN)/I_EratostenesFactoresPrimos \
		   $(OBJ)/I_EratostenesFactoresPrimos.o \
		   $(OBJ)/FuncionesEratostenesFactoresPrimos.o


#········································································
# OBJETOS


$(OBJ)/I_Ley_DHondt.o : $(SRC)/I_Ley_DHondt.cpp
	@echo
	@echo Creando objeto I_Ley_DHondt.o
	@echo
	g++ -c -o $(OBJ)/I_Ley_DHondt.o \
			  $(SRC)/I_Ley_DHondt.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/FuncionesLeyDhondt.o : $(SRC)/FuncionesLeyDhondt.cpp
	@echo
	@echo Creando objeto FuncionesLeyDhondt.o
	@echo
	g++ -c -o $(OBJ)/FuncionesLeyDhondt.o \
			  $(SRC)/FuncionesLeyDhondt.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/I_EratostenesFactoresPrimos.o : $(SRC)/I_EratostenesFactoresPrimos.cpp \
								$(OBJ)/FuncionesEratostenesFactoresPrimos.o
	@echo
	@echo Creando objeto I_EratostenesFactoresPrimos.o
	@echo
	g++ -c -o $(OBJ)/I_EratostenesFactoresPrimos.o \
			  $(SRC)/I_EratostenesFactoresPrimos.cpp -I$(INCLUDE) -std=c++14

#········································································

$(OBJ)/FuncionesEratostenesFactoresPrimos.o : \
								$(SRC)/FuncionesEratostenesFactoresPrimos.cpp
	@echo
	@echo Creando objeto FuncionesEratostenesFactoresPrimos.o
	@echo
	g++ -c -o $(OBJ)/FuncionesEratostenesFactoresPrimos.o \
			  $(SRC)/FuncionesEratostenesFactoresPrimos.cpp \
			  -I$(INCLUDE) -std=c++14


#········································································
# LIMPIEZA

clean : clean-objs

clean-objs : 
	@echo
	@echo Borrando objetos...
	
	-rm $(OBJ)/I_Ley_DHondt.o
	-rm $(OBJ)/FuncionesLeyDhondt.o
	-rm $(OBJ)/I_EratostenesFactoresPrimos.o
	-rm $(OBJ)/FuncionesEratostenesFactoresPrimos.o
	
	@echo ...objetos borrados
	@echo

clean-bins :
	@echo
	@echo Borrando ejecutables...
	
	-rm $(BIN)/I_Ley_DHondt
	-rm $(BIN)/I_EratostenesFactoresPrimos
	
	@echo ...ejecutables borrados
	@echo

clean-libs :
	@echo
	@echo Borrando bibliotecas...
	
#	-rm -f $(LIB)/*
	
	@echo ...bibliotecas borradas
	@echo

mr.proper : clean-objs clean-bins clean-libs
