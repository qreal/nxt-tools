#!/bin/bash

export CURPATH=$PWD
if [ -d "bin" ]; then
  export CURPATH=$CURPATH/bin
fi

export PATH="$PATH:$CURPATH/nxt-tools/gnuarm/bin"
export NXT_TOOLS_DIR="$CURPATH"
export NXT_TOOLS_DIR_POSIX="$CURPATH/nxt-tools"
export QREALDIR="$CURPATH"
export ROOT="$CURPATH/nxt-tools/nxtOSEK"
export DISPLAY=:0.0

cd $1

make clean
make all

echo "Compiling NXT program done"
