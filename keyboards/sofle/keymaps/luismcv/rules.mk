# Update keymaps visualisations, using fortitude60's layout for now, which is similar enoughgit 
.PHONY: %
%:
	keymapviz -r -c keyboards/sofle/keymaps/luismcv/keymapviz.toml -k fortitude60 keyboards/sofle/keymaps/luismcv/keymap.c > /dev/null

OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

LTO_ENABLE = yes
