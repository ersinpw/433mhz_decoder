install:
        cd ./wiringPi/ && git submodule init
        cd ./wiringPi/ && git submodule update
        cd ./wiringPi/ && ./build

        cd ./433Utils/RPi_utils && git submodule init
        cd ./433Utils/RPi_utils && git submodule update
        cd ./433Utils/RPi_utils && make

        sudo chmod +x ./433Utils/RPi_utils/RFSniffer
        sudo chmod +x ./433Utils/RPi_utils/script.sh

        ln -sf ./433Utils/RPi_utils/script.sh ./script.sh
        ln -sf ./433Utils/RPi_utils/RFSniffer ./RFsniffer

        sudo rm -rf /etc/init.d/RFSniffer

        sudo cp ./initd_rfsniffer /etc/init.d/RFSniffer
        sudo ln -sf $(shell pwd)/433Utils/RPi_utils/script.sh /etc/init.d/script.sh
        sudo chmod +x /etc/init.d/RFSniffer
        sudo update-rc.d RFSniffer defaults
