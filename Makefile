# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Glad_config = debug
  ImGui_config = debug
  ChiRhoLib_config = debug
  ChiRhoTest_config = debug
  ChiRhoPi_config = debug

else ifeq ($(config),release)
  Glad_config = release
  ImGui_config = release
  ChiRhoLib_config = release
  ChiRhoTest_config = release
  ChiRhoPi_config = release

else ifeq ($(config),dist)
  Glad_config = dist
  ImGui_config = dist
  ChiRhoLib_config = dist
  ChiRhoTest_config = dist
  ChiRhoPi_config = dist

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := Glad ImGui ChiRhoLib ChiRhoTest ChiRhoPi

.PHONY: all clean help $(PROJECTS) Dependencies

all: $(PROJECTS)

Dependencies: Glad ImGui

Glad:
ifneq (,$(Glad_config))
	@echo "==== Building Glad ($(Glad_config)) ===="
	@${MAKE} --no-print-directory -C vendor -f Glad.make config=$(Glad_config)
endif

ImGui:
ifneq (,$(ImGui_config))
	@echo "==== Building ImGui ($(ImGui_config)) ===="
	@${MAKE} --no-print-directory -C vendor -f ImGui.make config=$(ImGui_config)
endif

ChiRhoLib: Glad ImGui
ifneq (,$(ChiRhoLib_config))
	@echo "==== Building ChiRhoLib ($(ChiRhoLib_config)) ===="
	@${MAKE} --no-print-directory -C ChiRhoLib/ChiRhoLib -f Makefile config=$(ChiRhoLib_config)
endif

ChiRhoTest: ChiRhoLib ImGui Glad
ifneq (,$(ChiRhoTest_config))
	@echo "==== Building ChiRhoTest ($(ChiRhoTest_config)) ===="
	@${MAKE} --no-print-directory -C ChiRhoTest/ChiRhoTest -f Makefile config=$(ChiRhoTest_config)
endif

ChiRhoPi: ChiRhoLib ImGui Glad
ifneq (,$(ChiRhoPi_config))
	@echo "==== Building ChiRhoPi ($(ChiRhoPi_config)) ===="
	@${MAKE} --no-print-directory -C ChiRhoPi/ChiRhoPi -f Makefile config=$(ChiRhoPi_config)
endif

clean:
	@${MAKE} --no-print-directory -C vendor -f Glad.make clean
	@${MAKE} --no-print-directory -C vendor -f ImGui.make clean
	@${MAKE} --no-print-directory -C ChiRhoLib/ChiRhoLib -f Makefile clean
	@${MAKE} --no-print-directory -C ChiRhoTest/ChiRhoTest -f Makefile clean
	@${MAKE} --no-print-directory -C ChiRhoPi/ChiRhoPi -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo "  dist"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Glad"
	@echo "   ImGui"
	@echo "   ChiRhoLib"
	@echo "   ChiRhoTest"
	@echo "   ChiRhoPi"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"