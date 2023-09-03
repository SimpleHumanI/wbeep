## description
this scirpt just send a request to getting wifi signal power
and informs you of the distance with a beep. The closer the signal,
the faster and more numerous the beeps

## requirements
you need 'ffmpeg' and 'iw' before use script

## how works
just clone the source code and enter 'make all' command
then you can use script with 'sudo ./wbeep --help' to give
you a help page

## troubleshooting
if you had a problem with sound, maybe you should
change 'ffmpeg' command used in 'wbeep' script
you can go to first lines and change variable FFM\_CMD,
this will change the command in entire script
