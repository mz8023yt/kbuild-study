deps_config := \
	b/Kconfig \
	a/a1/Kconfig \
	a/Kconfig \
	Kconfig

include/config/auto.conf: \
	$(deps_config)

$(deps_config): ;
