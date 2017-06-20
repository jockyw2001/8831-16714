cd ../../


cp config.tmpl .config -f

PURE_PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/tools/bin/
export PATH=/tools/mips-sde-elf-gcc/bin:$PURE_PATH:$PATH

#==================================================================================

rm -rf Bin_* Obj_*

#-----------------------------------------------------------------------------------
#---------- EULER ----------

#PROJ=R2_EULER_ZUI_128MB_DVBT make
#rm -r Bin_R2_EULER*
#rm -r Obj_R2_EULER*


#-----------------------------------------------------------------------------------
#---------- EMERALD ----------

PROJ=MIPS_EMERALD_ZUI_MM_128MB_DVBT make
rm -r Bin_MIPS_EMERALD_*
rm -r Obj_MIPS_EMERALD_*

#-----------------------------------------------------------------------------------
#---------- EDEN ----------

#PROJ=R2_EDEN_ZUI_64MB_ATVMM make
PROJ=R2_EDEN_64MB_ATSC make
rm -rf Bin_* Obj_*

#-----------------------------------------------------------------------------------
#---------- NASA ----------
PROJ=R2_NASA_ZUI_64MB_DTMB make
rm -r Bin_R2_NASA*
rm -r Obj_R2_NASA*

