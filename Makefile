install:
	cd ./wiringPi/ && git submodule init
	cd ./wiringPi/ && git submodule update
	cd ./wiringPi/ && ./build

	cd ./433Utils/RPi_utils && git submodule init
	cd ./433Utils/RPi_utils && git submodule update
	cd ./433Utils/RPi_utils && make
	ln -sf ./433Utils/RPi_utils/script.sh ./script.sh
	ln -sf ./433Utils/RPi_utils/RFSniffer ./RFsniffer
