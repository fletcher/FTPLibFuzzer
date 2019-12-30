#!/usr/bin/env bash

# Update apt-get
apt-get update


# Install basic development packages 
apt-get install -y build-essential cmake libbsd-dev  


# Install llvm/fuzzing tools
apt-get install -y clang llvm


# Install Windows cross-development tools
apt-get install -y mingw-w64 nsis


# Install other development tools
apt-get install -y re2c lldb
