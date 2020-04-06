all: paper.pdf

paper.pdf: paper.tex references.bib
	pdflatex paper
	bibtex paper
	bibtex paper
	pdflatex paper
	pdflatex paper

tidy:
	rm -f paper.blg paper.bbl paper.aux paper.log

clean:
	make tidy
	rm -f paper.pdf

PHONY: all tidy clean
