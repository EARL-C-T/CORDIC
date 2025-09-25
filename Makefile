
BUILD_DIR := build/
FIXLIB := libfixpnt/
CORDICLIB := libCORDIC/
FIXCMD := fixcmd/
CORDICCMD := CORDICcmd/
OUT:= build/x86_64/
.PHONY:all clean install


all: $(BUILD_DIR) $(BUILD_DIR)$(FIXLIB) $(BUILD_DIR)$(FIXCMD) $(BUILD_DIR)$(CORDICLIB) $(BUILD_DIR)$(CORDICCMD) 
install:$(OUT) $(OUT)Makefile
	make -C $(OUT) install
$(OUT)Makfile: $(OUT) Makefile.install
	cp Makefile.install $(OUT)Makefile
$(OUT):
	@echo "IF THIS WAS TRIGURED SOMETHING IS AMISS";
	mkdir -p $(OUT)
$(BUILD_DIR)$(CORDICCMD):$(BUILD_DIR) $(CORDICCMD)
	cp -r $(CORDICCMD) $(BUILD_DIR)
	make -C $(BUILD_DIR)$(CORDICCMD)
	
$(BUILD_DIR)$(CORDICLIB): $(CORDICLIB) $(BUILD_DIR)
	cp -r $(CORDICLIB) $(BUILD_DIR)
	make -C $(BUILD_DIR)$(CORDICLIB)
	
$(BUILD_DIR)$(FIXCMD):$(BUILD_DIR) $(FIXCMD)
	cp -r $(FIXCMD) $(BUILD_DIR)
	make -C $(BUILD_DIR)$(FIXCMD)
	
$(BUILD_DIR)$(FIXLIB):$(FIXLIB) $(BUILD_DIR)
	cp -r $(FIXLIB)    $(BUILD_DIR)
	make -C $(BUILD_DIR)$(FIXLIB) all 
	
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
clean:
	rm -R $(BUILD_DIR)
	