#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion14_previa_estudiantes.mak
#
# makefile (estudiantes) para la sesión de prácticas 14 (ejercicios dados)
#
#############################################################################

PROYECTO = "SESION 14 -PREVIA- PARA ESTUDIANTES"

HOME = .
HOME_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_UTILS =  $(HOME_UTILS)/src
OBJ_UTILS =  $(HOME_UTILS)/obj
LIB_UTILS =  $(HOME_UTILS)/lib
INCLUDE_UTILS = $(HOME_UTILS)/include

#................................................
all: \
	preambulo \
	bibliotecas\
	$(LIB_UTILS)/libUtils.a \
	fin-bibliotecas \
	ejecutables \
	$(BIN)/CopiaEnteros \
	$(BIN)/CopiaEnteros-Bloques512 \
	$(BIN)/PGMP5_to_PGMP2 \
	$(BIN)/PGMP2_to_PGMP5 \
	$(BIN)/VerificaPGM \
	$(BIN)/LeeMP3 \
	fin-ejecutables 

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

ejecutables:
	@echo 		
	@echo Creando ejecutables...

fin-ejecutables:
	@echo 		
	@echo ...Ejecutables creados
	@echo 	

bibliotecas:
	@echo 		
	@echo Creando modulos objeto y bibliotecas...

fin-bibliotecas:
	@echo 		
	@echo ...Creados
	@echo 	

#................................................
# EJECUTABLES

$(BIN)/CopiaEnteros : $(OBJ)/CopiaEnteros.o  \
         $(INCLUDE_UTILS)/Utils.h \
	     $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: CopiaEnteros
	@echo 
	g++ -o $(BIN)/CopiaEnteros $(OBJ)/CopiaEnteros.o \
       -L$(LIB_UTILS) -lUtils 

$(BIN)/CopiaEnteros-Bloques512 : $(OBJ)/CopiaEnteros-Bloques512.o   \
         $(INCLUDE_UTILS)/Utils.h \
	     $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: CopiaEnteros-Bloques512
	@echo 
	g++ -o $(BIN)/CopiaEnteros-Bloques512 $(OBJ)/CopiaEnteros-Bloques512.o \
        -L$(LIB_UTILS) -lUtils 

$(BIN)/VerificaPGM : $(OBJ)/VerificaPGM.o \
         $(INCLUDE_UTILS)/Utils.h \
	     $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: VerificaPGM
	@echo
	g++ -o $(BIN)/VerificaPGM $(OBJ)/VerificaPGM.o  \
         -L$(LIB_UTILS) -lUtils 

$(BIN)/LeeMP3 : $(OBJ)/LeeMP3.o \
         $(INCLUDE_UTILS)/Utils.h $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: LeeMP3
	@echo
	g++ -o $(BIN)/LeeMP3 $(OBJ)/LeeMP3.o  -L$(LIB_UTILS) -lUtils 

$(BIN)/PGMP5_to_PGMP2 : $(OBJ)/PGMP5_to_PGMP2.o \
         $(INCLUDE_UTILS)/Utils.h \
	     $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: PGMP5_to_PGMP2
	@echo
	g++ -o $(BIN)/PGMP5_to_PGMP2 $(OBJ)/PGMP5_to_PGMP2.o \
         -L$(LIB_UTILS) -lUtils 

$(BIN)/PGMP2_to_PGMP5 : $(OBJ)/PGMP2_to_PGMP5.o \
         $(INCLUDE_UTILS)/Utils.h \
	     $(LIB_UTILS)/libUtils.a
	@echo 
	@echo Creando ejecutable: PGMP2_to_PGMP5
	@echo
	g++ -o $(BIN)/PGMP2_to_PGMP5 $(OBJ)/PGMP2_to_PGMP5.o \
         -L$(LIB_UTILS) -lUtils 

#................................................
# OBJETO

$(OBJ)/CopiaEnteros.o : $(SRC)/CopiaEnteros.cpp \
                        $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: CopiaEnteros.o 
	@echo
	g++ -c -o $(OBJ)/CopiaEnteros.o $(SRC)/CopiaEnteros.cpp \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/CopiaEnteros-Bloques512.o : $(SRC)/CopiaEnteros-Bloques512.cpp \
                        $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: CopiaEnteros-Bloques512.o 
	@echo
	g++ -c -o $(OBJ)/CopiaEnteros-Bloques512.o \
              $(SRC)/CopiaEnteros-Bloques512.cpp  \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/VerificaPGM.o : $(SRC)/VerificaPGM.cpp \
                       $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: VerificaPGM.o 
	@echo
	g++ -c -o $(OBJ)/VerificaPGM.o $(SRC)/VerificaPGM.cpp  \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/LeeMP3.o : $(SRC)/LeeMP3.cpp $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: LeeMP3.o 
	@echo
	g++ -c -o $(OBJ)/LeeMP3.o $(SRC)/LeeMP3.cpp \
            -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/PGMP5_to_PGMP2.o : $(SRC)/PGMP5_to_PGMP2.cpp \
                          $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: PGMP5_to_PGMP2.o 
	@echo
	g++ -c -o $(OBJ)/PGMP5_to_PGMP2.o $(SRC)/PGMP5_to_PGMP2.cpp  \
            -I$(INCLUDE_UTILS)

$(OBJ)/PGMP2_to_PGMP5.o : $(SRC)/PGMP2_to_PGMP5.cpp \
                          $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: PGMP2_to_PGMP5.o 
	@echo
	g++ -c -o $(OBJ)/PGMP2_to_PGMP5.o $(SRC)/PGMP2_to_PGMP5.cpp  \
            -I$(INCLUDE_UTILS)

#................................................
# BIBLIOTECAS

# (Utils) ........................

$(OBJ_UTILS)/Utils.o : $(SRC_UTILS)/Utils.cpp \
                              $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: Utils.o 
	@echo  
	g++ -c -o $(OBJ_UTILS)/Utils.o $(SRC_UTILS)/Utils.cpp \
        -I$(INCLUDE_UTILS) -std=c++11

$(LIB_UTILS)/libUtils.a : $(OBJ_UTILS)/Utils.o 
	@echo 
	@echo Creando biblioteca: libUtils.a 
	@echo  
	ar -rvs $(LIB_UTILS)/libUtils.a $(OBJ_UTILS)/Utils.o 

# (Fin Utils) ........................


#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: 
	@echo Borrando objetos...

	-rm $(OBJ)/CopiaEnteros.o
	-rm $(OBJ)/CopiaEnteros-Bloques512.o
	-rm $(OBJ)/PGMP5_to_PGMP2.o
	-rm $(OBJ)/PGMP2_to_PGMP5.o
	-rm $(OBJ)/VerificaPGM.o
	-rm $(OBJ)/LeeMP3.o

	@echo ...Borrados
	@echo

clean-libs: 
	@echo Borrando modulos objeto y bibliotecas...

	-rm $(OBJ_UTILS)/Utils.o 
	-rm $(LIB_UTILS)/libUtils.a

	@echo ...Borrado
	@echo 

clean-bins : 
	@echo Borrando ejecutables...

	-rm $(BIN)/CopiaEnteros 
	-rm $(BIN)/CopiaEnteros-Bloques512 
	-rm $(BIN)/PGMP5_to_PGMP2 
	-rm $(BIN)/PGMP2_to_PGMP5 
	-rm $(BIN)/VerificaPGM 
	-rm $(BIN)/LeeMP3 

	@echo ...Borrados
	@echo 	

mr.proper:  clean clean-bins
