# Compilador e Flags
CXX = g++
CXXFLAGS = -Wall -fPIC -std=c++17

# O alvo padrão compila o executável principal
all: programa

# 1. Cria a DLL de Moradores
libUserLib.so: UserManager.cpp
	$(CXX) $(CXXFLAGS) -shared -o libUserLib.so UserManager.cpp

# 2. Cria a DLL de Cômodos
libRoomLib.so: RoomManager.cpp
	$(CXX) $(CXXFLAGS) -shared -o libRoomLib.so RoomManager.cpp

# 3. Compila o Main e linka as duas bibliotecas
programa: Main.cpp libUserLib.so libRoomLib.so
	$(CXX) -Wall -std=c++17 Main.cpp -o programa -L. -lUserLib -lRoomLib -Wl,-rpath=.

# Limpeza
clean:
	rm -f *.o *.so programa