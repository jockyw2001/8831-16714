#!/bin/bash

if [ "$1" == "" ] || [ "$2" == "" ]; then
  echo ""
  echo "Please copy this file to your local directory first. (ex: /home/ck.yang)"
  echo ""
	echo "Usage: $0 <Charka3 code path> <UT workspace path>"
  echo "ex: source $0 PERFORCE/DAILEO/Yoga/Chakra3 workspace_chakra3"
  echo ""
	exit -1
fi

if [ ! -d "$1" ]; then
    echo "Directory \"$1\" does NOT exist!"
  	exit -1
fi

echo "Checking Chakra3 directory \"$1\"... [OK]"

echo "Building BDF file..."

cd $1
cp config.tmpl .config
sed -i '/PROJ ?=/d' .config
sed -i '2a PROJ ?= MIPS_EMERALD_ZUI_MM_128MB_DVBT_CI_PLUS' .config
make clean
rm *.bdf
make PARA=1
tmpline=$(cat cpptestscan.bdf | grep -n -w 'cpptestscan v.9.0.1.12' | tail -n 1 | cut -d: -f1)
sed -i "$tmpline,\$d" cpptestscan.bdf
cd -

if [ -d "$2" ]; then
    echo "Removing original directory \"$2\"..."
    rm -rf $2
fi

echo "Copying Parasoft to your local directory..."
cp -rf /home/muters/parasoft/cpptest/9.0 cpptest9.0

cd cpptest9.0

echo "Copying Chakra3 customized files to your local Parasoft..."
cp engine/lib/libcpptestruntime.so.x86.gcc.32bit.no_isspace engine/lib/libcpptestruntime.so
cp engine/lib/libcpptestruntime.a.x86.gcc.32bit.no_isspace engine/lib/libcpptestruntime.a
cp engine/runtime/include/cpptest_driver.c.h__chakra3 engine/runtime/include/cpptest_driver.c.h

echo "Creating Parasoft workspace using your BDF file..."
./cpptestcli -data "../$2" -prefs "/home/muters/workspace_template/chakra3_x86/chakra3_x86.epf" -bdf "../$1/cpptestscan.bdf"
cd -

echo "Changing Property Settings..."
cd $2/UTProject
sed -i s/com.parasoft.xtest.checkers.api.cpp.options.linker.options.linux.x86=.*/com.parasoft.xtest.checkers.api.cpp.options.linker.options.linux.x86=\${cpptest\\\\:original_options}\ -L\${workspace_loc}\\/..\\/cpptest9.0\\/engine\\/lib/g .parasoft
sed -i '$a \/UTProject\/\/com.parasoft.xtest.checkers.api.cpp.options.runtime.location=\${workspace_loc}\/..\/cpptest9.0\/engine\/runtime' .parasoft
sed -i '$a \/UTProject\/\/com.parasoft.xtest.checkers.api.cpp.options.compiler.family.linux.x86=gcc_4_4' .parasoft
cd -

echo "Copying command properties files..."
cd $2/.metadata/.plugins/com.parasoft.xtest.common.eclipse.core/com.parasoft.xtest.checkers.api
rm configs/c++test/*
cp /home/muters/workspace_template/chakra3_x86/*.properties configs/c++test/
chmod +w configs/c++test/*
sed -i s/com.parasoft.xtest.checkers.api.config.active.c++test=.*/com.parasoft.xtest.checkers.api.config.active.c++test=c++test.user\\\\:\\/\\/\Build\ Test\ Executable/g ConfigManager.properties
sed -i s/com.parasoft.xtest.checkers.api.config.active.multitool=.*/com.parasoft.xtest.checkers.api.config.active.multitool=c++test\\\\:c++test.user\\\\:\\/\\/\Build\ Test\ Executable/g ConfigManager.properties
cd -

echo "Copying Unit Test files into your workspace..."
cp -rf $1/unittest/* $2/UTProject/.

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$2/../cpptest9.0/engine/lib


echo "[Done!]"
echo ""
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ""
echo "  Next Steps:"
echo "    1. cd cpptest9.0"
echo "    2. ./cpptest&"
echo ""
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo ""
