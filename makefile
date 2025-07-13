# cores
ROSA=35
VERDE=32
AMARELO=33
CIANO=36

#alvo
all:
	@echo "\033[$(CIANO)m----------------------------------------\033[0m"
	@echo "\033[$(ROSA)mIniciando a compilação...\033[0m"
	@echo "\033[$(AMARELO)mCompilando main.cpp ...\033[0m"
	g++ -Wall -c main.cpp
	@echo "\033[$(AMARELO)mCompilando cliente.cpp ...\033[0m"
	g++ -Wall -c cliente.cpp

	@echo "\033[$(AMARELO)mCompilando corretor.cpp ...\033[0m"
	g++ -Wall -c corretor.cpp

	@echo "\033[$(AMARELO)mCompilando imovel.cpp ...\033[0m"
	g++ -Wall -c imovel.cpp

	@echo "\033[$(AMARELO)mCompilando funcoesAux.cpp ...\033[0m"
	g++ -Wall -c funcoesAux.cpp

	@echo "\033[$(ROSA)mLinkando arquivos...\033[0m"
	g++ -Wall -o imobiliaria main.o cliente.o corretor.o imovel.o funcoesAux.o
	@echo "\033[1;$(VERDE)mCompilação realizada com sucesso!:)\033[0m"
	@echo "\033[$(CIANO)m----------------------------------------\033[0m"

clean:
	@echo "\033[$(ROSA)mLimpando arquivos...\033[0m"
	rm -f *.o imobiliaria
	@echo "\033[1;$(VERDE)mLimpeza realizada com sucesso!\033[0m"