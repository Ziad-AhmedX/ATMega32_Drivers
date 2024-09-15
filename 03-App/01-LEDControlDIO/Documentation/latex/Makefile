LATEX_CMD=pdflatex

all: refman.pdf

pdf: refman.pdf

refman.pdf: clean refman.tex
	@$(LATEX_CMD) refman
	@makeindex refman.idx
	@$(LATEX_CMD) refman
	@latex_count=8 ; \
	@while egrep -s 'Rerun (LaTeX|to get cross-references right)' refman.log && [ $$latex_count -gt 0 ] ;\
	    @do \
	      @echo "Rerunning latex...." ;\
	      @$(LATEX_CMD) refman ;\
	      @latex_count=`expr $$latex_count - 1` ;\
	    @done
	@makeindex refman.idx
	@$(LATEX_CMD) refman


clean:
	@rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl refman.pdf
	
clean_up:
	@rm -f 01-LEDControlDIO.pdf

merge: clean_up
	@pdfunite main_8c__incl.pdf DIO__program_8c__incl.pdf DIO__config_8h__dep__incl.pdf DIO__private_8h__dep__incl.pdf DIO__interface_8h__dep__incl.pdf 01-LEDControlDIO.pdf
