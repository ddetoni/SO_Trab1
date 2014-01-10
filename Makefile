## -*- Makefile -*-
##
## Usuário: douglas
## Hora: 17/12/2013 15:53:20
## Makefile created by Oracle Solaris Studio.
##
## Este arquivo é gerado automaticamente.
##


#### Definições do compilador e da ferramenta compartilhadas por todos os destinos de build #####
CCC = g++
CXX = g++
BASICOPTS = -g -pthread -lpthread -std=gnu++0x
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Definir os diretórios de destino.
TARGETDIR_main=bin


all: $(TARGETDIR_main)/main

## Destino: main
OBJS_main =  \
	$(TARGETDIR_main)/Entry.o \
	$(TARGETDIR_main)/HashTable.o \
	$(TARGETDIR_main)/Main.o
USERLIBS_main = $(SYSLIBS_main) 
DEPLIBS_main =  
LDLIBS_main = $(USERLIBS_main)


# Link ou archive
$(TARGETDIR_main)/main: $(TARGETDIR_main) $(OBJS_main) $(DEPLIBS_main)
	$(LINK.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ $(OBJS_main) $(LDLIBS_main)


# Compilar arquivos de código-fonte nos arquivos .o
$(TARGETDIR_main)/Entry.o: $(TARGETDIR_main) src/Entry.cpp
	$(COMPILE.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ src/Entry.cpp

$(TARGETDIR_main)/HashTable.o: $(TARGETDIR_main) src/HashTable.cpp
	$(COMPILE.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ src/HashTable.cpp

$(TARGETDIR_main)/Main.o: $(TARGETDIR_main) src/Main.cpp
	$(COMPILE.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ src/Main.cpp



#### Limpar o destino deleta todos os arquivos gerados ####
clean:
	rm -f \
		$(TARGETDIR_main)/main \
		$(TARGETDIR_main)/Entry.o \
		$(TARGETDIR_main)/HashTable.o \
		$(TARGETDIR_main)/Main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_main)


# Criar o diretório de destino (se necessário)
$(TARGETDIR_main):
	mkdir -p $(TARGETDIR_main)


# Ativar verificação de dependências
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-i386-Linux

