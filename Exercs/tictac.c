#include<system.h>
#include<stdio.h>

PTR_DESC dtic;
PTR_DESC dtac;
PTR_DESC dmain;

void far corotina_tic() {
	
	while(1) {
		printf("tic-");
		transfer(dtic, dtac);	
	}

}


void far corotina_tac () {

	while (1) {
		printf("tac ");
		transfer(dtac, dtic);
	}

}


void main () {
	
	dtic = cria_desc();
	dtac = cria_desc();
	dmain = cria_desc();
	newprocess(corotina_tic,dtic);
	newprocess(corotina_tac,dtac);
	
	transfer(dmain, dtic);
	
}
