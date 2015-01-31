
define reset
monitor reset
monitor flash device = AT91SAM3U4E
monitor flash download = 1
load
mon reg sp=(0x80000)
mon reg pc=(0x80004)
end
