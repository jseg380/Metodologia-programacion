###########################################################################
#
#       METODOLOGÍA DE LA PROGRAMACIÓN
#
#		Autor: Juan Manuel Segura Duarte
#
#		Proyecto: Práctica 12
#
#		Fichero: makefile_12.mak
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


RELACION_EJERCICIOS = "Relación de Problemas V"

PROYECTO = "Ejercicios 7, 13, 14, 19, 20"


#··········································································

all:	preambulo \
		$(BIN)/CopiaLineasSinAlmohadilla \
		$(BIN)/CuentaCaracteresConcretos \
		$(BIN)/CuentaPalabrasLongitudConcreta \
		$(BIN)/V_Demo-Lista \
		$(BIN)/V_Demo-Matriz \
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


$(BIN)/CopiaLineasSinAlmohadilla : $(SRC)/CopiaLineasSinAlmohadilla.cpp
	@echo
	@echo Creando ejecutable CopiaLineasSinAlmohadilla
	@echo
	g++ -o $(BIN)/CopiaLineasSinAlmohadilla \
		   $(SRC)/CopiaLineasSinAlmohadilla.cpp

$(BIN)/CuentaCaracteresConcretos : $(SRC)/CuentaCaracteresConcretos.cpp
	@echo
	@echo Creando ejecutable CuentaCaracteresConcretos
	@echo
	g++ -o $(BIN)/CuentaCaracteresConcretos \
		   $(SRC)/CuentaCaracteresConcretos.cpp

$(BIN)/CuentaPalabrasLongitudConcreta : \
									$(SRC)/CuentaPalabrasLongitudConcreta.cpp
	@echo
	@echo Creando ejecutable CuentaPalabrasLongitudConcreta
	@echo
	g++ -o $(BIN)/CuentaPalabrasLongitudConcreta \
		   $(SRC)/CuentaPalabrasLongitudConcreta.cpp

$(BIN)/V_Demo-Lista : $(OBJ)/V_Demo-Lista.o \
					  $(LIB)/libLista.a
	@echo
	@echo Creando ejecutable V_Demo-Lista
	@echo
	g++ -o $(BIN)/V_Demo-Lista \
		   $(OBJ)/V_Demo-Lista.o -L$(LIB) -lLista

$(BIN)/V_Demo-Matriz : $(OBJ)/V_Demo-Matriz.o \
					   $(LIB)/libMatriz2D.a
	@echo
	@echo Creando ejecutable V_Demo-Matriz
	@echo
	g++ -o $(BIN)/V_Demo-Matriz \
		   $(OBJ)/V_Demo-Matriz.o -L$(LIB) -lMatriz2D


#··········································································
# OBJETOS


$(OBJ)/V_Demo-Lista.o : $(SRC)/V_Demo-Lista.cpp
	@echo
	@echo Creando objeto V_Demo-Lista.o
	@echo
	g++ -c -o $(OBJ)/V_Demo-Lista.o \
			  $(SRC)/V_Demo-Lista.cpp -I$(INCLUDE) -std=c++14

$(OBJ)/V_Demo-Matriz.o : $(SRC)/V_Demo-Matriz.cpp
	@echo
	@echo Creando objeto V_Demo-Matriz.o
	@echo
	g++ -c -o $(OBJ)/V_Demo-Matriz.o \
			  $(SRC)/V_Demo-Matriz.cpp -I$(INCLUDE) -std=c++14


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
	
	-rm $(OBJ)/V_Demo-Lista.o
	-rm $(OBJ)/Lista.o
	-rm $(OBJ)/V_Demo-Matriz.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Secuencia.o
	
	@echo
	@echo ... objetos borrados
	@echo

clean-bins:
	@echo
	@echo Borrando ejecutables ...
	@echo
	
	-rm $(BIN)/CopiaLineasSinAlmohadilla
	-rm $(BIN)/CuentaCaracteresConcretos
	-rm $(BIN)/CuentaPalabrasLongitudConcreta
	-rm $(BIN)/V_Demo-Lista
	-rm $(BIN)/V_Demo-Matriz
	
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
