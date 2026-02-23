F_COLLEEN = ./Colleen
F_GRACE   = ./Grace
F_SULLY   = ./Sully

ASM      = nasm
ASMFLAGS = -f elf64
CC       = gcc
CFLAGS   = -Wall -Werror -Wextra

COLLEEN_BIN = $(F_COLLEEN)/Colleen
GRACE_BIN   = $(F_GRACE)/Grace
SULLY_BIN   = $(F_SULLY)/Sully

all: $(COLLEEN_BIN) $(GRACE_BIN) $(SULLY_BIN)
exec_all: colleen_exec grace_exec sully_exec
diff_all: colleen_diff grace_diff sully_diff

##############
# COLORS
##############

GREEN  = \033[0;32m
BLUE   = \033[0;34m
CYAN   = \033[0;36m
YELLOW = \033[0;33m
RED    = \033[0;31m
MAGENTA= \033[0;35m
RESET  = \033[0m

##############
# COLLEEN
##############

$(COLLEEN_BIN): $(F_COLLEEN)/Colleen.s
	$(ASM) $(ASMFLAGS) $< -o $(F_COLLEEN)/Colleen.o
	$(CC) $(F_COLLEEN)/Colleen.o -o $@

colleen_exec: $(COLLEEN_BIN)
	@cd $(F_COLLEEN) && ./Colleen > tmp_Colleen

colleen_diff: colleen_exec
	@cd $(F_COLLEEN) && \
	if diff Colleen.s tmp_Colleen >/dev/null ; then \
		echo "$(GREEN)Colleen: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Colleen: diff found ❌$(RESET)"; \
		diff Colleen.s tmp_Colleen; \
	fi

##############
# GRACE
##############

$(GRACE_BIN): $(F_GRACE)/Grace.s
	$(ASM) $(ASMFLAGS) $< -o $(F_GRACE)/Grace.o
	$(CC) $(F_GRACE)/Grace.o -o $@

grace_exec: $(GRACE_BIN)
	@cd $(F_GRACE) && ./Grace

grace_diff: grace_exec
	@cd $(F_GRACE) && \
	if diff Grace.s Grace_kid.s >/dev/null ; then \
		echo "$(GREEN)Grace: no diff ✅$(RESET)"; \
	else \
		echo "$(RED)Grace: diff found ❌$(RESET)"; \
		diff Grace.s Grace_kid.s; \
	fi

##############
# SULLY
##############

$(SULLY_BIN): $(F_SULLY)/Sully.s
	$(ASM) $(ASMFLAGS) $< -o $(F_SULLY)/Sully.o
	$(CC) $(F_SULLY)/Sully.o -o $@

sully_exec: $(SULLY_BIN)
	@cd $(F_SULLY) && ./Sully

sully_diff: sully_exec
	@cd $(F_SULLY) && for f in Sully[0-9].s; do \
		echo "$(GREEN)Diff with $(RED)$$f$(RESET)"; \
		diff Sully.s $$f || true; \
	done

##############
# CLEAN
##############

fclean:
	rm -f $(COLLEEN_BIN) $(F_COLLEEN)/Colleen.o $(F_COLLEEN)/tmp_Colleen
	rm -f $(GRACE_BIN) $(F_GRACE)/Grace.o $(F_GRACE)/Grace_kid.s
	rm -f $(SULLY_BIN) $(F_SULLY)/Sully.o $(F_SULLY)/Sully[0-9]*

.PHONY: all exec_all diff_all colleen_exec colleen_diff grace_exec grace_diff sully_exec sully_diff fclean