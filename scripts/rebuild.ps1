$scriptPath = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition
$buildPath = Join-Path -Path $scriptPath -ChildPath "..\build"

# Remove the build folder itself
Get-ChildItem -Path $buildPath -Recurse | Remove-Item -Force -Recurse -ErrorAction Ignore

Start-Process -FilePath "cmake.exe" -ArgumentList ".." -WorkingDirectory $buildPath -NoNewWindow -Wait
Start-Process -FilePath "cmake.exe" -ArgumentList "--build ." -WorkingDirectory $buildPath -NoNewWindow -Wait
