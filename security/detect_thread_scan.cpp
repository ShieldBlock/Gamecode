// Detecção Anti-kill thread
// @Author : Matuzalém Teles
// @Version: 0.0.1

// ============================================================================ //
// Include
// ============================================================================ //
#include "stdafx.h"

// ============================================================================ //
// DC - Fecha o jogo ou enviar informações para o servidor
// ============================================================================ //
void DC(){
	
}

// ============================================================================ //
// Analise do processo
// ============================================================================ //
PROCESSENTRY32 *GetProcessInfo(char *szExeFile){
	PROCESSENTRY32  *pe32 = new PROCESSENTRY32 [sizeof(PROCESSENTRY32)];
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hSnapshot == INVALID_HANDLE_VALUE)
		return NULL;

    if(!Process32First(hSnapshot, pe32)){
        CloseHandle(hSnapshot);
        return NULL;
    }

    while(Process32Next( hSnapshot, pe32 )){
		if( strcmp(szExeFile, pe32->szExeFile) == 0){
			CloseHandle(hSnapshot);
			return pe32;
		}
    }
	return NULL;
}

// ============================================================================ //
// Tempo do kill
// ============================================================================ //
void tKill(){
	Killt();
    Sleep (load.Kill_T_Occours); 
    Killt();
    Sleep (load.Kill_T_Occours); 
    Killt();
    Sleep (load.Kill_T_Occours); 
	
	PROCESSENTRY32 *spe32 = GetProcessInfo(load.Nome_do_Main);
	again:
	Sleep (load.Kill_T_Occours);
    PROCESSENTRY32 *pe32 = GetProcessInfo(load.Nome_do_Main);
   	if (spe32->cntThreads != pe32->cntThreads){
  		DC();
   	}else{
   		Killt();
   		delete [] pe32;
   		pe32 = NULL;
   		goto again;
	}
}

void tKills(){
	if (load.AK_Scan_A == 1){
		Killt();
	    tKill();
	}else{
		tKill();
	}
}

void AntiKill_Start(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(tKills),NULL,0,0);
}