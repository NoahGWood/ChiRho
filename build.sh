# Clean existing makefiles
rm -rf *Makefile build bin */*Makefile
# Build Linux
./build_scripts/build_linux.sh
# Build Windows
#./build_scripts/build_windows.sh
# Build MacOS
#./build_scripts/build_macos.sh
