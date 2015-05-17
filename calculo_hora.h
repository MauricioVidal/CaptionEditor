/*-----------------------------------------------------------
*          UNIFAL – Universidade Federal de Alfenas.        
 * Trabalho..: Editor de Legendas usando lista encadeada    
 * Disciplina: Estrutura de Dados I                         
 * Professor.: Luiz Eduardo da Silva                        
 * Aluno(s)..: Beatriz de Oliveira Rodrigues
 *             Maurício Roque Vidal                             
 *             Monica de Cassia Roncada 
 *             Willian de Souza Soares       
 * Data......: 27/05/2015                                   
 *------------------------------------------------------------*/

 
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

#ifndef CALCULO_HORA_H
#define	CALCULO_HORA_H

void iniVariavel(char *h, char *m, char *s, char *ms, char *marcacao){
	h[0] = marcacao[0];
	h[1] = marcacao[1];
	h[2] = '\0';
	m[0] = marcacao[3];
	m[1] = marcacao[4];
	m[2] = '\0';
	s[0] = marcacao[6];
	s[1] = marcacao[7];
	s[2] = '\0';
	ms[0] = marcacao[9];
	ms[1] = marcacao[10];
	ms[2] = marcacao[11];
	ms[3] = '\0';
}

char itoa(int i){
    if(i == 0){
        return  '0';
    }else if(i == 1){
        return '1';
    }else if(i == 2){
        return '2';
    }else if(i == 3){
        return '3';
    }else if(i == 4){
        return '4';
    }else if(i == 5){
        return '5';
    }else if(i == 6){
        return '6';
    }else if(i == 7){
        return '7';
    }else if(i == 8){
        return '8';
    }else if(i == 9){
        return '9';
    }
    printf("Nao eh um numero inteiro");
}

void somaTempo(char * ini, char * fim, int tempo, char id){

	char horaIn[3], minIn[3], segIn[3], msIn[4], horaFim[3], minFim[3], segFim[3], msegFim[4];

	iniVariavel(horaIn, minIn, segIn, msIn, ini);
	iniVariavel(horaFim, minFim, segFim, msegFim, fim);
	int hIni, mIni, sIni, msIni;
	int hFim, mFim, sFim, msFim;
	hIni = atoi(horaIn);
	mIni = atoi(minIn);
	sIni = atoi(segIn);
	msIni = atoi(msIn);
	hFim = atoi(horaFim);
	mFim = atoi(minFim);
	sFim = atoi(segFim);
	msFim = atoi(msegFim);
        	
	if(id == 'h'){
		int h;
		//Tempo inicial
		h = hIni + tempo;
		hIni = h%24;
		//Tempo final
		h = hFim + tempo;
		hFim = h%24;
	}else if(id == 'm'){
		int m, incremento, h;
		//Tempo inicial
		m = mIni + tempo;
		mIni = m%60;
		incremento = m/60;
		h = hIni + incremento;
		hIni = h%24;
		//Tempo final
		m = mFim + tempo;
		mFim = m%60;
		incremento = m/60;
		h = hFim + incremento;
		hFim = h%24;
	}else if(id == 's'){
		int s, incremento1, m, incremento2, h;
		//Tempo Inicial
		s = sIni + tempo;
		sIni = s%60;
		incremento1 = s/60;
		m = mIni + incremento1;
		mIni = m%60;
		incremento2 = m/60;
		h = hIni + incremento2;
		hIni = h%24;	
		//Tempo Final
		s = sFim + tempo;
		sFim = s%60;
		incremento1 = s/60;
		m = mFim + incremento1;
		mFim = m%60;
		incremento2 = m/60;
		h = hFim + incremento2;
		hFim = h%24;
                
	}else if(id == 'l'){
		int ms, incremento1, s, incremento2, m, incremento3, h;
		//Tempo inicial
		ms = msIni + tempo;
		msIni = ms%1000;
		incremento1 = ms/1000;
                s = sIni + incremento1;
		sIni = s%60;

		incremento2 = s/60;
		m = mIni + incremento2;
		mIni = m%60;
		incremento3 = m/60;
		h = hIni + incremento3;
		hIni = h%24;
		//Tempo final
		ms = msFim + tempo;
		msFim = ms%1000;
		incremento1 = ms/1000;
		s = sFim + incremento1;
		sFim = s%60;
		incremento2 = s/60;
		m = mFim + incremento2;
		mFim = m%60;
		incremento3 = m/60;
		h = hFim + incremento3;
		hFim = h%24;
	}
        
	//Tranformar em char novamente e colocar nas posicoes corretas.
	//Hora inicial
	ini[0] = itoa(hIni/10);
	ini[1] = itoa(hIni%10);
	ini[3] = itoa(mIni/10);
	ini[4] = itoa(mIni%10);
	ini[6] = itoa(sIni/10);
	ini[7] = itoa(sIni%10);
	ini[9] = itoa(msIni/100);
	ini[10] = itoa((msIni%100)/10);
	ini[11] = itoa((msIni%100)%10);
	//Hora final
	fim[0] = itoa(hFim/10);
	fim[1] = itoa(hFim%10);
	fim[3] = itoa(mFim/10);
	fim[4] = itoa(mFim%10);
	fim[6] = itoa(sFim/10);
	fim[7] = itoa(sFim%10);
	fim[9] = itoa(msFim/100);
	fim[10] = itoa((msFim%100)/10);
	fim[11] = itoa((msFim%100)%10);
}

