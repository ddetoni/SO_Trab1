## -*- Makefile -*-
##
## Usuário: douglas
## Hora: 03/12/2013 10:57:54
## Makefile created by Oracle Solaris Studio.
##
## Este arquivo é gerado automaticamente.
##


#### Definições do compilador e da ferramenta compartilhadas por todos os destinos de build #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Definir os diretórios de destino.
TARGETDIR_main=GNU-i386-Linux


all: $(TARGETDIR_main)/main

## Destino: main
OBJS_main =  \
	$(TARGETDIR_main)/main.o \
	$(TARGETDIR_main)/hash_table.o
USERLIBS_main = $(SYSLIBS_main) 
DEPLIBS_main =  
LDLIBS_main = $(USERLIBS_main)


# Link ou archive
$(TARGETDIR_main)/main: $(TARGETDIR_main) $(OBJS_main) $(DEPLIBS_main)
	$(LINK.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ $(OBJS_main) $(LDLIBS_main)


# Compilar arquivos de código-fonte nos arquivos .o
$(TARGETDIR_main)/main.o: $(TARGETDIR_main) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ src/main.cpp

$(TARGETDIR_main)/hash_table.o: $(TARGETDIR_main) src/hash_table.cpp
	$(COMPILE.cc) $(CCFLAGS_main) $(CPPFLAGS_main) -o $@ src/hash_table.cpp



#### Limpar o destino deleta todos os arquivos gerados ####
clean:
	rm -f \
		$(TARGETDIR_main)/main \
		$(TARGETDIR_main)/main.o \
		$(TARGETDIR_main)/hash_table.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_main)


# Criar o diretório de destino (se necessário)
$(TARGETDIR_main):
	mkdir -p $(TARGETDIR_main)


# Ativar verificação de dependências
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-i386-Linux

