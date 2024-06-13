###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 13
#
#		Fichero: makefile_13.mak
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


RELACION_EJERCICIOS = "Relación de Problemas VI"

PROYECTO = "Ejercicios 2, 6, 7, 8, 10, 11"


#··········································································

all:	preambulo \
		$(BIN)/NumeraLineas_Ampliacion \
		$(BIN)/MensajesOcultos-2 \
		$(BIN)/InfoPGM \
		$(BIN)/Verifica_FicheroMarcas \
		$(BIN)/VI_Demo-Lista \
		$(BIN)/VI_Demo-Matriz \
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


$(BIN)/NumeraLineas_Ampliacion : $(SRC)/NumeraLineas_Ampliacion.cpp
	@echo
	@echo Creando ejecutable NumeraLineas_Ampliacion
	@echo
	g++ -o $(BIN)/NumeraLineas_Ampliacion \
		   $(SRC)/NumeraLineas_Ampliacion.cpp -std=c++14

$(BIN)/MensajesOcultos-2 : $(SRC)/MensajesOcultos-2.cpp
	@echo
	@echo Creando ejecutable MensajesOcultos-2
	@echo
	g++ -o $(BIN)/MensajesOcultos-2 \
		   $(SRC)/MensajesOcultos-2.cpp -std=c++14

$(BIN)/InfoPGM : $(SRC)/InfoPGM.cpp
	@echo
	@echo Creando ejecutable InfoPGM
	@echo
	g++ -o $(BIN)/InfoPGM \
		   $(SRC)/InfoPGM.cpp -std=c++14

$(BIN)/Verifica_FicheroMarcas : $(SRC)/Verifica_FicheroMarcas.cpp
	@echo
	@echo Creando ejecutable Verifica_FicheroMarcas
	@echo
	g++ -o $(BIN)/Verifica_FicheroMarcas \
		   $(SRC)/Verifica_FicheroMarcas.cpp -std=c++14

$(BIN)/VI_Demo-Lista : $(OBJ)/VI_Demo-Lista.o \
					   $(LIB)/libLista.a
	@echo
	@echo Creando ejecutable VI_Demo-Lista
	@echo
	g++ -o $(BIN)/VI_Demo-Lista \
		   $(OBJ)/VI_Demo-Lista.o -L$(LIB) -lLista

$(BIN)/VI_Demo-Matriz : $(OBJ)/VI_Demo-Matriz.o \
					   $(LIB)/libMatriz2D.a
	@echo
	@echo Creando ejecutable VI_Demo-Matriz
	@echo
	g++ -o $(BIN)/VI_Demo-Matriz \
		   $(OBJ)/VI_Demo-Matriz.o -L$(LIB) -lMatriz2D


#··········································································
# OBJETOS


$(OBJ)/VI_Demo-Lista.o : $(SRC)/VI_Demo-Lista.cpp
	@echo
	@echo Creando objeto VI_Demo-Lista.o
	@echo
	g++ -c -o $(OBJ)/VI_Demo-Lista.o \
			  $(SRC)/VI_Demo-Lista.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/VI_Demo-Matriz.o : $(SRC)/VI_Demo-Matriz.cpp
	@echo
	@echo Creando objeto VI_Demo-Matriz.o
	@echo
	g++ -c -o $(OBJ)/VI_Demo-Matriz.o \
			  $(SRC)/VI_Demo-Matriz.cpp -I$(INCLUDE) -std=c++14


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
	
	-rm $(OBJ)/VI_Demo-Lista.o
	-rm $(OBJ)/Lista.o
	-rm $(OBJ)/VI_Demo-Matriz.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Secuencia.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/NumeraLineas_Ampliacion
	-rm $(BIN)/MensajesOcultos-2
	-rm $(BIN)/InfoPGM
	-rm $(BIN)/Verifica_FicheroMarcas
	-rm $(BIN)/VI_Demo-Lista
	-rm $(BIN)/VI_Demo-Matriz
	
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
