EUID    := $(shell id -u -r)

all: check addcron

# Check for root user
check:
ifneq ($(EUID),0)
        @echo "Please run as root user"
        @exit 1
endif

addcron:
        chmod +x ./wifi_rebooter.sh
        cp ./wifi_rebooter.sh /usr/local/bin/
        CRONENTRY= \
        crontab -l; echo "*/5 * * * * root /usr/local/bin/wifi_rebooter.sh" | crontab -
