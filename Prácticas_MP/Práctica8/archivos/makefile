#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion08_previa.mak
#
# makefile para la sesión de prácticas 8 (previa, para alumnos)
#
#############################################################################

SESION = "8 (preparatoria)"

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
      $(BIN)/II_EstadisticaBasica_Lista \
      $(BIN)/II_OrdenarLista_Basico \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas II
	@echo Sesion de practicas $(SESION)	
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

$(BIN)/II_EstadisticaBasica_Lista : \
           $(OBJ)/II_EstadisticaBasica_Lista.o $(LIB)/libLista.a
	@echo 
	@echo Creando ejecutable: II_EstadisticaBasica_Lista
	@echo 
	g++ -o $(BIN)/II_EstadisticaBasica_Lista \
	       $(OBJ)/II_EstadisticaBasica_Lista.o -L$(LIB) -lLista
	  
$(BIN)/II_OrdenarLista_Basico : \
           $(OBJ)/II_OrdenarLista_Basico.o $(LIB)/libLista.a \
           $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 
	@echo 
	@echo Creando ejecutable: II_OrdenarLista_Basico
	@echo 
	g++ -o $(BIN)/II_OrdenarLista_Basico \
	       $(OBJ)/II_OrdenarLista_Basico.o \
	       -L$(LIB) -lLista \
	       -L$(LIB_CLASES_UTILS) -lGeneradorAleatorioEnteros


#................................................
# OBJETOS 

$(OBJ)/II_EstadisticaBasica_Lista.o : $(SRC)/II_EstadisticaBasica_Lista.cpp \
                           $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h 
	@echo 
	@echo Creando objeto: II_EstadisticaBasica_Lista.o
	@echo 
	g++ -c -o $(OBJ)/II_EstadisticaBasica_Lista.o \
	          $(SRC)/II_EstadisticaBasica_Lista.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/II_OrdenarLista_Basico.o : $(SRC)/II_OrdenarLista_Basico.cpp \
                           $(INCLUDE)/Lista.h $(INCLUDE)/TipoBaseLista.h \
						   $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: II_OrdenarLista_Basico.o
	@echo 
	g++ -c -o $(OBJ)/II_OrdenarLista_Basico.o \
	          $(SRC)/II_OrdenarLista_Basico.cpp -I$(INCLUDE) -std=c++11


#................................................
# BIBLIOTECAS

# libMatriz2D.a .................................

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h \
                       $(INCLUDE)/TipoBaseLista.h
	@echo 
	@echo Creando objeto: Lista.o 
	@echo  
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp \
			  -I$(INCLUDE) -I$(INCLUDE_CLASES_UTILS) -std=c++14

$(LIB)/libLista.a : $(OBJ)/Lista.o
	@echo 
	@echo Creando biblioteca: libLista.a 
	@echo   
	ar rvs $(LIB)/libLista.a $(OBJ)/Lista.o 
# ...............................................


# (Números aleatorios) ........................

$(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a : \
	$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o
	@echo 
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a \
		   $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o

$(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o : \
    $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
    $(INCLUDE_CLASES_UTILS)/GeneradorAleatorioEnteros.h
	@echo 
	@echo Creando objeto: GeneradorAleatorioEnteros.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o \
			  $(SRC_CLASES_UTILS)/GeneradorAleatorioEnteros.cpp \
			-I$(INCLUDE_CLASES_UTILS) -std=c++14


#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas
	
	@echo Borrando objetos de la sesion de practicas $(SESION)...
	
	-rm $(OBJ)/II_EstadisticaBasica_Lista.o
	-rm $(OBJ)/II_OrdenarLista_Basico.o
	
	@echo ...Borrados objetos de la sesión de prácticas $(SESION)
	@echo 

clean-objetos-bibliotecas:
	
	@echo Borrando objetos usados en bibliotecas de la sesión $(SESION)
	
	-rm $(OBJ)/Lista.o
	-rm $(OBJ_CLASES_UTILS)/GeneradorAleatorioEnteros.o
	
	@echo ...Borrados
	@echo

clean-libs: 
	@echo Borrando bibliotecas de la sesion de practicas $(SESION)...
	
	-rm $(LIB)/libLista.a
	-rm $(LIB_CLASES_UTILS)/libGeneradorAleatorioEnteros.a 
	
	@echo ...Borradas bibliotecas de la sesion de practicas $(SESION)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de la sesion de practicas $(SESION)...
	
	-rm $(BIN)/II_EstadisticaBasica_Lista
	-rm $(BIN)/II_OrdenarLista_Basico
	
	@echo ...Borrados ejecutables de la sesion de practicas $(SESION)

mr.proper:  clean-objs clean-libs clean-bins

