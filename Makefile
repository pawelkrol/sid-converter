include config

clean:
	make -C ./t clean
	make -C ./lib clean

compile:
	make -C ./lib compile

test: compile
	make -C ./t test
