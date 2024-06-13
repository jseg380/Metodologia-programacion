###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 14
#
#		Fichero: makefile_14.mak
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


RELACION_EJERCICIOS = "Relación de Problemas VII"

PROYECTO = "Ejercicios 5, 6, 9, 12"


#··········································································

all:	preambulo \
		$(BIN)/ParteFicheroPorNumBytes \
		$(BIN)/Reconstruye \
		$(BIN)/Binariza \
		$(BIN)/NotaMedia \
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


$(BIN)/ParteFicheroPorNumBytes : $(OBJ)/ParteFicheroPorNumBytes.o \
								 $(LIB)/libUtils.a
	@echo
	@echo Creando ejecutable ParteFicheroPorNumBytes
	@echo
	g++ -o $(BIN)/ParteFicheroPorNumBytes \
		   $(OBJ)/ParteFicheroPorNumBytes.o -L$(LIB) -lUtils

$(BIN)/Reconstruye : $(OBJ)/Reconstruye.o \
					 $(LIB)/libUtils.a
	@echo
	@echo Creando ejecutable Reconstruye
	@echo
	g++ -o $(BIN)/Reconstruye \
		   $(OBJ)/Reconstruye.o -L$(LIB) -lUtils

$(BIN)/Binariza : $(OBJ)/Binariza.o \
				  $(LIB)/libUtils.a
	@echo
	@echo Creando ejecutable Binariza
	@echo
	g++ -o $(BIN)/Binariza \
		   $(OBJ)/Binariza.o -L$(LIB) -lUtils

$(BIN)/NotaMedia : $(OBJ)/NotaMedia.o \
				   $(LIB)/libUtils.a
	@echo
	@echo Creando ejecutable NotaMedia
	@echo
	g++ -o $(BIN)/NotaMedia \
		   $(OBJ)/NotaMedia.o -L$(LIB) -lUtils


#··········································································
# OBJETOS


$(OBJ)/ParteFicheroPorNumBytes.o : $(SRC)/ParteFicheroPorNumBytes.cpp
	@echo
	@echo Creando objeto ParteFicheroPorNumBytes.o
	@echo
	g++ -c -o $(OBJ)/ParteFicheroPorNumBytes.o \
			  $(SRC)/ParteFicheroPorNumBytes.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Reconstruye.o : $(SRC)/Reconstruye.cpp
	@echo
	@echo Creando objeto Reconstruye.o
	@echo
	g++ -c -o $(OBJ)/Reconstruye.o \
			  $(SRC)/Reconstruye.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/Binariza.o : $(SRC)/Binariza.cpp
	@echo
	@echo Creando objeto Binariza.o
	@echo
	g++ -c -o $(OBJ)/Binariza.o \
			  $(SRC)/Binariza.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/NotaMedia.o : $(SRC)/NotaMedia.cpp
	@echo
	@echo Creando objeto NotaMedia.o
	@echo
	g++ -c -o $(OBJ)/NotaMedia.o \
			  $(SRC)/NotaMedia.cpp -I$(INCLUDE) -std=c++14


#··········································································
# BIBLIOTECAS


$(LIB)/libUtils.a : $(OBJ)/Utils.o
	@echo
	@echo Creando biblioteca libUtils.a
	@echo
	ar rvs $(LIB)/libUtils.a \
		   $(OBJ)/Utils.o

# Objetos para crear las bibliotecas

$(OBJ)/Utils.o : $(SRC)/Utils.cpp
	@echo
	@echo Creando objeto Utils.o
	@echo
	g++ -c -o $(OBJ)/Utils.o \
			  $(SRC)/Utils.cpp -I$(INCLUDE) -std=c++14


#··········································································
# LIMPIEZA

clean : clean-objs

clean-objs:
	@echo
	@echo Borrando objetos ...
	@echo
	
	-rm $(OBJ)/ParteFicheroPorNumBytes.o
	-rm $(OBJ)/Reconstruye.o
	-rm $(OBJ)/Binariza.o
	-rm $(OBJ)/NotaMedia.o
	-rm $(OBJ)/Utils.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/ParteFicheroPorNumBytes
	-rm $(BIN)/Reconstruye
	-rm $(BIN)/Binariza
	-rm $(BIN)/NotaMedia
	
	@echo
	@echo ... ejecutables borrados
	@echo

clean-libs:
	@echo
	@echo Borrando bibliotecas ...
	@echo
	
	-rm $(LIB)/libUtils.a
	
	@echo
	@echo ... bibliotecas borrados
	@echo

mr.proper : clean-objs clean-bins clean-libs
