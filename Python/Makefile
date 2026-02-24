F_COLLEEN = ./Colleen
F_GRACE   = ./Grace
F_SULLY   = ./Sully

all: colleen grace sully
diff_all: colleen_diff grace_diff sully_diff

##############
# COLORS
##############

GREEN = \033[0;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
MAGENTA = \033[0;35m
RESET = \033[0m

##############
# COLLEEN
##############

colleen:
	@cd $(F_COLLEEN) && python3 Colleen.py > tmp_Colleen

colleen_diff: colleen
	@cd $(F_COLLEEN) && \
	if diff Colleen.py tmp_Colleen >/dev/null ; then \
		echo "$(GREEN)Colleen: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Colleen: diff found ❌$(RESET)"; \
		diff Colleen.py tmp_Colleen; \
	fi

##############
# GRACE
##############

grace:
	@cd $(F_GRACE) && python3 Grace.py

grace_diff: grace
	@cd $(F_GRACE) && \
	if diff Grace.py Grace_kid.py >/dev/null ; then \
		echo "$(GREEN)Grace: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Grace: diff found ❌$(RESET)"; \
		diff Grace.py Grace_kid.py; \
	fi

##############
# SULLY
##############

sully:
	@cd $(F_SULLY) && python3 Sully.py

sully_diff: sully
	@cd $(F_SULLY) && for f in Sully[0-9].py; do \
		echo "$(GREEN)Diff with $(RED)$$f$(RESET)"; \
		diff Sully.py $$f || true; \
	done

##############
# CLEAN
##############

fclean:
	rm -f $(F_COLLEEN)/tmp_Colleen
	rm -f $(F_GRACE)/Grace_kid.py
	rm -f $(F_SULLY)/Sully[0-9]*

.PHONY: all diff_all colleen colleen_diff grace grace_diff sully sully_diff fclean