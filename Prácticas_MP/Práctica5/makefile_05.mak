###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 5
#
#		Fichero: makefile_05.mak
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


RELACION_EJERCICIOS = "Relación de ejercicios I"

PROYECTO = "Ejercicio 29"


#··········································································

all:	preambulo \
		$(BIN)/I_MezclaArrays_ref \
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


$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o \
							$(OBJ)/ProcesamientoArrayInt.o \
							$(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando ejecutable I_MezclaArrays_ref
	@echo
	g++ -o $(BIN)/I_MezclaArrays_ref \
		   $(OBJ)/I_MezclaArrays_ref.o \
		   $(OBJ)/ProcesamientoArrayInt.o \
		   $(OBJ)/GeneradorAleatorioEnteros.o


#··········································································
# OBJETOS


$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp
	@echo
	@echo Creando objeto I_MezclaArrays_ref.o
	@echo
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o \
			  $(SRC)/I_MezclaArrays_ref.cpp -I$(INCLUDE)

$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp
	@echo
	@echo Creando objeto ProcesamientoArrayInt.o
	@echo
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o \
			  $(SRC)/ProcesamientoArrayInt.cpp -I$(INCLUDE)

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp
	@echo
	@echo Creando objeto GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
			  $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE)


#··········································································
# LIMPIEZA

clean : clean-objs


clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/I_MezclaArrays_ref.o
	-rm $(OBJ)/ProcesamientoArrayInt.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o
	
	@echo
	@echo ... objetos borrados
	@echo


clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/I_MezclaArrays_ref
	
	@echo
	@echo ... ejecutables borrados
	@echo


mr.proper : clean-objs clean-bins
