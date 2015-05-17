// Detecção de injeção por pesquisa de dlls
// @Author : Matuzalém Teles
// @Version: 0.0.1

// ============================================================================ //
// Include
// ============================================================================ //
#include "stdafx.h"

// ============================================================================ //
// Pesquisa
// ============================================================================ //
int file_exists(const char *filename)
{
  FILE *arquivo;
  if(arquivo = fopen(filename, "r"))
  {	 
    fclose(arquivo);	
	return 1;	
  }
    return 0;
}

// ============================================================================ //
// Enviar para o servidor e gravar log
// ============================================================================ //
void Injetado(){
	
}

// ============================================================================ //
// Lista de dlls
// ============================================================================ //
void I_loop(){
	 // [NAME.extension] Are NON case-sensitive.
	 if (GetModuleHandle("speedhack.dll")    ||
        (GetModuleHandle("smoll.dll"))        ){
			// Quando detectado, enviado para o servidor
			Injetado();
	 }
	 else
	 Sleep(100);
}

// ============================================================================ //
// TRD-Scan - Monitoramento das threads de detecção
// ============================================================================ //
void I_Scan(){
	
}

// ============================================================================ //
// Criação da tread final
// ============================================================================ //
void Dll_Inject(){
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(I_Scan),NULL,0,0);
}