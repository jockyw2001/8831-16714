cd ../../


cp config.tmpl .config -f

PURE_PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/tools/bin/
export PATH=/tools/mips-sde-elf-gcc/bin:$PURE_PATH:$PATH

#==================================================================================

rm -rf Bin_* Obj_*

#-----------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------
#---------- WHISKY ----------

PROJ=R2_WHISKY_128M_ATSC make
rm -r Bin_R2_WHISKY*
rm -r Obj_R2_WHISKY*

PROJ=R2_WHISKY_64M_ATSC make
rm -r Bin_R2_WHISKY*
rm -r Obj_R2_WHISKY*

PROJ=R2_WHISKY_ATV_MM_64MB make
rm -r Bin_R2_WHISKY*
rm -r Obj_R2_WHISKY*