int horaMaior(char h1[], char h2[]){ //h1 > h2
	char h1H[3], h1Min[3], h1S[3], h1Ms[4], h2H[3], h2Min[3], h2S[3], h2Ms[4];
	iniVariavel(h1H, h1Min, h1S, h1Ms, h1);
	iniVariavel(h2H, h2Min, h2S, h1Ms, h2);
	int h1HI, h1MinI, h1SI, h1MsI;
	int h2HI, h2MinI, h2SI, h2MsI;
	h1HI = atoi(h1H);
	h1MinI = atoi(h1Min);
	h1SI = atoi(h1S);
	h1MsI = atoi(h1Ms);
	h2HI = atoi(h2H);
	h2MinI = atoi(h2Min);
	h2SI = atoi(h2S);
	h2MsI = atoi(h2Ms);
	
	if(h1HI > h2HI)
		return 1;
	if(h1HI == h2HI)
		if(h1MinI > h2MinI)
			return 1;
	if(h1HI == h2HI)
		if(h1MinI == h2MinI)
			if(h1SI > h2SI)
				return 1;
	if(h1HI == h2HI)
		if(h1MinI == h2MinI)
			if(h1SI == h2SI)
				if(h1MsI > h2MsI)
					return 1;
	return 0;
}

int horaMenor(char h1[], char h2[]){
	char h1H[3], h1Min[3], h1S[3], h1Ms[4], h2H[3], h2Min[3], h2S[3], h2Ms[4];
	iniVariavel(h1H, h1Min, h1S, h1Ms, h1);
	iniVariavel(h2H, h2Min, h2S, h1Ms, h2);
	int h1HI, h1MinI, h1SI, h1MsI;
	int h2HI, h2MinI, h2SI, h2MsI;
	h1HI = atoi(h1H);
	h1MinI = atoi(h1Min);
	h1SI = atoi(h1S);
	h1MsI = atoi(h1Ms);
	h2HI = atoi(h2H);
	h2MinI = atoi(h2Min);
	h2SI = atoi(h2S);
	h2MsI = atoi(h2Ms);
	
	if(h1HI < h2HI)
		return 1;
	if(h1HI == h2HI)
		if(h1MinI < h2MinI)
			return 1;
	if(h1HI == h2HI)
		if(h1MinI == h2MinI)
			if(h1SI < h2SI)
				return 1;
	if(h1HI == h2HI)
		if(h1MinI == h2MinI)
			if(h1SI == h2SI)
				if(h1MsI < h2MsI)
					return 1;
	return 0;
}

int horaIgual(char h1[], char h2[] ){
	if(!strcmp(h1,h2)){
		return 1;
	}
	return 0;
}


#endif	/* CALCULO_HORA_H */

