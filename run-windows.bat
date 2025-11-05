@echo off
setlocal

:: Download the Windows executable
powershell -Command "Invoke-WebRequest -Uri 'https://github.com/KeshavAnandCode/Terminal/releases/download/v2.0/portfolio-windows' -OutFile '%TEMP%\\portfolio.exe'"

:: Run the executable
"%TEMP%\portfolio.exe"

:: Clean up
del "%TEMP%\portfolio.exe"

endlocal