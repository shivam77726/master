

PWD:=$(shell pwd)
INSTALL_DIR=modules

obj-m+=helloWorld.o
helloworld_mod-objs := helloworld.o






default:
	@rm -rf ${INSTALL_DIR}
	@mkdir  ${INSTALL_DIR}

all:
	make -C /lib/modules/$(shell uname -r)/M=$(PWD) ${INSTALL_DIR}
	@mv -f*.o*.ko*.mod.c*.cmd ${INSTALL_DIR}

install:
	@mkdir /lib/modules/$(shell uname -r)/build/extra
	@cp ./modules/Hellok.ko /lib/modules/6.6.1/extra/HelloK.ko
	make -C /lib/modules/$(shell uname -r)/build/M=$(PWD) modules_install

clean:
	make -C /lib/modules/$(shell uname -r)/build/M=$(PWD) clean
	@rm -rf ${INSTALL_DIR}
