QMAKE_TARGET  = cascades_performance_biz_apps
PROJECT_DIR	  := $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))
I18N_DIR	  := $(PROJECT_DIR)/translations

include mk/cs-base.mk

