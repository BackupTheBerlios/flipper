BIN_DIRECTORY=~/bin
#BIN_DIRECTORY=/usr/local/bin

all:
	$(MAKE) -C fotrans

install: uninstall
	mkdir ~/.flipper
	cp -R includes ~/.flipper
	cp bin/flipper $(BIN_DIRECTORY)
	cp bin/fo2c $(BIN_DIRECTORY)
	cp bin/fo2tptp $(BIN_DIRECTORY)

uninstall:
	rm -Rf ~/.flipper
	rm -f $(BIN_DIRECTORY)/flipper
	rm -f $(BIN_DIRECTORY)/fo2c
	rm -f $(BIN_DIRECTORY)/fo2tptp

clean:
	$(MAKE) clean -C fotrans
	$(MAKE) clean -C includes
	$(MAKE) clean -C bin



