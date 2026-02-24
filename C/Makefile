F_COLLEEN = ./Colleen
F_GRACE   = ./Grace
F_SULLY   = ./Sully

CC      = gcc
CFLAGS  = -Wall -Werror -Wextra

COLLEEN_BIN = $(F_COLLEEN)/Colleen
GRACE_BIN   = $(F_GRACE)/Grace
SULLY_BIN   = $(F_SULLY)/Sully

all: $(COLLEEN_BIN) $(GRACE_BIN) $(SULLY_BIN)
exec_all: colleen_exec grace_exec sully_exec
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

$(COLLEEN_BIN): $(F_COLLEEN)/Colleen.c
	$(CC) $(CFLAGS) -o $@ $<

colleen_exec: $(COLLEEN_BIN)
	@cd $(F_COLLEEN) && ./Colleen > tmp_Colleen

colleen_diff: colleen_exec
	@cd $(F_COLLEEN) && \
	if diff Colleen.c tmp_Colleen >/dev/null ; then \
		echo "$(GREEN)Colleen: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Colleen: diff found ❌$(RESET)"; \
		diff Colleen.c tmp_Colleen; \
	fi

##############
# GRACE
##############

$(GRACE_BIN): $(F_GRACE)/Grace.c
	$(CC) $(CFLAGS) -o $@ $<

grace_exec: $(GRACE_BIN)
	@cd $(F_GRACE) && ./Grace

grace_diff: grace_exec
	@cd $(F_GRACE) && \
	if diff Grace.c Grace_kid.c >/dev/null ; then \
		echo "$(GREEN)Grace: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Grace: diff found ❌$(RESET)"; \
		diff Grace.c Grace_kid.c; \
	fi

##############
# SULLY
##############

$(SULLY_BIN): $(F_SULLY)/Sully.c
	$(CC) $(CFLAGS) -o $@ $<

sully_exec: $(SULLY_BIN)
	@cd $(F_SULLY) && ./Sully

sully_diff: sully_exec
	@cd $(F_SULLY) && for f in Sully[0-9].c; do \
		echo "$(GREEN)Diff with $(RED)$$f$(RESET)"; \
		diff Sully.c $$f || true; \
	done

##############
# CLEAN
##############

fclean:
	rm -f $(COLLEEN_BIN) $(F_COLLEEN)/tmp_Colleen
	rm -f $(GRACE_BIN) $(F_GRACE)/Grace_kid.c
	rm -f $(SULLY_BIN) $(F_SULLY)/Sully[0-9]*

.PHONY: all exec_all diff_all colleen_exec colleen_diff grace_exec grace_diff sully_exec sully_diff fclean