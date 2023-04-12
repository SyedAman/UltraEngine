cd ..\build;
Remove-Item -Path .\* -Recurse -Force;
cmake ..;
cmake --build .