#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# sesion09_previa.mak
#
# makefile para la sesión de prácticas 9 (previa, para alumnos)
#
#############################################################################

PROYECTO = "SESION 9 -SECUENCIA- VERSION PREVIA PARA ESTUDIANTES"

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
      $(BIN)/III_Demo-Secuencia \
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

$(BIN)/III_Demo-Secuencia : \
              $(OBJ)/III_Demo-Secuencia.o \
              $(LIB)/libSecuencia.a
	@echo 
	@echo Creando ejecutable: III_Demo-Secuencia
	@echo 
	g++ -o $(BIN)/III_Demo-Secuencia \
         $(OBJ)/III_Demo-Secuencia.o -L$(LIB) -lSecuencia

#................................................
# OBJETOS 

$(OBJ)/III_Demo-Secuencia.o : \
              $(SRC)/III_Demo-Secuencia.cpp \
              $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: III_Demo-Secuencia.o
	@echo
	g++ -c -o $(OBJ)/III_Demo-Secuencia.o $(SRC)/III_Demo-Secuencia.cpp  \
        -I$(INCLUDE) -std=c++11


#................................................
# BIBLIOTECAS


# (Secuencia) ........................
 
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o


#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas

	@echo Borrando objetos de $(PROYECTO)...

	-rm $(OBJ)/III_Demo-Secuencia.o

	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando objetos usados en bibliotecas de $(PROYECTO)...

	-rm $(OBJ)/Secuencia.o 

	@echo ...Borrados objetos usados en bibliotecas de $(PROYECTO)
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de $(PROYECTO)...

	-rm $(LIB)/libSecuencia.a

	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...

	-rm $(BIN)/III_Demo-Secuencia
	
	@echo ...Borrados ejecutables de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

