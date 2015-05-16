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

void iniVariavel(char *h, char *m, char *s, char *ms, char *ini){
	h[0] = ini[0];
	h[1] = ini[1];
	h[2] = '\0';
	m[0] = ini[3];
	m[1] = ini[4];
	m[2] = '\0'
	s[0] = ini[6];
	s[1] = ini[7];
	s[2] = '\0';
	ms[0] = ini[9];
	ms[1] = ini[10];
	ms[2] = ini[11];
	ms[3] = '\0';
}

void somaTempo(char * ini, char * fim, char id){

	char horaIn[3], minIn[3], segIn[3], msIn[4], horaFim[3], minFim[3], segFim[3], msFim[4];

	iniVariavel(horaIn, minIn, segIn, msIn, ini);
	iniVariavel(horaFim, minFim, segFim, msFim, fim);

	
	if(id == 'h'){


	}else if(id == 'm'){


	}else if(id == 's'){


	}else{

	}
	

}


#endif	/* CALCULO_HORA_H */

