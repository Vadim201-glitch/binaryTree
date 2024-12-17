# ��� ������������ �����
TARGET = kursovaja

# ����������
CXX = g++

# ����� ����������
CXXFLAGS = -std=c++17 -Wall -g

# �����
SRCDIR = src
BUILDDIR = build

# ����� �������
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# ������ ������������ �����
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# ���������� ������� � �������� build, ���� � ���
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# �������� ����� build, ���� � ���
$(BUILDDIR):
	@powershell -Command "if (!(Test-Path -Path $(BUILDDIR))) {New-Item -ItemType Directory -Path $(BUILDDIR)}"

# ������� ������
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)