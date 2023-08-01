@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2023a
call "C:\Program Files\MATLAB\R2023a\sys\lcc64\lcc64\mex\lcc64opts.bat"
"C:\Program Files\MATLAB\R2023a\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"C:\Program Files\MATLAB\R2023a\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
