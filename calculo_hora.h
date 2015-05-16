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

#ifndef CALCULO_HORA_H
#define	CALCULO_HORA_H

void iniVariavel(char *h, char *m, char *s, char *ms, char *marcacao){
	h[0] = marcacao[0];
	h[1] = marcacao[1];
	h[2] = '\0';
	m[0] = marcacao[3];
	m[1] = marcacao[4];
	m[2] = '\0'
	s[0] = marcacao[6];
	s[1] = marcacao[7];
	s[2] = '\0';
	ms[0] = marcacao[9];
	ms[1] = marcacao[10];
	ms[2] = marcacao[11];
	ms[3] = '\0';
}

void somaTempo(char * ini, char * fim, char id){

	char horaIn[3], minIn[3], segIn[3], msIn[4], horaFim[3], minFim[3], segFim[3], msFim[4];

	iniVariavel(horaIn, minIn, segIn, msIn, ini);
	iniVariavel(horaFim, minFim, segFim, msFim, fim);
	int hIni, mIni, sIni, msIni;
	int hFim, mFim, sFim, msFim;
	hIni = atoi(horaIn);
	mIni = atoi(minIn);
	sIni = atoi(segIn);
	msIni = atoi(msIn);
	hFim = atoi(horaFim);
	mFim = atoi(minFim);
	sFim = atoi(segFim);
	msFim = atoi(msFim);
	
	if(id == 'h'){


	}else if(id == 'm'){


	}else if(id == 's'){


	}else{

	}
	

}


#endif	/* CALCULO_HORA_H */

