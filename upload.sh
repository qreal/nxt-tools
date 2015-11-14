PATH=$PWD/cygwin/bin:$PATH
cd "$2"
make clean    
make all
echo Executing NeXTTool to upload $1.rxe...
 $3/nexttool/NeXTTool.exe  /COM=usb -download=$1.rxe
 $3/nexttool/NeXTTool.exe  /COM=usb -listfiles=${1:0:15}.rxe # NXT crops file name to 15 letters, so doing it here too...
echo "NeXTTool is terminated"
echo "Done"
