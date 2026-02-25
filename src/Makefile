# Compilador e Flags
CXX = g++
CXXFLAGS = -Wall -fPIC -std=c++17

# O alvo padrão compila o executável principal
all: programa

# 1. Cria a DLL/Shared Library de Moradores
libUserLib.so: UserManager.cpp
	$(CXX) $(CXXFLAGS) -shared -o libUserLib.so UserManager.cpp

# 2. Cria a DLL/Shared Library de Cômodos
libRoomLib.so: RoomManager.cpp
	$(CXX) $(CXXFLAGS) -shared -o libRoomLib.so RoomManager.cpp

# 3. Cria a DLL/Shared Library de Escalas
libScheduleLib.so: ScheduleManager.cpp
	$(CXX) $(CXXFLAGS) -shared -o libScheduleLib.so ScheduleManager.cpp

# 4. Compila o Main e linka as TRÊS bibliotecas
programa: Main.cpp libUserLib.so libRoomLib.so libScheduleLib.so
	$(CXX) -Wall -std=c++17 Main.cpp -o programa -L. -lUserLib -lRoomLib -lScheduleLib -Wl,-rpath=.

# --- TESTES FUNCIONAIS ---

# Compila os testes de comodos
test_comodos: TestRoom.cpp libRoomLib.so
	$(CXX) -Wall -std=c++17 TestRoom.cpp -o test_comodos -L. -lRoomLib -Wl,-rpath=.

# Compila os testes de escalas (NOVO)
test_escalas: TestSchedule.cpp libScheduleLib.so
	$(CXX) -Wall -std=c++17 TestSchedule.cpp -o test_escalas -L. -lScheduleLib -Wl,-rpath=.

# Limpeza geral
clean:
	rm -f *.o *.so programa test_comodos test_escalas