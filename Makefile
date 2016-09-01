SUBDIRS = src tests

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	make -C $@

.PHONY: clean
clean:
	make -C src clean
	make -C tests clean 
