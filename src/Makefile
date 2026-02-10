# Makefile Linux com Testes

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC

# Nomes
LIB_NAME = libUserLib.so
EXE_NAME = programa
TEST_NAME = test_runner

# Regra padrão: compila tudo
all: $(EXE_NAME) $(TEST_NAME)

# --- PROGRAMA PRINCIPAL ---
$(EXE_NAME): Main.o $(LIB_NAME)
	@echo "--- Linkando Programa Principal ---"
	$(CXX) Main.o -o $(EXE_NAME) -L. -lUserLib -Wl,-rpath=.

Main.o: Main.cpp IUserManager.h
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

# --- TESTES AUTOMATIZADOS ---
$(TEST_NAME): Test.o $(LIB_NAME)
	@echo "--- Linkando Test Runner ---"
	$(CXX) Test.o -o $(TEST_NAME) -L. -lUserLib -Wl,-rpath=.

Test.o: Test.cpp IUserManager.h
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

# --- BIBLIOTECA COMPARTILHADA (.so) ---
$(LIB_NAME): UserManager.o
	@echo "--- Gerando Shared Library ---"
	$(CXX) -shared -o $(LIB_NAME) UserManager.o

UserManager.o: UserManager.cpp IUserManager.h
	$(CXX) $(CXXFLAGS) -c UserManager.cpp -o UserManager.o

# --- COMANDOS ÚTEIS ---
clean:
	rm -f *.o *.so $(EXE_NAME) $(TEST_NAME)

# Roda o programa interativo
run: $(EXE_NAME)
	./$(EXE_NAME)

# Roda os testes automatizados
test: $(TEST_NAME)
	./$(TEST_NAME)