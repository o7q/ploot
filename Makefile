CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

SOURCES = $(wildcard *.cpp */*.cpp */*/*.cpp)

ICON = "resources\icon\icon.res"

INCLUDES = -I "C:\CppLibs\SFML\SFML_STATIC\include"
LIBRARIES = -L "C:\CppLibs\SFML\SFML_STATIC\lib"

EXECUTABLE = ploot

# Windows-specific settings
all-windows:
	$(CXX) $(CXXFLAGS) $(SOURCES) $(ICON) $(INCLUDES) $(LIBRARIES) -o $(EXECUTABLE) \
	--static \
	-static-libstdc++ \
	-static-libgcc \
	-DSFML_STATIC \
	-lsfml-graphics-s \
	-lsfml-window-s \
	-lsfml-system-s \
	-lopengl32 \
	-lwinmm \
	-lgdi32 \
	-lfreetype