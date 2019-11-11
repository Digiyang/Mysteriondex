Mantel.txt: Schuhe.txt Handy.txt Pullover.txt
	@touch $@
	@echo Mantel anziehen

Schuhe.txt: Hose.txt Struempfe.txt
	@touch $@
	@echo Schuhe angezogen

Handy.txt: Hose.txt
	@touch $@
	@echo Handy in der Hosentasche

Pullover.txt: Hemd.txt
	@touch $@
	@echo Pullover anziehen

Hose.txt: Hemd.txt Unterhose.txt
	@touch $@
	@echo Hose anziehen
Hemd.txt: Unterhemd.txt
	@touch $@
	@echo  Hemd angezogen
Struempfe.txt:
	@touch Struempfe.txt 
	@echo Strumpfe angezogen

Unterhose.txt:
	@touch Unterhose.txt 
	@echo Unterhose angezogen

Unterhemd.txt:
	@touch Unterhemd.txt
	@echo Unterhemd angezogen

Nackt:
	rm *.txt
