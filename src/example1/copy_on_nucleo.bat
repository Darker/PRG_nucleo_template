@echo off
for /f %%D in ('%SystemRoot%\System32\wbem\WMIC.exe volume get DriveLetter^, Label ^| find "NODE_F446RE"') do set nucleo_drive=%%D
rem echo Nucleo drive: %nucleo_drive%

IF EXIST %nucleo_drive%\DETAILS.TXT (
  IF EXIST %1 (
    @echo on
    xcopy %1 %nucleo_drive%
    @echo off
    echo Copied %1 on nucleo
  ) ELSE (
    echo Binary %1 not found. Run `mingw32-make` in this directory to compile the project.
  )
) ELSE (
  echo Nucleo drive not found. If needed, edit the `find "NODE_F446RE"` part of this script to refference your nucleo volume name.
)
