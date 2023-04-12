$scriptPath = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition
$buildPath = Join-Path -Path $scriptPath -ChildPath "..\build"

Start-Process -FilePath "powershell.exe" -ArgumentList "-NoProfile -Command { Remove-Item -Path .\* -Recurse -Force }" -WorkingDirectory $buildPath -NoNewWindow -Wait
Start-Process -FilePath "cmake.exe" -ArgumentList ".." -WorkingDirectory $buildPath -NoNewWindow -Wait
Start-Process -FilePath "cmake.exe" -ArgumentList "--build ." -WorkingDirectory $buildPath -NoNewWindow -Wait
