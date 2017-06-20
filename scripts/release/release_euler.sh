#!/bin/bash

cd ../../../
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

exclude=""
filter=(    
BD_MST015B_*
BD_MST024B_*
BD_MST132*
BD_MST157*
a7_nos_mips
emerald_nos_mips
FILES_COMMON_EMERALD.mk
FILES_MIPS_A7*
FILES_MIPS_EMERALD_*
bootloader_A7.ld
target_A7.ld
MIUSEL_A7_*
MIUSEL_EMERALD_*
MMAP_DTVMM_A7_*
MMAP_DTVMM_EMERALD_*
sysinfo2_a7.h
sysinfo2_emerald.h
SW_CONFIG_TRUNK_A7_*
SW_Config_Trunk_A7_*
SW_Config_Trunk_Dvbt_A7_*
SW_CONFIG_TRUNK_EMERALD_*
a7
A7
emerald
EMERALD
include_sz
Bin_*
Obj_*
)
for i in "${filter[@]}" ; do
  exclude="$exclude --exclude=$i"
done

date=`date +%Y%m%d_%k%M`

targetDir="Chakra3"

zipFile="Chakra3_DVBT_$1.tar.gz"

echo -----
echo $zipFile
echo $exclude
echo -----
tar -zcvf $zipFile $exclude -C $targetDir/ `ls $targetDir`

exit 0

