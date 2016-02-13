echo off
set mainpath=%cd:\=/%
set projpath=%2
set projpath=%projpath:\=/%
set projpath=%projpath:"=%
echo on
"./cygwin/bin/bash" -c "./compile.sh '%1' '%projpath%' '%mainpath%'"
