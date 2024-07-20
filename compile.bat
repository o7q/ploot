@echo off
set makescript="all-windows"
title Compiling %makescript%
mingw32-make %makescript%
title %makescript% finished
pause