export CC=/usr/bin/gcc
cd ../../


cp config.tmpl .config -f


PROJ=R2_EULER_ZUI_128MB_DVBT make
rm -r Bin_R2_EULER*
rm -r Obj_R2_EULER*

