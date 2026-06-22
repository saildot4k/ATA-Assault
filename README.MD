# ATA Assault

ATA Assault is a homebrew project for PS2 that packages ATA-backed BDM support into the two external driver slots used by old closed source homebrew apps that can load external USB drivers.

This tree builds:

- `usbd.irx`: BDM + BDMFS mass filesystem
- `usbhdfsd.irx`: DEV9 + ATAD block-device transport for BDM

Active source layout:

- `libbdm/`: shared BDM cache/defrag helpers
- `__bdm_assault/`: BDM and BDMFS source used by the `usbd.irx` bundle
- `__dev9_bdm_assault/`: `usbd.irx` bundle definition
- `__atad_bd_assault/`: `usbhdfsd.irx` bundle definition

The split now follows the working BDM Assault load shape. Load `usbd.irx` first in the `USBD.IRX` slot, then load `usbhdfsd.irx` second in the `USBHDFSD.IRX` slot. This keeps the first slot free of DEV9/DMACMAN link requirements, while the second slot starts DEV9 and then connects ATAD to BDM as a `mass` block device.

Even for ATA-backed storage, BDMFS registers the filesystem device as `mass`, so launched programs should receive `mass:/...` or `massN:/...` paths instead of `ata:/...`.

## Usage

To use this project you have to place the two IRX binaries provided in the release section into the path that your app looks for


### POPStarter
- `usbd.irx` must be pasted into `mc?:/POPSTARTER/usbd.irx`
- `usbhdfsd.irx` must be pasted into `mc?:/POPSTARTER/usbhdfsd.irx`

### FreeMcBoot
- `usbd.irx` must be pasted into `mc?:/SYS-CONF/USBD.IRX`
- `usbhdfsd.irx` must be pasted into `mc?:/SYS-CONF/USBHDFSD.IRX`

### FreeHdBoot
- `usbd.irx` must be pasted into `hdd0:__sysconf/FMCB/USBD.IRX`
- `usbhdfsd.irx` must be pasted into `hdd0:__sysconf/FMCB/USBHDFSD.IRX`

### old wLaunchELF versions
- `usbd.irx` must be pasted into the path you configured for `USBD.IRX`
- `usbhdfsd.irx` must be pasted into the path you configured for `USBHDFSD.IRX`

### Any other homebrew
- find out by yourself. I cant remember any other.

## Incompatible programs

- Simple Media System (SMS): incompatible due to usage of custom USB drivers and practices wich are not common amongst the homebrew devs. support not planned (and most likely not even possible)

## CREDITS

the softwares found here were taken and modified from [__PS2SDK__](https://github.com/ps2dev/ps2sdk)

- krHACKen: for letting me know POPStarter loads external USB drivers (wich ended up in the creation of this project)
- juankytutoriales: for making tests in real hardware
- everyone that collaborated to PS2SDK
