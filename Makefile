CC = g++
CFLAGS = -W -Wall -ansi -pedantic
INSTALL_DIR = archive
DOC_DIR = doc

all: compile

compile: src/Client.cpp
	$(CC) src/Client.cpp -o src/client

executable:
	@echo "-----Archivage en cours...-----"
	mkdir $(INSTALL_DIR)
	mv src/client $(INSTALL_DIR)
	@echo "-----Archivage terminé !-----"

client:
	@echo "-----Lancement du client-----"
	@cd $(INSTALL_DIR) && ./client
	@echo "-----Fin du client-----"

clean:
	@echo "----Nettoyage en cours...-----"
	rm -rf $(INSTALL_DIR)
	rm -rf $(DOC_DIR)
	@echo "-----Nettoyage effectué !-----"

doc:
	@echo "-----Création de la documention...-----"
	doxygen utilitaires/configurationDoxygen
	@echo "-----Documentation créée !-----"
