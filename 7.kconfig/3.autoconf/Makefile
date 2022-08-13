
.PHONY: FORCE

menuconfig: scripts/kconfig/mconf
	$< Kconfig

autoconf: scripts/kconfig/conf FORCE
	mkdir -p include/config
	mkdir -p include/linux
	$< -s Kconfig
