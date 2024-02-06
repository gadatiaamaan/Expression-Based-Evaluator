# Makefile for Calculator Project

# Commands to execute by default
all: calculator

# Commands to generate dependencies for calculator
depend: calculator-depend

# Clean generated files, perform real clean, check syntax, and execute custom targets
clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.calculator $@

# Target for building calculator project
.PHONY: calculator
calculator:
	@$(MAKE) -f Makefile.calculator all

# Target for generating dependencies for calculator project
.PHONY: calculator-depend
calculator-depend:
	@$(MAKE) -f Makefile.calculator depend

# List the project names
project_name_list:
	@echo calculator
