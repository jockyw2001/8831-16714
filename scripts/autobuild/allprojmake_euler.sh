export CC=/usr/bin/gcc
cd ../../
rm -r -f BIN_EULER_ALL
mkdir BIN_EULER_ALL
cp config.tmpl .config -f


PURE_PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/tools/bin/
export PATH=/tools/aeon/bin:$PURE_PATH

VER_FILE=./project/boarddef/Board
CFG_FILE=./.config

#board 165C all project

BD_NAME=BD_MST165C_D01B_S
BD_FILE=./project/boarddef/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER

if [ "$1" == "" ]; then
	echo "No Version Number"
else
cp ${VER_FILE}.h ${VER_FILE}.org
sed -i 's/#define AUTO_BUILD_SW_VER.*/#define AUTO_BUILD_SW_VER                 '${1}'/g' ${VER_FILE}.h
fi

#cp ${BD_FILE}.h ${BD_FILE}.org
sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}
PROJ=R2_EULER_ZUI_128MB_DVBT make
PROJ=R2_EULER_ZUI_128MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_DVBT make
PROJ=R2_EULER_ZUI_64MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

TUNER_TYPE=NUTUNE_FK1602_TUNER

sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}
PROJ=R2_EULER_ZUI_128MB_DVBT make
PROJ=R2_EULER_ZUI_128MB_DVBT 
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_DVBT make
PROJ=R2_EULER_ZUI_64MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}


#board 165B all project

BD_NAME=BD_MST165B_D01B_S
BD_FILE=./project/boarddef/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER
sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}

PROJ=R2_EULER_ZUI_128MB_DVBT make
PROJ=R2_EULER_ZUI_128MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_DVBT make
PROJ=R2_EULER_ZUI_64MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_ISDBT make
PROJ=R2_EULER_ZUI_64MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_128MB_ISDBT make
PROJ=R2_EULER_ZUI_128MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

#board 042B all project

BD_NAME=BD_MST042B_EULER
BD_FILE=./project/boarddef/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER
sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}

PROJ=R2_EULER_ZUI_128MB_DVBT make
PROJ=R2_EULER_ZUI_128MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_DVBT make
PROJ=R2_EULER_ZUI_64MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}


PROJ=R2_EULER_ZUI_64MB_ISDBT make
PROJ=R2_EULER_ZUI_64MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_128MB_ISDBT make
PROJ=R2_EULER_ZUI_128MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

#board MST047B all project

BD_NAME=BD_MST047B_10APU
BD_FILE=./project/boarddef/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER
sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}

PROJ=R2_EULER_ZUI_128MB_DVBT make
PROJ=R2_EULER_ZUI_128MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_64MB_DVBT make
PROJ=R2_EULER_ZUI_64MB_DVBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}


PROJ=R2_EULER_ZUI_64MB_ISDBT make
PROJ=R2_EULER_ZUI_64MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

PROJ=R2_EULER_ZUI_128MB_ISDBT make
PROJ=R2_EULER_ZUI_128MB_ISDBT
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}


cp -r Bin_R2_EULER_* ./BIN_EULER_ALL
rm -r Bin_R2_EULER_*

#recovery to original file
#cp ${BD_FILE}.org ${BD_FILE}.h
#rm -r ${BD_FILE}.org

cp config.tmpl .config -f

if [ "$1" == "" ]; then
	echo "No Version Number"
else
cp ${VER_FILE}.org ${VER_FILE}.h
rm -r ${VER_FILE}.org
fi