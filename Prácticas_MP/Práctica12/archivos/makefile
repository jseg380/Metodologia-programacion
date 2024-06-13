#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
#
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# makefile_sesion12_alumnos.mak
#
# makefile (alumnos) para la sesión de prácticas 12
#
#############################################################################

PROYECTO = "SESION 12 - PARA ESTUDIANTES-"

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
all:  preambulo \
	  $(BIN)/CopiaTodo \
      $(BIN)/CopiaExceptoVocales \
      $(BIN)/CuentaCaracteres \
      $(BIN)/CopiaLineasNoVacias \
      $(BIN)/NumeraLineas \
      $(BIN)/ComprimeLineas \
      $(BIN)/ComprimeLineas-ProcesamientoLineasClasico \
      $(BIN)/ComprimeLineas-ProcesamientoLineasFlujo \
      $(BIN)/CopiaEnteros \
      $(BIN)/SumaEnteros \
      $(BIN)/CuentaLineas \
      $(BIN)/Cuenta_palabras_por_linea \
      $(BIN)/PuntoMedio \
      $(BIN)/SeleccionPuntos \
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

$(BIN)/CopiaTodo : $(SRC)/CopiaTodo.cpp
	@echo 
	@echo Creando ejecutable: CopiaTodo
	@echo 
	g++ -o $(BIN)/CopiaTodo  $(SRC)/CopiaTodo.cpp -std=c++14

$(BIN)/CopiaExceptoVocales : $(SRC)/CopiaExceptoVocales.cpp
	@echo 
	@echo Creando ejecutable: CopiaExceptoVocales
	@echo 
	g++ -o $(BIN)/CopiaExceptoVocales $(SRC)/CopiaExceptoVocales.cpp -std=c++14

$(BIN)/CuentaCaracteres  : $(SRC)/CuentaCaracteres.cpp
	@echo 
	@echo Creando ejecutable: CuentaCaracteres
	@echo 
	g++ -o $(BIN)/CuentaCaracteres  $(SRC)/CuentaCaracteres.cpp -std=c++14

$(BIN)/CopiaLineasNoVacias : $(SRC)/CopiaLineasNoVacias.cpp
	@echo 
	@echo Creando ejecutable: CopiaLineasNoVacias
	@echo 
	g++ -o $(BIN)/CopiaLineasNoVacias $(SRC)/CopiaLineasNoVacias.cpp -std=c++14

$(BIN)/NumeraLineas : $(SRC)/NumeraLineas.cpp
	@echo 
	@echo Creando ejecutable: NumeraLineas
	@echo 
	g++ -o $(BIN)/NumeraLineas $(SRC)/NumeraLineas.cpp -std=c++14

$(BIN)/ComprimeLineas : $(SRC)/ComprimeLineas.cpp
	@echo 
	@echo Creando ejecutable: ComprimeLineas
	@echo 
	g++ -o $(BIN)/ComprimeLineas $(SRC)/ComprimeLineas.cpp -std=c++14

$(BIN)/ComprimeLineas-ProcesamientoLineasClasico : \
                        $(SRC)/ComprimeLineas-ProcesamientoLineasClasico.cpp
	@echo 
	@echo Creando ejecutable: ComprimeLineas-ProcesamientoLineasClasico
	@echo 
	g++ -o $(BIN)/ComprimeLineas-ProcesamientoLineasClasico \
           $(SRC)/ComprimeLineas-ProcesamientoLineasClasico.cpp -std=c++14

$(BIN)/ComprimeLineas-ProcesamientoLineasFlujo : \
    $(SRC)/ComprimeLineas-ProcesamientoLineasFlujo.cpp
	@echo 
	@echo Creando ejecutable: ComprimeLineas-ProcesamientoLineasFlujo
	@echo 
	g++ -o $(BIN)/ComprimeLineas-ProcesamientoLineasFlujo \
           $(SRC)/ComprimeLineas-ProcesamientoLineasFlujo.cpp -std=c++14

$(BIN)/CopiaEnteros : $(SRC)/CopiaEnteros.cpp
	@echo 
	@echo Creando ejecutable: CopiaEnteros
	@echo 
	g++ -o $(BIN)/CopiaEnteros $(SRC)/CopiaEnteros.cpp -std=c++14

$(BIN)/SumaEnteros : $(SRC)/SumaEnteros.cpp
	@echo 
	@echo Creando ejecutable: SumaEnteros
	@echo 
	g++ -o $(BIN)/SumaEnteros $(SRC)/SumaEnteros.cpp -std=c++14

$(BIN)/CuentaLineas : $(SRC)/CuentaLineas.cpp
	@echo 
	@echo Creando ejecutable: CuentaLineas
	@echo 
	g++ -o $(BIN)/CuentaLineas $(SRC)/CuentaLineas.cpp -std=c++14

$(BIN)/Cuenta_palabras_por_linea : $(SRC)/Cuenta_palabras_por_linea.cpp
	@echo 
	@echo Creando ejecutable: Cuenta_palabras_por_linea
	@echo 
	g++ -o $(BIN)/Cuenta_palabras_por_linea \
	       $(SRC)/Cuenta_palabras_por_linea.cpp -std=c++14

