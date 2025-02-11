all: cc as ld test/test-cc

cc: src/cc/cc.c

as: src/as/as.c

ld: src/ld/ld.c

test/test-cc:
	make -C test

test: test/test-cc
	./test/test-cc

