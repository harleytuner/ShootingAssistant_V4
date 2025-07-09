#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\SD_Card.h"
#pragma once
#include "Arduino.h"
#include <cstring>
#include "FS.h"
#include "SD_MMC.h"

#define SD_CLK_PIN      14
#define SD_CMD_PIN      17 
#define SD_D0_PIN       16 
#define SD_D1_PIN       -1 
#define SD_D2_PIN       -1 
#define SD_D3_PIN       21 

extern uint16_t SDCard_Size;
extern uint16_t Flash_Size;

void SD_Init();
void Flash_test();

bool File_Search(const char* directory, const char* fileName);
uint16_t Folder_retrieval(const char* directory, const char* fileExtension, char File_Name[][100],uint16_t maxFiles);
