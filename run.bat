
echo off
color 3
echo lancons le convertiseur d'unite
g++ main.cpp source/menu_sys.cpp source/mecanic.cpp -o main.exe
start main.exe