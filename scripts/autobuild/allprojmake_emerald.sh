cd ../../
rm -r -f BIN_EMERALD_ALL
mkdir BIN_EMERALD_ALL

PURE_PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/tools/bin/
export PATH=/tools/mips-sde-elf-gcc/bin:$PURE_PATH:$PATH

VER_FILE=./project/boarddef/Board
SW_CFG_FILE=./project/swdef/SW_Config


if [ "$1" == "" ]; then
	echo "No Version Number"
else
cp ${VER_FILE}.h ${VER_FILE}.org
sed -i 's/#define AUTO_BUILD_SW_VER.*/#define AUTO_BUILD_SW_VER                 '${1}'/g' ${VER_FILE}.h
fi

cp config.tmpl .config -f &&  PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT make
cp -r Bin_MIPS_EMERALD_* ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT_CI_PLUS make
cp -r Bin_MIPS_EMERALD_* ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT_CI_PLUS_T2 make
cp -r Bin_MIPS_EMERALD_* ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DTMB make
cp -r Bin_MIPS_EMERALD_* ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT_PLUS_DVBC make
cp -r Bin_MIPS_EMERALD_* ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*



#for auto test model put at the end of script

cp ${SW_CFG_FILE}.h ${SW_CFG_FILE}.org
sed -i 's/#define CHAKRA3_AUTO_TEST.*/#define CHAKRA3_AUTO_TEST                       ENABLE/g' ${SW_CFG_FILE}.h
PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT make
cp -r Bin_MIPS_EMERALD_* ./Bin_MIPS_EMERALD_ZUI_MM_128MB_DVBT_AUTO_TEST
cp -r Bin_MIPS_EMERALD_ZUI_MM_128MB_DVBT_AUTO_TEST ./BIN_EMERALD_ALL
rm -r Obj_MIPS_EMERALD_*
rm -r Bin_MIPS_EMERALD_*
cp ${SW_CFG_FILE}.org ${SW_CFG_FILE}.h
rm -r ${SW_CFG_FILE}.org



if [ "$1" == "" ]; then
	echo "No Version Number"
else
cp ${VER_FILE}.org ${VER_FILE}.h
rm -r ${VER_FILE}.org
fi