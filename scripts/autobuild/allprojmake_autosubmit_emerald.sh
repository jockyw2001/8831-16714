cd ../../


cp config.tmpl .config -f

PURE_PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/tools/bin/
export PATH=/tools/mips-sde-elf-gcc/bin:$PURE_PATH:$PATH

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT make
rm -r Bin_MIPS_EMERALD_*
rm -r Obj_MIPS_EMERALD_*
