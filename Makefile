CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

SOURCES = $(wildcard *.cpp */*.cpp */*/*.cpp)

ICON = "resources\icon\icon.res"

INCLUDES = -I "C:\CppLibs\SFML\include"
LIBRARIES = -L "C:\CppLibs\SFML\lib"

EXECUTABLE = ploot

# Windows-specific settings
all-windows:
	$(CXX) $(CXXFLAGS) $(SOURCES) $(ICON) $(INCLUDES) $(LIBRARIES) -o $(EXECUTABLE) \
	--static \
	-DSFML_STATIC \
	-static-libstdc++ \
	-static-libgcc \
	-lsfml-graphics-s \
	-lsfml-window-s \
	-lsfml-system-s \
	-lopengl32 \
	-lwinmm \
	-lgdi32 \
	-lfreetype