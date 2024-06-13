#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion09_lista_estudiantes.mak
#
# makefile (estudiantes) para el proyecto de la clase Lista
#
#############################################################################

PROYECTO = "SESION 9 -LISTA- PARA ESTUDIANTES-"

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

#................................................
all:  preambulo \
      $(BIN)/III_Demo-Lista \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo PROYECTO: $(PROYECTO)	
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/III_Demo-Lista : $(OBJ)/III_Demo-Lista.o $(LIB)/libLista.a
	@echo 
	@echo Creando ejecutable: III_Demo-Lista
	@echo 
	g++ -o $(BIN)/III_Demo-Lista $(OBJ)/III_Demo-Lista.o -L$(LIB) -lLista 

#................................................
# OBJETOS 

$(OBJ)/III_Demo-Lista.o : $(SRC)/III_Demo-Lista.cpp  \
                          $(INCLUDE)/Lista.h $(INCLUDE)/TipoBase_Lista.h
	@echo 
	@echo Creando objeto: III_Demo-Lista.o
	@echo 
	g++ -c -o $(OBJ)/III_Demo-Lista.o $(SRC)/III_Demo-Lista.cpp \
        -I$(INCLUDE) -std=c++11

#................................................
# BIBLIOTECAS

# (Lista) ........................

$(OBJ)/Lista.o : $(SRC)/Lista.cpp \
                 $(INCLUDE)/Lista.h $(INCLUDE)/TipoBase_Lista.h
	@echo 
	@echo Creando objeto: Lista.o
	@echo  
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11

$(LIB)/libLista.a : $(OBJ)/Lista.o 
	@echo 
	@echo Creando biblioteca: libLista.a 
	@echo  
	ar -rvs $(LIB)/libLista.a $(OBJ)/Lista.o 

# (FIN Lista) ....................

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas

	@echo Borrando objetos de $(PROYECTO)...

	-rm $(OBJ)/III_Demo-Lista.o	

	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando objetos usados en bibliotecas de $(PROYECTO)...

	-rm $(OBJ)/Lista.o

	@echo ...Borrados objetos usados en bibliotecas de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...

	-rm $(LIB)/libLista.a

	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...

	-rm $(BIN)/III_Demo-Lista	
	
	@echo ...Borrados ejecutables de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

