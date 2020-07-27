# TrueConf-test-exersize

На входе картинка размером x1*y1. Нужно отмасштабировать ее в картинку размером х2*y2. Размер может как увеличиваться, так и уменьшаться. Причем масштаб х и y могут быть разные. 

## Compile
To compile program enter the command:
```bash
$ g++ -O3 -o scale main.cpp -lm -lpthread -lX11 -ljpeg
```

## Launch the program
To launch program enter the command with command-line arguments:
```bash
$ ./scale `path/to/img` x2 y2
```
x2, y2 - new image sizes respectively

## Required dependencies:
  - CImg.h  template library - for I/O;
  - libjpeg;
