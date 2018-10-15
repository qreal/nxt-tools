PATH="$PWD/cygwin/bin:$PATH"
cd "$2"
make clean
make all
echo "Compiling NXT program done"
