flags=-Wall -liw

check_iw:
	@if [ -z `command -v iw` ] ;then \
		echo "error: iw is not installed in your system"; \
		exit 1; \
	fi

check_ffmpeg:
	@if [ -z `command -v ffmpeg` ] ;then \
		echo "error: ffmpeg is not installed in your system"; \
		exit 1; \
	fi
list_ssid:
	gcc -liw list_ssid.c -o list_ssid
scan_ssid:
	gcc -liw scan_ssid.c -o scan_ssid

all: check_iw check_ffmpeg list_ssid scan_ssid

clean:
	rm scan_ssid list_ssid
