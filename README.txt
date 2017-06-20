

////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (“MStar Confidential Information”) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////


[How to build for S4L / S4LE]

1. copy "config.tmpl" to ".config" at this directory
2. take a look at .config and change the MS_BOARD_TYPE_SEL define in it
3. change "PROJ=" setting for default project
3. without .config, current "make" will go the T1 path
   T1:      "make PROJ=S4L" (default)
   T2:      "make PROJ=S4LE"
   T1 ZUI:  "make PROJ=S4L_ZUI"

   NOTE! Do not submit .config to perforce

[Toolchain]
\\design_svr3\db_asic\HDTV\Tools\ToolChain\aeon-20081007-*.tar.bz2

[Environment]
We suggest you build code under linux, with CoLinux or VMWare Player.

1. Linux environment
2. Share your Linux drive with Samba
3. Mount the directory to windows drive
4. Setup new p4 client spec, with root on exported drive and "line end" is unix
5. Login as root
6. mkdir /opt
7. tar jxvf aeon-20081007-cygwin.tar.bz2 -C /opt
8. edit ~/.bash_profile
  a. add /opt/aeon/bin to your PATH
  b. add PATH_CHAKRA point to your Chakra directory
9. library source are under \\THEALE\Titania\Aeon_LIB
10. see about section

[Install toolchain on Cygwin]

1. find your z drive (or \\mstarfs01\share)
2. z:\shareware\aeon\current-stable-20081007
   get the file aeon-20081007-cygwin.tar.bz2
3. open cygwin shell
4. chdir to the directory "aeon-20081007-cygwin.tar.bz2" locates
5. mkdir /opt
6. tar jxvf aeon-20081007-cygwin.tar.bz2 -C /opt
7. edit /etc/profile.d/chakra.sh
   export PATH=$PATH:/opt/aeon/bin
   export PATH_CHAKRA=<the path to your chakra directory>
8. close the shell, and run it again

[Build library]
1. make sure your PATH_CHAKRA is set
2. make clean all install

[USB update]
1. 在Channel 選單內設定 Software Update = On
2. Input source : DTV
3. plug in USB disk with "MERGE.BIN" file
