# About
This repository contains my complete master's thesis.

# Structure
Folder breakdown
* Thesis - contains the written thesis in Latex format.
    * images - used images in the thesis
* Projects - contains all projects created for the thesis
    * Cpp - contains the C++ game project. Raylib library used.
    * Java - contains the Java project. LibGDX framework used.
    * Unity - contains the Unity project.

# Dependencies
* Thesis
    * texlive (core,most,lang)
* Cpp projects
    * gcc (>7.3.x)
    * qmake
    * raylib
* Java project
    * JRE and JDK > 8 (>1.8.x)

# Installation / build
## Thesis
The following command should be used to build the PDF file:
```bash
pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex

bibtex thesis.aux

pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex

pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex
```
## Cpp project
QMake was used in order to build the project. QtCreator IDE is recommended for easier building of the project. Open the Breakout.pro file in QtCreator and you are good to go. RayLib library is required to installed systemwide. It can be build and installed from the official GitHub page (https://github.com/raysan5/raylib).

## Java project
Open the project in JetBrains IDEA. Latest JDK and JRE is required.

## Unity project
Open the project in the Unity editor. Version 2018.1 was used.

# Software used to create this thesis
Tex live
TexStudio
JabRef
QtCreator
JetBrains IDEA
Unity
Visual Studio Code