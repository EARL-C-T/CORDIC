#! /bin/bash
cp -r include ~/.local/
mkdir -p ~/.local/lib/
mv build/x86_64/libfixpnt.a ~/.local/lib/
mv build/x86_64/libCORDIC.a ~/.local/lib/
mkdir -p ~/.local/sbin/
mv build/x86_64/* ~/.local/sbin/
eval PATH=$PATH:~/.local/sbin/
