#!/bin/bash

if hash gksu 2>/dev/null; then
  gksu "modprobe -r cdc_acm sam_ba"
elif hash pkexec 2>/dev/null; then
  pkexec "modprobe -r cdc_acm sam_ba"
elif hash kdesu 2>/dev/null; then
  kdesu "modprobe -r cdc_acm sam_ba"
else
  echo "Sudo need"
fi

