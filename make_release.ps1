if([System.IO.File]::Exists("uep")){
    Remove-Item uep -Recurse
}
if([System.IO.File]::Exists("uep.zip")){
    Remove-Item uep.zip
}
mkdir uep
Copy-Item -Path bin/ -Destination uep/ -Recurse
Copy-Item -Path src/ -Destination uep/ -Recurse
Copy-Item -Path update.exe -Destination uep/
Copy-Item -Path update.bat -Destination uep/
Compress-Archive -Path .\uep -DestinationPath .\uep.zip
Remove-Item uep -Recurse