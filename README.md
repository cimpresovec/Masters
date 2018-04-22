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
    * minted (for code formatting)
* Cpp projects
    * gcc (>7.3.x)
    * qmake
    * raylib
* Java project
    * JRE and JDK > 8 (>1.8.x)

# Installation / build
## Thesis
The following command should be used:
```bash
pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex

bibtex thesis.aux

pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex

pdflatex -synctex=1 -interaction=nonstopmode --shell-escape thesis.tex
```
## Cpp projects
TODO

## Java projects
Open the project in JetBrains IDEA and just run.

# Software used to create this thesis
TODO