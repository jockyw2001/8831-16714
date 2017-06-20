export CC=/usr/bin/gcc
cd ../../


cp config.tmpl .config -f

PROJ=R2_EDEN_ZUI_64MB_ATVMM make

rm -r Bin_R2_EDEN*
rm -r Obj_R2_EDEN*