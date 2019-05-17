# OpenGL
Learning OpenGL  

# Setting up
Install GLFW.  
For Fedora
```console
foo@bar:~$ sudo dnf install glfw glfw-devel
```
If gives error of missing _gl.h_  
```console
foo@bar:~$ sudo dnf install mesa-libGL mesa-libGL-devel
```

Demo code: https://www.glfw.org/documentation.html  
To compile the code:
```console
g++ -l glfw -l GL main.cpp
```