# BDM Assault

BDM Assault is a homebrew project for PS2 that aims to bring EXFAT USB support to those old closed source homebrew apps that can load external USB drivers that people still use today (POPStarter, FreeMcBoot).

This tree also builds an ATA variant for the same two-driver loading model:

- `dev9_bdm_assault.irx`: DEV9 + BDM + BDMFS
- `ata_bd_assault.irx`: ATAD block-device transport for BDM

The split is after BDMFS. Load `dev9_bdm_assault.irx` first in the `USBD.IRX` slot, then load `ata_bd_assault.irx` second in the `USBHDFSD.IRX` slot. This keeps the ATA order as DEV9 -> BDM -> BDMFS -> ATA_BD.

Even for ATA-backed storage, BDMFS registers the filesystem device as `mass`, so launched programs should receive `mass:/...` or `massN:/...` paths instead of `ata:/...`.

## Usage

To use this project you have to place the two IRX binaries provided at the [release section](https://github.com/israpps/BDMAssault/releases) into the path that your app looks for


### POPStarter
- `bdm_assault.irx` must be pasted into `mc?:/POPSTARTER/usbd.irx`
- `usbd_bd_assault.irx` must be pasted into `mc?:/POPSTARTER/usbhdfsd.irx`
- ATA variant: paste `dev9_bdm_assault.irx` as `mc?:/POPSTARTER/usbd.irx` and `ata_bd_assault.irx` as `mc?:/POPSTARTER/usbhdfsd.irx`

### FreeMcBoot
- `bdm_assault.irx` must be pasted into `mc?:/SYS-CONF/USBD.IRX`
- `usbd_bd_assault.irx` must be pasted into `mc?:/SYS-CONF/USBHDFSD.IRX`
- ATA variant: paste `dev9_bdm_assault.irx` as `mc?:/SYS-CONF/USBD.IRX` and `ata_bd_assault.irx` as `mc?:/SYS-CONF/USBHDFSD.IRX`

### FreeHdBoot
- `bdm_assault.irx` must be pasted into `hdd0:__sysconf/FMCB/USBD.IRX`
- `usbd_bd_assault.irx` must be pasted into `hdd0:__sysconf/FMCB/USBHDFSD.IRX`
- ATA variant: paste `dev9_bdm_assault.irx` as `hdd0:__sysconf/FMCB/USBD.IRX` and `ata_bd_assault.irx` as `hdd0:__sysconf/FMCB/USBHDFSD.IRX`

### old wLaunchELF versions
- `bdm_assault.irx` must be pasted into the path you configured for `USBD.IRX`
- `usbd_bd_assault.irx` must be pasted into the path you configured for `USBHDFSD.IRX`
- ATA variant: paste `dev9_bdm_assault.irx` into the configured `USBD.IRX` path and `ata_bd_assault.irx` into the configured `USBHDFSD.IRX` path

### Any other homebrew
- find out by yourself. I cant remember any other.

## Incompatible programs

- Simple Media System (SMS): incompatible due to usage of custom USB drivers and practices wich are not common amongst the homebrew devs. support not planned (and most likely not even possible)

## CREDITS

the softwares found here were taken and modified from [__PS2SDK__](https://github.com/ps2dev/ps2sdk)

- krHACKen: for letting me know POPStarter loads external USB drivers (wich ended up in the creation of this project)
- juankytutoriales: for making tests in real hardware
- everyone that collaborated to PS2SDK
