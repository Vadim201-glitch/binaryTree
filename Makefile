# Имя исполняемого файла
TARGET = kursovaja

# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++17 -Wall -g

# Папки
SRCDIR = src
BUILDDIR = build

# Файлы проекта
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Компиляция объекта и создание build, если её нет
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки build, если её нет
$(BUILDDIR):
	@powershell -Command "if (!(Test-Path -Path $(BUILDDIR))) {New-Item -ItemType Directory -Path $(BUILDDIR)}"

# Очистка сборки
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)