$(BIN)/PuntoMedio : $(OBJ)/PuntoMedio.o $(LIB)/libPunto2D.a \
                    $(LIB)/libSecuenciaPunto2D.a
	@echo 
	@echo Creando ejecutable: PuntoMedio
	@echo 
	g++ -o $(BIN)/PuntoMedio $(OBJ)/PuntoMedio.o \
	     -L$(LIB) -lPunto2D -lSecuenciaPunto2D

$(BIN)/SeleccionPuntos : $(OBJ)/SeleccionPuntos.o $(LIB)/libPunto2D.a \
                         $(LIB)/libSecuenciaPunto2D.a
	@echo 
	@echo Creando ejecutable: SeleccionPuntos
	@echo 
	g++ -o $(BIN)/SeleccionPuntos $(OBJ)/SeleccionPuntos.o \
	     -L$(LIB) -lPunto2D -lSecuenciaPunto2D
	     
#................................................
# OBJETOS 

$(OBJ)/PuntoMedio.o : $(SRC)/PuntoMedio.cpp  \
                      $(INCLUDE)/Punto2D.h  $(INCLUDE)/SecuenciaPunto2D.h \
			          $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: PuntoMedio.o
	@echo
	g++ -c -o $(OBJ)/PuntoMedio.o $(SRC)/PuntoMedio.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/SeleccionPuntos.o : $(SRC)/SeleccionPuntos.cpp  \
                           $(INCLUDE)/Punto2D.h  $(INCLUDE)/SecuenciaPunto2D.h \
			               $(INCLUDE_UTILS)/Utils.h
	@echo 
	@echo Creando objeto: SeleccionPuntos.o
	@echo
	g++ -c -o $(OBJ)/SeleccionPuntos.o $(SRC)/SeleccionPuntos.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

#................................................
# BIBLIOTECAS

$(OBJ_UTILS)/Utils.o : $(SRC_UTILS)/Utils.cpp $(INCLUDE_UTILS)/Utils.h 
	@echo 
	@echo Creando objeto: Utils.o
	@echo 
	g++ -c -o $(OBJ_UTILS)/Utils.o $(SRC_UTILS)/Utils.cpp \
	        -I$(INCLUDE_UTILS) -std=c++14

$(OBJ)/Punto2D.o : $(SRC)/Punto2D.cpp $(INCLUDE)/Punto2D.h \
                   $(INCLUDE_UTILS)/Utils.h 
	@echo 
	@echo Creando objeto: Punto2D.o
	@echo 
	g++ -c -o $(OBJ)/Punto2D.o $(SRC)/Punto2D.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(LIB)/libPunto2D.a : $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o
	@echo 
	@echo Creando biblioteca: libPunto2D.a
	@echo 
	ar rvs $(LIB)/libPunto2D.a $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o


$(OBJ)/SecuenciaPunto2D.o : $(SRC)/SecuenciaPunto2D.cpp \
                            $(INCLUDE)/SecuenciaPunto2D.h \
                            $(INCLUDE)/Punto2D.h
	@echo 
	@echo Creando objeto: SecuenciaPunto2D.o
	@echo 
	g++ -c -o $(OBJ)/SecuenciaPunto2D.o $(SRC)/SecuenciaPunto2D.cpp \
	        -I$(INCLUDE) -I$(INCLUDE_UTILS) -std=c++14

$(LIB)/libSecuenciaPunto2D.a : $(OBJ)/SecuenciaPunto2D.o  \
                               $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o
	@echo 
	@echo Creando biblioteca: libSecuenciaPunto2D.a
	@echo 
	ar rvs $(LIB)/libSecuenciaPunto2D.a \
	 	 $(OBJ)/SecuenciaPunto2D.o  $(OBJ)/Punto2D.o $(OBJ_UTILS)/Utils.o

#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas

	@echo Borrando objetos de $(PROYECTO)...


	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-objetos-bibliotecas: 

	@echo Borrando objetos usados en $(PROYECTO)...

	-rm $(OBJ)/PuntoMedio.o
	-rm $(OBJ)/SeleccionPuntos.o

	@echo ...Borrados objetos usados en $(PROYECTO)
	@echo 

clean-libs: 

	@echo Borrando bibliotecas de $(PROYECTO)...

	-rm $(OBJ)/Punto2D.o
	-rm $(LIB)/libPunto2D.a 
	-rm $(OBJ)/SecuenciaPunto2D.o	
	-rm $(LIB)/libSecuenciaPunto2D.a 

	-rm $(OBJ_UTILS)/Utils.o

	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 

	@echo Borrando ejecutables de $(PROYECTO)...

	-rm $(BIN)/CopiaTodo 
	-rm $(BIN)/CopiaExceptoVocales 
	-rm $(BIN)/CuentaCaracteres 
	-rm $(BIN)/CopiaLineasNoVacias 
	-rm $(BIN)/NumeraLineas 
	-rm $(BIN)/ComprimeLineas 
	-rm $(BIN)/ComprimeLineas-ProcesamientoLineasClasico 
	-rm $(BIN)/ComprimeLineas-ProcesamientoLineasFlujo 
	-rm $(BIN)/CopiaEnteros 
	-rm $(BIN)/SumaEnteros 
	-rm $(BIN)/CuentaLineas
	-rm $(BIN)/Cuenta_palabras_por_linea 
	-rm $(BIN)/PuntoMedio
	-rm $(BIN)/SeleccionPuntos

	@echo ...Borrados ejecutables de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

