update.exe -repo MaxStgs/UEP
tar -xf plugin.zip
del plugin.zip
xcopy /s uep .
rmdir uep /S /Q
@PAUSE